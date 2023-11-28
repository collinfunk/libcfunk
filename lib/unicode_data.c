/*-
 * Copyright (c) 2023, Collin Funk
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#undef ARRAY_SIZE
#define ARRAY_SIZE(array) (sizeof (array) / sizeof (array[0]))

struct unicode_character
{
  char *name;
  char *category;
};

/* Table of Unicode characters indexed by code point. */
static struct unicode_character unicode_characters[0x10ffff];

static char *xstrdup (const char *s);
static unsigned long int xstrtoul (const char *nptr, char **endptr, int base);
static int read_unicode_data_line (FILE *fp, char *buffer, size_t buffer_size);
static int fill_unicode_character (unsigned long int index, char **fields);
static void read_unicode_data_file (const char *file_name);
static bool is_category_Lu (unsigned long int index);
static bool is_category_Ll (unsigned long int index);
static bool is_category_Lt (unsigned long int index);
static bool is_category_LC (unsigned long int index);
static bool is_category_Lm (unsigned long int index);
static bool is_category_Lo (unsigned long int index);
static bool is_category_L (unsigned long int index);
static bool is_category_Mn (unsigned long int index);
static bool is_category_Mc (unsigned long int index);
static bool is_category_Me (unsigned long int index);
static bool is_category_M (unsigned long int index);
static bool is_category_Nd (unsigned long int index);
static bool is_category_Nl (unsigned long int index);
static bool is_category_No (unsigned long int index);
static bool is_category_N (unsigned long int index);
static bool is_category_Pc (unsigned long int index);
static bool is_category_Pd (unsigned long int index);
static bool is_category_Ps (unsigned long int index);
static bool is_category_Pe (unsigned long int index);
static bool is_category_Pi (unsigned long int index);
static bool is_category_Pf (unsigned long int index);
static bool is_category_Po (unsigned long int index);
static bool is_category_P (unsigned long int index);
static bool is_category_Sm (unsigned long int index);
static bool is_category_Sc (unsigned long int index);
static bool is_category_Sk (unsigned long int index);
static bool is_category_So (unsigned long int index);
static bool is_category_S (unsigned long int index);
static bool is_category_Zs (unsigned long int index);
static bool is_category_Zl (unsigned long int index);
static bool is_category_Zp (unsigned long int index);
static bool is_category_Z (unsigned long int index);
static bool is_category_Cc (unsigned long int index);
static bool is_category_Cf (unsigned long int index);
static bool is_category_Cs (unsigned long int index);
static bool is_category_Co (unsigned long int index);
static bool is_category_Cn (unsigned long int index);
static bool is_category_C (unsigned long int index);

int
main (int argc, char **argv)
{
  size_t i;

  if (argc < 2)
    {
      fprintf (stderr, "Expected UnicodeData.txt\n");
      exit (1);
    }

  read_unicode_data_file (argv[1]);

  for (i = 0; i < ARRAY_SIZE (unicode_characters); ++i)
    {
      if (is_category_Zp (i))
        printf ("%s\n", unicode_characters[i].name);
    }

  return 0;
}

/* Duplicate the string S and abort if memory cannot be allocated. */
static char *
xstrdup (const char *s)
{
  char *copy = strdup (s);
  if (copy == NULL)
    {
      fprintf (stderr, "Out of memory\n");
      abort ();
    }
  return copy;
}

/* Convert NPTR from a string to an integer and abort on errors. */
static unsigned long int
xstrtoul (const char *nptr, char **endptr, int base)
{
  int saved_errno = errno;
  unsigned long int value;

  errno = 0;
  value = strtoul (nptr, endptr, base);
  if (errno == 0)
    errno = saved_errno;
  else
    {
      fprintf (stderr, "strtoul () failed\n");
      abort ();
    }
  return value;
}

/* Read a line from 'UnicodeData.txt'. Each line should have 14 semicolons
   separating each field and end in a LF or CRLF. */
static int
read_unicode_data_line (FILE *fp, char *buffer, size_t buffer_size)
{
  int semicolons_seen = 0;
  char *p = buffer;

  for (;;)
    {
      int ch = getc (fp);
      if (ch == EOF)
        ch = '\n';
      else if (ch == '\r')
        continue;
      else if (ch == ';')
        semicolons_seen++;
      if (p == buffer + buffer_size)
        {
          fprintf (stderr, "Increase buffer size for UnicodeData.txt\n");
          exit (1);
        }
      if (ch != '\n')
        *p++ = (char) ch;
      else
        {
          *p = '\0';
          break;
        }
    }
  return semicolons_seen;
}

/* Fill the character at INDEX using FIELDS which is an array of 15 strings.
   INDEX should be the code point of a character. */
static int
fill_unicode_character (unsigned long int index, char **fields)
{
  struct unicode_character *curr;
  char *name;
  char *category;

  if ((size_t) index > ARRAY_SIZE (unicode_characters))
    {
      fprintf (stderr, "Index out of range.\n");
      exit (1);
    }

  /* Get the character we are entering. */
  curr = &unicode_characters[index];

  name = fields[1];
  category = fields[2];

  curr->name = *name == '\0' ? "" : xstrdup (name);
  curr->category = *category == '\0' ? "" : xstrdup (category);
}

/* Fill the unicode_characters table from FILE_NAME. */
static void
read_unicode_data_file (const char *file_name)
{
  FILE *fp;
  size_t line_number;
  char buffer[2048];
  char *fields[15];
  unsigned long int index;

  /* Open the file. */
  fp = fopen (file_name, "rb");
  if (fp == NULL)
    {
      fprintf (stderr, "Failed to open UnicodeData.txt\n");
      exit (1);
    }

  /* Zero the unicode character table. */
  memset (unicode_characters, '\0', sizeof (unicode_characters));

  /* Parse each line. */
  for (line_number = 0;; ++line_number)
    {
      int result = read_unicode_data_line (fp, buffer, sizeof (buffer));
      if (result == 0)
        break;
      if (result != 14)
        {
          fprintf (stderr, "Invalid UnicodeData.txt\n");
          exit (1);
        }
      /* Separate the fields. */
      {
        int i;
        char *p = buffer;
        for (i = 0; i < 15; ++i)
          {
            fields[i] = p;
            p = strchr (p, (i == 14) ? '\0' : ';');
            if (p == NULL)
              abort ();
            *p++ = '\0';
          }
      }
      index = xstrtoul (fields[0], NULL, 16);
      if (fields[1][0] == '<' && strlen (fields[1]) > 8
          && strcmp (fields[1] + strlen (fields[1]) - 8, ", First>") == 0)
        {
          unsigned long int index_high;

          result = read_unicode_data_line (fp, buffer, sizeof (buffer));
          if (result != 14)
            {
              fprintf (stderr, "Missing end of range.\n");
              exit (1);
            }
          /* Separate the fields. */
          {
            int i;
            char *p = buffer;
            for (i = 0; i < 15; ++i)
              {
                fields[i] = p;
                p = strchr (p, (i == 14) ? '\0' : ';');
                if (p == NULL)
                  abort ();
                *p++ = '\0';
              }
          }
          index_high = xstrtoul (fields[0], NULL, 16);
          if (fields[1][0] != '<' || strlen (fields[1]) <= 7
              || strcmp (fields[1] + strlen (fields[1]) - 7, ", Last>") != 0)
            {
              fprintf (stderr, "Missing end of range.\n");
              exit (1);
            }
          else
            {
              unsigned long int i = index;

              fields[1][strlen (fields[1]) - 7] = '\0';
              fields[1]++;
              for (; i <= index_high; ++i)
                fill_unicode_character (i, fields);
            }
        }
      else
        fill_unicode_character (index, fields);
    }

  /* Close the file while checking for errors. */
  if (ferror (fp) != 0 || fclose (fp) != 0)
    {
      fprintf (stderr, "Failed to close UnicodeData.txt\n");
      exit (1);
    }
}

/* Returns true if INDEX is an uppercase letter. */
static bool
is_category_Lu (unsigned long int index)
{
  if ((size_t) index >= ARRAY_SIZE (unicode_characters))
    abort ();
  return unicode_characters[index].category != NULL
         && unicode_characters[index].category[0] == 'L'
         && unicode_characters[index].category[1] == 'u'
         && unicode_characters[index].category[2] == '\0';
}

/* Returns true if INDEX is an lowercase letter. */
static bool
is_category_Ll (unsigned long int index)
{
  if ((size_t) index >= ARRAY_SIZE (unicode_characters))
    abort ();
  return unicode_characters[index].category != NULL
         && unicode_characters[index].category[0] == 'L'
         && unicode_characters[index].category[1] == 'l'
         && unicode_characters[index].category[2] == '\0';
}

/* Returns true if INDEX is a digraph encoded as a single character, with
   the first part uppercase. */
static bool
is_category_Lt (unsigned long int index)
{
  if ((size_t) index >= ARRAY_SIZE (unicode_characters))
    abort ();
  return unicode_characters[index].category != NULL
         && unicode_characters[index].category[0] == 'L'
         && unicode_characters[index].category[1] == 't'
         && unicode_characters[index].category[2] == '\0';
}

/* Returns true if INDEX is a cased letter. */
static bool
is_category_LC (unsigned long int index)
{
  if ((size_t) index >= ARRAY_SIZE (unicode_characters))
    abort ();
  return unicode_characters[index].category != NULL
         && unicode_characters[index].category[0] == 'L'
         && (unicode_characters[index].category[1] == 'u'
             || unicode_characters[index].category[1] == 'l'
             || unicode_characters[index].category[1] == 't')
         && unicode_characters[index].category[2] == '\0';
}

/* Returns true if INDEX is a modifier letter. */
static bool
is_category_Lm (unsigned long int index)
{
  if ((size_t) index >= ARRAY_SIZE (unicode_characters))
    abort ();
  return unicode_characters[index].category != NULL
         && unicode_characters[index].category[0] == 'L'
         && unicode_characters[index].category[1] == 'm'
         && unicode_characters[index].category[2] == '\0';
}

/* Returns true if INDEX is an "other" letter, including syllables and
   ideographs. */
static bool
is_category_Lo (unsigned long int index)
{
  if ((size_t) index >= ARRAY_SIZE (unicode_characters))
    abort ();
  return unicode_characters[index].category != NULL
         && unicode_characters[index].category[0] == 'L'
         && unicode_characters[index].category[1] == 'o'
         && unicode_characters[index].category[2] == '\0';
}

/* Returns true if INDEX is a latter. */
static bool
is_category_L (unsigned long int index)
{
  if ((size_t) index >= ARRAY_SIZE (unicode_characters))
    abort ();
  return unicode_characters[index].category != NULL
         && unicode_characters[index].category[0] == 'L'
         && (unicode_characters[index].category[1] == 'u'
             || unicode_characters[index].category[1] == 'l'
             || unicode_characters[index].category[1] == 't'
             || unicode_characters[index].category[1] == 'm'
             || unicode_characters[index].category[1] == 'o')
         && unicode_characters[index].category[2] == '\0';
}

/* Returns true if INDEX is a nonspacing combining mark. */
static bool
is_category_Mn (unsigned long int index)
{
  if ((size_t) index >= ARRAY_SIZE (unicode_characters))
    abort ();
  return unicode_characters[index].category != NULL
         && unicode_characters[index].category[0] == 'M'
         && unicode_characters[index].category[1] == 'n'
         && unicode_characters[index].category[2] == '\0';
}

/* Returns true if INDEX is a spacing combining mark. */
static bool
is_category_Mc (unsigned long int index)
{
  if ((size_t) index >= ARRAY_SIZE (unicode_characters))
    abort ();
  return unicode_characters[index].category != NULL
         && unicode_characters[index].category[0] == 'M'
         && unicode_characters[index].category[1] == 'c'
         && unicode_characters[index].category[2] == '\0';
}

/* Returns true if INDEX is an enclosing-combining mark. */
static bool
is_category_Me (unsigned long int index)
{
  if ((size_t) index >= ARRAY_SIZE (unicode_characters))
    abort ();
  return unicode_characters[index].category != NULL
         && unicode_characters[index].category[0] == 'M'
         && unicode_characters[index].category[1] == 'e'
         && unicode_characters[index].category[2] == '\0';
}

/* Returns true if INDEX is a mark. */
static bool
is_category_M (unsigned long int index)
{
  if ((size_t) index >= ARRAY_SIZE (unicode_characters))
    abort ();
  return unicode_characters[index].category != NULL
         && unicode_characters[index].category[0] == 'M'
         && (unicode_characters[index].category[1] == 'n'
             || unicode_characters[index].category[1] == 'c'
             || unicode_characters[index].category[1] == 'e')
         && unicode_characters[index].category[2] == '\0';
}

/* Returns true if INDEX is a decimal digit. */
static bool
is_category_Nd (unsigned long int index)
{
  if ((size_t) index >= ARRAY_SIZE (unicode_characters))
    abort ();
  return unicode_characters[index].category != NULL
         && unicode_characters[index].category[0] == 'N'
         && unicode_characters[index].category[1] == 'd'
         && unicode_characters[index].category[2] == '\0';
}

/* Returns true if INDEX is a letterlike numeric character. */
static bool
is_category_Nl (unsigned long int index)
{
  if ((size_t) index >= ARRAY_SIZE (unicode_characters))
    abort ();
  return unicode_characters[index].category != NULL
         && unicode_characters[index].category[0] == 'N'
         && unicode_characters[index].category[1] == 'l'
         && unicode_characters[index].category[2] == '\0';
}

/* Returns true if INDEX is a numeric character of "other" type. */
static bool
is_category_No (unsigned long int index)
{
  if ((size_t) index >= ARRAY_SIZE (unicode_characters))
    abort ();
  return unicode_characters[index].category != NULL
         && unicode_characters[index].category[0] == 'N'
         && unicode_characters[index].category[1] == 'o'
         && unicode_characters[index].category[2] == '\0';
}

/* Returns true if INDEX is a number. */
static bool
is_category_N (unsigned long int index)
{
  if ((size_t) index >= ARRAY_SIZE (unicode_characters))
    abort ();
  return unicode_characters[index].category != NULL
         && unicode_characters[index].category[0] == 'N'
         && (unicode_characters[index].category[1] == 'd'
             || unicode_characters[index].category[1] == 'l'
             || unicode_characters[index].category[1] == 'o')
         && unicode_characters[index].category[2] == '\0';
}

/* Returns true if INDEX is a connector punctuation mark. */
static bool
is_category_Pc (unsigned long int index)
{
  if ((size_t) index >= ARRAY_SIZE (unicode_characters))
    abort ();
  return unicode_characters[index].category != NULL
         && unicode_characters[index].category[0] == 'P'
         && unicode_characters[index].category[1] == 'c'
         && unicode_characters[index].category[2] == '\0';
}

/* Returns true if INDEX is a dash or hyphen punctuation mark. */
static bool
is_category_Pd (unsigned long int index)
{
  if ((size_t) index >= ARRAY_SIZE (unicode_characters))
    abort ();
  return unicode_characters[index].category != NULL
         && unicode_characters[index].category[0] == 'P'
         && unicode_characters[index].category[1] == 'd'
         && unicode_characters[index].category[2] == '\0';
}

/* Returns true if INDEX is an opening punctuation mark. */
static bool
is_category_Ps (unsigned long int index)
{
  if ((size_t) index >= ARRAY_SIZE (unicode_characters))
    abort ();
  return unicode_characters[index].category != NULL
         && unicode_characters[index].category[0] == 'P'
         && unicode_characters[index].category[1] == 's'
         && unicode_characters[index].category[2] == '\0';
}

/* Returns true if INDEX is a closing punctuation mark. */
static bool
is_category_Pe (unsigned long int index)
{
  if ((size_t) index >= ARRAY_SIZE (unicode_characters))
    abort ();
  return unicode_characters[index].category != NULL
         && unicode_characters[index].category[0] == 'P'
         && unicode_characters[index].category[1] == 'e'
         && unicode_characters[index].category[2] == '\0';
}

/* Returns true if INDEX is an initial punctuation mark. */
static bool
is_category_Pi (unsigned long int index)
{
  if ((size_t) index >= ARRAY_SIZE (unicode_characters))
    abort ();
  return unicode_characters[index].category != NULL
         && unicode_characters[index].category[0] == 'P'
         && unicode_characters[index].category[1] == 'i'
         && unicode_characters[index].category[2] == '\0';
}

/* Returns true if INDEX is a final punctuation mark. */
static bool
is_category_Pf (unsigned long int index)
{
  if ((size_t) index >= ARRAY_SIZE (unicode_characters))
    abort ();
  return unicode_characters[index].category != NULL
         && unicode_characters[index].category[0] == 'P'
         && unicode_characters[index].category[1] == 'f'
         && unicode_characters[index].category[2] == '\0';
}

/* Returns true if INDEX is a punctuation mark of "other" type. */
static bool
is_category_Po (unsigned long int index)
{
  if ((size_t) index >= ARRAY_SIZE (unicode_characters))
    abort ();
  return unicode_characters[index].category != NULL
         && unicode_characters[index].category[0] == 'P'
         && unicode_characters[index].category[1] == 'o'
         && unicode_characters[index].category[2] == '\0';
}

/* Returns true if INDEX is a punctuation mark. */
static bool
is_category_P (unsigned long int index)
{
  if ((size_t) index >= ARRAY_SIZE (unicode_characters))
    abort ();
  return unicode_characters[index].category != NULL
         && unicode_characters[index].category[0] == 'P'
         && (unicode_characters[index].category[1] == 'c'
             || unicode_characters[index].category[1] == 'd'
             || unicode_characters[index].category[1] == 's'
             || unicode_characters[index].category[1] == 'e'
             || unicode_characters[index].category[1] == 'i'
             || unicode_characters[index].category[1] == 'f'
             || unicode_characters[index].category[1] == 'o')
         && unicode_characters[index].category[2] == '\0';
}

/* Returns true if INDEX is a symbol of mathematical use. */
static bool
is_category_Sm (unsigned long int index)
{
  if ((size_t) index >= ARRAY_SIZE (unicode_characters))
    abort ();
  return unicode_characters[index].category != NULL
         && unicode_characters[index].category[0] == 'S'
         && unicode_characters[index].category[1] == 'm'
         && unicode_characters[index].category[2] == '\0';
}

/* Returns true if INDEX is a currency sign. */
static bool
is_category_Sc (unsigned long int index)
{
  if ((size_t) index >= ARRAY_SIZE (unicode_characters))
    abort ();
  return unicode_characters[index].category != NULL
         && unicode_characters[index].category[0] == 'S'
         && unicode_characters[index].category[1] == 'c'
         && unicode_characters[index].category[2] == '\0';
}

/* Returns true if INDEX is a non-letterlike modifier symbol. */
static bool
is_category_Sk (unsigned long int index)
{
  if ((size_t) index >= ARRAY_SIZE (unicode_characters))
    abort ();
  return unicode_characters[index].category != NULL
         && unicode_characters[index].category[0] == 'S'
         && unicode_characters[index].category[1] == 'k'
         && unicode_characters[index].category[2] == '\0';
}

/* Returns true if INDEX is a symbol of "other" type. */
static bool
is_category_So (unsigned long int index)
{
  if ((size_t) index >= ARRAY_SIZE (unicode_characters))
    abort ();
  return unicode_characters[index].category != NULL
         && unicode_characters[index].category[0] == 'S'
         && unicode_characters[index].category[1] == 'o'
         && unicode_characters[index].category[2] == '\0';
}

/* Returns true if INDEX is a symbol. */
static bool
is_category_S (unsigned long int index)
{
  if ((size_t) index >= ARRAY_SIZE (unicode_characters))
    abort ();
  return unicode_characters[index].category != NULL
         && unicode_characters[index].category[0] == 'S'
         && (unicode_characters[index].category[1] == 'm'
             || unicode_characters[index].category[1] == 'c'
             || unicode_characters[index].category[1] == 'k'
             || unicode_characters[index].category[1] == 'o')
         && unicode_characters[index].category[2] == '\0';
}

/* Returns true if INDEX is a space character. */
static bool
is_category_Zs (unsigned long int index)
{
  if ((size_t) index >= ARRAY_SIZE (unicode_characters))
    abort ();
  return unicode_characters[index].category != NULL
         && unicode_characters[index].category[0] == 'Z'
         && unicode_characters[index].category[1] == 's'
         && unicode_characters[index].category[2] == '\0';
}

/* Returns true if INDEX is U+2028 LINE SEPARATOR. */
static bool
is_category_Zl (unsigned long int index)
{
  if ((size_t) index >= ARRAY_SIZE (unicode_characters))
    abort ();
  return unicode_characters[index].category != NULL
         && unicode_characters[index].category[0] == 'Z'
         && unicode_characters[index].category[1] == 'l'
         && unicode_characters[index].category[2] == '\0';
}

/* Returns true if INDEX is U+2029 PARAGRAPH SEPARATOR. */
static bool
is_category_Zp (unsigned long int index)
{
  if ((size_t) index >= ARRAY_SIZE (unicode_characters))
    abort ();
  return unicode_characters[index].category != NULL
         && unicode_characters[index].category[0] == 'Z'
         && unicode_characters[index].category[1] == 'p'
         && unicode_characters[index].category[2] == '\0';
}

/* Returns true if INDEX is a separator. */
static bool
is_category_Z (unsigned long int index)
{
  if ((size_t) index >= ARRAY_SIZE (unicode_characters))
    abort ();
  return unicode_characters[index].category != NULL
         && unicode_characters[index].category[0] == 'Z'
         && (unicode_characters[index].category[1] == 's'
             || unicode_characters[index].category[1] == 'l'
             || unicode_characters[index].category[1] == 'p')
         && unicode_characters[index].category[2] == '\0';
}

/* Returns true if INDEX is a C0 or C1 control code. */
static bool
is_category_Cc (unsigned long int index)
{
  if ((size_t) index >= ARRAY_SIZE (unicode_characters))
    abort ();
  return unicode_characters[index].category != NULL
         && unicode_characters[index].category[0] == 'C'
         && unicode_characters[index].category[1] == 'c'
         && unicode_characters[index].category[2] == '\0';
}

/* Returns true if INDEX is a format control character. */
static bool
is_category_Cf (unsigned long int index)
{
  if ((size_t) index >= ARRAY_SIZE (unicode_characters))
    abort ();
  return unicode_characters[index].category != NULL
         && unicode_characters[index].category[0] == 'C'
         && unicode_characters[index].category[1] == 'f'
         && unicode_characters[index].category[2] == '\0';
}

/* Returns true if INDEX is a surrogate code point. */
static bool
is_category_Cs (unsigned long int index)
{
  if ((size_t) index >= ARRAY_SIZE (unicode_characters))
    abort ();
  return unicode_characters[index].category != NULL
         && unicode_characters[index].category[0] == 'C'
         && unicode_characters[index].category[1] == 's'
         && unicode_characters[index].category[2] == '\0';
}

/* Returns true if INDEX is a private-use character. */
static bool
is_category_Co (unsigned long int index)
{
  if ((size_t) index >= ARRAY_SIZE (unicode_characters))
    abort ();
  return unicode_characters[index].category != NULL
         && unicode_characters[index].category[0] == 'C'
         && unicode_characters[index].category[1] == 'o'
         && unicode_characters[index].category[2] == '\0';
}

/* Returns true if INDEX is a reserved unassigned code point or a
   noncharacter. */
static bool
is_category_Cn (unsigned long int index)
{
  if ((size_t) index >= ARRAY_SIZE (unicode_characters))
    abort ();
  return unicode_characters[index].category != NULL
         && unicode_characters[index].category[0] == 'C'
         && unicode_characters[index].category[1] == 'n'
         && unicode_characters[index].category[2] == '\0';
}

/* Returns true if INDEX is an "other" character. */
static bool
is_category_C (unsigned long int index)
{
  if ((size_t) index >= ARRAY_SIZE (unicode_characters))
    abort ();
  return unicode_characters[index].category != NULL
         && unicode_characters[index].category[0] == 'C'
         && (unicode_characters[index].category[1] == 'c'
             || unicode_characters[index].category[1] == 'f'
             || unicode_characters[index].category[1] == 's'
             || unicode_characters[index].category[1] == 'o'
             || unicode_characters[index].category[1] == 'n')
         && unicode_characters[index].category[2] == '\0';
}

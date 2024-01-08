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

#include <config.h>

#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

#include "slist.h"

const void *
slist_node_data (struct slist_node *node)
{
  assert (node != NULL);

  return node->data;
}

struct slist_node *
slist_next_node (struct slist *list, struct slist_node *node)
{
  assert (list != NULL);
  assert (node != NULL);

  /* Unused. */
  (void) list;

  return node->next;
}

struct slist_node *
slist_previous_node (struct slist *list, struct slist_node *node)
{
  struct slist_node *prev;

  assert (list != NULL);
  assert (node != NULL);

  prev = list->head;
  if (prev == node)
    prev = NULL;
  else
    {
      /* Assumes that node is in the list. */
      while (prev->next != node)
        prev = prev->next;
    }

  return prev;
}

struct slist_node *
slist_first_node (struct slist *list)
{
  assert (list != NULL);

  return list->head;
}

struct slist_node *
slist_last_node (struct slist *list)
{
  struct slist_node *node;

  assert (list != NULL);

  node = list->head;
  if (node != NULL)
    {
      while (node->next != NULL)
        node = node->next;
    }

  return node;
}

size_t
slist_count (struct slist *list)
{
  struct slist_node *node;
  size_t count;

  assert (list != NULL);

  node = list->head;
  count = 0;
  while (node != NULL)
    {
      node = node->next;
      count++;
    }

  return count;
}

struct slist *
slist_new (bool (*equalfunc) (const void *, const void *))
{
  struct slist *list;

  list = (struct slist *) malloc (sizeof (struct slist));
  if (list == NULL)
    return NULL;

  list->head = NULL;
  list->equalfunc = equalfunc;

  return list;
}

void
slist_delete (struct slist *list)
{
  struct slist_node *node;

  assert (list != NULL);

  node = list->head;
  while (node != NULL)
    {
      struct slist_node *next = node->next;
      free (node);
      node = next;
    }

  free (list);
}

struct slist_node *
slist_add_first (struct slist *list, const void *data)
{
  struct slist_node *node;

  assert (list != NULL);

  node = (struct slist_node *) malloc (sizeof (struct slist_node));
  if (node == NULL)
    return NULL;

  node->data = data;
  node->next = list->head;
  list->head = node;

  return node;
}

struct slist_node *
slist_add_last (struct slist *list, const void *data)
{
  struct slist_node *node;
  struct slist_node *curr;

  assert (list != NULL);

  node = (struct slist_node *) malloc (sizeof (struct slist_node));
  if (node == NULL)
    return NULL;

  node->data = data;
  node->next = NULL;

  curr = list->head;
  if (curr == NULL)
    list->head = node;
  else
    {
      while (curr->next != NULL)
        curr = curr->next;
      curr->next = node;
    }

  return node;
}

bool
slist_remove_first (struct slist *list)
{
  struct slist_node *node;

  assert (list != NULL);

  node = list->head;
  if (node == NULL)
    return false;
  else
    {
      list->head = node->next;
      free (node);
      return true;
    }
}

bool
slist_remove_last (struct slist *list)
{
  struct slist_node *node;
  struct slist_node *prev;

  assert (list != NULL);

  node = list->head;
  if (node == NULL)
    return false;
  else
    {
      if (node->next == NULL)
        list->head = NULL;
      else
        {
          do
            {
              prev = node;
              node = node->next;
            }
          while (node->next != NULL);
          prev->next = NULL;
        }
      free (node);
      return true;
    }
}

void
slist_reverse (struct slist *list)
{
  struct slist_node *node;
  struct slist_node *prev;

  assert (list != NULL);

  node = list->head;
  prev = NULL;
  while (node != NULL)
    {
      struct slist_node *next = node->next;
      node->next = prev;
      prev = node;
      node = next;
    }

  list->head = prev;
}

struct slist_node *
slist_search (struct slist *list, const void *data)
{
  struct slist_node *node;

  assert (list != NULL);
  assert (list->equalfunc != NULL);

  for (node = list->head; node != NULL; node = node->next)
    {
      if (list->equalfunc (data, node->data))
        break;
    }

  return node;
}

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

#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "slist.h"
#include "test-help.h"

static struct slist *list = NULL;
static struct slist *reverse_list = NULL;

static const int input[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

static bool slist_int_equal (const void *aptr, const void *bptr);
static void setup_lists (void);
static void test_slist_loop_conditions (void);
static void test_slist_remove_first_last (void);
static void test_slist_reverse (void);
static void test_slist_search (void);

int
main (void)
{
  setup_lists ();
  test_slist_loop_conditions ();
  test_slist_remove_first_last ();
  test_slist_reverse ();
  test_slist_search ();

  if (list != NULL)
    slist_delete (list);
  if (reverse_list != NULL)
    slist_delete (reverse_list);
  return 0;
}

static bool
slist_int_equal (const void *aptr, const void *bptr)
{
  const int a = *(const int *) aptr;
  const int b = *(const int *) bptr;

  return a == b;
}

static void
setup_lists (void)
{
  size_t i;
  struct slist_node *node1;
  struct slist_node *node2;

  list = slist_new (slist_int_equal);
  ASSERT (list != NULL);

  reverse_list = slist_new (slist_int_equal);
  ASSERT (reverse_list != NULL);

  for (i = 0; i < ARRAY_SIZE (input); ++i)
    {
      ASSERT (slist_add_first (reverse_list, &input[i]) != NULL);
      ASSERT (slist_add_last (list, &input[i]) != NULL);
    }

  node1 = slist_first_node (list);
  node2 = slist_last_node (reverse_list);

  ASSERT (node1 != NULL);
  ASSERT (node2 != NULL);
  ASSERT (slist_node_data (node1) == &input[0]);
  ASSERT (slist_node_data (node2) == &input[0]);

  node1 = slist_last_node (list);
  node2 = slist_first_node (reverse_list);

  ASSERT (node1 != NULL);
  ASSERT (node2 != NULL);
  ASSERT (slist_node_data (node1) == &input[ARRAY_SIZE (input) - 1]);
  ASSERT (slist_node_data (node2) == &input[ARRAY_SIZE (input) - 1]);
}

static void
test_slist_loop_conditions (void)
{
  size_t i;
  struct slist_node *node1;
  struct slist_node *node2;

  node1 = slist_first_node (list);
  node2 = slist_last_node (reverse_list);

  for (i = 0; i < ARRAY_SIZE (input); ++i)
    {
      ASSERT (node1 != NULL);
      ASSERT (node2 != NULL);
      ASSERT (slist_node_data (node1) == &input[i]);
      ASSERT (slist_node_data (node2) == &input[i]);
      node1 = slist_next_node (list, node1);
      node2 = slist_previous_node (reverse_list, node2);
    }

  ASSERT (node1 == NULL);
  ASSERT (node2 == NULL);
}

static void
test_slist_remove_first_last (void)
{
  size_t i;

  while (slist_remove_first (list))
    ;
  ASSERT (slist_first_node (list) == NULL);
  ASSERT (slist_last_node (list) == NULL);

  while (slist_remove_first (reverse_list))
    ;
  ASSERT (slist_first_node (reverse_list) == NULL);
  ASSERT (slist_last_node (reverse_list) == NULL);

  for (i = 0; i < ARRAY_SIZE (input); ++i)
    {
      ASSERT (slist_add_first (reverse_list, &input[i]) != NULL);
      ASSERT (slist_add_last (list, &input[i]) != NULL);
    }
}

static void
test_slist_reverse (void)
{
  size_t i;
  struct slist_node *node1;
  struct slist_node *node2;

  slist_reverse (reverse_list);

  node1 = slist_first_node (list);
  node2 = slist_first_node (reverse_list);

  for (i = 0; i < ARRAY_SIZE (input); ++i)
    {
      ASSERT (node1 != NULL);
      ASSERT (node2 != NULL);
      ASSERT (slist_node_data (node1) == &input[i]);
      ASSERT (slist_node_data (node2) == &input[i]);
      node1 = slist_next_node (list, node1);
      node2 = slist_next_node (reverse_list, node2);
    }

  ASSERT (node1 == NULL);
  ASSERT (node2 == NULL);

  slist_reverse (reverse_list);
}

static void
test_slist_search (void)
{
  size_t i;
  int value;
  struct slist_node *node;

  for (i = 0; i < ARRAY_SIZE (input); ++i)
    {
      value = (int) i;
      node = slist_search (list, &value);
      ASSERT (node != NULL);
      ASSERT (*(const int *) slist_node_data (node) == value);
    }

  value = INT_MAX;
  node = slist_search (list, &value);
  ASSERT (node == NULL);
}

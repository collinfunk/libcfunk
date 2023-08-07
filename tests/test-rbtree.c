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

#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "rbtree.h"
#include "test-help.h"

static struct rbtree *tree = NULL;

static const char input[52]
    = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

static int rbtree_char_compare (const void *aptr, const void *bptr);
static void setup_tree (void);
static void test_rbtree_loop_conditions (void);
static void test_rbtree_remove_node (void);
static void test_rbtree_search (void);

int
main (void)
{
  setup_tree ();
  test_rbtree_loop_conditions ();
  test_rbtree_remove_node ();
  test_rbtree_search ();

  if (tree != NULL)
    rbtree_delete (tree);
  return 0;
}

static int
rbtree_char_compare (const void *aptr, const void *bptr)
{
  const char a = *(const char *) aptr;
  const char b = *(const char *) bptr;

  if (a == b)
    return 0;
  return a < b ? -1 : 1;
}

static void
setup_tree (void)
{
  size_t i;

  tree = rbtree_new (rbtree_char_compare);
  ASSERT (tree != NULL);

  for (i = 0; i < ARRAY_SIZE (input); ++i)
    ASSERT (rbtree_insert (tree, &input[i]) != NULL);
}

/* Test inorder traversal works as expected. */
static void
test_rbtree_loop_conditions (void)
{
  size_t i;
  struct rbtree_node *node1;
  struct rbtree_node *node2;

  node1 = rbtree_first_node (tree);
  node2 = rbtree_last_node (tree);

  for (i = 0; i < ARRAY_SIZE (input); ++i)
    {
      ASSERT (node1 != NULL);
      ASSERT (node2 != NULL);
      const char a = *(const char *) rbtree_node_data (node1);
      const char b = *(const char *) rbtree_node_data (node2);
      printf ("%c, %c\n", a, b);
      node1 = rbtree_next_node (tree, node1);
      node2 = rbtree_previous_node (tree, node2);
    }

  ASSERT (node1 == NULL);
  ASSERT (node2 == NULL);
}

static void
test_rbtree_remove_node (void)
{
  size_t i;
  struct rbtree_node *node;

  for (;;)
    {
      node = rbtree_root_node (tree);
      if (node == NULL)
        break;
      rbtree_remove_node (tree, node);
    }

  ASSERT (rbtree_first_node (tree) == NULL);
  ASSERT (rbtree_last_node (tree) == NULL);

  for (i = 0; i < ARRAY_SIZE (input); ++i)
    ASSERT (rbtree_insert (tree, &input[i]) != NULL);

  for (;;)
    {
      node = rbtree_first_node (tree);
      if (node == NULL)
        break;
      rbtree_remove_node (tree, node);
    }

  ASSERT (rbtree_root_node (tree) == NULL);
  ASSERT (rbtree_last_node (tree) == NULL);

  for (i = 0; i < ARRAY_SIZE (input); ++i)
    ASSERT (rbtree_insert (tree, &input[i]) != NULL);

  for (;;)
    {
      node = rbtree_last_node (tree);
      if (node == NULL)
        break;
      rbtree_remove_node (tree, node);
    }

  ASSERT (rbtree_first_node (tree) == NULL);
  ASSERT (rbtree_root_node (tree) == NULL);

  for (i = 0; i < ARRAY_SIZE (input); ++i)
    ASSERT (rbtree_insert (tree, &input[i]) != NULL);
}

static void
test_rbtree_search (void)
{
  size_t i;
  char value;
  struct rbtree_node *node;

  for (i = 0; i < ARRAY_SIZE (input); ++i)
    {
      value = input[i];
      node = rbtree_search (tree, &value);
      ASSERT (node != NULL);
      ASSERT (*(const char *) rbtree_node_data (node) == value);
    }

  value = '\0';
  node = rbtree_search (tree, &value);
  ASSERT (node == NULL);
}

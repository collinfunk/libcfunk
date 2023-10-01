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

#include "bstree.h"
#include "test-help.h"

static struct bstree *tree = NULL;

static const int input[10] = { 5, 2, 7, 3, 6, 0, 9, 1, 4, 8 };

static int bstree_int_compare (const void *aptr, const void *bptr);
static void setup_tree (void);
static void test_bstree_loop_conditions (void);
static void test_bstree_remove_node (void);
static void test_bstree_search (void);

int
main (void)
{
  setup_tree ();
  test_bstree_loop_conditions ();
  test_bstree_remove_node ();
  test_bstree_search ();

  if (tree != NULL)
    bstree_delete (tree);
  return 0;
}

static int
bstree_int_compare (const void *aptr, const void *bptr)
{
  const int a = *(const int *) aptr;
  const int b = *(const int *) bptr;

  if (a == b)
    return 0;
  return a < b ? -1 : 1;
}

static void
setup_tree (void)
{
  size_t i;
  struct bstree_node *node;

  tree = bstree_new (bstree_int_compare);
  ASSERT (tree != NULL);

  for (i = 0; i < ARRAY_SIZE (input); ++i)
    ASSERT (bstree_insert (tree, &input[i]) != NULL);

  node = bstree_root_node (tree);
  ASSERT (node != NULL);

  ASSERT (*(const int *) bstree_node_data (node) == 5);
  ASSERT (*(const int *) bstree_node_data (node->left) == 2);
  ASSERT (*(const int *) bstree_node_data (node->right) == 7);
  ASSERT (*(const int *) bstree_node_data (node->left->left) == 0);
  ASSERT (*(const int *) bstree_node_data (node->left->right) == 3);
  ASSERT (*(const int *) bstree_node_data (node->right->left) == 6);
  ASSERT (*(const int *) bstree_node_data (node->right->right) == 9);
  ASSERT (*(const int *) bstree_node_data (node->left->left->right) == 1);
  ASSERT (*(const int *) bstree_node_data (node->left->right->right) == 4);
  ASSERT (*(const int *) bstree_node_data (node->right->right->left) == 8);
}

/* Test inorder traversal works as expected. */
static void
test_bstree_loop_conditions (void)
{
  size_t i;
  struct bstree_node *node1;
  struct bstree_node *node2;

  node1 = bstree_first_node (tree);
  node2 = bstree_last_node (tree);

  for (i = 0; i < ARRAY_SIZE (input); ++i)
    {
      ASSERT (node1 != NULL);
      ASSERT (node2 != NULL);
      const int a = *(const int *) bstree_node_data (node1);
      const int b = *(const int *) bstree_node_data (node2);
      ASSERT (a == (int) i);
      ASSERT (b == (int) ARRAY_SIZE (input) - (int) i - 1);
      node1 = bstree_next_node (tree, node1);
      node2 = bstree_previous_node (tree, node2);
    }

  ASSERT (node1 == NULL);
  ASSERT (node2 == NULL);
}

static void
test_bstree_remove_node (void)
{
  size_t i;
  struct bstree_node *node;

  for (;;)
    {
      node = bstree_root_node (tree);
      if (node == NULL)
        break;
      bstree_remove_node (tree, node);
    }

  ASSERT (bstree_first_node (tree) == NULL);
  ASSERT (bstree_last_node (tree) == NULL);

  for (i = 0; i < ARRAY_SIZE (input); ++i)
    ASSERT (bstree_insert (tree, &input[i]) != NULL);

  for (;;)
    {
      node = bstree_first_node (tree);
      if (node == NULL)
        break;
      bstree_remove_node (tree, node);
    }

  ASSERT (bstree_root_node (tree) == NULL);
  ASSERT (bstree_last_node (tree) == NULL);

  for (i = 0; i < ARRAY_SIZE (input); ++i)
    ASSERT (bstree_insert (tree, &input[i]) != NULL);

  for (;;)
    {
      node = bstree_last_node (tree);
      if (node == NULL)
        break;
      bstree_remove_node (tree, node);
    }

  ASSERT (bstree_first_node (tree) == NULL);
  ASSERT (bstree_root_node (tree) == NULL);

  for (i = 0; i < ARRAY_SIZE (input); ++i)
    ASSERT (bstree_insert (tree, &input[i]) != NULL);
}

static void
test_bstree_search (void)
{
  size_t i;
  int value;
  struct bstree_node *node;

  for (i = 0; i < ARRAY_SIZE (input); ++i)
    {
      value = (int) i;
      node = bstree_search (tree, &value);
      ASSERT (node != NULL);
      ASSERT (*(const int *) bstree_node_data (node) == value);
    }

  value = INT_MAX;
  node = bstree_search (tree, &value);
  ASSERT (node == NULL);
}

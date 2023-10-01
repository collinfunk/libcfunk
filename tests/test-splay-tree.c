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

#include "splay-tree.h"
#include "test-help.h"

static struct splay_tree *tree = NULL;

static const int input[10] = { 5, 2, 7, 3, 6, 0, 9, 1, 4, 8 };

static int splay_tree_int_compare (const void *aptr, const void *bptr);
static void setup_tree (void);
static void test_splay_tree_loop_conditions (void);
static void test_splay_tree_remove_node (void);
static void test_splay_tree_search (void);

int
main (void)
{
  setup_tree ();
  test_splay_tree_loop_conditions ();
  test_splay_tree_remove_node ();
  test_splay_tree_search ();

  if (tree != NULL)
    splay_tree_delete (tree);
  return 0;
}

static int
splay_tree_int_compare (const void *aptr, const void *bptr)
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
  struct splay_tree_node *node;

  tree = splay_tree_new (splay_tree_int_compare);
  ASSERT (tree != NULL);

  for (i = 0; i < ARRAY_SIZE (input); ++i)
    {
      node = splay_tree_insert (tree, &input[i]);
      ASSERT (node != NULL);
      ASSERT (node == splay_tree_root_node (tree));
    }

  node = splay_tree_root_node (tree);
  ASSERT (node != NULL);

  ASSERT (*(const int *) splay_tree_node_data (node) == 8);
  ASSERT (*(const int *) splay_tree_node_data (node->right) == 9);
  ASSERT (node->right->right == NULL);
  ASSERT (node->right->left == NULL);

  node = node->left;
  ASSERT (*(const int *) splay_tree_node_data (node) == 7);
  ASSERT (node->right == NULL);

  node = node->left;
  ASSERT (*(const int *) splay_tree_node_data (node) == 4);
  ASSERT (*(const int *) splay_tree_node_data (node->right) == 5);
  ASSERT (*(const int *) splay_tree_node_data (node->right->right) == 6);
  ASSERT (node->right->left == NULL);
  ASSERT (node->right->right->left == NULL);
  ASSERT (node->right->right->right == NULL);

  node = node->left;
  ASSERT (*(const int *) splay_tree_node_data (node) == 3);
  ASSERT (node->right == NULL);

  node = node->left;
  ASSERT (*(const int *) splay_tree_node_data (node) == 1);
  ASSERT (*(const int *) splay_tree_node_data (node->left) == 0);
  ASSERT (*(const int *) splay_tree_node_data (node->right) == 2);

  ASSERT (node->left->left == NULL);
  ASSERT (node->left->right == NULL);
  ASSERT (node->right->left == NULL);
  ASSERT (node->left->right == NULL);
}

/* Test inorder traversal works as expected. */
static void
test_splay_tree_loop_conditions (void)
{
  size_t i;
  struct splay_tree_node *node1;
  struct splay_tree_node *node2;

  node1 = splay_tree_first_node (tree);
  ASSERT (node1 == splay_tree_root_node (tree));
  node2 = splay_tree_last_node (tree);
  ASSERT (node2 == splay_tree_root_node (tree));

  for (i = 0; i < ARRAY_SIZE (input); ++i)
    {
      ASSERT (node1 != NULL);
      ASSERT (node2 != NULL);
      const int a = *(const int *) splay_tree_node_data (node1);
      const int b = *(const int *) splay_tree_node_data (node2);
      ASSERT (a == (int) i);
      ASSERT (b == (int) ARRAY_SIZE (input) - (int) i - 1);
      node1 = splay_tree_next_node (tree, node1);
      node2 = splay_tree_previous_node (tree, node2);
    }

  ASSERT (node1 == NULL);
  ASSERT (node2 == NULL);
}

static void
test_splay_tree_remove_node (void)
{
  size_t i;
  struct splay_tree_node *node;

  for (;;)
    {
      node = splay_tree_root_node (tree);
      if (node == NULL)
        break;
      splay_tree_remove_node (tree, node);
    }

  ASSERT (splay_tree_first_node (tree) == NULL);
  ASSERT (splay_tree_last_node (tree) == NULL);

  for (i = 0; i < ARRAY_SIZE (input); ++i)
    ASSERT (splay_tree_insert (tree, &input[i]) != NULL);

  for (;;)
    {
      node = splay_tree_first_node (tree);
      ASSERT (node == splay_tree_root_node (tree));
      if (node == NULL)
        break;
      splay_tree_remove_node (tree, node);
    }

  ASSERT (splay_tree_root_node (tree) == NULL);
  ASSERT (splay_tree_last_node (tree) == NULL);

  for (i = 0; i < ARRAY_SIZE (input); ++i)
    ASSERT (splay_tree_insert (tree, &input[i]) != NULL);

  for (;;)
    {
      node = splay_tree_last_node (tree);
      ASSERT (node == splay_tree_root_node (tree));
      if (node == NULL)
        break;
      splay_tree_remove_node (tree, node);
    }

  ASSERT (splay_tree_first_node (tree) == NULL);
  ASSERT (splay_tree_root_node (tree) == NULL);

  for (i = 0; i < ARRAY_SIZE (input); ++i)
    ASSERT (splay_tree_insert (tree, &input[i]) != NULL);
}

static void
test_splay_tree_search (void)
{
  size_t i;
  int value;
  struct splay_tree_node *node;

  for (i = 0; i < ARRAY_SIZE (input); ++i)
    {
      value = (int) i;
      node = splay_tree_search (tree, &value);
      ASSERT (node == splay_tree_root_node (tree));
      ASSERT (node != NULL);
      ASSERT (*(const int *) splay_tree_node_data (node) == value);
    }

  value = INT_MAX;
  node = splay_tree_search (tree, &value);
  ASSERT (node == NULL);
}

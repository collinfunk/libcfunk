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

#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

#include "splay-tree.h"

/* Splay trees are a binary search tree where recently accessed elements are
   quick to access again. This is due to operations performing an extra step
   called "splaying." When we splay the tree at node N, the splay step
   continues until N is at the root of the tree. */

/* The top-down splay function. Does not require DATA to be in the tree.
   This function is based on the algorithm "simple top-down splay" on page
   669 of "Self-adjusting Binary Search Trees" by Daniel Dominic Sleator
   and Robert Endre Tarjan. */
static void
splay_tree_splay (struct splay_tree *tree, const void *data)
{
  struct splay_tree_node node;
  struct splay_tree_node *left;
  struct splay_tree_node *right;

  node.left = NULL;
  node.right = NULL;

  left = &node;
  right = &node;

  for (;;)
    {
      int result1 = tree->comparefunc (data, tree->root->data);
      int result2;

      if (result1 == 0)
        break;

      if (result1 < 0)
        {
          struct splay_tree_node *child = tree->root->left;

          if (child == NULL)
            break;

          result2 = tree->comparefunc (data, child->data);
          if (result2 < 0)
            {
              /* Rotate right. */
              tree->root->left = child->right;
              child->right = tree->root;
              tree->root = child;
              if (tree->root->left == NULL)
                break;
            }

          /* Link right. */
          right->left = tree->root;
          right = tree->root;
          tree->root = tree->root->left;
        }
      else /* result1 > 0 */
        {
          struct splay_tree_node *child = tree->root->right;

          if (child == NULL)
            break;

          result2 = tree->comparefunc (data, child->data);
          if (result2 > 0)
            {
              /* Rotate left. */
              tree->root->right = child->left;
              child->left = tree->root;
              tree->root = child;
              if (tree->root->right == NULL)
                break;
            }

          /* Link left. */
          left->right = tree->root;
          left = tree->root;
          tree->root = tree->root->right;
        }
    }

  /* Assemble. */
  left->right = tree->root->left;
  right->left = tree->root->right;
  tree->root->left = node.right;
  tree->root->right = node.left;
}

const void *
splay_tree_node_data (struct splay_tree_node *node)
{
  assert (node != NULL);

  return node->data;
}

struct splay_tree_node *
splay_tree_next_node (struct splay_tree *tree, struct splay_tree_node *node)
{
  assert (tree != NULL);
  assert (node != NULL);

  splay_tree_splay (tree, node->data);
  if (node->right == NULL)
    node = NULL;
  else
    {
      node = node->right;
      while (node->left != NULL)
        node = node->left;
    }

  return node;
}

struct splay_tree_node *
splay_tree_previous_node (struct splay_tree *tree,
                          struct splay_tree_node *node)
{
  assert (tree != NULL);
  assert (node != NULL);

  splay_tree_splay (tree, node->data);
  if (node->left == NULL)
    node = NULL;
  else
    {
      node = node->left;
      while (node->right != NULL)
        node = node->right;
    }

  return node;
}

struct splay_tree_node *
splay_tree_first_node (struct splay_tree *tree)
{
  struct splay_tree_node node;
  struct splay_tree_node *left;
  struct splay_tree_node *right;

  if (tree->root == NULL)
    return NULL;

  node.left = NULL;
  node.right = NULL;

  left = &node;
  right = &node;

  for (;;)
    {
      struct splay_tree_node *child = tree->root->left;

      if (child == NULL)
        break;

      /* Rotate right. */
      tree->root->left = child->right;
      child->right = tree->root;
      tree->root = child;
      if (tree->root->left == NULL)
        break;

      /* Link right. */
      right->left = tree->root;
      right = tree->root;
      tree->root = tree->root->left;
    }

  /* Assemble. */
  left->right = tree->root->left;
  right->left = tree->root->right;
  tree->root->left = node.right;
  tree->root->right = node.left;

  return tree->root;
}

struct splay_tree_node *
splay_tree_last_node (struct splay_tree *tree)
{
  struct splay_tree_node node;
  struct splay_tree_node *left;
  struct splay_tree_node *right;

  if (tree->root == NULL)
    return NULL;

  node.left = NULL;
  node.right = NULL;

  left = &node;
  right = &node;

  for (;;)
    {
      struct splay_tree_node *child = tree->root->right;

      if (child == NULL)
        break;

      /* Rotate left. */
      tree->root->right = child->left;
      child->left = tree->root;
      tree->root = child;
      if (tree->root->right == NULL)
        break;

      /* Link left. */
      left->right = tree->root;
      left = tree->root;
      tree->root = tree->root->right;
    }

  /* Assemble. */
  left->right = tree->root->left;
  right->left = tree->root->right;
  tree->root->left = node.right;
  tree->root->right = node.left;

  return tree->root;
}

struct splay_tree_node *
splay_tree_root_node (struct splay_tree *tree)
{
  assert (tree != NULL);

  return tree->root;
}

struct splay_tree *
splay_tree_new (int (*comparefunc) (const void *, const void *))
{
  struct splay_tree *tree;

  assert (comparefunc != NULL);

  tree = (struct splay_tree *) malloc (sizeof (struct splay_tree));
  if (tree == NULL)
    return NULL;

  tree->root = NULL;
  tree->comparefunc = comparefunc;

  return tree;
}

void
splay_tree_delete (struct splay_tree *tree)
{
  struct splay_tree_node *node;
  struct splay_tree_node *link;

  assert (tree != NULL);

  node = tree->root;
  link = NULL;

  while (node != NULL)
    {
      if (node->left != NULL)
        {
          struct splay_tree_node *child = node->left;

          /* Keep track of our way back up with the left pointer. */
          node->left = link;
          link = node;

          /* Continue down the tree. */
          node = child;
        }
      else if (node->right != NULL)
        {
          struct splay_tree_node *child = node->right;

          node->right = NULL;

          /* Keep track of our way back up with the left pointer. */
          node->left = link;
          link = node;

          /* Continue down the tree. */
          node = child;
        }
      else /* Node has no children. */
        {
          if (link == NULL)
            {
              free (node);
              break;
            }
          else /* Not back to the root. */
            {
              while (link != NULL)
                {
                  free (node);

                  if (link->right != NULL)
                    {
                      /* Check for right children. */
                      node = link->right;
                      link->right = NULL;
                      break;
                    }
                  else
                    {
                      /* Move back up with the left pointer. */
                      node = link;
                      link = link->left;
                    }
                }
            }
        }
    }

  free (tree);
}

struct splay_tree_node *
splay_tree_insert (struct splay_tree *tree, const void *data)
{
  struct splay_tree_node *node;

  assert (tree != NULL);
  assert (tree->comparefunc != NULL);

  node = (struct splay_tree_node *) malloc (sizeof (struct splay_tree_node));
  if (node == NULL)
    return NULL;

  node->data = data;

  if (tree->root == NULL)
    {
      node->left = NULL;
      node->right = NULL;
    }
  else
    {
      int result;

      splay_tree_splay (tree, data);

      result = tree->comparefunc (data, tree->root->data);
      /* Don't insert duplicates. */
      if (result == 0)
        {
          free (node);
          return tree->root;
        }

      if (result < 0)
        {
          node->left = tree->root->left;
          node->right = tree->root;
          tree->root->left = NULL;
        }
      else /* result > 0 */
        {
          node->right = tree->root->right;
          node->left = tree->root;
          tree->root->right = NULL;
        }
    }

  tree->root = node;
  return node;
}

void
splay_tree_remove_node (struct splay_tree *tree, struct splay_tree_node *node)
{
  int result;

  assert (tree != NULL);
  assert (node != NULL);

  if (tree->root == NULL)
    return;

  splay_tree_splay (tree, node->data);

  /* Make sure node is actually at the root before deleting it. */
  result = tree->comparefunc (node->data, tree->root->data);
  if (result == 0)
    {
      if (tree->root->left == NULL)
        tree->root = tree->root->right;
      else
        {
          struct splay_tree_node *temp = tree->root->right;
          tree->root = tree->root->left;
          splay_tree_splay (tree, node->data);
          tree->root->right = temp;
        }
      free (node);
    }
}

struct splay_tree_node *
splay_tree_search (struct splay_tree *tree, const void *data)
{
  assert (tree != NULL);

  if (tree->root == NULL)
    return NULL;

  splay_tree_splay (tree, data);
  return tree->comparefunc (data, tree->root->data) == 0 ? tree->root : NULL;
}

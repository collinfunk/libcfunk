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

#include <stddef.h>
#include <stdlib.h>
#include <assert.h>

#include "bstree.h"

/* TODO: Replace this with a iterative deletion function. */
static void
bstree_delete_subtree (struct bstree *tree, struct bstree_node *node)
{
  assert (tree != NULL);
  assert (node != NULL);

  /* Unused. */
  (void) tree;

  if (node->left != NULL)
    bstree_delete_subtree (tree, node->left);
  if (node->right != NULL)
    bstree_delete_subtree (tree, node->right);

  free (node);
}

const void *
bstree_node_data (struct bstree_node *node)
{
  assert (node != NULL);

  return node->data;
}

struct bstree_node *
bstree_next_node (struct bstree *tree, struct bstree_node *node)
{
  assert (tree != NULL);
  assert (node != NULL);

  /* Unused. */
  (void) tree;

  if (node->right != NULL)
    {
      node = node->right;
      while (node->left != NULL)
        node = node->left;
    }
  else
    {
      while (node->parent != NULL && node->parent->right == node)
        node = node->parent;
      node = node->parent;
    }

  return node;
}

struct bstree_node *
bstree_previous_node (struct bstree *tree, struct bstree_node *node)
{
  assert (tree != NULL);
  assert (node != NULL);

  /* Unused. */
  (void) tree;

  if (node->left != NULL)
    {
      node = node->left;
      while (node->right != NULL)
        node = node->right;
    }
  else
    {
      while (node->parent != NULL && node->parent->left == node)
        node = node->parent;
      node = node->parent;
    }

  return node;
}

struct bstree_node *
bstree_first_node (struct bstree *tree)
{
  struct bstree_node *node;

  assert (tree != NULL);

  node = tree->root;
  if (node != NULL)
    {
      while (node->left != NULL)
        node = node->left;
    }

  return node;
}

struct bstree_node *
bstree_last_node (struct bstree *tree)
{
  struct bstree_node *node;

  assert (tree != NULL);

  node = tree->root;
  if (node != NULL)
    {
      while (node->right != NULL)
        node = node->right;
    }

  return node;
}

struct bstree_node *
bstree_root_node (struct bstree *tree)
{
  assert (tree != NULL);

  return tree->root;
}

struct bstree *
bstree_new (int (*comparefunc) (const void *, const void *))
{
  struct bstree *tree;

  assert (comparefunc != NULL);

  tree = (struct bstree *) malloc (sizeof (struct bstree));
  if (tree == NULL)
    return NULL;

  tree->root = NULL;
  tree->comparefunc = comparefunc;

  return tree;
}

void
bstree_delete (struct bstree *tree)
{
  assert (tree != NULL);

  if (tree->root != NULL)
    bstree_delete_subtree (tree, tree->root);

  free (tree);
}

struct bstree_node *
bstree_insert (struct bstree *tree, const void *data)
{
  struct bstree_node *node;
  struct bstree_node *curr;
  struct bstree_node *parent;

  assert (tree != NULL);
  assert (tree->comparefunc != NULL);

  node = (struct bstree_node *) malloc (sizeof (struct bstree_node));
  if (node == NULL)
    return NULL;

  node->data = data;
  node->left = NULL;
  node->right = NULL;

  if (tree->root == NULL)
    {
      node->parent = NULL;
      tree->root = node;
    }
  else
    {
      int result;

      curr = tree->root;
      do
        {
          parent = curr;
          result = tree->comparefunc (data, curr->data);
          curr = (result < 0) ? curr->left : curr->right;
        }
      while (curr != NULL);

      node->parent = parent;
      if (result < 0)
        parent->left = node;
      else
        parent->right = node;
    }

  return node;
}

void
bstree_remove_node (struct bstree *tree, struct bstree_node *node)
{
  struct bstree_node *parent;

  assert (tree != NULL);
  assert (node != NULL);

  parent = node->parent;

  if (node->left == NULL)
    {
      struct bstree_node *child = node->right;

      if (parent == NULL)
        tree->root = child;
      else if (parent->left == node)
        parent->left = child;
      else if (parent->right == node)
        parent->right = child;
      else
        abort ();

      if (child != NULL)
        child->parent = parent;
    }
  else if (node->right == NULL)
    {
      struct bstree_node *child = node->left;

      if (parent == NULL)
        tree->root = child;
      else if (parent->left == node)
        parent->left = child;
      else if (parent->right == node)
        parent->right = child;
      else
        abort ();

      child->parent = parent;
    }
  else
    {
      struct bstree_node *prev = node->right;
      while (prev->left != NULL)
        prev = prev->left;

      if (prev->parent != node)
        {
          prev->parent->left = prev->right;

          if (prev->right != NULL)
            prev->right->parent = prev->parent;

          prev->right = node->right;
          prev->right->parent = prev;
        }

      if (parent == NULL)
        tree->root = prev;
      else if (parent->left == node)
        parent->left = prev;
      else if (parent->right == node)
        parent->right = prev;
      else
        abort ();

      prev->parent = parent;

      prev->left = node->left;
      prev->left->parent = prev;
    }

  free (node);
}

struct bstree_node *
bstree_search (struct bstree *tree, const void *data)
{
  struct bstree_node *node;

  assert (tree != NULL);
  assert (tree->comparefunc != NULL);

  node = tree->root;
  while (node != NULL)
    {
      int result = tree->comparefunc (data, node->data);
      if (result == 0)
        break;
      node = (result < 0) ? node->left : node->right;
    }

  return node;
}

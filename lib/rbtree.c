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

#include "rbtree.h"

/* Red-black trees are binary search trees that satisfy the following
   properties:
     1. Every node is either red or black.
     2. The root is always black.
     3. Every NULL node (leaf) is black.
     4. If a node is red then both of its children are black. Also written
        as "a red node does not have a red child."
     5. For each node, all paths leading to any of it's descendant NULL leaves
        contains the same number of black nodes.
     6. If NODE has one child, then NODE is black and the child is red. If this
        was not the case then the paths to it's NULL descendants would contain
        a different number of black nodes, violating rule 5.
 */

/* TODO: Replace this with a iterative deletion function. */
static void
rbtree_delete_subtree (struct rbtree *tree, struct rbtree_node *node)
{
  assert (tree != NULL);
  assert (node != NULL);

  /* Unused. */
  (void) tree;

  if (node->left != NULL)
    rbtree_delete_subtree (tree, node->left);
  if (node->right != NULL)
    rbtree_delete_subtree (tree, node->right);

  free (node);
}

/* Perform a left rotation on the subtree rooted by PARENT.

           P                      N
          / \                    / \
         S   N        ->        P   R
            / \                / \
           L   R              S   L
 */
static void
rbtree_rotate_left (struct rbtree *tree, struct rbtree_node *parent)
{
  struct rbtree_node *node;

  assert (tree != NULL);
  assert (parent != NULL);

  node = parent->right;
  parent->right = node->left;

  if (node->left != NULL)
    node->left->parent = parent;

  node->parent = parent->parent;

  if (parent->parent == NULL)
    tree->root = node;
  else if (parent->parent->left == parent)
    parent->parent->left = node;
  else if (parent->parent->right == parent)
    parent->parent->right = node;
  else
    abort ();

  node->left = parent;
  parent->parent = node;
}

/* Perform a right rotation on the subtree rooted by PARENT.

           P                      N
          / \                    / \
         N   S        ->        L   P
        / \                        / \
       L   R                      R   S
 */
static void
rbtree_rotate_right (struct rbtree *tree, struct rbtree_node *parent)
{
  struct rbtree_node *node;

  assert (tree != NULL);
  assert (parent != NULL);

  node = parent->left;
  parent->left = node->right;

  if (node->right != NULL)
    node->right->parent = parent;

  node->parent = parent->parent;

  if (parent->parent == NULL)
    tree->root = node;
  else if (parent->parent->left == parent)
    parent->parent->left = node;
  else if (parent->parent->right == parent)
    parent->parent->right = node;
  else
    abort ();

  node->right = parent;
  parent->parent = node;
}

static void
rbtree_insert_rebalance (struct rbtree *tree, struct rbtree_node *node,
                         struct rbtree_node *parent)
{
  assert (tree != NULL);
  assert (node != NULL);
  assert (parent != NULL);
  assert (node->parent == parent);

  while (parent != NULL && parent->color == RBTREE_RED)
    {
      struct rbtree_node *grandparent = parent->parent;

      if (grandparent->left == parent)
        {
          struct rbtree_node *uncle = grandparent->right;

          if (uncle != NULL && uncle->color == RBTREE_RED)
            {
              parent->color = RBTREE_BLACK;
              uncle->color = RBTREE_BLACK;
              grandparent->color = RBTREE_RED;
              node = grandparent;
            }
          else /* uncle == NULL || uncle->color == RBTREE_BLACK */
            {
              /* If NODE is the inner grandchild the following rotation and
                 swap is performed:

                         G              G             G
                        / \            / \           / \
                       P   U    ->    N   U    ->   P   U
                        \            /             /
                         N          P             N
               */
              if (parent->right == node)
                {
                  rbtree_rotate_left (tree, parent);
                  node = parent;
                  parent = grandparent->left;
                }
              /* The following rotation is performed and the nodes are
                 recolored:

                         G              P
                        / \            / \
                       P   U    ->    N   G
                      /                    \
                     N                      U
               */
              parent->color = RBTREE_BLACK;
              grandparent->color = RBTREE_RED;
              rbtree_rotate_right (tree, grandparent);
            }
        }
      else if (grandparent->right == parent)
        {
          struct rbtree_node *uncle = grandparent->left;

          if (uncle != NULL && uncle->color == RBTREE_RED)
            {
              parent->color = RBTREE_BLACK;
              uncle->color = RBTREE_BLACK;
              grandparent->color = RBTREE_RED;
              node = grandparent;
            }
          else /* uncle == NULL || uncle->color == RBTREE_BLACK */
            {
              /* If NODE is the inner grandchild the following rotation and
                 swap is performed:

                         G              G             G
                        / \            / \           / \
                       U   P    ->    U   N    ->   U   P
                          /                \             \
                         N                  P             N
               */
              if (parent->left == node)
                {
                  rbtree_rotate_right (tree, parent);
                  node = parent;
                  parent = grandparent->right;
                }
              /* The following rotation is performed and the nodes are
                 recolored:

                         G              P
                        / \            / \
                       U   P    ->    G   N
                            \        /
                             N      U
               */
              parent->color = RBTREE_BLACK;
              grandparent->color = RBTREE_RED;
              rbtree_rotate_left (tree, grandparent);
            }
        }
      else
        abort ();

      parent = node->parent;
    }

  /* Make sure root is always black. */
  tree->root->color = RBTREE_BLACK;
}

/* Called after the removal of a black node from the tree. PARENT is the
   parent of the deleted node. NODE is a child of the deleted node that
   replaces it. NODE is black (node == NULL || node->color == RBTREE_BLACK).
   As a result the sibling node will not be NULL. */
static void
rbtree_remove_rebalance (struct rbtree *tree, struct rbtree_node *node,
                         struct rbtree_node *parent)
{
  assert (tree != NULL);
  assert (node == NULL || node->color == RBTREE_BLACK);
  assert (parent != NULL);

  do
    {
      if (parent->left == node)
        {
          struct rbtree_node *sibling = parent->right;

          if (sibling->color == RBTREE_RED)
            {
              /* Sibling is red so it must have two non-NULL children which are
                 black. Convert it to the other cases which are differentiated
                 by the colors of the children.
                          P                S
                         / \              / \
                        N   S     ->     P  Sr
                           / \          / \
                          Sl Sr        N  Sl
               */
              sibling->color = RBTREE_BLACK;
              parent->color = RBTREE_RED;
              rbtree_rotate_left (tree, parent);
              /* Move sibling to be NODE's sibling (Sl on drawing). */
              sibling = parent->right;
            }
          /* Now sibling is black. */
          if ((sibling->left == NULL || sibling->left->color == RBTREE_BLACK)
              && (sibling->right == NULL
                  || sibling->right->color == RBTREE_BLACK))
            {
              /* Sibling and it's children are black. Recolor it and move up
                 a black level. */
              sibling->color = RBTREE_RED;
              node = parent;
            }
          else /* One child is red. */
            {
              if (sibling->right == NULL
                  || sibling->right->color == RBTREE_BLACK)
                {
                  /* Sibling's right child is black and it's left child is red.
                     We can swap their colors, rotate the subtree, and then
                     update the sibling pointer to transform this case into
                     the next case.

                         P               P
                        / \             / \
                       N   S    ->     N   Sl
                          / \               \
                         Sl Sr               S
                                              \
                                              Sr

                   */
                  sibling->left->color = RBTREE_BLACK;
                  sibling->color = RBTREE_RED;
                  rbtree_rotate_right (tree, sibling);
                  /* Update the sibling pointer so sibling is black and it's
                     right child is red. */
                  sibling = parent->right;
                  /* Fallthrough to the next case. */
                }
              /* Sibling's right child is red. Change it to black. Rotate the
                 subtree it is rooted by sibling with parent as it's left
                 child. Sibling takes parent's color and parent becomes
                 black. All paths passing through N now have an extra black
                 node.

                      P              S
                     / \            / \
                    N   S    ->    P   Sr
                       / \        / \
                      Sl Sr      N  Sl
               */
              sibling->color = parent->color;
              parent->color = RBTREE_BLACK;
              sibling->right->color = RBTREE_BLACK;
              rbtree_rotate_left (tree, parent);
              return;
            }
        }
      else if (parent->right == node)
        {
          struct rbtree_node *sibling = parent->left;

          if (sibling->color == RBTREE_RED)
            {
              /* Sibling is red so it must have two non-NULL children which are
                 black. Convert it to the other cases which are differentiated
                 by the colors of the children.
                          P                S
                         / \              / \
                        S   N     ->     Sl   P
                       / \                   / \
                      Sl Sr                 Sr  N
               */
              sibling->color = RBTREE_BLACK;
              parent->color = RBTREE_RED;
              rbtree_rotate_right (tree, parent);
              /* Move sibling to be NODE's sibling (Sr on drawing). */
              sibling = parent->left;
            }
          /* Now sibling is black. */
          if ((sibling->right == NULL || sibling->right->color == RBTREE_BLACK)
              && (sibling->left == NULL
                  || sibling->left->color == RBTREE_BLACK))
            {
              /* Sibling and it's children are black. Recolor it and move up
                 a black level. */
              sibling->color = RBTREE_RED;
              node = parent;
            }
          else /* One child is red. */
            {
              if (sibling->left == NULL
                  || sibling->left->color == RBTREE_BLACK)
                {
                  /* Sibling's left child is black and it's right child is red.
                     We can swap their colors, rotate the subtree, and then
                     update the sibling pointer to transform this case into
                     the next case.

                         P               P
                        / \             / \
                       S   N    ->    Sr   N
                      / \            /
                     Sl Sr          S
                                   /
                                  Sl
                   */
                  sibling->right->color = RBTREE_BLACK;
                  sibling->color = RBTREE_RED;
                  rbtree_rotate_left (tree, sibling);
                  /* Update the sibling pointer so sibling is black and it's
                     left child is red. */
                  sibling = parent->left;
                  /* Fallthrough to the next case. */
                }
              /* Sibling's left child is red. Change it to black. Rotate the
                 subtree it is rooted by sibling with parent as it's right
                 child. Sibling takes parent's color and parent becomes
                 black. All paths passing through N now have an extra black
                 node.

                      P              S
                     / \            / \
                    S   N    ->    Sl  P
                   / \                / \
                  Sl Sr              Sr  N
               */
              sibling->color = parent->color;
              parent->color = RBTREE_BLACK;
              sibling->left->color = RBTREE_BLACK;
              rbtree_rotate_right (tree, parent);
              return;
            }
        }
      else
        abort ();

      /* If node is red change it to black and exit the loop. */
      if (node != NULL && node->color == RBTREE_RED)
        {
          node->color = RBTREE_BLACK;
          return;
        }

      parent = node->parent;
    }
  while (parent != NULL);
}

const void *
rbtree_node_data (struct rbtree_node *node)
{
  assert (node != NULL);

  return node->data;
}

struct rbtree_node *
rbtree_next_node (struct rbtree *tree, struct rbtree_node *node)
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

struct rbtree_node *
rbtree_previous_node (struct rbtree *tree, struct rbtree_node *node)
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

struct rbtree_node *
rbtree_first_node (struct rbtree *tree)
{
  struct rbtree_node *node;

  assert (tree != NULL);

  node = tree->root;
  if (node != NULL)
    {
      while (node->left != NULL)
        node = node->left;
    }

  return node;
}

struct rbtree_node *
rbtree_last_node (struct rbtree *tree)
{
  struct rbtree_node *node;

  assert (tree != NULL);

  node = tree->root;
  if (node != NULL)
    {
      while (node->right != NULL)
        node = node->right;
    }

  return node;
}

struct rbtree_node *
rbtree_root_node (struct rbtree *tree)
{
  assert (tree != NULL);

  return tree->root;
}

struct rbtree *
rbtree_new (int (*comparefunc) (const void *, const void *))
{
  struct rbtree *tree;

  assert (comparefunc != NULL);

  tree = (struct rbtree *) malloc (sizeof (struct rbtree));
  if (tree == NULL)
    return NULL;

  tree->root = NULL;
  tree->comparefunc = comparefunc;

  return tree;
}

void
rbtree_delete (struct rbtree *tree)
{
  assert (tree != NULL);

  if (tree->root != NULL)
    rbtree_delete_subtree (tree, tree->root);

  free (tree);
}

struct rbtree_node *
rbtree_insert (struct rbtree *tree, const void *data)
{
  struct rbtree_node *node;
  struct rbtree_node *curr;
  struct rbtree_node *parent;

  assert (tree != NULL);
  assert (tree->comparefunc != NULL);

  node = (struct rbtree_node *) malloc (sizeof (struct rbtree_node));
  if (node == NULL)
    return NULL;

  node->data = data;
  node->left = NULL;
  node->right = NULL;

  if (tree->root == NULL)
    {
      /* Root node is always black. */
      node->color = RBTREE_BLACK;
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

      /* Rebalance the tree. */
      node->color = RBTREE_RED;
      rbtree_insert_rebalance (tree, node, parent);
    }

  return node;
}

void
rbtree_remove_node (struct rbtree *tree, struct rbtree_node *node)
{
  struct rbtree_node *parent;

  assert (tree != NULL);
  assert (node != NULL);

  parent = node->parent;

  if (node->left == NULL)
    {
      struct rbtree_node *child = node->right;

      if (parent == NULL)
        tree->root = child;
      else if (parent->left == node)
        parent->left = child;
      else if (parent->right == node)
        parent->right = child;
      else
        abort ();

      if (child != NULL)
        {
          /* Child has no sibling so it must be red. Just recolor it. */
          child->color = RBTREE_BLACK;
          child->parent = parent;
        }
      else /* child == NULL */
        {
          /* If the node we are removing is black and it is not the root node
             we have to rebalance the tree. */
          if (node->color == RBTREE_BLACK && parent != NULL)
            rbtree_remove_rebalance (tree, child, parent);
        }
    }
  else if (node->right == NULL)
    {
      struct rbtree_node *child = node->left;

      if (parent == NULL)
        tree->root = child;
      else if (parent->left == node)
        parent->left = child;
      else if (parent->right == node)
        parent->right = child;
      else
        abort ();

      /* Child has no sibling so it must be red. Just recolor it. */
      child->color = RBTREE_BLACK;
      child->parent = parent;
    }
  else
    {
      struct rbtree_node *prev = node->right;
      struct rbtree_node *prev_parent;
      struct rbtree_node *child;
      enum rbtree_color prev_color;

      /* Get the minimum of the right subtree. */
      while (prev->left != NULL)
        prev = prev->left;

      prev_parent = prev->parent;
      child = prev->right;
      prev_color = prev->color;

      if (prev_parent != node)
        {
          prev_parent->left = child;

          if (child != NULL)
            child->parent = prev_parent;

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

      prev->color = node->color;
      prev->parent = parent;

      prev->left = node->left;
      prev->left->parent = prev;

      /* If prev's original color was black we have check for violations
         of red-black properties. */
      if (prev_color == RBTREE_BLACK)
        {
          /* If child exists then it is an only child. If it is red we can
             just flip the color. */
          if (child != NULL && child->color == RBTREE_RED)
            child->color = RBTREE_BLACK;
          else /* child == NULL || child->color == RBTREE_BLACK */
            {
              /* Don't pass the node that we are removing to
                 rbtree_remove_rebalance (). */
              if (prev_parent == node)
                rbtree_remove_rebalance (tree, child, prev);
              else
                rbtree_remove_rebalance (tree, child, prev_parent);
            }
        }
    }

  free (node);
}

struct rbtree_node *
rbtree_search (struct rbtree *tree, const void *data)
{
  struct rbtree_node *node;

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

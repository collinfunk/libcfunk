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

#ifndef BSTREE_H
#define BSTREE_H

#include <stddef.h>

/* Basic binary search tree.
   Does not perform any self-balancing.
   The tree can be used similarly to a sorted list using
   bstree_first_node (), bstree_next_node (), bstree_previous_node (),
   and bstree_last_node () which follow inorder traversal. */

struct bstree_node
{
  const void *data;
  struct bstree_node *left;
  struct bstree_node *right;
  struct bstree_node *parent;
};

struct bstree
{
  struct bstree_node *root;
  int (*comparefunc) (const void *, const void *);
};

extern const void *bstree_node_data (struct bstree_node *node);
extern struct bstree_node *bstree_next_node (struct bstree *tree,
                                             struct bstree_node *node);
extern struct bstree_node *bstree_previous_node (struct bstree *tree,
                                                 struct bstree_node *node);
extern struct bstree_node *bstree_first_node (struct bstree *tree);
extern struct bstree_node *bstree_last_node (struct bstree *tree);
extern struct bstree_node *bstree_root_node (struct bstree *tree);
extern struct bstree *bstree_new (int (*comparefunc) (const void *,
                                                      const void *));
extern void bstree_delete (struct bstree *tree);
extern struct bstree_node *bstree_insert (struct bstree *tree,
                                          const void *data);
extern void bstree_remove_node (struct bstree *tree, struct bstree_node *node);
extern struct bstree_node *bstree_search (struct bstree *tree,
                                          const void *data);

#endif /* BSTREE_H */

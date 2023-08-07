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

#ifndef RBTREE_H
#define RBTREE_H

#include <stddef.h>

enum rbtree_color
{
  RBTREE_RED,
  RBTREE_BLACK
};

struct rbtree_node
{
  const void *data;
  enum rbtree_color color;
  struct rbtree_node *left;
  struct rbtree_node *right;
  struct rbtree_node *parent;
};

struct rbtree
{
  struct rbtree_node *root;
  int (*comparefunc) (const void *, const void *);
};

extern const void *rbtree_node_data (struct rbtree_node *node);
extern struct rbtree_node *rbtree_next_node (struct rbtree *tree,
                                             struct rbtree_node *node);
extern struct rbtree_node *rbtree_previous_node (struct rbtree *tree,
                                                 struct rbtree_node *node);
extern struct rbtree_node *rbtree_first_node (struct rbtree *tree);
extern struct rbtree_node *rbtree_last_node (struct rbtree *tree);
extern struct rbtree_node *rbtree_root_node (struct rbtree *tree);
extern struct rbtree *rbtree_new (int (*comparefunc) (const void *,
                                                      const void *));
extern void rbtree_delete (struct rbtree *tree);
extern struct rbtree_node *rbtree_insert (struct rbtree *tree,
                                          const void *data);
extern void rbtree_remove_node (struct rbtree *tree, struct rbtree_node *node);
extern struct rbtree_node *rbtree_search (struct rbtree *tree,
                                          const void *data);

#endif /* RBTREE_H */

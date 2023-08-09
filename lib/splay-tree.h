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

#ifndef SPLAY_TREE_H
#define SPLAY_TREE_H

#include <stddef.h>

struct splay_tree_node
{
  const void *data;
  struct splay_tree_node *left;
  struct splay_tree_node *right;
};

struct splay_tree
{
  struct splay_tree_node *root;
  int (*comparefunc) (const void *, const void *);
};

extern const void *splay_tree_node_data (struct splay_tree_node *node);
extern struct splay_tree_node *
splay_tree_next_node (struct splay_tree *tree, struct splay_tree_node *node);
extern struct splay_tree_node *
splay_tree_previous_node (struct splay_tree *tree,
                          struct splay_tree_node *node);
extern struct splay_tree_node *splay_tree_first_node (struct splay_tree *tree);
extern struct splay_tree_node *splay_tree_last_node (struct splay_tree *tree);
extern struct splay_tree_node *splay_tree_root_node (struct splay_tree *tree);
extern struct splay_tree *splay_tree_new (int (*comparefunc) (const void *,
                                                              const void *));
extern void splay_tree_delete (struct splay_tree *tree);
extern struct splay_tree_node *splay_tree_insert (struct splay_tree *tree,
                                                  const void *data);
extern void splay_tree_remove_node (struct splay_tree *tree,
                                    struct splay_tree_node *node);
extern struct splay_tree_node *splay_tree_search (struct splay_tree *tree,
                                                  const void *data);

#endif /* SPLAY_TREE_H */

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

#ifndef LIST_H
#define LIST_H

#include <stdbool.h>
#include <stddef.h>

struct list_node
{
  const void *data;
  struct list_node *next;
  struct list_node *prev;
};

struct list
{
  struct list_node *head;
  struct list_node *tail;
  bool (*equalfunc) (const void *, const void *);
};

extern const void *list_node_data (struct list_node *node);
extern struct list_node *list_next_node (struct list *list,
                                         struct list_node *node);
extern struct list_node *list_previous_node (struct list *list,
                                             struct list_node *node);
extern struct list_node *list_first_node (struct list *list);
extern struct list_node *list_last_node (struct list *list);
extern size_t list_count (struct list *list);
extern struct list *list_new (bool (*equalfunc) (const void *, const void *));
extern void list_delete (struct list *list);
extern struct list_node *list_add_first (struct list *list, const void *data);
extern struct list_node *list_add_last (struct list *list, const void *data);
extern bool list_remove_first (struct list *list);
extern bool list_remove_last (struct list *list);
extern void list_reverse (struct list *list);
extern struct list_node *list_search (struct list *list, const void *data);

#endif /* LIST_H */

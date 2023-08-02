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

#ifndef SLIST_H
#define SLIST_H

#include <stddef.h>
#include <stdbool.h>

struct slist_node
{
  const void *data;
  struct slist_node *next;
};

struct slist
{
  struct slist_node *head;
  bool (*equalfunc) (const void *, const void *);
};

extern const void *slist_node_data (struct slist_node *node);
extern struct slist_node *slist_next_node (struct slist *list,
                                           struct slist_node *node);
extern struct slist_node *slist_previous_node (struct slist *list,
                                               struct slist_node *node);
extern struct slist_node *slist_first_node (struct slist *list);
extern struct slist_node *slist_last_node (struct slist *list);
extern size_t slist_count (struct slist *list);
extern struct slist *slist_new (bool (*equalfunc) (const void *,
                                                   const void *));
extern void slist_delete (struct slist *list);
extern struct slist_node *slist_add_first (struct slist *list,
                                           const void *data);
extern struct slist_node *slist_add_last (struct slist *list,
                                          const void *data);
extern bool slist_remove_first (struct slist *list);
extern bool slist_remove_last (struct slist *list);
extern void slist_reverse (struct slist *list);
extern struct slist_node *slist_search (struct slist *list, const void *data);

#endif /* SLIST_H */

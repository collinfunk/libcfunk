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

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

#include "list.h"

const void *
list_node_data (struct list_node *node)
{
  return node->data;
}

struct list_node *
list_next_node (struct list *list, struct list_node *node)
{
  assert (list != NULL);
  assert (node != NULL);

  /* Unused. */
  (void) list;

  return node->next;
}

struct list_node *
list_previous_node (struct list *list, struct list_node *node)
{
  assert (list != NULL);
  assert (node != NULL);

  /* Unused. */
  (void) list;

  return node->prev;
}

struct list_node *
list_first_node (struct list *list)
{
  assert (list != NULL);

  return list->head;
}

struct list_node *
list_last_node (struct list *list)
{
  assert (list != NULL);

  return list->tail;
}

size_t
list_count (struct list *list)
{
  struct list_node *node;
  size_t count;

  assert (list != NULL);

  node = list->head;
  count = 0;
  while (node != NULL)
    {
      node = node->next;
      count++;
    }

  return count;
}

struct list *
list_new (bool (*equalfunc) (const void *, const void *))
{
  struct list *list;

  list = (struct list *) malloc (sizeof (struct list));
  if (list == NULL)
    return NULL;

  list->head = NULL;
  list->tail = NULL;
  list->equalfunc = equalfunc;

  return list;
}

void
list_delete (struct list *list)
{
  struct list_node *node;

  assert (list != NULL);

  node = list->head;
  while (node != NULL)
    {
      struct list_node *next = node->next;
      free (node);
      node = next;
    }

  free (list);
}

struct list_node *
list_add_first (struct list *list, const void *data)
{
  struct list_node *node;

  assert (list != NULL);

  node = (struct list_node *) malloc (sizeof (struct list_node));
  if (node == NULL)
    return NULL;

  node->data = data;
  node->next = list->head;
  node->prev = NULL;
  list->head = node;

  if (node->next != NULL)
    node->next->prev = node;
  else
    list->tail = node;

  return node;
}

struct list_node *
list_add_last (struct list *list, const void *data)
{
  struct list_node *node;

  assert (list != NULL);

  node = (struct list_node *) malloc (sizeof (struct list_node));
  if (node == NULL)
    return NULL;

  node->data = data;
  node->next = NULL;
  node->prev = list->tail;
  list->tail = node;

  if (node->prev != NULL)
    node->prev->next = node;
  else
    list->head = node;

  return node;
}

bool
list_remove_first (struct list *list)
{
  struct list_node *node;

  assert (list != NULL);

  node = list->head;
  if (node == NULL)
    return false;
  else
    {
      list->head = node->next;
      if (node->next != NULL)
        node->next->prev = NULL;
      else
        list->tail = NULL;
      free (node);
      return true;
    }
}

bool
list_remove_last (struct list *list)
{
  struct list_node *node;

  assert (list != NULL);

  node = list->tail;
  if (node == NULL)
    return false;
  else
    {
      list->tail = node->prev;
      if (node->prev != NULL)
        node->prev->next = NULL;
      else
        list->head = NULL;
      free (node);
      return true;
    }
}

void
list_reverse (struct list *list)
{
  struct list_node *node;
  struct list_node *tail;

  assert (list != NULL);

  node = list->head;
  tail = NULL;
  while (node != NULL)
    {
      tail = node;
      node = node->next;
      tail->next = tail->prev;
      tail->prev = node;
    }

  list->tail = list->head;
  list->head = tail;
}

struct list_node *
list_search (struct list *list, const void *data)
{
  struct list_node *node;

  assert (list != NULL);
  assert (list->equalfunc != NULL);

  for (node = list->head; node != NULL; node = node->next)
    {
      if (list->equalfunc (data, node->data))
        break;
    }

  return node;
}

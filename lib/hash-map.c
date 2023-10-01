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
#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#include "hash-map.h"

/* Check if a number is prime.
   Should be fast enough for any realistic table size. */
static bool
is_prime (size_t value)
{
  size_t i;

  if (value == 0 || value == 1)
    return false;
  if (value == 2 || value == 3)
    return true;
  if ((value % 2) == 0 || (value % 3) == 0)
    return false;

  for (i = 5; i * i <= value; i += 6)
    {
      if ((value % i) == 0 || (value % (i + 2)) == 0)
        return false;
    }

  return true;
}

/* Expand the hash table in MAP to have NEW_COUNT buckets. */
static void
hash_map_expand (struct hash_map *map, size_t new_count)
{
  size_t i;
  struct hash_map_node **new_table;

  assert (map != NULL);
  assert (new_count > map->bucket_count);

  /* Check for overflow of size_t and attempt to allocate a new table. If it
     fails we continue using the existing table. */
  if (new_count > SIZE_MAX / sizeof (struct hash_map_node *))
    return;
  new_table = (struct hash_map_node **) calloc (
      new_count, sizeof (struct hash_map_node *));
  if (new_table == NULL)
    return;

  /* For each bucket in the old table. */
  for (i = 0; i < map->bucket_count; ++i)
    {
      struct hash_map_node *node = map->table[i];

      /* For each node in the chain. */
      while (node != NULL)
        {
          struct hash_map_node *next = node->next;
          size_t bucket = node->hash % new_count;

          /* Insert the node into the new table. */
          node->next = new_table[bucket];
          new_table[bucket] = node;
          node = next;
        }
    }

  /* Free the old table and set the values in MAP. */
  free (map->table);
  map->table = new_table;
  map->bucket_count = new_count;
}

/* For a hash-map with N entries, we have < (2 * N) buckets to reduce
   collisions. There is probably a better ratio to do this but it is easy
   to calculate :). */
static void
hash_map_expand_maybe (struct hash_map *map)
{
  /* Make sure new count is odd. */
  size_t new_count = (map->count * 2) + 1;

  /* Check if we should expand the table. */
  if (new_count > map->bucket_count)
    {
      /* Get the next prime number. */
      while (new_count < SIZE_MAX - 2)
        {
          if (is_prime (new_count))
            break;
          else
            new_count += 2;
        }
      hash_map_expand (map, new_count);
    }
}

struct hash_map *
hash_map_new (size_t (*hashfunc) (const void *),
              bool (*equalfunc) (const void *, const void *))
{
  struct hash_map *map;

  assert (hashfunc != NULL);
  assert (equalfunc != NULL);

  map = (struct hash_map *) malloc (sizeof (struct hash_map));
  if (map == NULL)
    return NULL;

  map->bucket_count = 11;
  map->table = (struct hash_map_node **) calloc (
      map->bucket_count, sizeof (struct hash_map_node *));
  if (map->table == NULL)
    {
      free (map);
      return NULL;
    }
  map->count = 0;
  map->hashfunc = hashfunc;
  map->equalfunc = equalfunc;

  return map;
}

void
hash_map_delete (struct hash_map *map)
{
  size_t i;

  assert (map != NULL);
  assert (map->table != NULL);

  for (i = 0; i < map->bucket_count; ++i)
    {
      struct hash_map_node *node = map->table[i];

      while (node != NULL)
        {
          struct hash_map_node *next = node->next;
          free (node);
          node = next;
        }
    }

  free (map->table);
  free (map);
}

struct hash_map_node *
hash_map_put (struct hash_map *map, const void *key, const void *value)
{
  struct hash_map_node *node;
  struct hash_map_node *curr;
  size_t hash;
  size_t bucket;

  assert (map != NULL);

  hash = map->hashfunc (key);
  bucket = hash % map->bucket_count;

  /* Search for the key in the chain. */
  curr = map->table[bucket];
  while (curr != NULL)
    {
      /* If we find the key in the map, replace its value. */
      if (curr->hash == hash && map->equalfunc (key, curr->key))
        {
          curr->value = value;
          return curr;
        }
      curr = curr->next;
    }

  /* Allocate a new node if the key was not in the table. */
  node = (struct hash_map_node *) malloc (sizeof (struct hash_map_node));
  if (node == NULL)
    return NULL;

  node->key = key;
  node->value = value;
  node->hash = hash;

  /* Insert it at the front of the chain. */
  node->next = map->table[bucket];
  map->table[bucket] = node;

  /* Check if we should expand to reduce the chances of collisions. */
  map->count++;
  hash_map_expand_maybe (map);

  return node;
}

const void *
hash_map_get (struct hash_map *map, const void *key)
{
  struct hash_map_node *node;
  size_t hash;
  size_t bucket;

  assert (map != NULL);

  hash = map->hashfunc (key);
  bucket = hash % map->bucket_count;

  /* Search for the key in the chain. */
  node = map->table[bucket];
  while (node != NULL)
    {
      /* If we find the key, return its associated value. */
      if (node->hash == hash && map->equalfunc (key, node->key))
        return node->value;
      node = node->next;
    }

  return NULL;
}

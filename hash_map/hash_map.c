#include "hash_map.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hash_map *hash_map_init(size_t size)
{
    struct hash_map *res = malloc(sizeof(struct hash_map));
    res->data = calloc(sizeof(struct pair_list), size);
    res->size = size;

    return res;
}

bool hash_map_insert(struct hash_map *hash_map, const char *key, char *value,
                     bool *updated)
{
    if (!hash_map || hash_map->size == 0)
        return false;

    size_t h = hash(key) % hash_map->size;
    struct pair_list *tmp = hash_map->data[h];
    if (updated)
        *updated = false;

    while (tmp)
    {
        if (!strcmp(key, tmp->key))
        {
            tmp->value = value;
            if (updated)
                *updated = true;
            return true;
        }
        tmp = tmp->next;
    }

    struct pair_list *elt = calloc(1, sizeof(struct pair_list));
    elt->key = key;
    elt->value = value;

    if (hash_map->data[h])
        elt->next = hash_map->data[h];

    hash_map->data[h] = elt;

    return true;
}

void hash_map_free(struct hash_map *hash_map)
{
    if (hash_map)
    {
        for (size_t i = 0; i < hash_map->size; i++)
        {
            while (hash_map->data[i])
            {
                struct pair_list *tmp = hash_map->data[i]->next;
                free(hash_map->data[i]);
                hash_map->data[i] = tmp;
            }
        }
        free(hash_map->data);
        free(hash_map);
    }
}

void hash_map_dump(struct hash_map *hash_map)
{
    for (size_t i = 0; i < hash_map->size; i++)
    {
        struct pair_list *tmp = hash_map->data[i];
        while (tmp)
        {
            printf("%s: %s", tmp->key, tmp->value);
            if (tmp->next)
                printf(", ");
            tmp = tmp->next;
        }
        if (hash_map->data[i])
            printf("\n");
    }
}

const char *hash_map_get(const struct hash_map *hash_map, const char *key)
{
    if (!hash_map || !key || hash_map->size == 0)
        return NULL;

    size_t h = hash(key) % hash_map->size;
    struct pair_list *tmp = hash_map->data[h];
    while (tmp)
    {
        if (!strcmp(key, tmp->key))
            return tmp->value;

        tmp = tmp->next;
    }
    return NULL;
}

bool hash_map_remove(struct hash_map *hash_map, const char *key)
{
    if (!hash_map || !key || hash_map->size == 0)
        return false;

    size_t h = hash(key) % hash_map->size;
    struct pair_list *prev = NULL;
    struct pair_list *tmp = hash_map->data[h];

    while (tmp)
    {
        if (!strcmp(tmp->key, key))
        {
            if (prev)
            {
                prev->next = tmp->next;
                free(tmp);
                return true;
            }
            else
            {
                hash_map->data[h] = tmp->next;
                free(tmp);
                return true;
            }
        }
        prev = tmp;
        tmp = tmp->next;
    }
    return false;
}

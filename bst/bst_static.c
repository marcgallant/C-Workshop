#include "bst_static.h"

#include <stdio.h>
#include <stdlib.h>

struct bst *init(size_t capacity)
{
    struct bst *res = calloc(1, sizeof(struct bst));

    res->capacity = capacity;
    res->data = calloc(capacity, sizeof(struct value *));

    return res;
}

void add_rec(struct bst *tree, int value, size_t i)
{
    if (i < tree->capacity && tree->data[i])
    {
        if (tree->data[i]->val > value)
            add_rec(tree, value, 2 * i + 1);
        else
            add_rec(tree, value, 2 * i + 2);
    }
    else
    {
        if (i > tree->capacity)
        {
            size_t tmp = tree->capacity;
            tree->capacity = tree->capacity * 2 + 2;
            tree->data =
                realloc(tree->data, sizeof(struct value *) * tree->capacity);

            for (size_t j = tmp; j < tree->capacity; j++)
            {
                tree->data[j] = NULL;
            }
        }

        struct value *elt = malloc(sizeof(struct value));
        elt->val = value;
        tree->data[i] = elt;
    }
}

void add(struct bst *tree, int value)
{
    tree->size++;
    add_rec(tree, value, 0);
}

int search_rec(struct bst *tree, int value, size_t i)
{
    if (i >= tree->capacity || !tree->data[i])
        return -1;

    if (tree->data[i]->val == value)
        return i;
    else if (tree->data[i]->val > value)
        return search_rec(tree, value, 2 * i + 1);
    else
        return search_rec(tree, value, 2 * i + 2);
}

int search(struct bst *tree, int value)
{
    return search_rec(tree, value, 0);
}

void bst_free(struct bst *tree)
{
    for (size_t i = 0; i < tree->capacity; i++)
    {
        free(tree->data[i]);
    }

    free(tree->data);
    free(tree);
}

#include "bst.h"

#include <stdio.h>
#include <stdlib.h>

struct bst_node *create_node(int value)
{
    struct bst_node *res = calloc(1, sizeof(struct bst_node));
    res->data = value;

    return res;
}

struct bst_node *add_node(struct bst_node *tree, int value)
{
    if (!tree)
        return create_node(value);

    if (tree->data > value)
        tree->left = add_node(tree->left, value);
    else
        tree->right = add_node(tree->right, value);

    return tree;
}

struct bst_node *maximum(struct bst_node *tree)
{
    struct bst_node *tmp = tree;
    while (tmp->right)
    {
        tmp = tmp->right;
    }
    return tmp;
}

struct bst_node *delete_node(struct bst_node *tree, int value)
{
    if (!tree)
        return NULL;

    if (tree->data > value)
        tree->left = delete_node(tree->left, value);
    else if (tree->data < value)
        tree->right = delete_node(tree->right, value);
    else
    {
        if (tree->left)
        {
            if (tree->right)
            {
                struct bst_node *tmp = maximum(tree->left);
                tree->data = tmp->data;
                tree->left = delete_node(tree->left, tmp->data);
                return tree;
            }
            else
            {
                struct bst_node *tmp = tree->left;
                free(tree);
                return tmp;
            }
        }
        else
        {
            if (tree->right)
            {
                struct bst_node *tmp = tree->right;
                free(tree);
                return tmp;
            }
            else
            {
                free(tree);
                return NULL;
            }
        }
    }

    return tree;
}

const struct bst_node *find(const struct bst_node *tree, int value)
{
    if (!tree)
        return NULL;

    if (tree->data == value)
        return tree;
    else if (tree->data > value)
        return find(tree->left, value);
    else
        return find(tree->right, value);
}

void free_bst(struct bst_node *tree)
{
    if (tree)
    {
        free_bst(tree->left);
        free_bst(tree->right);
        free(tree);
    }
}

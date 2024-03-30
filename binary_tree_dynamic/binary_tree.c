#include "binary_tree.h"

#include <stdio.h>

#include "queue.h"

int size(const struct binary_tree *tree)
{
    return tree ? 1 + size(tree->left) + size(tree->right) : 0;
}

static int max(int a, int b)
{
    return a > b ? a : b;
}

int height(const struct binary_tree *tree)
{
    return tree ? 1 + max(height(tree->left), height(tree->right)) : -1;
}

void dfs_print_prefix(const struct binary_tree *tree)
{
    if (tree)
    {
        printf("%d ", tree->data);
        dfs_print_prefix(tree->left);
        dfs_print_prefix(tree->right);
    }
}

void dfs_print_infix(const struct binary_tree *tree)
{
    if (tree)
    {
        dfs_print_infix(tree->left);
        printf("%d ", tree->data);
        dfs_print_infix(tree->right);
    }
}

void dfs_print_postfix(const struct binary_tree *tree)
{
    if (tree)
    {
        dfs_print_postfix(tree->left);
        dfs_print_postfix(tree->right);
        printf("%d ", tree->data);
    }
}

static int is_perfect_rec(const struct binary_tree *tree)
{
    if (!tree)
        return 1;

    if (!tree->left)
        return !tree->right;

    if (!tree->right)
        return 0;

    int a = is_perfect_rec(tree->left);
    if (!a)
        return 0;

    int b = is_perfect_rec(tree->right);
    if (!b || a != b)
        return 0;

    return b + 1;
}

int is_perfect(const struct binary_tree *tree)
{
    if (is_perfect_rec(tree))
        return 1;

    return 0;
}

int is_complete(const struct binary_tree *tree)
{
    if (tree)
    {
        struct queue *queue = queue_init();
        queue_push(queue, tree);

        int flag = 0;
        while (queue->size != 0)
        {
            const struct binary_tree *elt = queue_pop(queue);

            if (!elt->left)
            {
                if (flag)
                {
                    queue_destroy(queue);
                    return 0;
                }
                queue_push(queue, elt->left);
            } else
                flag = 1;

            if (elt->right)
            {
                if (flag)
                {
                    queue_destroy(queue);
                    return 0;
                }
                queue_push(queue, elt->right);
            } else
                flag = 1;
        }

        queue_destroy(queue);
    }
    return 1;
}

int is_degenerate(const struct binary_tree *tree)
{
    if (!tree)
        return 1;

    if (tree->left && tree->right)
        return 0;

    return is_degenerate(tree->left) && is_degenerate(tree->right);
}

int is_full(const struct binary_tree *tree)
{
    if (!tree)
        return 1;

    if (!tree->left)
        return !tree->right;

    if (!tree->right)
        return 0;

    return is_full(tree->left) && is_full(tree->right);
}

int is_bst(const struct binary_tree *tree)
{
    if (!tree)
        return 1;

    struct binary_tree *max = tree->left;
    if (max)
    {
        while (max->right)
        {
            max = max->right;
        }
    }

    struct binary_tree *min = tree->right;
    if (min)
    {
        while (min->left)
        {
            min = min->left;
        }
    }

    if ((max && max->data > tree->data) || (min && min->data < tree->data))
        return 0;

    return is_bst(tree->left) && is_bst(tree->right);
}

#ifndef LIST_H
#define LIST_H

#include "binary_tree.h"

struct list
{
    const struct binary_tree *data;
    struct list *next;
};

#endif /* ! LIST_H */

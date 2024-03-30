#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

struct dlist *dlist_init(void)
{
    struct dlist *res = calloc(1, sizeof(struct dlist));
    return res;
}

int dlist_push_front(struct dlist *list, int element)
{
    if (element < 0)
        return 0;

    struct dlist_item *tmp = calloc(1, sizeof(struct dlist_item));
    tmp->data = element;
    tmp->next = list->head;

    if (list->size == 0)
    {
        list->tail = tmp;
    }
    else
    {
        list->head->prev = tmp;
    }

    list->head = tmp;
    list->size++;
    return 1;
}

void dlist_print(const struct dlist *list)
{
    if (list)
    {
        struct dlist_item *tmp = list->head;
        while (tmp)
        {
            printf("%d\n", tmp->data);
            tmp = tmp->next;
        }
    }
}

int dlist_push_back(struct dlist *list, int element)
{
    if (element < 0)
        return 0;

    struct dlist_item *tmp = calloc(1, sizeof(struct dlist_item));
    tmp->data = element;
    tmp->prev = list->tail;

    if (list->size == 0)
    {
        list->head = tmp;
    }
    else
    {
        list->tail->next = tmp;
    }

    list->tail = tmp;
    list->size++;
    return 1;
}

size_t dlist_size(const struct dlist *list)
{
    return list->size;
}

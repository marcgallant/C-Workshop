#include "dlist.h"

void dlist_map_square(struct dlist *list)
{
    struct dlist_item *tmp = list->head;
    while (tmp)
    {
        tmp->data *= tmp->data;
        tmp = tmp->next;
    }
}

void dlist_reverse(struct dlist *list)
{
    struct dlist_item *tmp = NULL;
    struct dlist_item *cur = list->head;

    while (cur)
    {
        tmp = cur->prev;
        cur->prev = cur->next;
        cur->next = tmp;
        cur = cur->prev;
    }

    tmp = list->head;
    list->head = list->tail;
    list->tail = tmp;
}

struct dlist *dlist_split_at(struct dlist *list, size_t index)
{
    if (!list)
        return dlist_init();

    if (index == 0)
    {
        struct dlist *res = dlist_init();
        res->head = list->head;
        res->tail = list->tail;
        res->size = list->size;
        list->head = NULL;
        list->tail = NULL;
        list->size = 0;

        return res;
    }
    else if (index < list->size)
    {
        size_t i = 0;
        struct dlist *res = dlist_init();
        res->tail = list->tail;
        struct dlist_item *last = list->head;

        while (i < index - 1 && last)
        {
            last = last->next;
            i++;
        }

        struct dlist_item *first = last->next;
        res->head = first;
        first->prev = NULL;

        list->tail = last;
        last->next = NULL;
        res->size = list->size - index;
        list->size = index;
        return res;
    }

    return NULL;
}

void dlist_concat(struct dlist *list1, struct dlist *list2)
{
    if (list1->head && list2->tail)
    {
        list2->head->prev = list1->tail;
        list1->tail->next = list2->head;

        list1->size += list2->size;
        list1->tail = list2->tail;
    }

    list2->size = 0;
    list2->tail = NULL;
    list2->head = NULL;
}

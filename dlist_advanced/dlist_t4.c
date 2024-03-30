#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

void dlist_shift(struct dlist *list, int offset)
{
    if (list && list->head && list->tail && list->size)
    {
        int n = list->size;
        offset = (offset % n + n) % n;

        list->head->prev = list->tail;
        list->tail->next = list->head;

        for (int i = 0; i < offset; i++)
        {
            list->head = list->head->prev;
            list->tail = list->tail->prev;
        }

        list->head->prev = NULL;
        list->tail->next = NULL;
    }
}

int dlist_add_sort(struct dlist *list, int element)
{
    if (!list || element < 0)
        return -1;

    struct dlist_item *tmp = list->head;
    size_t i = 0;

    while (tmp && tmp->data < element)
    {
        tmp = tmp->next;
        i++;
    }

    if (i == list->size)
        return dlist_push_back(list, element) == 0 ? -1 : 1;

    struct dlist_item *elt = malloc(sizeof(struct dlist_item));
    elt->data = element;
    elt->next = tmp;
    elt->prev = tmp->prev;

    if (i == 0)
        list->head = elt;

    if (tmp->prev)
    {
        tmp->prev->next = elt;
    }
    tmp->prev = elt;
    list->size++;

    return 1;
}

int dlist_remove_eq(struct dlist *list, int element)
{
    if (!list || element < 0)
        return 0;

    struct dlist_item *tmp = list->head;
    size_t i = 0;
    while (tmp && tmp->data != element)
    {
        tmp = tmp->next;
        i++;
    }

    if (!tmp)
        return 0;

    if (tmp->prev)
        tmp->prev->next = tmp->next;
    if (tmp->next)
        tmp->next->prev = tmp->prev;

    if (i == 0)
        list->head = list->head->next;
    else if (i == list->size - 1)
        list->tail = list->tail->prev;

    free(tmp);
    list->size--;

    return 1;
}

struct dlist *dlist_copy(const struct dlist *list)
{
    if (!list)
        return NULL;

    struct dlist *res = dlist_init();
    struct dlist_item *head = list->head;
    while (head)
    {
        struct dlist_item *tmp = malloc(sizeof(struct dlist_item));
        if (!tmp)
            return 0;

        tmp->data = head->data;
        tmp->next = NULL;
        tmp->prev = res->tail;

        if (res->size == 0)
            res->head = tmp;
        else
            res->tail->next = tmp;

        res->tail = tmp;
        res->size++;

        head = head->next;
    }
    return res;
}

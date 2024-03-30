#include <stdlib.h>

#include "dlist.h"

struct dlist_item* dlist_get_item(const struct dlist *list, size_t index)
{
    if (index >= list->size)
        return NULL;

    struct dlist_item *tmp = list->head;
    size_t i = 0;
    while (i < index)
    {
        tmp = tmp->next;
        i++;
    }
    return tmp;
}

int dlist_get(const struct dlist *list, size_t index)
{
    struct dlist_item *res = dlist_get_item(list, index);
    if (!res)
        return -1;

    return res->data;
}

int dlist_insert_at(struct dlist *list, int element, size_t index)
{
    if (element < 0)
        return -1;

    struct dlist_item *tmp = dlist_get_item(list, index);
    if (!tmp)
    {
        if (index == list->size)
            return dlist_push_back(list, element) == 0 ? -1 : 1;

        return -1;
    }

    struct dlist_item *elt = malloc(sizeof(struct dlist_item));
    elt->data = element;
    elt->next = tmp;
    elt->prev = tmp->prev;

    if (tmp->prev)
        tmp->prev->next = elt;

    tmp->prev = elt;

    if (index == 0)
        list->head = elt;

    list->size++;

    return 1;
}

int dlist_find(const struct dlist *list, int element)
{
    struct dlist_item *tmp = list->head;
    int i = 0;

    while (tmp)
    {
        if (tmp->data == element)
            return i;

        tmp = tmp->next;
        i++;
    }
    return -1;
}

int dlist_remove_at(struct dlist *list, size_t index)
{
    struct dlist_item *tmp = dlist_get_item(list,index);
    if (!tmp)
        return -1;

    if (tmp->prev)
        tmp->prev->next = tmp->next;
    if (tmp->next)
        tmp->next->prev = tmp->prev;

    if (index == 0)
        list->head = list->head->next;
    else if (index == list->size - 1)
        list->tail = list->tail->prev;

    int res = tmp->data;
    free(tmp);
    list->size--;

    return res;
}

void dlist_clear(struct dlist *list)
{
    while (list->head)
    {
        struct dlist_item *tmp = list->head;
        list->head = list->head->next;
        free(tmp);
    }

    list->size = 0;
    list->tail = NULL;
}

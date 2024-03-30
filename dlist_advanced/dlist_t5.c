#include <stdlib.h>

#include "dlist.h"

void dlist_sort(struct dlist *list)
{
    if (list)
    {
        struct dlist_item *i = list->head;

        while (i)
        {
            struct dlist_item *j = list->head;
            int swap = 0;

            while (j && j->next)
            {
                if (j->data > j->next->data)
                {
                    int tmp = j->data;
                    j->data = j->next->data;
                    j->next->data = tmp;

                    swap = 1;
                }
                j = j->next;
            }
            if (!swap)
                break;
            i = i->next;
        }
    }
}

void dlist_merge(struct dlist *list1, struct dlist *list2)
{
    dlist_sort(list1);

    while (list2->head)
    {
        struct dlist_item *tmp = list2->head;
        dlist_add_sort(list1, list2->head->data);
        list2->head = list2->head->next;

        free(tmp);
    }
    list2->head = NULL;
    list2->tail = NULL;
    list2->size = 0;
}

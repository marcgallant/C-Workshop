#include "list.h"

#include <stdlib.h>
#include <string.h>

struct list *list_prepend(struct list *list, const void *value,
                          size_t data_size)
{
    struct list *node = malloc(sizeof(struct list));

    node->data = malloc(data_size);
    memcpy(node->data, value, data_size);
    node->next = list;

    return node;
}

size_t list_length(struct list *list)
{
    struct list *tmp = list;
    size_t i = 0;
    while (tmp)
    {
        i++;
        tmp = tmp->next;
    }
    return i;
}

void list_destroy(struct list *list)
{
    while (list)
    {
        struct list *tmp = list;
        list = list->next;
        free(tmp->data);
        free(tmp);
    }
}

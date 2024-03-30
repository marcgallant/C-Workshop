#include "dlist.h"

unsigned int dlist_levenshtein_rec(struct dlist_item *head1,
                                   struct dlist_item *head2, unsigned int n1,
                                   unsigned int n2)
{
    if (!n1)
        return n2;
    if (!n2)
        return n1;

    if (head1->data == head2->data)
        return dlist_levenshtein_rec(head1->next, head2->next, n1 - 1, n2 - 1);

    unsigned long rec1 = dlist_levenshtein_rec(head1->next, head2, n1 - 1, n2);
    unsigned long rec2 = dlist_levenshtein_rec(head1, head2->next, n1, n2 - 1);
    unsigned long rec3 =
        dlist_levenshtein_rec(head1->next, head2->next, n1 - 1, n2 - 1);

    if (rec1 < rec2)
    {
        if (rec1 < rec3)
            return 1 + rec1;
        else
            return 1 + rec3;
    }
    else
    {
        if (rec2 < rec3)
            return 1 + rec2;
        else
            return 1 + rec3;
    }
}

unsigned int dlist_levenshtein(struct dlist *list1, struct dlist *list2)
{
    return dlist_levenshtein_rec(list1->head, list2->head, list1->size,
                                 list2->size);
}

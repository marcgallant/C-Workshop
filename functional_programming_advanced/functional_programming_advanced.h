#ifndef FUNCTIONAL_PROGRAMMING_ADVANCED_H
#define FUNCTIONAL_PROGRAMMING_ADVANCED_H

#include <stdbool.h>
#include <stddef.h>

bool all(int *array, size_t len, bool (*func)(int));
bool any(int *array, size_t len, bool (*func)(int));
size_t filter(int *array, size_t len, int **out_array, bool (*func)(int));

int max(int *array, size_t len);
void print_even(int *array, size_t len);

#endif /* !FUNCTIONAL_PROGRAMMING_ADVANCED_H */

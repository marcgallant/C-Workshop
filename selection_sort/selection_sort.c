unsigned array_min(const int arr[], unsigned start, unsigned size)
{
    unsigned min = start;
    for (unsigned i = start + 1; i < size; i++)
    {
        if (arr[i] < arr[min])
            min = i;
    }
    return min;
}

void selection_sort(int arr[], unsigned size)
{
    if (size > 0)
    {
        for (unsigned int i = 0; i < size; i++)
        {
            unsigned min = array_min(arr, i, size);
            if (i != min)
            {
                unsigned tmp = arr[min];
                arr[min] = arr[i];
                arr[i] = tmp;
            }
        }
    }
}

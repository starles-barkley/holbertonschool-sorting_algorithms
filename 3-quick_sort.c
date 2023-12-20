#include "sort.h"

/**
 * int_swap - swap integers
 * @first: first element to swap
 * @second: element to swap with first
 */
void int_swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

/**
 * lomuto_part - implement lomuto partition
 * @array: array to partition
 * @size: size of array
 * @low: lowest index in array
 * @high: highest index in array
 * Return: index where partition ended up
 */
int lomuto_part(int array[], size_t size, int low, int high)
{
    int pivot = array[high];
    int i = low - 1;
    
    for (int j = low; j <= high - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            int_swap(&array[i], &array[j]);
        }
    }
    print_array(array, size);
    int_swap(&array[i + 1], &array[high]);
    return (i + 1);
}

/**
 * quick_sort - implementation of quick sort algorithm
 * @array: array to partition and sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
    if (size > 1)
    {
        lomuto_part(array, size, 0, size - 1);
    }
}
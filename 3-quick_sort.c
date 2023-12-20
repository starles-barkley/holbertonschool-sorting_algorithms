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
 * lomuto_part - implement Lomuto partition
 * @array: array to partition
 * @low: lowest index in array
 * @high: highest index in array
 * Return: index where partition ended up
 */
int lomuto_part(int array[], int low, int high)
{
    int pivot = array[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            int_swap(&array[i], &array[j]);
        }
    }
    int_swap(&array[i + 1], &array[high]);
    return (i + 1);
}

/**
 * quicksort_recursive - recursive function for Quick Sort
 * @array: array to partition and sort
 * @low: lowest index in array
 * @high: highest index in array
 */
void quicksort_recursive(int array[], int low, int high)
{
    if (low < high)
    {
        int partition_index = lomuto_part(array, low, high);

        quicksort_recursive(array, low, partition_index - 1);
        quicksort_recursive(array, partition_index + 1, high);
    }
}

/**
 * quick_sort - implementation of Quick Sort algorithm
 * @array: array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quicksort_recursive(array, 0, size - 1);
}

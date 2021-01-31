#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

// Display Function
void display(struct Array arr)
{
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
    printf("\nLength : %d", arr.length);
}

// Append Function
void append(struct Array *arr, int x)
{
    if (arr->length < arr->size)
    {
        arr->A[arr->length++] = x;
    }
}

// Insert Function
void insert(struct Array *arr, int index, int x)
{
    if (index >= 0 && index <= arr->length)
    {
        for (int i = arr->length; i > index; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}

// Delete Function
void delete (struct Array *arr, int index)
{
    if (index >= 0 && index < arr->length)
    {
        for (int i = index; i < arr->length - 1; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
    }
}

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// Linear Search
int linearSearch(struct Array arr, int key)
{
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i] == key)
        {
            return i;
        }
    }
    return -1;
}

// Improvement in Linear Search
int impLinearSearch(struct Array *arr, int key)
{
    for (int i = 0; i < arr->length; i++)
    {
        if (arr->A[i] == key)
        {
            // Transposition
            // swap(&arr->A[i], &arr->A[i - 1]);
            // return i - 1;
            // Move to Front/ Move to head
            swap(&arr->A[i], &arr->A[0]);
            return 0;
        }
    }
    return -1;
}

// Iterative version of Binary Search
int binarySearch(struct Array arr, int key)
{
    int l, h, mid;
    l = 0;
    h = arr.length - 1;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == arr.A[mid])
            return mid;
        else if (key < arr.A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

// Recursive version of Binary Search
int recBinarySearch(struct Array arr, int l, int h, int key)
{
    int mid;
    if (l <= h)
    {
        mid = (l + h) / 2;
        if (key == arr.A[mid])
            return mid;
        else if (key < arr.A[mid])
            return recBinarySearch(arr, l, mid - 1, key);
        else
            return recBinarySearch(arr, mid + 1, h, key);
    }
    return -1;
}

int main()
{
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};
    // append(&arr, 10);
    // insert(&arr, 2, 10);
    // delete (&arr, 0);
    // display(arr);

    // int lSearch = linearSearch(arr, 4);
    // printf("%d", lSearch);

    // printf("%d", impLinearSearch(&arr, 6));
    // printf("%d", binarySearch(arr, 5));
    printf("%d", recBinarySearch(arr, 0, arr.length, 2));
    return 0;
}
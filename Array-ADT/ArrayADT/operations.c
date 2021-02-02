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
    printf("\nLength : %d\n", arr.length);
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

// Get
int get(struct Array arr, int index)
{
    if (index >= 0 && index < arr.length)
    {
        return arr.A[index];
    }
    return -1;
}

// Set
void set(struct Array *arr, int index, int x)
{
    if (index >= 0 && index < arr->length)
    {
        arr->A[index] = x;
    }
}

// Max
int Max(struct Array arr)
{
    int max = arr.A[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] > max)
        {
            max = arr.A[i];
        }
    }
    return max;
}

// Min
int Min(struct Array arr)
{
    int min = arr.A[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] < min)
        {
            min = arr.A[i];
        }
    }
    return min;
}

// Sum
int sum(struct Array arr)
{
    int total = 0;
    for (int i = 0; i < arr.length; i++)
    {
        total += arr.A[i];
    }
    return total;
}

// Average
float avg(struct Array arr)
{
    return (float)sum(arr) / arr.length;
}

// Reverse- (1st Method- Auxilary array)
void Reverse(struct Array *arr)
{
    int *B;
    B = (int *)malloc(arr->length * sizeof(int));
    for (int i = arr->length - 1, j = 0; i >= 0; i--, j++)
    {
        B[j] = arr->A[i];
    }
    for (int i = 0; i < arr->length; i++)
    {
        arr->A[i] = B[i];
    }
}

void Reverse2(struct Array *arr)
{
    for (int i = 0, j = arr->length - 1; i < j; i++, j--)
    {
        swap(&arr->A[i], &arr->A[j]);
    }
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
    // printf("%d", recBinarySearch(arr, 0, arr.length, 2));

    // printf("%d", get(arr, 1));
    // set(&arr, 1, 10);
    // display(arr);

    // printf("%d", Max(arr));
    // printf("%d", Min(arr));
    // printf("%d", sum(arr));
    // printf("%f", avg(arr));

    // display(arr);
    Reverse2(&arr);
    display(arr);

    return 0;
}
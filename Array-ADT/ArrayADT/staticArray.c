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
    if (index < arr->length)
    {
        for (int i = index; i < arr->length - 1; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
    }
}

int main()
{
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};
    // append(&arr, 10);
    // insert(&arr, 2, 10);
    delete (&arr, 2);
    display(arr);
    return 0;
}
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

class Array
{
    private:
        int *A;
        int size;
        int length;
        void swap(int *x, int *y);

    public:
        Array()
        {
            size = 10;
            length = 0;
            A = new int[size];
        }
        Array(int sz)
        {
            size = sz;
            length = 0;
            A = new int[size];
        }
        ~Array()
        {
            delete[] A;
        }
        void display();
        void append(int x);
        void insert(int index, int x);
        void Delete(int index);
        int linearSearch(int key);
        int impLinearSearch(int key);
        int binarySearch(int key);
        int get(int index);
        void set(int index, int x);
        int Max();
        int Min();
        int sum();
        float avg();
        void Reverse();
        void Reverse2();
        void InsertSort(int x);
        int isSorted();
        void rearrange();
        Array *merge(Array *arr2);
        Array *Union(Array *arr2);
        Array *Intersection(Array *arr2);
        Array *Difference(Array *arr2);
};

// Display Function
void Array::display()
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\nLength : %d\n", length);
}

// Append Function
void Array::append(int x)
{
    if (length < size)
    {
        A[length++] = x;
    }
}

// Insert Function
void Array::insert(int index, int x)
{
    if (index >= 0 && index <= length)
    {
        for (int i = length; i > index; i--)
        {
            A[i] = A[i - 1];
        }
        A[index] = x;
        length++;
    }
}

// Delete Function
void Array::Delete(int index)
{
    if (index >= 0 && index < length)
    {
        for (int i = index; i < length - 1; i++)
        {
            A[i] = A[i + 1];
        }
        length--;
    }
}

void Array::swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// Linear Search
int Array::linearSearch(int key)
{
    for (int i = 0; i < length; i++)
    {
        if (A[i] == key)
        {
            return i;
        }
    }
    return -1;
}

// Improvement in Linear Search
int Array::impLinearSearch(int key)
{
    for (int i = 0; i < length; i++)
    {
        if (A[i] == key)
        {
            // Transposition
            // swap(&A[i], &A[i - 1]);
            // return i - 1;
            // Move to Front/ Move to head
            swap(&A[i], &A[0]);
            return 0;
        }
    }
    return -1;
}

// Iterative version of Binary Search
int Array::binarySearch(int key)
{
    int l, h, mid;
    l = 0;
    h = length - 1;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == A[mid])
            return mid;
        else if (key < A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

// Get
int Array::get(int index)
{
    if (index >= 0 && index < length)
    {
        return A[index];
    }
    return -1;
}

// Set
void Array::set(int index, int x)
{
    if (index >= 0 && index < length)
    {
        A[index] = x;
    }
}

// Max
int Array::Max()
{
    int max = A[0];
    for (int i = 1; i < length; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }
    return max;
}

// Min
int Array::Min()
{
    int min = A[0];
    for (int i = 1; i < length; i++)
    {
        if (A[i] < min)
        {
            min = A[i];
        }
    }
    return min;
}

// Sum
int Array::sum()
{
    int total = 0;
    for (int i = 0; i < length; i++)
    {
        total += A[i];
    }
    return total;
}

// Average
float Array::avg()
{
    return (float)sum() / length;
}

// Reverse- (1st Method- Auxilary array)
void Array::Reverse()
{
    int *B;
    B = (int *)malloc(length * sizeof(int));
    for (int i = length - 1, j = 0; i >= 0; i--, j++)
    {
        B[j] = A[i];
    }
    for (int i = 0; i < length; i++)
    {
        A[i] = B[i];
    }
}

// Reverse2- (2nd Method)
void Array::Reverse2()
{
    for (int i = 0, j = length - 1; i < j; i++, j--)
    {
        swap(&A[i], &A[j]);
    }
}

// Insert
void Array::InsertSort(int x)
{
    int i = length - 1;
    if (length == size)
        return;
    while (i >= 0 && A[i] > x)
    {
        A[i + 1] = A[i];
        i--;
    }
    A[i + 1] = x;
    length++;
}

// Check if array is sorted or not
int Array::isSorted()
{
    for (int i = 0; i < length - 1; i++)
    {
        if (A[i] > A[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

// Rearranging Positives and negatives
void Array::rearrange()
{
    int i, j;
    i = 0;
    j = length - 1;
    while (i < j)
    {
        while (A[i] < 0)
            i++;
        while (A[j] >= 0)
            j--;
        if (i < j)
        {
            swap(&A[i], &A[j]);
        }
    }
}

// Merge Sort
// Array *merge(Array arr2)
// {
//     int i = 0, j = 0, k = 0;
//     Array *arr3 = new Array(length + arr2.length);
//     while (i < length && j < arr2.length)
//     {
//         if (A[i] < arr2.A[j])
//             arr3->A[k++] = A[i++];
//         else
//             arr3->A[k++] = arr2.A[j++];
//     }
//     for (; i < length; i++)
//         arr3->A[k++] = A[i];
//     for (; j < arr2.length; j++)
//         arr3->A[k++] = arr2.A[j];
//     arr3->length = length + arr2.length;
//     return arr3;
// }

// // Union
// Array *Union(struct Array arr1, struct Array arr2)
// {
//     int i = 0, j = 0, k = 0;
//     struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
//     while (i < length && j < length)
//     {
//         if (A[i] < [j])
//             arr3->A[k++] = A[i++];
//         else if ([j] < A[i])
//             arr3->A[k++] = [j++];
//         else
//         {
//             arr3->A[k++] = A[i++];
//             j++;
//         }
//     }
//     for (; i < length; i++)
//         arr3->A[k++] = A[i];
//     for (; j < length; j++)
//         arr3->A[k++] = [j];
//     arr3->length = k;
//     arr3->size = 10;
//     return arr3;
// }

// // Intersection
// struct Array *Intersection(struct Array arr1, struct Array arr2)
// {
//     int i = 0, j = 0, k = 0;
//     struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
//     while (i < length && j < length)
//     {
//         if (A[i] < [j])
//             i++;
//         else if ([j] < A[i])
//             j++;
//         else
//         {
//             arr3->A[k++] = A[i++];
//             j++;
//         }
//     }
//     arr3->length = k;
//     arr3->size = 10;
//     return arr3;
// }

// Difference
// struct Array *Difference(struct Array arr1, struct Array arr2)
// {
//     int i = 0, j = 0, k = 0;
//     struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
//     while (i < length && j < length)
//     {
//         if (A[i] < [j])
//             arr3->A[k++] = A[i++];
//         else if ([j] < A[i])
//             j++;
//         else
//         {
//             i++;
//             j++;
//         }
//     }
//     for (; i < length; i++)
//         arr3->A[k++] = A[i];
//     arr3->length = k;
//     arr3->size = 10;
//     return arr3;
// }

int main()
{
    Array *arr1;
    int ch,sz;
    int x, index;
    scanf("%d", &sz);
    arr1=new Array(sz);

    return 0;
}
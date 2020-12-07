#include <iostream>

using namespace std;

void bubbleSort(int arr[],int n);
void selectedSort(int arr[],int n);
void insertionSort(int arr[],int n);
void mergeSort(int arr[],int l,int r);
void quickSort(int arr[],int n);

void printArray(int arr[], int size_)
{
    int i;
    for (i=0; i < size_; i++)
       cout << arr[i] << " ";
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    //Bubble_Sort(arr, n);
    //selectedSort(arr,n);
    mergeSort(arr,0,n-1);
    printArray(arr, n);
    return 0;
}

void swap_(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[],int n)
{
    bool swapped = false;

    for(int i = 0; i < n - 1; i++)
    {
        swapped = false;

        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                swap_(&arr[j], &arr[j+1]);
                swapped = true;
            }
        }

        if(!swapped)
        {
            break;
        }
    }
}

void selectedSort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        int min_i = i;

        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[min_i])
            {
                min_i = j;

            }
        }

        swap_(&arr[min_i],&arr[i]);
    }
}
/*
void insertionSort(int arr[],int n)
{
    int j;

    for(int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j -= 1;
        }

        arr[j + 1] = key;
    }
}
*/
void merge_(int arr[],int l,int m,int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[],int l,int r)
{
    if(l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr,l,m);
        mergeSort(arr,m + 1,r);

        merge_(arr,l,m,r);
    }
}
/*
void mergeSort1(int arr[],int size_)
{
    if(size_ > 1)
    {

        mergeSort(arr, size_ / 2);
        mergeSort(arr + size_ / 2, size_ / 2);

        merge_(arr,l,m,r);
    }
}
*/

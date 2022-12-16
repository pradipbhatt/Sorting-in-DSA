// C++ Implementation of the Quick Sort Algorithm.
#include <iostream>
#include <bits/stdc++.h>
#include <time.h>
using namespace std;
int partition(int arr[], int start, int end);

void quickSort(int arr[], int start, int end);

int main()
{

    int arr[] = {9, 3, 4, 2, 1, 8};
    int n = 6, i;
    time_t start, end, bubble_time;
    start = clock();
    quickSort(arr, 0, n - 1);
    end = clock();

    cout << "Sorted Element List from Quick sort is ...\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    // This way also we calculate time taken by program bubble_time = (double)(end - start);
    // cout<<bubble_time<<endl;

    // Calculating total time taken by the program.
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(10);
    cout << " sec " << endl;
    return 0;
}

int partition(int arr[], int start, int end)
{

    int pivot = arr[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= pivot)
            count++;
    }

    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    // Sorting left and right parts of the pivot element
    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex)
    {

        while (arr[i] <= pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{

    // base case
    if (start >= end)
        return;

    // partitioning the array
    int p = partition(arr, start, end);

    // Sorting the left part
    quickSort(arr, start, p - 1);

    // Sorting the right part
    quickSort(arr, p + 1, end);
}
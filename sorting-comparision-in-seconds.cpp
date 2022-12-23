#include <iostream>
#include <bits/stdc++.h>
#include <time.h>
using namespace std;

int partition(int arr[], int start, int end);
int findSmallest(int myarray[], int i);
void quickSort(int arr[], int start, int end);
void merge_sort(int *arr, int low, int high);
void merge(int *arr, int low, int high, int mid);

int main() // main function starts from here...
{
    system("cls");
    /* Time function returns the time since the
        Epoch(jan 1 1970). Returned time is in seconds. */
    time_t start, end, bubble_time,start1,end1,start2,end2 ,start3,end3 ,start4,end4,start5,end5;
    int sz;
    int arr[] = {9, 3, 4, 2, 1, 8};
    int n = 6, i, temp, pass, pos, j;
    cout << "Enter the size of array you wanna to enter::";
    cin >> sz;
    int randArray[sz];

    for (int i = 0; i < sz; i++)
        randArray[i] = rand() % 1000; // Generate number between 0 to 99

    // cout << "\nElements of the array::" << endl;

    for (int i = 0; i < sz; i++)
        cout << "Elements no " << i + 1 << "::" << randArray[i] << endl;
    // cout << "Input list ...\n";
    // for (i = 0; i < sz; i++)
    // {
    //     cout << randArray[i] << "\t";
    // }
    // cout << endl;



    // Bubble sort starts from here...
    start1 = clock();
    for (i = 0; i < sz; i++)
    {
        for (j = i + 1; j < sz; j++)
        {
            if (randArray[j] < randArray[i])
            {
                temp = randArray[i];
                randArray[i] = randArray[j];
                randArray[j] = temp;
            }
        }
        pass++;
    }
    cout << "\n Sorted Element List from bubble sort is ...\n";
    for (i = 0; i < sz; i++)
    {
        cout << randArray[i] << "\t ";
    }
    end1 = clock();
    // Calculating total time taken by the program of insertion sort.
    double time_taken1 = double(end1 - start1) / double(CLOCKS_PER_SEC);
    cout << "\nTime taken by insertion sort program is :\n " << fixed
         << time_taken1 << setprecision(5);
    cout << " sec  \n  \n  " << endl;
// bubble sort programs ends here...





    // insertion sort starts from here...
    start2 = clock();
    for (int i = 0; i < sz; i++)
    {
        cout << randArray[i] << "\t";
    }
    for (int k = 1; k < sz; k++)
    {
        int temp = randArray[k];
        int j = k - 1;
        while (j >= 0 && temp <= randArray[j])
        {
            randArray[j + 1] = randArray[j];
            j = j - 1;
        }
        randArray[j + 1] = temp;
    }

    // cout << "\nSorted list is from insertion sort is:\n";
    // for (int i = 0; i < sz; i++)
    // {
    //     cout << randArray[i] << "\t\n\n";
    // }
    cout << "\n Sorted Element List from insertion sort is ...\n";
    for (i = 0; i < sz; i++)
    {
        cout << randArray[i] << "\t";
    }
    end2 = clock();
    // Calculating total time taken by the program of insertion sort.
    double time_taken2 = double(end2 - start2) / double(CLOCKS_PER_SEC);
    cout << "\nTime taken by insertion sort program is :\n " << fixed
         << time_taken2 << setprecision(15);
    cout << " sec  \n  \n  " << endl;
  // insertion sort ends here...


    // merge sort
    start3 = clock();
    merge_sort(randArray, 0, sz - 1);
    end3 = clock();
    cout << "\n Sorted Element List from merge sort is : \n";
    for (int i = 0; i < sz; i++)
    {
        cout << randArray[i] << "\t";
    }

    double time_taken3 = double(end3 - start3) / double(CLOCKS_PER_SEC);
    cout << "\nTime taken by merge program is : \n" << fixed
         << time_taken3 << setprecision(5);
    cout << " sec   \n  \n " << endl;



    // quick sort
    start4 = clock();
    quickSort(arr, 0, n - 1);
        cout << "Sorted Element List from quick sort is ...\n";
    for (i = 0; i < sz; i++)
    {
        cout << randArray[i] << "\t";
    }
    end4 = clock();
    double time_taken4 = double(end4 - start4) / double(CLOCKS_PER_SEC);
    cout << "\nTime taken by quick sort program is :\n " << fixed
         << time_taken4 << setprecision(5);
    cout << " sec   \n  \n " << endl;



    // Selection sort code starts from here...

    start5 = clock();
    for (int i = 0; i < sz; i++)
    {
        pos = findSmallest(randArray, i);
        temp = randArray[i];
        randArray[i] = randArray[pos];
        randArray[pos] = temp;
        pass++;
    }
        cout << "\n Sorted Element List from selection sort is ...\n";
    for (i = 0; i < sz; i++)
    {
        cout << randArray[i] << "\t";
    }
    end5 = clock();
    // Calculating total time taken by the program.
    double time_taken5 = double(end5 - start5) / double(CLOCKS_PER_SEC);
    cout << "\nTime taken by selection sort program is : \n" << fixed
         << time_taken5 << setprecision(5);
    cout << " sec  \n  \n  " << endl;
    return 0;
}

void merge_sort(int *arr, int low, int high)
{
    int mid;
    if (low < high)
    {
        // divide the array at mid and sort independently using merge sort
        mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        // merge or conquer sorted arrays
        merge(arr, low, high, mid);
    }
}
// Merge sort
void merge(int *arr, int low, int high, int mid)
{
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            c[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        c[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        arr[i] = c[i];
    }
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

// Findsmallest function is defined here...
int findSmallest(int myarray[], int i)
{
    int ele_small, position, j, sz = 10;
    ele_small = myarray[i];
    position = i;
    for (j = i + 1; j < sz; j++)
    {
        if (myarray[j] < ele_small)
        {
            ele_small = myarray[j];
            position = j;
        }
    }
    return position;
}
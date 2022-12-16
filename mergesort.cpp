#include <iostream>
#include <bits/stdc++.h>
#include <time.h>
using namespace std;
void merge(int *, int, int, int);
void merge_sort(int *arr, int low, int high);

int main() // main function starts from here...
{
    system("cls");
    /* Time function returns the time since the
        Epoch(jan 1 1970). Returned time is in seconds. */
    time_t start, end, bubble_time;
    int i, j, temp, pass = 0, pos;
    int sz;
    cout << "Enter the size of array you wanna to enter::";
    cin >> sz;
    int randArray[sz];
    for (int i = 0; i < sz; i++)
        randArray[i] = rand() % 1000; // Generate number between 0 to 99

    cout << "\nElements of the array::" << endl;

    for (int i = 0; i < sz; i++)
        cout << "Elements no " << i + 1 << "::" << randArray[i] << endl;

    cout << "Input list ...\n";
    for (i = 0; i < sz; i++)
    {
        cout << randArray[i] << "\t";
    }
    cout << endl;

    start = clock();
    merge_sort(randArray, 0, sz - 1);
    end = clock();
    cout << "Sorted array from merge sort is : \n";
    for (int i = 0; i < sz; i++)
    {
        cout << randArray[i] << "\t";
    }
    cout << "\nNumber of passes required to sort the array: " << pass << "\n";



    cout << "\nNumber of passes taken to sort the list:" << pass << endl;

    // This way also we calculate time taken by program bubble_time = (double)(end - start);
    // cout<<bubble_time<<endl;

    // Calculating total time taken by the program.
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(10);
    cout << " sec " << endl;
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
#include <iostream>
using namespace std;
int findSmallest(int myarray[], int i);
void merge(int *, int, int, int);
void merge_sort(int *arr, int low, int high);

int main() // main function starts from here...
{
    system("cls");
    int i, j, temp, pass = 0, pos;
    int sz;
    cout << "Enter the size of array you wanna to enter::";
    cin >> sz;
    int randArray[sz];
    for (int i = 0; i < sz; i++)
        randArray[i] = rand() % 100; // Generate number between 0 to 99

    cout << "\nElements of the array::" << endl;

    for (int i = 0; i < sz; i++)
        cout << "Elements no " << i + 1 << "::" << randArray[i] << endl;

    cout << "Input list ...\n";
    for (i = 0; i < sz; i++)
    {
        cout << randArray[i] << "\t";
    }
    cout << endl;



    // Bubble sort starts from here...
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
    cout << "Sorted Element List from bubble sort is ...\n";
    for (i = 0; i < sz; i++)
    {
        cout << randArray[i] << "\t\n\n";
    }
    cout << "\nNumber of passes taken to sort the list:" << pass << endl;


    // Insertion sort code start from here....
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
    cout << "\nSorted list is from insertion sort is:\n";
    for (int i = 0; i < sz; i++)
    {
        cout << randArray[i] << "\t\n\n";
    }

    // Selection sort code starts from here...

    for (int i = 0; i < sz; i++)
    {
        cout << randArray[i] << "\t";
    }
    for (int i = 0; i < sz; i++)
    {
        pos = findSmallest(randArray, i);
        temp = randArray[i];
        randArray[i] = randArray[pos];
        randArray[pos] = temp;
        pass++;
    }
    cout << "\n Sorted list of elements from selection is\n\n";
    for (int i = 0; i < sz; i++)
    {
        cout << randArray[i] << "\t";
    }
    cout << "\nNumber of passes required to sort the array: " << pass << "\n";




    // Merge sort starts from here...

    merge_sort(randArray, 0, sz - 1);
    cout << "Sorted array from merge sort is : \n";
    for (int i = 0; i < sz; i++)
    {
        cout << randArray[i] << "\t";
    }
    return 0;
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
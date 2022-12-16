#include <iostream>
#include <bits/stdc++.h>
#include <time.h>
using namespace std;

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
    end = clock();
    cout << "Sorted Element List from bubble sort is ...\n";
    for (i = 0; i < sz; i++)
    {
        cout << randArray[i] << "\t\n\n";
    }
    cout << "\nNumber of passes taken to sort the list:" << pass << endl;

    // This way also we calculate time taken by program bubble_time = (double)(end - start);
    // cout<<bubble_time<<endl;

    // Calculating total time taken by the program.
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(10);
    cout << " sec " << endl;
}
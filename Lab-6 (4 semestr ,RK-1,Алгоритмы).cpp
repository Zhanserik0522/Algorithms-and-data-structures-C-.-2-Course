#include <iostream>
using namespace std;

int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

//Time Complexity : O(N + M), where N and M are the size of inputArray[] and countArray[]
//Auxiliary Space : O(N + M), where N and M are the space taken by outputArray[] and countArray[]


int* countSort(int arr[], int n) {
    int largest = getMax(arr, n);
    int* countArray = new int[largest + 1]();
    int* outputArray = new int[n];

    for (int i = 0; i < n; i++) {
        countArray[arr[i]]++;
    }

    for (int i = 1; i <= largest; i++) {
        countArray[i] += countArray[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        outputArray[countArray[arr[i]] - 1] = arr[i];
        countArray[arr[i]]--;
    }

    delete[] countArray;

    return outputArray;
}

//Time Complexity : O(d * (n + b)), where d is the number of digits, n is the number of elements, and b is the base of the number system being used.
//Auxiliary Space : O(n + b), where n is the number of elements and b is the base of the number system.


void countSort(int arr[], int n, int exp) {
    int* output = new int[n];
    int i, count[10] = { 0 };

    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];

    delete[] output;
}

void radixsort(int arr[], int n) {
    int largest = getMax(arr, n);
    for (int exp = 1; largest / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

int main() {
    int arr[] = { 5,3,2,1,0,5,7,9 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int* sortedArr = countSort(arr, n);

    for (int i = 0; i < n; i++) {
        cout << sortedArr[i] << " ";
    }

    delete[] sortedArr;
    cout << endl;

    int arr_1[] = { 5,3,2,1,0,5,7,9 };
    n = sizeof(arr_1) / sizeof(arr_1[0]);
    radixsort(arr_1, n);
    print(arr_1, n);

    return 0;
}

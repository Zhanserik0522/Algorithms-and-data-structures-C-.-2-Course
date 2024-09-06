#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class InsertionSort {
public:
    void sort(int arr[], int n) {
        int i, key, j;
        for (i = 1; i < n; i++) {
            key = arr[i];
            j = i - 1;

            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }
};

class ShellSort {
public:
    void sort(int arr[], int n) {
        for (int gap = n / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < n; i += 1) {
                int temp = arr[i];
                int j;
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                    arr[j] = arr[j - gap];

                arr[j] = temp;
            }
        }
    }
};


class BucketSort {
public:
    void sort(vector<double>& arr) {
        int n = arr.size();

        // Create buckets
        vector<vector<double>> buckets(n);

        // Distribute elements into buckets
        for (int i = 0; i < n; ++i) {
            int bucketIndex = n * arr[i];
            buckets[bucketIndex].push_back(arr[i]);
        }

        // Sort individual buckets
        pfor (int i = 0; i < n; ++i) {
            insertionSort(buckets[i]);
        }

        // Concatenate buckets back into arr[]
        int index = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < buckets[i].size(); ++j) {
                arr[index++] = buckets[i][j];
            }
        }
    }

private:
    void insertionSort(vector<double>& bucket) {
        for (int i = 1; i < bucket.size(); ++i) {
            double key = bucket[i];
            int j = i - 1;
            while (j >= 0 && bucket[j] > key) {
                bucket[j + 1] = bucket[j];
                j--;
            }
            bucket[j + 1] = key;
        }
    }
};;


int main() {
    return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;


void swap(int arr[], int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int partition(int arr[], int start, int end) {
	int pivot = arr[end];
	int i = start - 1;
	for (int j = start; j <= end; j++) {
		if (arr[j] < pivot){
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[end]);
	return (i + 1);
}

void Quicksort(int arr[], int start, int end) {
	if (start < end) {
		int pi = partition(arr, start, end);
		Quicksort(arr, start, pi - 1);
		Quicksort(arr, pi + 1, end);
	}
}



void heapify(int arr[], int n, int i) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && arr[largest] < arr[left]) {
		largest = left;
	}

	if (right < n && arr[largest] < arr[right]) {
		largest = right;
	}

	if (largest != i) {
		swap(arr, i, largest);
		heapify(arr, n, largest);
	}
}

void Heap_Sort(int arr[],int n) {
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(arr,n,i);
	}
	for (int i = n - 1; i >= 0; i--) {
		swap(arr,0,i);
		heapify(arr, i, 0);
	}
}


int partition(int* arr, int start, int end, int* left_pivot);

void swap_dual(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void DualPivotQuickSort(int* arr, int low, int high)
{
	if (low < high) {
		
		int left_pivot, right_pivot;
		right_pivot = partition(arr, low, high, &left_pivot);
		DualPivotQuickSort(arr, low, left_pivot - 1);
		DualPivotQuickSort(arr, left_pivot + 1, right_pivot - 1);
		DualPivotQuickSort(arr, right_pivot + 1, high);
	}
}

int partition(int* arr, int start, int end, int* left_pivot)
{
	if (arr[start] > arr[end])
		swap_dual(&arr[start], &arr[end]);

	// p is the left pivot, and q is the right pivot. 
	int j = start + 1;
	int g = end - 1, k = start + 1, p = arr[start], q = arr[end];
	while (k <= g) {

		// if elements are less than the left pivot 
		if (arr[k] < p) {
			swap_dual(&arr[k], &arr[j]);
			j++;
		}

		// if elements are greater than or equal 
		// to the right pivot 
		else if (arr[k] >= q) {
			while (arr[g] > q && k < g)
				g--;
			swap_dual(&arr[k], &arr[g]);
			g--;
			if (arr[k] < p) {
				swap_dual(&arr[k], &arr[j]);
				j++;
			}
		}
		k++;
	}
	j--;
	g++;

	// bring pivots to their appropriate positions. 
	swap_dual(&arr[start], &arr[j]);
	swap_dual(&arr[end], &arr[g]);

	// returning the indices of the pivots. 
	*left_pivot = j; // because we cannot return two elements 
	// from a function. 

	return g;
}


int main()
{
	int arr[] = { 1,3,43,7,32,8,3,-4,31 };
	int n = sizeof(arr) / sizeof(arr[0]);
	Heap_Sort(arr, n);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}


#include <bits/stdc++.h> 
using namespace std; 

int partition (int arr[], int left, int right) { 
	int pivot = arr[right]; 
	int i = (left - 1);
	for (int j = left; j < right; j++) 
	{ 
		if (arr[j] < pivot) 
		{ 
			i++;
			int temp = arr[i];
 			arr[i] = arr[j];
 			arr[j] = temp;
		} 
	} 
	int temp = arr[i+1];
	arr[i+1] = arr[right];
	arr[right] = temp;
	return (i + 1); 
} 

void quickSort(int arr[], int left, int right) 
{ 
	if (left < right) 
	{ 
		int p = partition(arr, left, right); 

		quickSort(arr, left, p - 1); 
		quickSort(arr, p + 1, right); 
	} 
} 

void printArray(int arr[], int size) 
{ 
	int i; 
	for (i = 0; i < size; i++) 
		cout << arr[i] << " "; 
	cout << endl; 
} 

int main() 
{ 
	int arr[] = {5,4,3,2,1}; 
	int n = 5;
	quickSort(arr, 0, n - 1); 
	cout << endl <<"Sorted array: "; 
	printArray(arr, n); 
	return 0; 
} 


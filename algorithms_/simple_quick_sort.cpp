#include <iostream>
#include <vector>
#include <unistd.h>


using namespace std;

// A utility function to swap two elements
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition(vector<int>& arr, int begin, int end)
{
	int pivot = arr[end]; // pivot
	int i = begin; // Index of smaller element and indicates
				// the right position of pivot found so far

	for (int j = begin; j < end; j++) 
    {
		if (arr[j] < pivot) 
        {
			swap(&arr[i], &arr[j]);
            i++;
		}
	}
	swap(&arr[i], &arr[end]);
	return i;
}



void quickSort(vector<int>& arr, int begin, int end)
{
	if (begin < end) 
    {

		int pi = partition(arr, begin, end);

		quickSort(arr, begin, pi - 1);
		quickSort(arr, pi + 1, end);
	}
}



void quick_sort(std::vector<int>& vect)
{
    quickSort(vect, 0, vect.size() - 1);
}
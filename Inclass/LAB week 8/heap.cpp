#include <iostream>
using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   int largest = root;
   int left = 2 * root + 1;
   int right = 2 * root + 2;

   // if the left child is larger than the root
   if (left < n && arr[left] > arr[largest])
   {
      largest = left;
   }

   // if the right child is larger than the root
   if (right < n && arr[right] > arr[largest])
   {
      largest = right;
   }

   if (largest != root)
   { // if root is not the laegest element in the heap
      swap(arr[root], arr[largest]);

      // recurssively heapify the sub tree
      heapify(arr, n, largest);
   }
}

// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for (int i = n / 2 - 1; i >= 0; i--)
   {
      heapify(arr, n, i);
   }

   // extracting elements from heap one by one
   for (int i = n - 1; i >= 0; i--)
   {
      // moving current root to the end
      swap(arr[0], arr[i]);
      // again heapyfy the redused sub tree
      heapify(arr, i, 0);
   }
}

/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i = 0; i < n; ++i)
      cout << arr[i] << " ";
   cout << "\n";
}

// main program
int main()
{
   int heap_arr[] = {4, 23, 17, 3, 67, 99, 34, 56, 78, 99, 14, 12, 9, 6};
   int n = sizeof(heap_arr) / sizeof(heap_arr[0]);
   cout << "Input array 1 " << endl;
   displayArray(heap_arr, n);

   heapSort(heap_arr, n);

   cout << "Sorted array 1 " << endl;
   displayArray(heap_arr, n);
}
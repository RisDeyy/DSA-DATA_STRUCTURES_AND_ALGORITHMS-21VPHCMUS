#include "main.h"
void Swap(int *a, int *b){
    
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Selection sort
void SelectionSort(int arr[], int n);
void Comparisons_Select(int arr[], int n, unsigned long long &count);

//Insertion sort
void InsertionSort(int arr[], int n);
void Comparisons_Insert(int arr[], int n, unsigned long long &count);

//Bubble sort
void BubbleSort(int arr[], int n);
void Comparisons_Bubble(int arr[], int n, unsigned long long &count);

//Shaker sort
void ShakerSort(int arr[], int n);
void Comparisons_Shaker(int arr[], int n, unsigned long long &count);

//Shell sort
void ShellSort(int arr[], int n);
void Comparisons_Shell(int arr[], int n, unsigned long long &count);

//Heap sort
void Heapify(int arr[], int n, int i);
void HeapSort(int arr[], int n);
void Comparisons_Heapify(int arr[], int n, int i, unsigned long long &count);
void Comparisons_Heap(int arr[], int n, unsigned long long &count);

//Merge sort
void Merge(int arr[], int const left, int const mid, int const right);
void MergeSort(int arr[], int const start, int const end);
void CountComparisons_Merge(int arr[], int const left, int const mid, int const right, unsigned long long  &count);
void CountComparisons_MergeSort(int arr[], int const start, int const end, unsigned long long  &count);

//Quick sort
void QuickSort(int arr[], int start, int end);
void Comparisons_QuickSort(int arr[], int start, int end, unsigned long long &count);

//Counting sort
void CountingSort(int arr[], int n);
void Comparisons_Counting(int arr[], int n, unsigned long long &count);

//Radix sort
int getMax(int arr[], int n);
void countSort(int arr[], int n, int exp);
void RadixSort(int arr[], int n);
int Comparisons_getMax(int arr[], int n, unsigned long long &count);
void Comparisons_countSort(int arr[], int n, int exp, unsigned long long &count);
void Comparisons_Radix(int arr[], int n, unsigned long long &count);

//Flash sort
void FlashSort(int arr[], int n);
void Comparisons_Flash(int arr[], int n, unsigned long long &count);
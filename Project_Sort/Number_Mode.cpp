#include"Number_Mode.h"
#include "DataGenerator.h"

int CharSortToNum(const char *nameofsort)
{
	int MODE = 0;
	if (strcmp(nameofsort, "selection-sort") == 0) 
		MODE = 1;

	if (strcmp(nameofsort, "insertion-sort") == 0) 
		MODE = 2;
	
	if (strcmp(nameofsort, "bubble-sort") == 0) 
		MODE = 3;
	
	if (strcmp(nameofsort, "shaker-sort") == 0) 
		MODE = 4;
	
	if (strcmp(nameofsort, "shell-sort") == 0) 
		MODE = 5;
	
	if (strcmp(nameofsort, "heap-sort") == 0) 
		MODE = 6;
	
	if (strcmp(nameofsort, "merge-sort") == 0) 
		MODE = 7;
	
	if (strcmp(nameofsort, "quick-sort") == 0) 
		MODE = 8;
	
	if (strcmp(nameofsort, "counting-sort") == 0) 
		MODE = 9;

	if (strcmp(nameofsort, "radix-sort") == 0) 
		MODE = 10;
	
	if (strcmp(nameofsort, "flash-sort") == 0) 
		MODE = 11;
	
	return MODE;
}

int NumMode(int i, char* argv[]) {
	if (i >= 5 && i <= 6) {
		if (strcmp(argv[1], "-a") == 0) {
			if (i == 5) {
				if (CharSortToNum(argv[2]) != 0) {
					if (argv[3][strlen(argv[3]) - 1] == 't') {//command 1
						if (ReadFileA(argv) != -1) {
							if (strcmp(argv[4], "-both") == 0 || strcmp(argv[4], "-time") == 0 || strcmp(argv[4], "-comp") == 0)
								return 1;
						}
					}
				else {//command 3
					if (strcmp(argv[4], "-both") == 0 || strcmp(argv[4], "-time") == 0 || strcmp(argv[4], "-comp") == 0)
						return 3;
					}
				}
			}
			else {//command 2
				if (CharSortToNum(argv[2]) != 0) {
					if (argv[3][strlen(argv[3]) - 1] != 't') {
						if (strcmp(argv[4], "-rand") == 0 || strcmp(argv[4], "-nsorted") == 0 || strcmp(argv[4], "-sorted") == 0 || strcmp(argv[4], "-rev") == 0) {
							if (strcmp(argv[5], "-both") == 0 || strcmp(argv[5], "-time") == 0 || strcmp(argv[5], "-comp") == 0)
								return 2;
						}
					}
				}
			}
			return -1;
		}
		else if (strcmp(argv[1], "-c") == 0) {
			if (i == 5) { // command 4
				if (CharSortToNum(argv[2]) != 0 && CharSortToNum(argv[3]) != 0) {
					if (argv[3][strlen(argv[3]) - 1] == 't')
						if (ReadFileC(argv) != -1) {
							return 4;
						}
				}
			}
			else {//command 5
				if (CharSortToNum(argv[2]) != 0 && CharSortToNum(argv[3]) != 0) {
					if (argv[4][strlen(argv[4]) - 1] != 't') {
						if (strcmp(argv[5], "-rand") == 0 || strcmp(argv[5], "-nsorted") == 0 || strcmp(argv[5], "-sorted") == 0 || strcmp(argv[5], "-rev") == 0)
							return 5;
					}
				}
			}
			return -1;
		}
	}
	return -1;
}


void PrintSortingMode(int SortMode)
{
	switch (SortMode) {
		case 1: {
			cout << "Selection Sort";
			break;
		}
		case 2: {
			cout << "Insertion Sort";
			break;
		}
		case 3: {
			cout << "Bubble Sort";
			break;
		}
		case 4: {
			cout << "Shaker Sort";
			break;
		}
		case 5: {
			cout << "Shell Sort";
			break;
		}
		case 6:{
			cout << "Heap Sort";
			break;
		}
		case 7:{
			cout << "Merge Sort";
			break;
		}
		case 8:{
			cout << "Quick Sort";
			break;
		}
		case 9:{
			cout << "Counting Sort";
			break;
		}
		case 10:{
			cout << "Radix Sort";
			break;
		}
		case 11:{
			cout << "Flash Sort";
			break;
		}
	}
}

void Sorting_runningTime(int arr[], int n, int SortMode)
{
    int i, start, end;
	switch (SortMode) {
		case 1: {
			SelectionSort(arr, n);
			break;
		}
		case 2: {
			InsertionSort(arr, n);
			break;
		}
		case 3: {
			BubbleSort(arr, n);
			break;
		}
		case 4: {
			ShakerSort(arr, n);
			break;
		}
		case 5: {
			ShellSort(arr, n);
			break;
		}
		case 6:{
			HeapSort(arr, n);
			break;
		}
		case 7:{
			MergeSort(arr, 0, n-1);
			break;
		}
		case 8:{
			QuickSort(arr, 0, n-1);
			break;
		}
		case 9:{
			CountingSort(arr, n);
			break;
		}
		case 10:{
			RadixSort(arr, n);
			break;
		}
		case 11:{
			FlashSort(arr, n);
			break;
		}
	}

}

void Counting_comparisons(int arr[], int n, int SortMode, unsigned long long& count)
{
    int start, end;
	switch (SortMode) {
        case 1: {
            Comparisons_Select(arr, n, count);
            break;
        }
        case 2: {
            Comparisons_Insert(arr, n, count);
            break;
        }
        case 3: {
            Comparisons_Bubble(arr, n, count);
            break;
        }
        case 4: {
            Comparisons_Shaker(arr, n, count);
            break;
        }
        case 5: {
            Comparisons_Shell(arr, n, count);
            break;
        }
        case 6:
        {
            Comparisons_Heap(arr, n, count);
            break;
        }
        case 7:
        {
            CountComparisons_MergeSort(arr, start, end, count);
            break;
        }
        case 8:
        {
            Comparisons_QuickSort(arr, start, end, count);
            break;
        }
        case 9:
        {
            Comparisons_Counting(arr, n, count);
            break;
        }
        case 10:
        {
            Comparisons_Radix(arr, n, count);
            break;
        }
        case 11:
        {
            Comparisons_Flash(arr, n, count);
            break;
        }
	}

}

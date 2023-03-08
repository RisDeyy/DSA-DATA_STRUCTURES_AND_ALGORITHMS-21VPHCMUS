// #include "sort.h"

// //thuat toa sap xep: Selection Sort
// //thuat toan 
// void SelectionSort(int arr[], int n){
//     int i, j, min;

//     for (i = 0; i < n-1; i++)
//     {
//         min = i;
//         for (j = i+1; j < n; j++)
//         if (arr[j] < arr[min])
//             min = j;
//         if (min!=i)
//             Swap(&arr[min], &arr[i]);
//     } 
// }

// //dem phep so sanh cua selection sort
// void Comparisons_Select(int arr[], int n, unsigned long long &count){
//     int i, j, min;

//     for (i = 0; ++ count && i < n-1; i++)
//     {
//         min = i;
//         for (j = i+1;++ count && j < n; j++)
//         if (++count && arr[j] < arr[min])
//             min = j;
//         if (++count && min!=i)
//             Swap(&arr[min], &arr[i]);
//     } cout << "Number of Comparisons for Selection Sort: "<< count << endl;
// }

// //Thuat toan sap xep: Intersert sort
// //thuat toan
// void InsertionSort(int arr[], int n){
//     int i, key, j;
    
//     for (i = 1; i < n; i++){
//         key = arr[i];
//         j = i - 1;
 
//         while (j >= 0 && arr[j] > key){
//             arr[j + 1] = arr[j];
//             j = j - 1;
//         }
//         arr[j + 1] = key;
//     }
// }

// //dem phep so sanh trong thuat toan
// void Comparisons_Insert(int arr[], int n, unsigned long long &count){
//     int i, key, j;
    
//     for (i = 1; ++count && i < n; i++){
//         key = arr[i];
//         j = i - 1;
 
//         while ((++ count && j >= 0) && (++ count && arr[j] > key)){
//             arr[j + 1] = arr[j];
//             j = j - 1;
//         }
//         arr[j + 1] = key;
//     }
// } 

// //Thuat toan sap xep: Bubble sort
// //thuat toan
// void BubbleSort(int arr[], int n){
//     int i, j;
//     for (i = 0; i < n - 1; i++)
//         for (j = 0; j < n - i - 1; j++)
//             if (arr[j] > arr[j + 1])
//                 Swap(&arr[j], &arr[j + 1]);
// }

// //dem so phep so sanh cua thuat toan
// void Comparisons_Bubble(int arr[], int n, unsigned long long &count){
//     int i, j;
//     for (i = 0; ++ count && i < n - 1; i++)
//         for (j = 0; ++ count && j < n - i - 1; j++)
//             if (++ count && arr[j] > arr[j + 1])
//                 Swap(&arr[j], &arr[j + 1]);
// }

// //thuat toan sap xep: Shaker sort
// //thuat toan
// void ShakerSort(int arr[], int n){
// 	int left = 0;
// 	int right = n - 1;
// 	int k = 0;
//     int i;
// 	while (left < right){
// 		for (i = left;i < right; i++){
// 			if (arr[i] > arr[i + 1]){
// 				Swap(&arr[i], &arr[i + 1]);
// 				k = i;
// 			}
// 		}
// 		right = k;
// 		for (i = right; i > left; i--){
// 			if (arr[i] < arr[i - 1]){
// 				Swap(&arr[i], &arr[i - 1]);
// 				k = i;
// 			}
// 		}
// 		left = k;
// 	}
// }

// //dem phep so sanh của Shaker sort
// void Comparisons_Shaker(int arr[], int n, unsigned long long &count){
//     int left = 0;
// 	int right = n - 1;
// 	int k = 0;
//     int i;
// 	while (++count && left < right){
// 		for (i = left; ++ count && i < right; i++){
// 			if (++ count && arr[i] > arr[i + 1]){
// 				Swap(&arr[i], &arr[i + 1]);
// 				k = i;
// 			}
// 		}
// 		right = k;
// 		for (i = right; ++ count && i > left; i--){
// 			if (++ count && arr[i] < arr[i - 1]){
// 				Swap(&arr[i], &arr[i - 1]);
// 				k = i;
// 			}
// 		}
// 		left = k;
// 	}
// }

// void ShellSort(int arr[], int n){
//     int inter, i, j, temp;
// 	for (inter = n / 2; inter > 0; inter /= 2){
// 		for (i = inter; i < n; i++){
// 			temp = arr[i];
// 			for (j = i; j >= inter && arr[j - inter] > temp; j -= inter){
// 				arr[j] = arr[j - inter];
// 			}
// 			arr[j] = temp;
// 		}
// 	}
// }

// void Comparisons_Shell(int arr[], int n, unsigned long long &count){
//     int inter, i, j, temp;
// 	for (inter = n / 2; ++ count && inter > 0; inter /= 2){
// 		for (i = inter; ++ count && i < n; i++){
// 			temp = arr[i];
// 			for (j = i; ++ count && j >= inter && ++ count && arr[j - inter] > temp; j -= inter){
// 				arr[j] = arr[j - inter];
// 			}
// 			arr[j] = temp;
// 		}
// 	}
// }

// //Thuat toan sap xep: heap sort
// //thuat toan
// void Heapify(int arr[], int n, int i){
//     int largest = i;
//     int left = 2 * i + 1;
//     int right = 2 * i + 2;
 
//     if (left < n && arr[left] > arr[largest])
//         largest = left;

//     if (right < n && arr[right] > arr[largest])
//         largest = right;
 
//     if (largest != i) {
 
//         Swap(&arr[i], &arr[largest]);
//         Heapify(arr, n, largest);
//     }
// }
 
// void HeapSort(int arr[], int n){
//     for (int i = n / 2 - 1; i >= 0; i--)
//         Heapify(arr, n, i);
 
//     for (int i = n - 1; i >= 0; i--) {
 
//         Swap(&arr[0], &arr[i]);
//         Heapify(arr, i, 0);
//     }
// }

// //dem so phep so sanh cua Heap sort
// void Comparisons_Heapify(int arr[], int n, int i, unsigned long long &count){
//     int largest = i;
//     int left = 2 * i + 1;
//     int right = 2 * i + 2;
 
//     if ((++ count && left < n) && (++count && arr[left] > arr[largest]))
//         largest = left;

//     if ((++ count && right < n) && (++ count && arr[right] > arr[largest]))
//         largest = right;
 
//     if (++ count && largest != i) {
 
//         Swap(&arr[i], &arr[largest]);
//         Comparisons_Heapify(arr, n, largest, count);
//     }
// }

// void Comparisons_Heap(int arr[], int n, unsigned long long &count){
//     for (int i = n / 2 - 1; ++ count && i >= 0; i--)
//         Comparisons_Heapify(arr, n, i, count);
 
//     for (int i = n - 1;++ count && i >= 0; i--) {
 
//         Swap(&arr[0], &arr[i]);
//         Comparisons_Heapify(arr, i, 0, count);
//     }
// }

// //thuat toan sap xep: Merge sort
// // thuat toan
// void Merge(int arr[], int const left, int const mid, int const right){
//     int const Sub_Arr1 = mid - left + 1;
//     int const Sub_Arr2 = right - mid;
 
//     int *left_Arr = new int[Sub_Arr1],
//         *right_Arr = new int[Sub_Arr2];
 
//     for (int i = 0; i < Sub_Arr1; i++)
//         left_Arr[i] = arr[left + i];
//     for (int j = 0; j < Sub_Arr2; j++)
//         right_Arr[j] = arr[mid + 1 + j];
 
//     int index_Arr1 = 0, index_Arr2 = 0; 
//     int index_MergedArr = left; 

//     while ( index_Arr1 < Sub_Arr1 && index_Arr2 < Sub_Arr2) {
//         if (left_Arr[index_Arr1] <= right_Arr[index_Arr2]) {
//             arr[index_MergedArr] = left_Arr[index_Arr1];
//             index_Arr1++;
//         }
//         else if (left_Arr[index_Arr1] > right_Arr[index_Arr2]) {
//             arr[index_MergedArr] = right_Arr[index_Arr2];
//             index_Arr2++;
//         }
//         index_MergedArr++;
//     }
//     while (index_Arr1 < Sub_Arr1) {
//         arr[index_MergedArr] = left_Arr[index_Arr1];
//         index_Arr1++;
//         index_MergedArr++;
//     }
//     while (index_Arr2 < Sub_Arr2) {
//         arr[index_MergedArr] = right_Arr[index_Arr2];
//         index_Arr2++;
//         index_MergedArr++;
//     }
//     delete[] left_Arr;
//     delete[] right_Arr;
// }

// void MergeSort(int arr[], int const start, int const end){
//     if (start >= end)
//         return; 
 
//     int mid = start + (end - start) / 2;
//     MergeSort(arr, start, mid);
//     MergeSort(arr, mid + 1, end);
//     Merge(arr, start, mid, end);
// }

// void CountComparisons_Merge(int arr[], int const left, int const mid, int const right, unsigned long long  &count){
//     int const Sub_Arr1 = mid - left + 1;
//     int const Sub_Arr2 = right - mid;
 
//     int *left_Arr = new int[Sub_Arr1],
//         *right_Arr = new int[Sub_Arr2];
 
//     for (int i = 0;++ count && i < Sub_Arr1; i++)
//         left_Arr[i] = arr[left + i];
//     for (int j = 0;++ count && j < Sub_Arr2; j++)
//         right_Arr[j] = arr[mid + 1 + j];
 
//     int index_Arr1 = 0, index_Arr2 = 0; 
//     int index_MergedArr = left; 

//     while ((++ count && index_Arr1 < Sub_Arr1) && (++ count && index_Arr2 < Sub_Arr2)) {
//         if (++ count && left_Arr[index_Arr1] <= right_Arr[index_Arr2]) {
//             arr[index_MergedArr] = left_Arr[index_Arr1];
//             index_Arr1++;
//         }
//         else if (++ count && left_Arr[index_Arr1] > right_Arr[index_Arr2]) {
//             arr[index_MergedArr] = right_Arr[index_Arr2];
//             index_Arr2++;
//         }
//         index_MergedArr++;
//     }
//     while (++ count && index_Arr1 < Sub_Arr1) {
//         arr[index_MergedArr] = left_Arr[index_Arr1];
//         index_Arr1++;
//         index_MergedArr++;
//     }
//     while (++ count && index_Arr2 < Sub_Arr2) {
//         arr[index_MergedArr] = right_Arr[index_Arr2];
//         index_Arr2++;
//         index_MergedArr++;
//     }
//     delete[] left_Arr;
//     delete[] right_Arr;
// }

// void CountComparisons_MergeSort(int arr[], int const start, int const end, unsigned long long  &count){
//     if (++ count && start >= end)
//         return; 
 
//     int mid = start + (end - start) / 2;
//     CountComparisons_MergeSort(arr, start, mid, count);
//     CountComparisons_MergeSort(arr, mid + 1, end, count);
//     CountComparisons_Merge(arr, start, mid, end, count);
// }

// //thuat toan sap xep: Quick sort
// //thuat toan 
// void QuickSort(int arr[], int start, int end){
//     int i = start;
// 	int j = end;
// 	int pivot = arr[(i + j) / 2];
// 	int temp;

// 	while (i <= j){
// 		while (arr[i] < pivot) 
//         i++;
// 		while (arr[j] > pivot) 
//         j--;
// 		if (i <= j){
// 			Swap(&arr[i], &arr[j]);
// 			i++;
// 			j--;
// 		}
// 	}
// 	if (j > start)
// 		QuickSort(arr, start, j);
// 	if (i < end)
// 		QuickSort(arr, i, end);
// }

// //dem so phep so sanh cua Quick sort
// void Comparisons_QuickSort(int arr[], int start, int end, unsigned long long &count){
//     int i = start;
// 	int j = end;
// 	int pivot = arr[(i + j) / 2];
// 	int temp;

// 	while (++ count && i <= j){
// 		while (++ count && arr[i] < pivot) 
//         i++;
// 		while (++ count && arr[j] > pivot) 
//         j--;
// 		if (++ count && i <= j){
// 			Swap(&arr[i], &arr[j]);
// 			i++;
// 			j--;
// 		}
// 	}
// 	if (++ count && j > start)
// 		QuickSort(arr, start, j);
// 	if (++ count && i < end)
//         QuickSort(arr, i, end);
// }

// //thuat toan sap xep: counting sort
// //thuat toan
// void CountingSort(int arr[], int n)
// {
//     int output[n]; 
//     int max = arr[0];
//     int min = arr[0];
 
//     int i;
//     for(i = 1; i < n; i++)
//     {
//         if(arr[i] > max)
//             max = arr[i]; 
//         else if(arr[i] < min)
//             min = arr[i]; 
//     }
 
//     int k = max - min + 1; 
//     int count_arr[k]; 
    
//     for(i=0; i<k; i++)
//         count_arr[i]=0;
 
//     for(i = 0; i < n; i++)
//         count_arr[arr[i] - min]++;
        
//     for(i = 1; i < k; i++)
//         count_arr[i] += count_arr[i - 1];
 
//     for(i = 0; i < n; i++)
//     {
//         output[count_arr[arr[i] - min] - 1] = arr[i];
//         count_arr[arr[i] - min]--;
//     }
 
//     for(i = 0; i < n; i++)
//         arr[i] = output[i]; 
// }

// //dem so phep so sanh trong thuat toan Couting sort
// void Comparisons_Counting(int arr[], int n, unsigned long long &count){
//     int output[n]; 
//     int max = arr[0];
//     int min = arr[0];
 
//     int i;
//     for(i = 1;++ count && i < n; i++)
//     {
//         if(++ count && arr[i] > max)
//             max = arr[i]; 
//         else if(++ count && arr[i] < min)
//             min = arr[i]; 
//     }
 
//     int k = max - min + 1; 
//     int count_arr[k]; 
    
//     for(i=0;++ count && i<k; i++)
//         count_arr[i]=0;
 
//     for(i = 0;++ count &&  i < n; i++)
//         count_arr[arr[i] - min]++;
        
//     for(i = 1;++ count && i < k; i++)
//         count_arr[i] += count_arr[i - 1];
 
//     for(i = 0;++ count && i < n; i++)
//     {
//         output[count_arr[arr[i] - min] - 1] = arr[i];
//         count_arr[arr[i] - min]--;
//     }
 
//     for(i = 0;++ count && i < n; i++)
//         arr[i] = output[i]; 
// }

// //thuat toan sap xep: radix sort
// //thuat toan 
// int getMax(int arr[], int n){
//     int max = arr[0];
//         for (int i = 1; i < n; i++)
//             if (arr[i] > max)
//                max = arr[i];
//             return max;
// }
 
// void countSort(int arr[], int n, int exp){
//     int output[n]; 
//     int i, count[10] = { 0 };
 
//     for (i = 0; i < n; i++)
//         count[(arr[i] / exp) % 10]++;
 
    
//     for (i = 1; i < 10; i++)
//         count[i] += count[i - 1];
          
//     for (i = n - 1; i >= 0; i--) {
//         output[count[(arr[i] / exp) % 10] - 1] = arr[i];
//         count[(arr[i] / exp) % 10]--;
//     }
 
  
//     for (i = 0; i < n; i++)
//         arr[i] = output[i];
// }
 
// void RadixSort(int arr[], int n){
//     int m = getMax(arr, n);
 
//     for (int exp = 1; m / exp > 0; exp *= 10)
//         countSort(arr, n, exp);
// }

// //dem phep so sanh trong Radix sort
// int Comparisons_getMax(int arr[], int n, unsigned long long &count){
//     int max = arr[0];
//         for (int i = 1;++ count && i < n; i++)
//             if (arr[i] > max)
//                max = arr[i];
//             return max;
// }
 
// void Comparisons_countSort(int arr[], int n, int exp, unsigned long long &count){
//     int output[n]; 
//     int i, countS[10] = { 0 };
 
//     for (i = 0;++ count && i < n; i++)
//         countS[(arr[i] / exp) % 10]++;
 
    
//     for (i = 1;++ count && i < 10; i++)
//         countS[i] += countS[i - 1];
          
//     for (i = n - 1;++ count && i >= 0; i--) {
//         output[countS[(arr[i] / exp) % 10] - 1] = arr[i];
//         countS[(arr[i] / exp) % 10]--;
//     }
 
//     for (i = 0;++ count && i < n; i++)
//         arr[i] = output[i];
// }
 
// void Comparisons_Radix(int arr[], int n, unsigned long long &count){
//     int m = Comparisons_getMax(arr, n, count);
 
//     for (int exp = 1; m / exp > 0; exp *= 10)
//         Comparisons_countSort(arr, n, exp, count);
// }

// //thuat toan sap xep: Flash sort
// //thaut toan
// void FlashSort(int arr[], int n) {
//     int min = arr[0]; 
// 	int max = 0;
// 	int m = int(0.45 * n);
// 	int* l = new int[n];

// 	int i1 = 0;
// 	while (i1 < m){
// 		l[i1] = 0; 
// 		i1++;
// 	}

// 	int i2 = 1;
// 	while (i2 < n){
// 		if (arr[i2] < min)
// 			min = arr[i2];
// 		if (arr[i2] > arr[max])
// 			max = i2;
// 		i2++;
// 	}

// 	if (arr[max] == min)
// 		return;
// 	double c1 = (double)(m - 1) / (arr[max] - min);

// 	int i3 = 0;
// 	while (i3 < n){
// 		int k = int(c1 * (arr[i3] - min));
// 		++l[k];
// 		i3++;
// 	}

// 	int i4 = 1;
// 	while (i4 < m){
// 		l[i4] += l[i4 - 1];
// 		i4++;
// 	}


// 	Swap(&arr[max], &arr[0]);
// 	int move = 0;
// 	int j = 0;
// 	int k = m - 1;
// 	int t = 0;
// 	int flash;

// 	while (move < n - 1){
// 		while (j > l[k] - 1){
// 			j++;
// 			k = int(c1 * (arr[j] - min));
// 		}
// 		flash = arr[j];
// 		if (k < 0) break;
// 		while (j != l[k]){
// 			k = int(c1 * (flash - min));
// 			int hold = arr[t = --l[k]];
// 			arr[t] = flash;
// 			flash = hold;
// 			++move;
// 		}
// 	}
// 	delete[] l;
// 	for (int i = 1; i < n; i++){
// 		int j = i - 1;
// 		int t = arr[i];
// 		while (t < arr[j] && j >= 0){
// 			arr[j + 1] = arr[j];
// 			j--;
// 		}
// 		arr[j + 1] = t;
// 	}
// }
 
// void Comparisons_Flash(int arr[], int n, unsigned long long &count){
//     int min = arr[0]; 
// 	int max = 0;
// 	int m = int(0.45 * n);
// 	int* l = new int[n];

// 	int i1 = 0;
// 	while (++ count && i1 < m){
// 		l[i1] = 0; 
// 		i1++;
// 	}

// 	int i2 = 1;
// 	while (++ count && i2 < n){
// 		if (++ count && arr[i2] < min)
// 			min = arr[i2];
// 		if (++ count && arr[i2] > arr[max])
// 			max = i2;
// 		i2++;
// 	}

// 	if (++ count && arr[max] == min)
// 		return;
// 	double c1 = (double)(m - 1) / (arr[max] - min);

// 	int i3 = 0;
// 	while (++ count && i3 < n){
// 		int k = int(c1 * (arr[i3] - min));
// 		++l[k];
// 		i3++;
// 	}

// 	int i4 = 1;
// 	while (++ count && i4 < m){
// 		l[i4] += l[i4 - 1];
// 		i4++;
// 	}


// 	Swap(&arr[max], &arr[0]);
// 	int move = 0;
// 	int j = 0;
// 	int k = m - 1;
// 	int t = 0;
// 	int flash;

// 	while (++ count && move < n - 1){
// 		while (++ count && j > l[k] - 1){
// 			j++;
// 			k = int(c1 * (arr[j] - min));
// 		}
// 		flash = arr[j];
// 		if (++ count && k < 0) break;
// 		while (++ count && j != l[k]){
// 			k = int(c1 * (flash - min));
// 			int hold = arr[t = --l[k]];
// 			arr[t] = flash;
// 			flash = hold;
// 			++move;
// 		}
// 	}
// 	delete[] l;
// 	for (int i = 1;++ count && i < n; i++){
// 		int j = i - 1;
// 		int t = arr[i];
// 		while ((++ count && t < arr[j]) && (++ count && j >= 0)){
// 			arr[j + 1] = arr[j];
// 			j--;
// 		}
// 		arr[j + 1] = t;
// 	}
// }

#include <iostream>
#include <math.h>

using namespace std;

int main(){
    //int *a;
    int n;
    cout << "Nhap vao day so phan tu muon tinh toan: ";
    cin >> n;
    cout << endl;
    //a = new int [n];

    int Tong = 0;
    for (int i = 1; i <= n ; i++){
        Tong += i;
    }

    cout << "Tong cua cac so nguyen tu 0 den n la: " << Tong << endl;

    system("pause");
    return 0;
}
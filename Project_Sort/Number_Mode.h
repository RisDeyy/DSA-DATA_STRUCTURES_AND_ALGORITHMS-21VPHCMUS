#include"Operatefile.h"

int CharSortToNum(const char *nameofsort);
int NumMode(int i, char* argv[]);
void PrintSortingMode(int SortMode);
void Sorting_runningTime(int arr[], int n, int SortMode);
void Counting_comparisons(int arr[], int n, int SortMode, unsigned long long& count);
void print(int arr[], int n);
int* Copyarr(int* a, int n);
void PrintCommand(int Output_Param, double runTime, unsigned long long count);
void PrintCommand4(double runTime1, double runTime2, unsigned long long& count1, unsigned long long& count2);

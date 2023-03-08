#include "command.h"

void Command1(int argc, char* argv[]){
	cout << "Algorithm: ";
	int SortMode = CharSortToNum(argv[2]);
	PrintSortingMode(SortMode); 
	cout << endl;
	int n = 0;
	n = ReadFileA(argv);
	cout << "Input file: " << argv[3] << endl;
	cout << "Input size: " << n << endl;

	int outputParam = 0; // 2 - both, 1 - time, 0 - comparison
	if (strcmp(argv[4], "-both") == 0) {
		outputParam = 2;
	}
	else {
		if (strcmp(argv[4], "-time") == 0) {
			outputParam = 1;
		}
		else {
			outputParam = 0;
		}
	}

	unsigned long long count = 0;

	int* arr1 = new int[n];
	int* arr2 = new int[n];
	GenerateData(arr1, n, outputParam);
    arr2 = Copyarr(arr1, n);
	ReadFileModeA(argv, arr1, n);
	clock_t start;
	double runTime;
	start = clock();
	Sorting_runningTime( arr1, n, SortMode );
    runTime= clock() - start;
	Counting_comparisons(arr2, n, SortMode, count);
	WriteFileOutput(arr1, n);
	PrintCommand(outputParam, runTime, count);
	delete[] arr1;
	delete[] arr2;
}


void Command2(int argc, char* argv[]){
	cout << "Algorithm: ";
	int SortMode = CharSortToNum(argv[2]);
	PrintSortingMode(SortMode); cout << endl;
	int n = 0;
	n = atoi(argv[3]);
	cout << "Input size: " << atoi(argv[3]) << endl;

	int OutputParam = 0;
	int data = 0;
	cout << "Input order: ";
	if (strcmp(argv[4], "-rand") == 0) {
		data = 0;
		cout << "Randomized data" << endl;
	}
	else {
		if (strcmp(argv[4], "-nsorted") == 0) {
			data = 1;
			cout << "Nearly sorted data" << endl;
		}
		else if (strcmp(argv[4], "-sorted") == 0) {
			data = 2;
			cout << "Sorted data" << endl;
		}
		else {
			data = 3;
			cout << "Reverse sorted data" << endl;
		} 

	}
	if (strcmp(argv[5], "-both") == 0) {
		OutputParam = 2;
	}
	else {
		if (strcmp(argv[5], "-time") == 0) {
			OutputParam = 1;
		}
		else {
			OutputParam = 0;
		}
	}

	unsigned long long count = 0;

	int* arr1 = new int[n];
	int* arr2 = new int[n];
	GenerateData(arr1, n, data);
	arr2 = Copyarr(arr1, n);
	float running_time = 0;
	
	clock_t start;
	double runTime;
	Counting_comparisons(arr1, n, SortMode, count);
	start = clock();
	Sorting_runningTime( arr2, n, SortMode );
    runTime= clock() - start;
	WriteFileOutput(arr1, n);
	PrintCommand(OutputParam, running_time, count);
	delete[] arr1;
	delete[] arr2;
}

void Command3(int argc, char* argv[]){
	cout << "Algorithm: ";
	int SortMode = CharSortToNum(argv[2]);
	PrintSortingMode(SortMode); cout << endl;
	int n = 0;
	n = atoi(argv[3]);
	cout << "Input size: " << atoi(argv[3]) << endl;

	int Output_Param = 0;
	if (strcmp(argv[4], "-time") == 0) {
		Output_Param = 1;
	}
	else if (strcmp(argv[4], "-comp") == 0) {
		Output_Param = 0;
	}
	else if (strcmp(argv[4], "-both") == 0){
		Output_Param = 2;
	}
    else{
        cout << "Argument error" << endl;
    }

	
	unsigned long long count = 0;
	
	cout << endl;
	for (int i = 0; i < 4; i++)
	{
	    int* arr1 = new int[n];
		int* arr2 = new int[n];
		GenerateData(arr1, n, i);
		arr2 = Copyarr(arr1, n);
		switch (i)
		{
			case 0:
			{
				cout << "Input order: Randomized data" << endl;
				Write_File(arr1, n, "input1.txt");
				break;
			}
			case 1:
			{
				cout << "Input order: Nearly sorted data" << endl;
				Write_File(arr1, n, "input2.txt");
				break;
			}
			case 2:
			{
				cout << "Input order: Sorted data" << endl;
				Write_File(arr1, n, "input3.txt");
				break;
			}
			case 3:
			{
				cout << "Input order: Reverse sorted data" << endl;
				Write_File(arr1, n, "input4.txt");
				break;
			}
		}
		double runTime = 0;
		clock_t start;
		start = clock();
		Sorting_runningTime( arr1, n, SortMode );
        runTime = clock()- start;
		Counting_comparisons(arr2, n, SortMode, count);
        PrintCommand(Output_Param, runTime, count);
		cout << endl;
		count = 0;
        runTime  = 0;
		delete[] arr1;
		delete[] arr2;
	}
}


void Command4(int argc, char* argv[]){
	cout << "Algorithm: ";

	int Mode1 = CharSortToNum(argv[2]);
	int Mode2 = CharSortToNum(argv[3]);
	PrintSortingMode(Mode1); cout << " | "; 
	PrintSortingMode(Mode2); cout << endl;

	int n = 0;
	n = ReadFileC(argv);
	cout << "Input file: " << argv[4] << endl;
	cout << "Input size: " << n << endl;
	unsigned long long count1 = 0, count2 = 0;

	int* arr1 = new int[n];
	int* arr2 = new int[n];
	int* arr3 = new int[n];
	int* arr4 = new int[n];
	ReadFileModeC(argv, arr1, n);
	arr2 = Copyarr(arr1, n);
	arr3 = Copyarr(arr1, n);
	arr4 = Copyarr(arr1, n);

	double runTime1, runTime2;
	count1 = 0; 
	count2 = 0;

	//sorting algorithms 2
	clock_t start;
	start = clock();
	Sorting_runningTime( arr1, n, Mode1);
    runTime1= clock()-start;
	Counting_comparisons(arr3, n, Mode1, count1);

	//sorting algorithms 2
	start = clock();
	Sorting_runningTime( arr2, n, Mode2);
    runTime2 = clock()- start;
	Counting_comparisons(arr4, n, Mode2, count2);
	PrintCommand4(runTime1, runTime2, count1, count2);
	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;
}

void Command5(int argc, char* argv[]){
	cout << "Algorithm: ";

	int Mode1 = CharSortToNum(argv[2]);
	int Mode2 = CharSortToNum(argv[3]);
	PrintSortingMode(Mode1); cout << " | "; 
	PrintSortingMode(Mode2); cout << endl;	

	int n = 0;
	n = atoi(argv[4]);
	cout << "Input size: " << atoi(argv[4]) << endl;
	int data = 0; // get data type
	cout << "Input order: ";
	if (strcmp(argv[5], "-rand") == 0) {
		data = 0;
		cout << "Randomized data" << endl;
	}
	else {
		if (strcmp(argv[5], "-nsorted") == 0) {
			data = 1;
			cout << "Nearly sorted data" << endl;
		}
		else if (strcmp(argv[5], "-sorted") == 0) {
			data = 2;
			cout << "Sorted data" << endl;
		}
		else {
			data = 3;
			cout << "Reverse sorted data" << endl;
		}
	}
	unsigned long long count1 = 0, count2 = 0;

	int* arr1 = new int[n];
	int* arr2 = new int[n];
	int* arr3 = new int[n];
	int* arr4 = new int[n];
	GenerateData(arr1, n, data);
	arr2 = Copyarr(arr1, n);
	arr3 = Copyarr(arr1, n);
	arr4 = Copyarr(arr1, n);


	double runTime1, runTime2;

	//sorting algorithms 1
	clock_t start;
	Sorting_runningTime( arr1, n, Mode1);
    runTime1 = clock() - start; 
	Counting_comparisons(arr3, n, Mode1, count1);

	//sorting algorithms 2
	start = clock();
	Sorting_runningTime( arr2, n, Mode2);
	runTime2 = clock() - start; 
	Counting_comparisons(arr4, n, Mode2, count2);
	PrintCommand4(runTime1, runTime2, count1, count2);
	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;
}
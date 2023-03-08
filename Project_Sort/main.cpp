#include "main.h"
#include "command.h"

void print(int *arr, int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << "\t";
}

int* Copyarr(int* a, int n)
{
	int* b = new int[n];
	for (int i = 0; i < n; i++) b[i] = a[i];
	return b;
}

void PrintCommand(int Output_Param, double runTime, unsigned long long count) {
	switch (Output_Param) {
		case 2: {
			cout << "----------------------------" << endl;
			cout << "Running time: " << runTime << " milli sec" << endl;
			cout << "Comparisons: " << count << endl;
			break;
		}
		case 1: {
			cout << "----------------------------" << endl;
			cout << "Running time: " << runTime << " milli sec" << endl;
			break;
		}
		case 0: {
			cout << "----------------------------" << endl;
			cout << "Comparisons: " << count << endl;
			break;
		}
	}
}

void PrintCommand4(double runTime1, double runTime2, unsigned long long& count1, unsigned long long& count2)
{
	cout << "-----------------------------------" << endl;
	cout << "Running time: " << runTime1 << " milli sec" << " | " << runTime2 << " milli sec" << endl;
	cout << "Comparisons: " << count1 << " | " << count2 << endl;
}



int main(int argc, char* argv[]){

	int ConvertMode = NumMode(argc, argv);
	if (ConvertMode == -1) {
		cout << " Error!" << endl;
		return 0;
	}
	if (strcmp(argv[1], "-a") == 0) {
		cout << "ALGORITHM MODE" << endl;
	}
	else {
		cout << "COMPARISONS MODE" << endl;
	}
	switch (ConvertMode){
			case 1:{
				Command1(argc, argv);
				break;
			}
			case 2:{
				Command2(argc, argv);;
				break;
			}
			case 3:{
				Command3(argc, argv);;
				break;
			}
			case 4:{
				Command4(argc, argv);;
				break;
			}
			case 5:{
				Command5(argc, argv);;
				break;
			}
		}
    return 0;
}
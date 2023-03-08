#include "sort.h"

int ReadFileA( char* filein[5]) {
	ifstream ifs(filein[5]);
	if (!ifs) 
	return -1;
	int n;
	ifs >> n;
	ifs.close();
	return n;
}

int ReadFileC(char* filein[5]) {
	ifstream ifs(filein[5]);
	if (!ifs) 
	return -1;
	int n;
	ifs >> n;
	ifs.close();
	return n;
}

void ReadFileModeA(char* filein[5], int* a, int n) {
	ifstream ifs(filein[5]);
	ifs >> n;
	int i = 0;
	while (!ifs.eof()) {
		ifs >> a[i];
		i++;
	}
	ifs.close();
}

void ReadFileModeC(char* filein[5], int* a, int n) {
	ifstream ifs(filein[5]);
	ifs >> n;
	int i = 0;
	while (!ifs.eof()) {
		ifs >> a[i];
		i++;
	}
	ifs.close();
}

void WriteFileOutput(int *arr, int n) {
	ofstream ofs("output.txt");
	ofs << n << endl;
	for (int i = 0; i < n; i++)
		ofs << arr[i] << " ";
	ofs.close();
}

void Write_File(int *arr, int n, char* fileName) {
	ofstream ofs(fileName);
	ofs << n << endl;
	for (int i = 0; i < n; i++)
		ofs << arr[i] << " ";
}

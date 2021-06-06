#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <chrono>
#include <fstream>
#include <string>
#include "SortAlgorithems.h"
#include "Quintuplet.h"
#include "SelectionSort.h"

using namespace std;
using namespace std::chrono;
void checkValidation(char c);
bool checkSize(int size);
double* createArray(int size, int index);
void checkInput(int size, int index);
void checkInputMatchTOSize(int size, int inputSize);
char* reallocation(char* string, int logSize, int phySize);
double measureTimeForInsertationSort(double* arr, int  size, int index);
double measureTimeForSelection(double* arr, int  size, int index);
double measureTimeForQuintupletSort(double* arr, int  size, int index);
double createMantisa(int counter, int resAfterPoint);
double MyPow(double constN, int counter);
int charToInt(char c, int x);

int main(void)
{
	double* arr;

	double valueAfterInsertationSort = 0 , valueAfterSelection = 0 , valueAfterQuintupletAlgorithm = 0 ;
	int size, index, indexForArr = 0;
	/////////////////////////////////////////////////
	cin >> size;
	checkSize(size); //check when to exit the system
	/////////////////////////////////////////////////
	cin >> index;
	/////////////////////////////////////////////////
	checkInput(size, index);
	arr = createArray(size, index);
	double* copyArray1 = new double[size]();
	double* copyArray2 = new double[size]();

	for (int i = 0; i < size; i++)
	{
		copyArray1[i] = arr[i];
		copyArray2[i] = arr[i];
	}
	/////////////////////////////////////////////////
	valueAfterInsertationSort = measureTimeForInsertationSort(arr , size , index);
	cout << fixed << "Insertion sort i'th element: " << setprecision(4) << valueAfterInsertationSort << endl;
	/////////////////////////////////////////////////
	valueAfterSelection = measureTimeForSelection(copyArray1 , size, index);
	cout << fixed << "Selection i'th element: " << setprecision(4) << valueAfterSelection << endl;
	/////////////////////////////////////////////////
	valueAfterQuintupletAlgorithm = measureTimeForQuintupletSort(copyArray2, size, index);
	//valueAfterQuintupletAlgorithm = Quintuplet(arr, size, index-1);
	cout << fixed << "Quintuplet Algorithm i'th element: " << setprecision(4) << valueAfterQuintupletAlgorithm << endl;

	delete[] arr;
	delete[] copyArray1;
	delete[] copyArray2;
}	

double measureTimeForInsertationSort(double* arr, int  size, int index)
{
	double valueAfterInsertationSort = 0;
	auto start = chrono::high_resolution_clock::now();
	// unsync the I/O of C and C++.
	ios_base::sync_with_stdio(false);
	
	auto end = chrono::high_resolution_clock::now();
	valueAfterInsertationSort =  Algorithem :: insertaionSort(arr, size, index);
		// Calculating total time taken by the program.
		double time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	ofstream myfile("Measure.txt"); // The name of the file
	myfile << "Time taken by function <Insertation-Sort> is : " << fixed
		<< time_taken << setprecision(9);
	myfile << " sec" << endl;
	myfile.close();
	return valueAfterInsertationSort;
}

double measureTimeForSelection(double* arr, int  size, int index)
{
	double valueAfterSelection = 0;
	auto start = chrono::high_resolution_clock::now();
	// unsync the I/O of C and C++.
	ios_base::sync_with_stdio(false);

	auto end = chrono::high_resolution_clock::now();
	valueAfterSelection = SelectionSort :: Selection(arr, 0, size - 1, index);
	// Calculating total time taken by the program.
	double time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	ofstream myfile("Measure.txt"); // The name of the file
	myfile << "Time taken by function <Selection> is : " << fixed
		<< time_taken << setprecision(9);
	myfile << " sec" << endl;
	myfile.close();
	return valueAfterSelection;
}

double measureTimeForQuintupletSort(double* arr, int  size, int index)
{
	double valueAfterQuintupletAlgorithm = 0;
	auto start = chrono::high_resolution_clock::now();
	// unsync the I/O of C and C++.
	ios_base::sync_with_stdio(false);

	auto end = chrono::high_resolution_clock::now();
	valueAfterQuintupletAlgorithm = QuintupletSort :: Quintuplet(arr, size, index -1);
	// Calculating total time taken by the program.
	double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	ofstream myfile("Measure.txt"); // The name of the file
	myfile << "Time taken by function <Quintuplet-Sort> is : " << fixed
		<< time_taken << setprecision(9);
	myfile << " sec" << endl;
	myfile.close();
	return valueAfterQuintupletAlgorithm;
}


double* createArray(int size, int index)
{
	double* arr;
	arr = new double[size]();
	cin.ignore();

	char c;
	int resBeforePoint, resAfterPoint, counter = 0;
	long int indexForArr = 0;
	double finalRES = 0;
	bool negative = false, point = false;
	c = getchar();
	checkValidation(c);
	while (c != '\n')
	{
		resBeforePoint = 0;
		resAfterPoint = 0;

		while (c != '.' && c != '\n')
		{
			if (c == '-')
			{
				negative = true;
				c = getchar();
				checkValidation(c);
			}
			resBeforePoint = charToInt(c, resBeforePoint);
			c = getchar();
			checkValidation(c);
		}
		if (c == '.')
		{
			point = true;
			c = getchar();
			checkValidation(c);
		}
		while (c != ' ' && c != '\n' && counter <= 4)
		{
			counter++;
			resAfterPoint = charToInt(c, resAfterPoint);
			c = getchar();
			checkValidation(c);
		}
		finalRES = createMantisa(counter, resAfterPoint) + resBeforePoint;
		if (point == false)
		{
			cout << "wrong input" << endl;
			exit(1);
		}
		if (negative)
		{
			finalRES = finalRES * (-1);
		}
		arr[indexForArr] = finalRES;
		indexForArr++;
		finalRES = 0;
		negative = false;
		point = false;
		counter = 0;
		if (c == ' ')
		{
			c = getchar();
			checkValidation(c);
		}
	}
	checkInputMatchTOSize(size, (indexForArr));
	cout << endl << endl;
	return arr;
}

double createMantisa(int counter, int resAfterPoint)
{
	double newNum = 0;
	return newNum = resAfterPoint * MyPow(0.1, counter);
}

double MyPow(double constN, int counter)
{
	for (int i = 1; i < counter; i++)
	{
		constN = 0.1 * constN;
	}
	return constN;
}

int charToInt(char c, int x)
{
	int newNum;
	newNum = c - '0';
	newNum = x * 10 + newNum;
	return newNum;
}

void checkInputMatchTOSize(int size , int inputSize)
{
	if (size != inputSize)
	{
		cout << "Invalide input : size is not match to the amount of numbers that were inserted." << endl;
		exit(1);
	}
}


void checkValidation(char c)
{
	if ((c > '9' || c < '0') && (c != ' ') && (c != '.') && (c != '\n') && (c != '-'))
	{
		cout << "wrong input" << endl;
		exit(1);
	}

}

bool checkSize(int size)
{
	if (size <= 0)
	{
		cout << "wrong input" << endl;
		exit(1);
	}
	return true;
}

void checkInput(int size, int index)
{
	if (index > size || !checkSize(index))
	{
		cout << "wrong input" << endl;
		exit(1);
	}
}

char* reallocation(char* string, int logSize, int phySize)
{
	char* newString = new char[phySize];
	int i;

	for (i = 0; i < min(logSize, phySize); i++)
	{
		newString[i] = string[i];
	}

	delete string;

	return newString;
}


/*
double* createArray(int size, int index)
{
	double* arr;
	arr = new double[size]();
	cin.ignore();
	int phSize = 10, logSize = 0 , counter =0 , indexForArr=0;
	char* string;
	char c;
	double finalRES = 0;
	bool point = false;
	c = getchar();
	checkValidation(c);
	while (c != '\n')
	{
		string = new char[10]();

		while (c != '.' && c != '\n')
		{
			if (logSize == phSize)
			{
				phSize *= 2;
				string = reallocation(string, logSize, phSize);
			}
			string[logSize] = c;
			logSize++;
			c = getchar();
			checkValidation(c);
		}
		if (c == '.')
		{
			point = true;
			if (logSize == phSize)
			{
				phSize *= 2;
				string = reallocation(string, logSize, phSize);
			}
			string[logSize] = c;
			logSize++;
			c = getchar();
			checkValidation(c);
		}
		while (c != ' ' && c != '\n' && counter <= 4)
		{
			counter++;
			if (logSize == phSize)
			{
				phSize *= 2;
				string = reallocation(string, logSize, phSize);
			}
			string[logSize] = c;
			logSize++;
			c = getchar();
			checkValidation(c);
		}
		if (point == false) //אם המספר הוא מספר שלם ללא נקודה.
		{
			cout << "wrong input" << endl;
			exit(1);
		}
		//finalRES =std :: stod(string);
		//finalRES = strtod(string, &(string+(size)));
		finalRES = atof(string);
		arr[indexForArr] = finalRES;
		indexForArr++;
		logSize = 0;
		phSize = 10;
		finalRES = 0;
		point = false;
		counter = 0;
		if (c == ' ')
		{
			c = getchar();
			checkValidation(c);
		}
		delete[] string;
	}
	return arr;
}
*/
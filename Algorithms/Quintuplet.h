#pragma once
#include <iostream>
#include <math.h>
#include "SelectionSort.h"

class QuintupletSort
{
public:
	QuintupletSort() {};
	~QuintupletSort() {};
public :
	double static Quintuplet(double* arr, int size, int index);

	int static returnIndex(double* arr, int size, double val);

	void static bubbleSort(double* arr, int size);

//	int static partition(double* arr, int left, int right);

//	void static swap(double& left, double& right);
};

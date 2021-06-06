#pragma once
#include <iostream>
#include <math.h>

class SelectionSort
{
public:
	SelectionSort() {};

	~SelectionSort() {};
public :
	double static Selection(double* arr, int left, int right, int idx);

	int static partition(double* arr, int left, int right);

	void static mySwap(double& left, double& right);
};
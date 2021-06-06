#include "SortAlgorithems.h"
using namespace std;

double Algorithem :: insertaionSort(double* arr, int size, int idx)
{
	cout << endl << endl;

	int val;
	double holder;
	for (int i = 1; i < size; i++)
	{
		holder = arr[i];
		val = i - 1;
		while (val >= 0 && arr[val] > holder)
		{
			arr[val +1] = arr[val];
			val--;
		}
		arr[val + 1] = holder; 	
	}
	cout << endl;
	return arr[idx-1];
}

/*double Selection(double* arr, int left, int right, int idx)
{
	int pivot = 0;
	int subArray = 0;
	pivot = partition(arr, left, right);
	subArray = pivot - left + 1;
	if (idx == subArray)
		return arr[pivot];

	if (idx < subArray)
		return Selection(arr, left, pivot - 1, idx);

	else
		return Selection(arr, pivot + 1, right, idx - subArray);
}

int partition(double* arr, int left, int right)
{
	int pivot = left;
	while (left < right)
	{

		if (arr[left] > arr[right])
		{
			swap(arr[left], arr[right]);
			if (pivot == left)
			{
				left++;
				pivot = right;
			}
			else
			{
				right--;
				pivot = left;
			}
		}
		else
		{
			if (pivot == left)
				right--;

			else
				left++;
		}
	}
	return pivot;
}
*/

//double Quintuplet(double* arr, int size, int index)
//{
//	double pivot = 0;
//	int pivotIdx = 0, k = 0;
//	int sizeArray = (size / 5);
//	if (size % 5 != 0)
//		sizeArray += 1;
//	double * arrayOfMiddles = new double[sizeArray]();
//	
//	if (size <= 5)
//	{
//		bubbleSort(arr, size);
//		return arr[index];
//	}
//	else
//	{
//		for (int i = 0, j = 0; i < size && j < sizeArray; i++, j++)
//		{
//			if ((j == sizeArray - 1) && (size % 5 != 0))
//			{
//				bubbleSort(arr + i, size % 5);
//				if (size % 5 == 1 || size % 5 == 2)
//					arrayOfMiddles[j] = arr[i];
//
//				else if (size % 5 == 3 || size % 5 == 4)
//					arrayOfMiddles[j] = arr[i + 1];
//			}
//			else {
//				bubbleSort(arr + i, 5);
//				arrayOfMiddles[j] = arr[i + 2];
//			}
//			
//			i += 4;
//		}
//		pivot = Quintuplet(arrayOfMiddles, sizeArray, sizeArray / 2);
//		pivotIdx = returnIndex(arr, size, pivot);
//		swap(arr[0], arr[pivotIdx]);
//		k = partition(arr, 0, size - 1) + 1; 
//		if (k > index)
//			return Quintuplet(arr, k - 1, index);
//
//		if (k < index)
//			return Quintuplet(arr + k, size-k , index-k);
//
//		if (k == index)
//			return arr[index];
//	}
//}
//int returnIndex(double* arr, int size , double val)
//{
//	for (int i = 0 ; i < size; i++)
//	{
//		if (arr[i] == val)
//			return i;
//	}
//}
//void  bubbleSort(double* arr, int size)
//{
//	for (int i = 0; i < size; i++)
//		for (int j = 0; j < size - 1; j++)
//			if (arr[j] > arr[j + 1])
//				swap(arr[j], arr[j + 1]);
//	return;
//}
//
//void swap(double& left, double& right)
//{
//	double temp = left;
//	left = right;
//	right = temp;
//}
//
//void printArr(double* arr, int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		cout << arr[i];
//		cout << '\n';
//	}
//}

#include  "Quintuplet.h"

double QuintupletSort :: Quintuplet(double* arr, int size, int index)
{
	double pivot = 0;
	int pivotIdx = 0, k = 0;
	int sizeArray = (size / 5);
	if (size % 5 != 0)
		sizeArray += 1;
	double* arrayOfMiddles = new double[sizeArray]();

	if (size <= 5)
	{
		bubbleSort(arr, size);
		return arr[index];
	}
	else
	{
		for (int i = 0, j = 0; i < size && j < sizeArray; i++, j++)
		{
			if ((j == sizeArray - 1) && (size % 5 != 0))
			{
				bubbleSort(arr + i, size % 5);
				if (size % 5 == 1 || size % 5 == 2)
					arrayOfMiddles[j] = arr[i];

				else if (size % 5 == 3 || size % 5 == 4)
					arrayOfMiddles[j] = arr[i + 1];
			}
			else {
				bubbleSort(arr + i, 5);
				arrayOfMiddles[j] = arr[i + 2];
			}

			i += 4;
		}
		pivot = Quintuplet(arrayOfMiddles, sizeArray, sizeArray / 2);
		pivotIdx = returnIndex(arr, size, pivot);
		SelectionSort::mySwap(arr[0], arr[pivotIdx]);
		k = SelectionSort::partition(arr, 0, size - 1) + 1;
		if (k > index)
			return Quintuplet(arr, k - 1, index);

		if (k < index)
			return Quintuplet(arr + k, size - k, index - k);

		if (k == index)
			return arr[index];
	}
}

void QuintupletSort :: bubbleSort(double* arr, int size)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size - 1; j++)
			if (arr[j] > arr[j + 1])
				SelectionSort::mySwap(arr[j], arr[j + 1]);
	return;
}

int QuintupletSort :: returnIndex(double* arr, int size, double val)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == val)
			return i;
	}
}

//int QuintupletSort :: partition(double* arr, int left, int right)
//{
//	int pivot = left;
//	while (left < right)
//	{
//
//		if (arr[left] > arr[right])
//		{
//			swap(arr[left], arr[right]);
//			if (pivot == left)
//			{
//				left++;
//				pivot = right;
//			}
//			else
//			{
//				right--;
//				pivot = left;
//			}
//		}
//		else
//		{
//			if (pivot == left)
//				right--;
//
//			else
//				left++;
//		}
//	}
//	return pivot;
//}
//
//void  QuintupletSort :: swap(double& left, double& right)
//{
//	double temp = left;
//	left = right;
//	right = temp;
//}
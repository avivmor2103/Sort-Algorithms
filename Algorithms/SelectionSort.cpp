#include "SelectionSort.h"

double SelectionSort :: Selection(double* arr, int left, int right, int idx)
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

int SelectionSort :: partition(double* arr, int left, int right)
{
	int pivot = left;
	while (left < right)
	{

		if (arr[left] > arr[right])
		{
			mySwap(arr[left], arr[right]);
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

void SelectionSort :: mySwap(double& left, double& right)
{
	double temp = left;
	left = right;
	right = temp;
}

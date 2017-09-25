// ACMICPC_2016_football
/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>


using namespace std;






void quickSort(int *arr, int left, int right) {
	int pivot, left_temp, right_temp;
	left_temp = left;
	right_temp = right;
	pivot = arr[left];
	while (left < right) {
		while (arr[right] >= pivot && (left < right)) {
			right--;
		}
		if (left != right) {
			arr[left] = arr[right];
		}
		while (arr[left] <= pivot && (left < right)) {
			left++;
		}
		if (left != right) {
			arr[right] = arr[left];
			right--;
		}
	}
	arr[left] = pivot;
	pivot = left;
	left = left_temp;
	right = right_temp;
	if (left < pivot) quickSort(arr, left, pivot - 1);
	if (right > pivot) quickSort(arr, pivot + 1, right);
}
int main(int argc, char** argv)
{
	
	int n;
	cin >> n;
	int * points = new int[n]();
	for (int i = 0; i < n; i++)
	{
		cin >> points[i];

	}

	quickSort(points, 0, n-1);
	for (int i = 0; i < n/2; i++)
	{
		int temp = 0;
		temp = points[i];
		points[i] = points[n-1 - i];
		points[n -1 - i] = temp;
	} // 내림차순 
	int index = 0;
	int canpoint = n - 1;
	int pp = 0;
	int Answer = 1;
	while (1)
	{
	
		if (index == n  )
		{
			if (pp > 0)
			{
				Answer = -1;
					break;
			}

			break;

		}

		if (points[index] <= canpoint + pp) // 가능한경우 
		{
			pp = canpoint + pp - points[index];
			index++;
			canpoint--;

		}
		else 
		{
			Answer = -1;
			break;

		}




	}
	printf("%d\n", Answer);

	return 0;//Your program should return 0 on normal termination.
}
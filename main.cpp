#include <iostream>
#include <climits>
using namespace std;

void recursionMaxandMin(int arr[], int small, int largest, int& min, int& max)
{

	if (small == largest)
	{
		if (max < arr[small]) max = arr[small];

		if (min > arr[largest]) min = arr[largest];

		return;
	}


	if (largest - small == 1)
	{
		if (arr[small] < arr[largest])
		{
			if (min > arr[small]) min = arr[small];

			if (max < arr[largest]) max = arr[largest];
		}
		else
		{
			if (min > arr[largest]) min = arr[largest];

			if (max < arr[small]) max = arr[small];
		}
		return;
	}

	int mid = (small + largest) / 2;

	recursionMaxandMin(arr, small, mid, min, max);

	recursionMaxandMin(arr, mid + 1, largest, min, max);
}

int main()
{
	int num;
	cout<<"Enter the number of elements for the array: ";
	cin>>num;
	int arr[num];
	for(int x = 0; x < num; x++) {
        cout<<"Enter element "<< x + 1<<": ";
        cin>>arr[x];
	}

	int max = INT_MIN, min = INT_MAX;

	recursionMaxandMin(arr, 0, num - 1, min, max);

	cout << "The minimum is " << min << " and maximum is " << max;

	return 0;
}

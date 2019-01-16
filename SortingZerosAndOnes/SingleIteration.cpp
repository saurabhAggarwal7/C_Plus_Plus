#include <iostream>

//Global:
using namespace std;

int main()
{
	int arr[] = {0, 0, 1, 1, 0, 1, 1, 1, 0};
	int length = sizeof(arr)/sizeof(arr[0]);
	int left_index = 0, right_index = length-1;
	int lower_bound = 0, upper_bound = 1;

	while (left_index < right_index)
	{
		//{ End to First: n-1 to 1 }
		while (arr[right_index] == upper_bound){
			right_index--;
		}

		//{ Move Forward: 1 to n-1 }
		while (arr[left_index] == lower_bound){
			left_index++;
		}

		//Correct Position:
		if (left_index < right_index)
		{
			arr[left_index] = lower_bound;
			arr[right_index] = upper_bound;

			left_index++;
			right_index--;
		}
	}

	for (int i = 0; i < length; i++) {
		cout<<arr[i];
	}

	getchar();
	return 0;
}

#include <iostream>

//Global:
using namespace std;

void swap(int *start, int *end)
{
	int temp = *start;
	*start = *end;
	*end = temp;
}

int main()
{
	int arr[] = {0, 1, 2, 2, 1, 1, 0, 0, 2, 2, 1, 1};
	int length = sizeof(arr)/sizeof(arr[0]);
	int left_index = 0, right_index = length-1;
	int lower_bound = 0, upper_bound = 2, middle_bound = 1;

	//can also take length-1 for resolving using backward counter
	int middle_index = 0; 

	while (middle_index <= right_index)
	{
		//Both lower and middle started with 0, so both move forwarded, middle will be handled again to resolve middle & lower
		if(arr[middle_index] == lower_bound)
		{
			swap(arr[left_index], arr[middle_index]);
			left_index++;
			middle_index++;
		}

		//Keep middle index ahead of left index then only it can be resolved, accelerate the middle point and overtake from left index 
		if(arr[middle_index] == middle_bound)
		{
			middle_index ++;
		}

		//apply brakes on middle and dont move forward to right index, dont change let it be there so that it is poised and middled and decrement right index
		if(arr[middle_index] == upper_bound)
		{
			swap(arr[middle_index], arr[right_index]);
			right_index --;
		}
	}

	for (int i = 0; i < length; i++) {
		cout<<arr[i];
	}

	getchar();
	return 0;
}

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	string start = "astonishieout";
	int start_index = 0;
	int count_index = 0;
	int max=0;
	int max_index =0;
	int arr[26];

	//all index value 0's:
	memset(arr, 0, sizeof(arr));

	for (int i = 0; i < start.size(); i++){
		if(start[i] == 'a' || start[i]== 'e' || start[i]== 'i' || start[i]== 'o' ||start[i]== 'u')
		{
			if(start_index == 0)
			{
				start_index = i;
			}
			count_index ++;
		}
		else
		{
			arr[start_index] = count_index;
			start_index = 0;
			count_index = 0;
		}
	}

	for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
		if(arr[i] > 0 && arr[i] > max)
		{
			max = arr[i];
			max_index = i;
		}
	}
	string maxSubstring = start.substr(max_index, arr[max_index]);
	cout<<maxSubstring;
	getchar();
	return 0;
}

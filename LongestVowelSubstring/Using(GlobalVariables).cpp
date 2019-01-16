#include <iostream>
#include <string>
#include <map>

//Global:
using namespace std;
int Start_Index = 0;
int Count_Index = 0;

int main()
{
	string start = "astonishieout";
	int start_index = 0;
	int count_index = 0;
	int max=0;
	int max_index =0;

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
			if(count_index > Count_Index)
			{
				Count_Index = count_index;
				Start_Index = start_index;
			}

			start_index = 0;
			count_index = 0;
		}
	}

	string maxSubstring = start.substr(Start_Index, Count_Index);
	cout<<maxSubstring;

	getchar();
	return 0;
}

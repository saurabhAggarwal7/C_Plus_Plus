
#include <iostream>
#include <string>
#include <map>
using namespace std;

string StringCompare_Frequency(string start, string end) {
	int benchmark_ascii = int('a');
	int dense_array[30];
	for (int i = 0; i < start.size(); i++){
		int index = int(start[i]) - benchmark_ascii;
		if(dense_array[index] > 0)
		{
			dense_array[index] += 1;
		}
		else
		dense_array[index] = 1;
	}
	for (int i = 0; i < end.size(); i++){
		int index = int(end[i]) - benchmark_ascii;
		if(dense_array[index] > 0)
		{
			dense_array[index] -= 1;
		}
		else
		dense_array[index] = 0;
	}
	for (int i = 0; i < sizeof(dense_array)/sizeof(dense_array[0]); i++){
		if(dense_array[i] > 0)
		{
			return "Not Equal";
		}
	}
	return "Equal";
}

int main() {
	string start = "somyaa";
	string end = "asomay";
	string result = StringCompare_Frequency(start, end);
	cout<<"Result"<<result;
	return 0;
}

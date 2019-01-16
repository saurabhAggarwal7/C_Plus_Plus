#include <iostream>
#include <string>
#include <map>
using namespace std;

string StringCompare_Anagrams(char *startArray, char *resultArray) {
	std::map<char,int> start_map;
	for (int i = 0; i < 6; i++) {
		char key = startArray[i];
		int key_Count = start_map.count(key);
		if(key_Count > 0){
			start_map[key] = key_Count;
		} else{
			start_map.insert ( std::pair<int,int>(key,key_Count));
		}
	}
	for (int i = 0; i < 6; i++) {
		char key = resultArray[i];
		int key_Count = start_map.count(key);
		if(key_Count > 0){
			int newValue = start_map[key] -1;
			start_map[key] = newValue;
			if(start_map[key] == -1)
			{
				start_map.erase(key);
			}
		} else{
			return "Not equal";
		}
	}
	if(start_map.size() > 0)
	{
		return "Not Equal";
	}
	else
	{
		return "equal";
	}

	return "Not equal";
}

int main() {
	char startArray[] = { 's', 'o', 'm', 'y', 'a', 'a' };
	char endArray[] = { 'a', 's', 'o', 'm', 'a', 'y' };
	string result = StringCompare_Anagrams(startArray, endArray);
	cout<<"Result"<<result;
	return 0;
}

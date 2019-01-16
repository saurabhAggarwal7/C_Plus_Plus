#include <iostream>
#include <string>
#include <map>
#include "list" 
#include <stdlib.h>
using namespace std;

void update_Groupedmap(string start, std::map<string, list<string>> &start_map) {

	//create dense array:
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

	//create symbol
	string symbol;
	for (int i = 0; i < sizeof(dense_array)/sizeof(dense_array[0]); i++){
		if(dense_array[i] > 0)
		{
			string charSymbol = std::to_string(i) + ":" + std::to_string(dense_array[i]) + '|';
			symbol += charSymbol;
		}
	}

	//update map by reference '&'
	int key_Count = start_map.count(symbol);
	if(key_Count > 0)
	{
		start_map[symbol].push_back(start);
	}
	else
	{
		list<string> lst;
		lst.push_back(start);
		start_map.insert (std::pair<string,list<string>>(symbol,lst));
	}
}

  string group_anagrams(list<string> inputLst) {
	std::map<string,list<string>> start_map;
	list<string>::iterator i;

	//update map by reference
	for(i = inputLst.begin(); i != inputLst.end(); ++i){
		update_Groupedmap(*i, start_map);
	}

	//Print: 
	for(map<string,list<string>>::iterator it = start_map.begin(); it != start_map.end(); ++it) {
		string grouped;
		for(i = it->second.begin(); i != it->second.end(); ++i){
			grouped = grouped + ' '+ *i;
		}
		cout<<"Group "<<grouped<<"\n";
	}
	return "";
}

int main() {

	//InputList
	list<string> inputLst;
	inputLst.push_back ("cat");
	inputLst.push_back ("pin");
	inputLst.push_back ("act");
	inputLst.push_back ("nip");
	inputLst.push_back ("tca");

	string result = group_anagrams(inputLst);
	cout<<result;
	getchar();
	return 0;
}

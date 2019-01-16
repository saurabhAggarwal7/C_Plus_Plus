#include <iostream>
#include <map>
using namespace std;

bool map_compare(std::map<int, int> &map1, std::map<int, int> &map2) {
	return map1.size() == map2.size()
		&& std::equal(map1.begin(), map1.end(),
		map2.begin());
}

int getMapIndexUsingValue(std::map<int, int> &start_map, int value)
{
	for(map<int,int>::iterator it = start_map.begin(); it != start_map.end(); ++it) {
		if(it->second == value)
		{
			return it->first;
		}
	}
}

int getIdxForCarSwapWhenEmptyIdxMatches_Map(std::map<int, int> &map1, std::map<int, int> &map2) {
	int posIndex = 0;
	for(int i=0;i<6; i++)
	{
		if(map1[i] != map2[i])
		{
			posIndex = i;
			break;
		}
	}
	return posIndex;
}

void swapCars(std::map<int, int> &map1, int a, int b) {
	int temp = map1[a];
	map1[a] = map1[b];
	map1[b] = temp;
}

int setParkingPosition(int *startArray, int *resultArray) {
	int stepsCount = 0;
	std::map<int,int> start_map;
	std::map<int,int> final_map;

	for (int i = 0; i < 6; i++) {
		start_map.insert ( std::pair<int,int>(i,startArray[i]) );
		final_map.insert ( std::pair<int,int>(i,resultArray[i]) );
	}

	while(!map_compare(start_map, final_map))
	{
		int emptyIdx = getMapIndexUsingValue(start_map, -999);
		int posToSwapWithEmptyIdx = emptyIdx;

		if(start_map[emptyIdx] == final_map[emptyIdx])
		{
			posToSwapWithEmptyIdx = getIdxForCarSwapWhenEmptyIdxMatches_Map(start_map, final_map);
			swapCars(start_map, emptyIdx, posToSwapWithEmptyIdx);
			emptyIdx = posToSwapWithEmptyIdx;
		}
		posToSwapWithEmptyIdx = getMapIndexUsingValue(start_map, final_map[emptyIdx]);
		swapCars(start_map, emptyIdx, posToSwapWithEmptyIdx);
		stepsCount++;
	}

	return stepsCount;
}

int main() {
	int startArray[] = { 1, -999, 2, 5, 3, 4 };
	int endArray[] = { 5, 1, -999, 4, 2, 3 };
	int steps = setParkingPosition(startArray, endArray);
	cout<<"Steps:";
	cout<<steps;
	return steps;
}

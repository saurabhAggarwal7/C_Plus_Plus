#include <iostream>
using namespace std;

bool checkIfCarsInReqPos(int *startArray, int *resultArray) {
	bool allCarsInReqPos = true;
	int arrayLength = 6;

	for(int i=0;i<arrayLength; i++)
	{
		if(allCarsInReqPos)
		{
			if(startArray[i] == resultArray[i])
			{
				allCarsInReqPos = true;
			}
			else
			{
				allCarsInReqPos = false;
			}
		}
	}

	return allCarsInReqPos;
}

//Function: array compared traversed and matched index return:
int getCurrentCarPosIdx(int *startArray, int carToSearch) {
	int carIdx = 0;
	int arrayLength = 6;

	for(int i=0;i<arrayLength;i++)
	{
		if(startArray[i] == carToSearch)
		{
			carIdx = i;
			break;
		}
	}

	return carIdx;
}

//Function to swap cars using temp 3rd variable:
void swapCars(int *startArray, int a, int b) {
	int temp = startArray[a];
	startArray[a] = startArray[b];
	startArray[b] = temp;
}

//Function: When empty index for both array matches get the car index now to swap with, we will also use this index as new empty index
int getIdxForCarSwapWhenEmptyIdxMatches(int *startArray, int *resultArray) {
	int arrayLength = 6;
	int posIndex = 0;

	for(int i=0;i<arrayLength; i++)
	{
		if(startArray[i] != resultArray[i])
		{
			//Mismatch btw the two pattern, note this index immidiately.
			posIndex = i;
			break;
		}
	}

	return posIndex;
}


//Main Driver Function 
int setParkingPosition(int *startArray, int *resultArray) {

	//steps passes count
	int stepsCount = 0;
	//max steps
	int maxSteps = 50;

	//Loop till an estimated max steps count
	for(int i=0;i<maxSteps;i++)
	{
		//check if start and end array have same pos values, else continue to swap cars.
		bool isCarPositioned = checkIfCarsInReqPos(startArray, resultArray);
		if(!isCarPositioned)
		{
			//empty index is -999 taken and get it's index in start array
			int emptyIdx = getCurrentCarPosIdx(startArray, -999);

			int posToSwapWithEmptyIdx = emptyIdx;

			//Case: if empty index matches for start and result array while swapping cars, then find which car to swap and get new empty index hereby:
			//If this Case is removed infinite loop every time it will give me same empty position
			if(startArray[emptyIdx] == resultArray[emptyIdx])
			{
				posToSwapWithEmptyIdx = getIdxForCarSwapWhenEmptyIdxMatches(startArray, resultArray);

				//swap empty index with this position now:
				swapCars(startArray, emptyIdx, posToSwapWithEmptyIdx);

				//NOTE: (IMP) Update this as new empty index:
				emptyIdx = posToSwapWithEmptyIdx;
			}

			//Get Position Index calculated to swap with empty index:
			posToSwapWithEmptyIdx = getCurrentCarPosIdx(startArray, resultArray[emptyIdx]);

			//Swap using temp variable:
			swapCars(startArray, emptyIdx, posToSwapWithEmptyIdx);

			//steps result count:
			stepsCount++;
		}
		else
		{
			//pattern matched!!!
			break;
		}

	}
	return stepsCount;
}

int main() {

	//Initialze Arrays:
	int startArray[] = { 1, -999, 2, 5, 3, 4 };
	int endArray[] = { 5, 1, -999, 4, 2, 3 };

	//Main Function:
	int steps = setParkingPosition(startArray, endArray);

	//Output:
	cout<<"Steps Number:";
	cout<<steps;

	return steps;
}

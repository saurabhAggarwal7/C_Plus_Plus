#include<iostream>
#include <vector>
#include <set>
#include <map>
#include<bits/stdc++.h> 
using namespace std;


// This function prints the first repeating element in arr[] 
void method(int arr[], int n) 
{ 
	vector<int> v;
	
	//insert vector
	
	//beginning push
	v.insert(v.begin(), 1);
	
	//push at index
	int index = 1;
	v.insert(v.begin() + index, 10);
	
	//push at back
	v.push_back(100);
	
	//accessing the vector
	int size = v.size();
	//Interating And Printing
	for(vector<int>::iterator it = v.begin(); it!= v.end(); it++)
	{
	    cout<<*it;
	}
	cout<<"\nsize"<<size;
} 

// Driver method to test above method 
int main() 
{ 
	int arr[] = {10, 5, 3, 4, 3, 5, 6}; 

	int n = sizeof(arr) / sizeof(arr[0]); 
	method(arr, n); 
} 
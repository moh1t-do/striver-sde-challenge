#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &A, int n){
	// Write your code here.
	unordered_map<int,int> ump;
	for(auto &ele: A)
	{
		if (ump.find(ele) != ump.end())
		return ele;
		else
		ump[ele]++;
	}
}

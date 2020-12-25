//For example, if t = ATGGTCGGT and p = GGT, 
//then the result of an algorithm that solves the P
//attern Matching problem would be positions 3 and 7.

#include<iostream>
#include<string>
#include<vector>
using namespace std;
typedef vector<int> myVec;

myVec patternMatching(string s, string s2)
{
	myVec pos;
	int n = s2.length();
	int m = s.length(); \
		string sub = "";
	for (int i = 0; i < m - n + 1; i++)
	{
		sub = s.substr(i, n);
		if (sub == s2)
		{
			pos.push_back(i+1);
		}
	}


	return pos;
}

int main()
{
	string t = "ATGGTCGGT";
	string p = "GGT";
	cout << "Searching " << t << " for pattern " << p << "..." << endl;

	myVec results = patternMatching(t,p);
	for (int i = 0; i < results.size(); i++)
		cout << results[i] << " ";
	cout << endl;

	cin.get();
	return 0;
}
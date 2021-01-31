////Solve the Manhattan Tourist Problem

////Determine optimal path from source to sink
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

void printContents(vector<vector<int>>a)
{
	for (int index = 0; index < a.size(); index++)
	{
		for (int i = 0; i < a[index].size(); i++)
			std::cout <<setw(3)<< a[index][i];
		std::cout << endl;
	}
}

int main()
{
	string v = "ATCTGAT";
	string w = "TGCATA";
	const int m = w.length();
	const int n = v.length();

	vector<vector<int>>table;
	vector<int>num;
	int match = 1;
	int gap = -1;
	int mismatch = -1;

	for (int index = 0; index < n + 1; index++)
	{
		for (int i = 0; i < m + 1; i++)
		{
			num.push_back(0);
		}
		table.push_back(num);
		num.clear();
	}
	
	int s;
	for (int index = 0; index <m+1; index++)
	{
		table[0][index] += index * gap;;
	}
	for (int index = 0; index < n + 1; index++)
	{
		table[index][0] += index* gap;
	}
	
	for (int index = 1; index < n + 1; index++)
	{
		for (int i = 1; i < m + 1; i++)
		{
			if (v[index-1]==w[i-1])//match
			{
				s = max(max(table[index - 1][i] + gap, table[index][i - 1] + gap), table[index - 1][i - 1] + match);
			}
			else//mismatch
			{
				s = max(max(table[index - 1][i] + gap, table[index][i - 1] + gap), table[index - 1][i - 1] + mismatch);
			}
			table[index][i] = s;
		}
	}
	printContents(table);

	int rowNum = 0;
	int colNum = 0;
	int Score = 0;
	while (rowNum<n||colNum<m)
	{
		int numVal = table[rowNum][colNum];
		//there are more columns than rows in this case
		if (rowNum < n && colNum < m)
		{
			int a = table[rowNum + 1][colNum];
			int b = table[rowNum][colNum + 1];
			int c = table[rowNum + 1][colNum + 1];
		}
		else if (rowNum == n)
		{

		}
		else if (colNum == m)
		{

		}
		
		
		int hottestCol = 0;
		int hottestRow = 0;
		bool moveRight=false;
		bool moveDown=false;

		for (int i = 0; i < m; i++)
		{
			if (numVal < table[rowNum][i])
			{
				//std::cout << "\tFound better column placement: " << i << endl;
				hottestCol = i;
				moveRight = true;
				break;
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (numVal < table[i][colNum])
			{
				//std::cout << "\tFound better row placement: " << i << endl;
				hottestRow = i;
				moveDown = true;
				break;
			}
		}
		if (rowNum == v.length() || colNum == w.length())
		{
			//std::cout << "Terminal" << endl;
			if (rowNum == n)
			{
				colNum++;
			}
			if (colNum == m)
			{
				rowNum++;
			}
		}
		else if (moveRight || moveDown)
		{
			//std::cout << "Flag" << endl;
			if (moveRight && moveDown)
			{
				if ((table[hottestRow][colNum])>(table[rowNum][hottestCol]))
				{
					rowNum++;
				
				}
				else if ((table[hottestRow][colNum]) < (table[rowNum][hottestCol]))
				{
					colNum++;
				
				}
				else
				{
					rowNum++;
					colNum++;
					
				}
			}
			else if (moveRight && !moveDown)
			{
				colNum++;
			}
			else if (!moveRight && moveDown)
			{
				rowNum++;
			}
			else
			{
				std::cout << "Move Error.\n";
			}
		}
		else
		{
			//std::cout << "No Flag" << endl;
			if (table[rowNum + 1][colNum] > table[rowNum][colNum + 1] && table[rowNum + 1][colNum] > table[rowNum + 1][colNum + 1])
			{
				rowNum++;
			
			}
			else if (table[rowNum][colNum + 1] > table[rowNum + 1][colNum] && table[rowNum][colNum + 1] > table[rowNum + 1][colNum + 1])
			{
				colNum++;
				
			}
			else
			{
				rowNum++;
				colNum++;
		
			
			}
		}
		std::cout << rowNum << "," << colNum <<"\t" << table[rowNum][colNum]<< endl;
		Score += table[rowNum][colNum];
		
	}
	std::cout <<"Score:"<< Score << endl;

	std::cin.get();
	return 0;
}

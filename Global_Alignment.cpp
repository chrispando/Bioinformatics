////Solve the Manhattan Tourist Problem

////Determine optimal path from source to sink
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

typedef vector<vector<int>> myVec;
typedef vector<vector<char>> path;
class LCS
{
private:
	string v;
	string w;
	int m;
	int n;
	myVec table;
	path p;
	vector<int>num;
	vector<char>c;
	int match = 1;
	int gap = -1;
	int mismatch = -1;

	template<class T>
	void printContents(vector<vector<T>>);
public:
	LCS(string v, string w)
	{
		this->v = v;
		this->w = w;
		m = w.length();
		n = v.length();
	}

	void generateTable();
	void longestPath();
};

template<class T>
void LCS::printContents(vector<vector<T>>a)
{
	for (int index = 0; index < a.size(); index++)
	{
		for (int i = 0; i < a[index].size(); i++)
			std::cout << setw(3) << a[index][i];
		std::cout << endl;
	}
}
void LCS::generateTable()
{
	for (int index = 0; index < n + 1; index++)
	{
		for (int i = 0; i < m + 1; i++)
		{
			num.push_back(0);
			c.push_back('.');
		}
		table.push_back(num);
		p.push_back(c);
		num.clear();
		c.clear();
	}

	int s;
	for (int index = 0; index < m + 1; index++)
	{
		table[0][index] += index * gap;;
	}
	for (int index = 0; index < n + 1; index++)
	{
		table[index][0] += index * gap;
	}

	for (int index = 1; index < n + 1; index++)
	{
		for (int i = 1; i < m + 1; i++)
		{
			if (v[index - 1] == w[i - 1])//match
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
}
void printLCS(path b, string v, int i, int j)
{
	if (i == 0 || j == 0)
	{
		return;
	}
	if (b[i][j] == '\\')
	{
		printLCS(b, v, i - 1, j - 1);
		cout << v[i-1] << endl;
	}
	else
	{
		if (b[i][j] == '|')
		{
			printLCS(b, v, i - 1, j);
		}
		else
			printLCS(b, v, i, j - 1);
	}
}
void LCS::longestPath()
{
	for (int i = 1; i < m +1; i++) 
	{
		for (int j = 1; j < n +1; j++) 
		{
			if (i == 0 || j == 0)
				p[i][j] = '.';

			else if (v[i - 1] == w[j - 1])
			{
				int s = max(max(table[i - 1][j], table[i][j - 1]), table[i - 1][j - 1]);
				p[i][j] = '\\';
			}
			
			else 
			{
				if (table[i - 1][j] > table[i][j - 1]) 
					p[i][j] ='|';  
				
				else 
				{
					table[i][j] = table[i][j - 1];
					p[i][j] ='-';  
				}
			}
		}
	}
	printLCS(p, v, n, m);
	printContents(p);
	
}

int main()
{
	string v = "CGATAAC";
	string w = "AACGTTAC";

	LCS longest(v, w);

	longest.generateTable();
	longest.longestPath();

	std::cin.get();
	return 0;
}

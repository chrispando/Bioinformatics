#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

typedef vector<vector<int>> table;
typedef vector<vector<char>> path;

//To change weights for matches, gaps, and mismatches, edit the variables in class LCS
class LCS
{
private:
	string v, w;
	int m, n;
	table t;
	path p;
	vector<int>num;
	vector<char>c;
	int match = 1;
	int gap = -1;
	int mismatch = -1;

	template<class T>
	void printVector(vector<vector<T>>);
public:
	LCS(string v, string w)
	{
		this->v = v;
		this->w = w;
		m = w.length();
		n = v.length();
	}

	void generateTable();
	void longestCommonSubsequence();
	void printLCS(path, string, int, int);

};

template<class T>
void LCS::printVector(vector<vector<T>>a)
{
	for (int index = 0; index < a.size(); index++)
	{
		for (int i = 0; i < a[index].size(); i++)
			cout << setw(3) << a[index][i];
		cout << endl;
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
		t.push_back(num);
		p.push_back(c);
		num.clear();
		c.clear();
	}

	int s;
	for (int index = 0; index < m + 1; index++)
		t[0][index] += index + gap;
	for (int index = 0; index < n + 1; index++)
		t[index][0] += index * gap;

	for (int index = 1; index < m + 1; index++)
	{
		for (int i = 1; i < m + 1; i++)
		{
			if (v[index - 1] == w[i - 1])//match
			{
				s = max(max(t[index - 1][i] + gap, t[index][i - 1] + gap), t[index - 1][i - 1] + match);
			}
			else//mismatch
			{
				s = max(max(t[index - 1][i] + gap, t[index][i - 1] + gap), t[index - 1][i - 1] + mismatch);
			}
			t[index][i] = s;
		}
	}
	printVector(t);
}
void LCS::longestCommonSubsequence()
{
	for (int index = 1; index < n + 1; index++)
	{
		for (int i = 1; i < m + 1; i++)
		{
			if (index == 0 || i == 0)
				p[index][i] == '.';
			else if (v[index-1] == w[i-1])
			{
				int s = max(max(t[index - 1][i], t[index][i - 1]), t[index - 1][i - 1]);
				p[index][i] = '\\';
			}
			else
			{
				int s = max(max(t[index - 1][i], t[index][i - 1]), t[index - 1][i - 1]);
				if (t[index - 1][i] > t[index][i - 1])
					p[index][i] = '|';

				else
				{
					t[index][i] = t[index][i - 1];
					p[index][i] = '-';
				}
			}
		}
	}
	printLCS(p, w, n, m);
	printVector(p);
}
void LCS::printLCS(path b, string v, int i, int j)
{
	if (i == 0 || j == 0)
	{
		return;
	}
	if (b[i][j] == '\\')
	{
		printLCS(b, v, i - 1, j - 1);
		cout << v[i - 1] << endl;
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

int main()
{
	string v = "ATGTTAT";
	string w = "ATGCTAC";

	LCS longest(v, w);

	longest.generateTable();
	longest.longestCommonSubsequence();

	std::cin.get();
	return 0;
}

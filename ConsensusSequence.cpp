#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;


char nucleotides[4] = { 'A','T','G','C' };



class Consensus
{
private:
	vector<string>sequences;
	vector<vector<int>>table;
	int maxScore;
	string motif;
public:
	void alignment(string fileName);
	void profile();
	void consensus();

};

void Consensus::alignment(string fileName)
{
	cout << "Alignment:\n";

	ifstream inputFile;
	try
	{
		inputFile.open(fileName);
	}
	catch (exception e)
	{
		cout << "File read error...\n";
		cout << "Enter a file name:";
		string name;
		cin >> name;
		alignment(name);

	}
	string s;
	while (inputFile >> s)
	{
		if (strchr(nucleotides, s[0]))//validate data
			sequences.push_back(s);
	}
	inputFile.close();

	for (unsigned int index = 0; index < sequences.size(); index++)
		cout << sequences[index] << endl;
}
void Consensus::profile()
{
	vector<int>v;
	int l = sequences[0].length();
	for (int index = 0; index < 4; index++)
	{
		for (int i = 0; i < l; i++)
		{
			v.push_back(0);
		}
		table.push_back(v);
		v.clear();
	}
	for (int index = 0; index < sequences.size(); index++)
	{
		for (int i = 0; i < l; i++)
		{
			if (sequences[index][i] == 'A')
				table[0][i]++;
			else if (sequences[index][i] == 'T')
				table[1][i]++;
			else if (sequences[index][i] == 'G')
				table[2][i]++;
			else if (sequences[index][i] == 'C')
				table[3][i]++;
		}
	}
	cout << "Profile Matrix:\n";
	for (int index = 0; index < 4; index++)
	{
		for (int i = 0; i < l; i++)
			cout << table[index][i];
		cout << endl;
	}

}
void Consensus::consensus()
{
	int maxNum;
	int maxLoc;

	for (int i = 0; i < sequences[0].length(); i++)
	{
		maxNum = 0;
		for (int index = 0; index < 4; index++)
		{
			if (table[index][i] > maxNum)
			{
				maxNum = table[index][i];
				maxLoc = index;
			}
		}
		motif += nucleotides[maxLoc];
		maxScore += maxNum;
	}
	cout << "Consensus Sequence:\n";
	cout << motif;
	cout << "\nScore:" << maxScore << endl;
}

int main()
{
	Consensus c;
	string filepath;
	cout << "Enter a filepath:\n";
	cin >> filepath;
	c.alignment(filepath);
	c.profile();
	c.consensus();


	return 0;
}

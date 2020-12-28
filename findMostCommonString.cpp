#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

typedef vector<string> myVec;

class MostCommonStringLinkedList
{
private:
	struct Node
	{
		string val;
		struct Node* next;
	};
	Node* head;

	myVec v;
public:
	MostCommonStringLinkedList()
	{
		head = nullptr;
	}

	void readFile(string);
	void initializeList(int);
	void nMostCommonStrings(int);
	void appendNode(string);
	void insertNode(string);
	void deleteKey(string);
	void displayList()const;
	string findMostCommonString();
};

void MostCommonStringLinkedList::readFile(string filename)
{
	ifstream inputFile;
	inputFile.open(filename);
	if (inputFile)
	{
		string s;

		while (inputFile >> s)
		{
			v.push_back(s);
			cout << s << endl;
		}

		inputFile.close();
	}
	else
	{
		cout << "File read error...\n";
		cout << "Enter a file name:";
		string name;
		cin >> name;
		readFile(name);
	}
	

	
	
}
void MostCommonStringLinkedList::initializeList(int l)
{
	cout << "Finding most common substring of length " << l << "..." << endl;

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].size() - l + 1; j++)
		{
			string s2 = v[i].substr(j, l);
			insertNode(s2);
		}
	}
}
void MostCommonStringLinkedList::nMostCommonStrings(int l)
{
	for (int i = 0; i < l; i++)
	{
		string s3 = findMostCommonString();
		cout << s3 << endl;
		deleteKey(s3);
	}
}
void MostCommonStringLinkedList::appendNode(string val)
{
	Node* newNode;
	Node* nodePtr;

	newNode = new Node;
	newNode->val = val;
	newNode->next = nullptr;

	if (!head)
		head = newNode;
	else
	{
		nodePtr = head;
		while (nodePtr->next)
			nodePtr = nodePtr->next;
		nodePtr->next = newNode;
	}
}
void MostCommonStringLinkedList::insertNode(string val)
{
	Node* newNode;
	Node* nodePtr;
	Node* previousNode = nullptr;

	newNode = new Node;
	newNode->val = val;

	if (!head)
	{
		head = newNode;
		newNode->next = nullptr;
	}
	else
	{
		nodePtr = head;
		previousNode = nullptr;
		while (nodePtr != nullptr && nodePtr->val < val)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		if (previousNode == nullptr)
		{
			head = newNode;
			newNode->next = nodePtr;
		}
		else
		{
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
}
void MostCommonStringLinkedList::deleteKey(string val)
{
	// Store head node
	Node* tmp = head;

	while (head->val == val)
	{
		head = head->next;
	}
	while (tmp->next != NULL)
	{
		if (tmp->next->val == val)
		{
			tmp->next = tmp->next->next;
		}
		else
		{
			tmp = tmp->next;
		}
	}

}
void MostCommonStringLinkedList::displayList()const
{
	Node* nodePtr;
	nodePtr = head;
	while (nodePtr)
	{
		cout << nodePtr->val << endl;
		nodePtr = nodePtr->next;
	}
}
string MostCommonStringLinkedList::findMostCommonString()
{
	int len = 0;
	int maxLen = 0;
	string s;
	Node* nodePtr;
	nodePtr = head;
	if (nodePtr == nullptr)
	{
		cout << "List is empty...\n";
		return "";
	}
	else
	{
		while (nodePtr->next != nullptr)
		{
			if (nodePtr->val == nodePtr->next->val)
			{
				len++;
				nodePtr = nodePtr->next;
			}
			else if (nodePtr->val != nodePtr->next->val)
			{
				if (len >= maxLen)
				{
					maxLen = len;
					s = nodePtr->val;
					len = 0;
					nodePtr = nodePtr->next;
				}
				else if (len < maxLen)
				{
					len = 0;
					nodePtr = nodePtr->next;
				}
			}
		}
	}
	return s;
}

int main()
{
	MostCommonStringLinkedList m;
	string filename;
	int l;
	cout << "Enter file name:";
	cin >> filename;
	m.readFile(filename);

	cout << "Find most common string of length:";
	cin >> l;
		
	m.initializeList(l);
		
	//cout << "Displaying list...\n";
	//m.displayList();

	cout << "5 most common strings:" << endl;
	m.nMostCommonStrings(5);

	return 0;
}

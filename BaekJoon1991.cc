#include <iostream>
#include <vector>

using namespace std;

void preorder(vector<pair<char, char>> list[], char now);
void inorder(vector<pair<char, char>> list[], char now);
void postorder(vector<pair<char, char>> list[], char now);

int main()
{
	int size;
	vector<pair<char, char>> list[30];

	cin >> size;

	for (int i = 0; i < size; i++)
	{
		char root, left, right;
		cin >> root >> left >> right;

		list[root - 'A'].push_back(make_pair(left, right));
	}
	preorder(list, 'A');
	cout << endl;
	inorder(list, 'A');
	cout << endl;
	postorder(list, 'A');
}

void preorder(vector<pair<char, char>> list[], char now)
{
	//전위

	cout << now;

	if (list[now - 'A'].front().first != '.')
	{
		preorder(list, list[now - 'A'].front().first);
	}
	if (list[now - 'A'].front().second != '.')
	{
		preorder(list, list[now - 'A'].front().second);
	}
}

void inorder(vector<pair<char, char>> list[], char now)
{
	//중위
	if (list[now - 'A'].front().first != '.')
	{
		inorder(list, list[now - 'A'].front().first);
	}
	cout << now;
	if (list[now - 'A'].front().second != '.')
	{
		inorder(list, list[now - 'A'].front().second);
	}
}

void postorder(vector<pair<char, char>> list[], char now)
{
	//후위

	if (list[now - 'A'].front().first != '.')
	{
		postorder(list, list[now - 'A'].front().first);
	}
	if (list[now - 'A'].front().second != '.')
	{
		postorder(list, list[now - 'A'].front().second);
	}
	cout << now;
}
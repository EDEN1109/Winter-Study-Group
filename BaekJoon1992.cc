#include <iostream>

using namespace std;

void findAnswer(int sx, int sy, int size);

char map[64][64];

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	}

	findAnswer(0, 0, n);

	return 0;
}

void findAnswer(int sx, int sy, int size)
{
	char first = map[sx][sy];

	for (int i = sx; i < sx + size; i++)
	{
		for (int j = sy; j < sy + size; j++)
			if (map[i][j] != first)
			{
				cout << "(";
				findAnswer(sx, sy, size / 2);
				findAnswer(sx, sy + size / 2, size / 2);
				findAnswer(sx + size / 2, sy, size / 2);
				findAnswer(sx + size / 2, sy + size / 2, size / 2);
				cout << ")";
				return;
			}
	}
	cout << first;
}
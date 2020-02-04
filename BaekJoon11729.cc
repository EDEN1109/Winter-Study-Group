#include <iostream>
#include <vector>
#include <string>

using namespace std;

void findAnswer(int size, string first, string second, string third);

vector<string> answer;
int c = 0;

int main() {
	int num;

	cin >> num;
	findAnswer(num, "1", "2", "3");
	cout << c << endl;

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << endl;
	}

	return 0;
}

void findAnswer(int size, string first, string second, string third)
{
	c += 1;
	if (size == 1)
	{
		answer.push_back(first + " " + third);
	}
	else
	{
		findAnswer(size - 1, first, third, second);
		answer.push_back(first + " " + third);
		findAnswer(size - 1, second, first, third);
	}
}
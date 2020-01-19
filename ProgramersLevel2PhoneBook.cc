#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, int> makeMap(unordered_map<string, int> m, vector<string> p)
{
	for (int i = 0; i < p.size(); i++)
	{
		m.insert(make_pair(p[i], i));
	}

	return m;
}

bool findAnswer(unordered_map<string, int> m, vector<string> p)
{
	for (int i = 0; i < p.size(); i++)
	{
		for (int j = 0; j < p[i].size() - 1; j++)
		{
			string num = p[i].substr(0, j + 1);
			if (m.find(num) != m.end())
			{
				return false;
			}
		}
	}
	return true;
}

bool solution(vector<string> phone_book) {
	bool answer = true;
	unordered_map<string, int> phmap;

	phmap = makeMap(phmap, phone_book);
	answer = findAnswer(phmap, phone_book);

	return answer;
}
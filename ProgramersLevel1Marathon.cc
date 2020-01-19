#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

unordered_map<string, int> makeMap(unordered_map<string, int> m, vector<string> c)
{
	for (int i = 0; i < c.size(); i++)
	{
		m.insert(make_pair(c[i], ++m[c[i]]));
	}

	return m;
}

string findAnswer(unordered_map<string, int> cm, unordered_map<string, int> pm, vector<string> p)
{
	for (int i = 0; i < p.size(); i++)
	{
		if (cm[p[i]] != pm[p[i]])
			return p[i];
	}
	return "NoAnswer";
}

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	unordered_map<string, int> comap;
	unordered_map<string, int> pamap;

	comap = makeMap(comap, completion);
	pamap = makeMap(pamap, participant);
	answer = findAnswer(comap, pamap, participant);
	return answer;
}
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

string findUID(string logs)
{
	int start = logs.find(" ") + 1;
	int end = logs.find(" ", start);

	return logs.substr(start, end - start);
}

string findNAME(string logs)
{
	return logs.substr(logs.find(" ", logs.find(" ") + 1) + 1);
}

vector<string> printEnterAndLeave(vector<string> record, unordered_map<string, string> nikname)
{
	vector<string> result;

	for (int i = 0; i < record.size(); i++)
	{
		if (record[i].find("Enter") == 0)
		{
			result.push_back(nikname.at(findUID(record[i])) + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.");
		}
		else if (record[i].find("Leave") == 0)
		{
			result.push_back(nikname.at(findUID(record[i])) + "´ÔÀÌ ³ª°¬½À´Ï´Ù.");
		}
	}
	/*
	for(int i = 0; i < result.size(); i++)
	{
		cout << result[i] << endl;
	}
	*/
	return result;
}

unordered_map<string, string> makeChange(vector<string> record)
{
	unordered_map<string, string> result;

	for (int i = 0; i < record.size(); i++)
	{
		if (record[i].find("Enter") == 0)
		{
			if (result.find(findUID(record[i])) == result.end())
				result.insert(make_pair(findUID(record[i]), findNAME(record[i])));
			else
				result.at(findUID(record[i])) = findNAME(record[i]);
		}
		else if (record[i].find("Change") == 0)
		{
			if (result.find(findUID(record[i])) != result.end())
				result.at(findUID(record[i])) = findNAME(record[i]);
		}
	}
	/*
	cout << "mymap contains:";
	for ( auto it = result.begin(); it != result.end(); ++it )
		cout << " " << it->first << ":" << it->second << endl;
	*/
	return result;
}

vector<string> solution(vector<string> record) {
	vector<string> answer;
	unordered_map<string, string> nikname;

	nikname = makeChange(record);
	answer = printEnterAndLeave(record, nikname);

	return answer;
}
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, double> findFailRate(int N, vector<int> stages)
{
	unordered_map<int, double> result;
	unordered_map<int, int> fail;

	for (int i = 1; i <= N; i++)
	{
		fail.insert(make_pair(i, 0));
	}

	for (int i = 0; i < stages.size(); i++)
	{
		fail[stages[i]] = fail[stages[i]] + 1;
	}

	int total = stages.size();

	for (int i = 1; i <= N; i++)
	{
		if (total <= 0)
			result.insert(make_pair(i, 0));
		else
		{
			result.insert(make_pair(i, fail[i] / (double)total));
			total = total - fail[i];
		}
		// cout << i << ":" << result[i] << endl;
	}
	return result;
}

vector<int> sortStages(unordered_map<int, double> failRate, int N)
{
	vector<int> result;

	for (int i = 1; i <= N; i++)
	{
		double max = -1;
		int stage = N;
		for (int j = 1; j <= N; j++)
		{
			if (failRate[j] > max)
			{
				stage = j;
				max = failRate[j];
			}
		}
		result.push_back(stage);
		failRate[stage] = -1;
		// cout << result[i-1] << ", ";
	}

	return result;
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	unordered_map<int, double> failRate;

	failRate = findFailRate(N, stages);
	answer = sortStages(failRate, N);

	return answer;
}
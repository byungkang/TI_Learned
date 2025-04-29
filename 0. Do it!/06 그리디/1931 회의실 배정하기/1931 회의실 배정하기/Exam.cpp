#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int,int> a, pair<int, int> b)
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}
	else
	{
		return a.second < b.second;
	}
}

// int alpha[100000][2] = { 0, };
int N;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;	

	vector<pair<int, int>> alpha;
	
	for (int i = 0; i < N; i++)
	{
		int start, end;
		cin >> start >> end;
		alpha.push_back(make_pair(start, end));
	}

	sort(alpha.begin(), alpha.end(), compare );

	int count = 0;
	int start_time = 0;
	int end_time = 0;
	
	for (int i = 0; i < N; i++)
	{
		if (alpha[i].first >= end_time)
		{
			start_time = alpha[i].first;
			end_time = alpha[i].second;
			count++;
		}
	}

	cout << count;
}

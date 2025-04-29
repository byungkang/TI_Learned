#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

vector<pair<int, int>> time_let;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;


	int start_t;
	int end_t;
	for (int i = 1; i <= N; i++)
	{
		cin >> start_t >> end_t;
		time_let.push_back(make_pair(start_t, end_t));
	}

	sort(time_let.begin(), time_let.end(), [](const pair<int, int>& a, const pair<int, int>& b)
	{
			if (a.second == b.second)
			{
				return a.first < b.first;
			}
			else
			{
				return a.second < b.second;
			}
	});

	int last_time = time_let[0].second;
	int count = 1;
	for (int i = 1; i < time_let.size(); i++)
	{
		if (time_let[i].first >= last_time)
		{
			last_time = time_let[i].second;
			count++;
		}
	}
	
	cout << count;
}
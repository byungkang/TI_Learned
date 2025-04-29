#include <iostream>
#include <queue>

using namespace std;

int N;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	
	priority_queue<int>positive;
	priority_queue<int,vector<int>,greater<int>>negative;
	
	int final_result = 0;
	int zero_count = 0;
	int temp;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		if (temp > 1)
		{
			positive.push(temp);
		}
		else if (temp < 0)
		{
			negative.push(temp);
		}
		else if (temp == 0)
		{
			zero_count++;
		}
		else 
		{
			final_result += temp;
		}
	}

	while (!positive.empty())
	{
		int sum = 0;
		sum += positive.top();
		positive.pop();
		if (positive.size() > 0)
		{
			sum = sum * positive.top();
			positive.pop();
		}
		final_result += sum;
	}

	while (!negative.empty())
	{
		int sum = 0;
		sum += negative.top();
		negative.pop();
		if (negative.size() > 0)
		{
			sum = sum * negative.top();
			negative.pop();
		}
		else
		{
			if (zero_count > 0)
			{
				sum = 0;
			}
		}
		final_result += sum;
	}


	cout << final_result;
}
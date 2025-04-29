#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int arr[1000001] = { 0, };
int f_result[1000001] = { 0, };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;

	cin >> N;

	stack<int> result;
	vector<int> final;

	int top_value = 0;
	int count = 0;
	int temp;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	
	for (int i = N; i >= 1; i--)
	{
		while (!result.empty() && result.top() <= arr[i])
		{
			result.pop();
		}

		if (result.empty())
		{
			f_result[i] = -1;
		}
		else
		{
			f_result[i] = result.top();
		}
		result.push(arr[i]);
	}

	for (int i = 1; i <= N; i++)
	{
		cout << f_result[i] << " ";
	}

}
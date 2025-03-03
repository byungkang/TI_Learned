#include<iostream>
#include<cmath>
#include <algorithm>

using namespace std;
int arr[20] = { 0, };
int temp[20] = { 0, };
bool position[20] = { 0, };
int N, S;
int result;


void dfs(int depth, int nowvalue, int finalvalue, int& result)
{
	if (depth == finalvalue)
	{
		int temp = 0;
		for (int j = 0; j < depth; j++)
		{
			temp += arr[j];
		}

		if (temp == S)
		{
			result++;
		}
		return;
	}
	for (int i = nowvalue; i < N; i++)
	{
		if (!position[i])
		{
			position[i] = true;
			arr[depth] = temp[i];
			dfs(depth + 1, i+1,finalvalue, result);
			position[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> S;

	for (int i = 0; i < N; i++)
	{
		cin >> temp[i];
	}
	result = 0;
	sort(temp, temp + N);

	for (int i = 1; i <= N; i++)
	{
		dfs(0, 0,i, result);
	}
	cout << result;
}
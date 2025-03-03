#include <iostream>

using namespace std;

int N;
int route[11][11] = { 0 };
int arr[11] = { 0 };
bool position[11] = { 0 };

void dfs(int depth, int &min)
{
	if (depth == N)
	{
		int temp_result = 0;
		for (int i = 0; i < depth; i++)
		{
			if (i == depth - 1 && route[arr[i]][arr[0]] != 0)
			{
				temp_result += route[arr[i]][arr[0]];
				continue;
			}
			else if (route[arr[i]][arr[i + 1]] != 0)
			{
				temp_result += route[arr[i]][arr[i + 1]];
			}
			else if (route[arr[i]][arr[i + 1]] == 0)
			{
				return;
			}
		}
		if (min > temp_result)
		{
			min = temp_result;
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (!position[i])
		{
			position[i] = true;
			arr[depth] = i;
			dfs(depth + 1, min);
			position[i] = false;
		}
	}

}


int main()
{
	cin >> N;
	int max_result = 0;
	for (int i = 1; i <= N; i++)
	{
		int max = 0;
		for (int j = 1; j <= N; j++)
		{	
			cin >> route[i][j];
			if (max < route[i][j])
			{
				max = route[i][j];
			}
		}
		max_result += max;
	}
	
	dfs(0, max_result);

	cout << max_result;
}
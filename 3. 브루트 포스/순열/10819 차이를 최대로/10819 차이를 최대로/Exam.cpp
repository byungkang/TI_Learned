#include <iostream>

using namespace std;

int arr[13] = { 0, };
int temp[13] = { 0, };
bool position[13] = { 0, };

int N;

void dfs(int count, int depth)
{
	if (depth == 6)
	{
		for (int i = 0; i < depth; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;		
	}

	for (int i = count; i <= N; i++)
	{
		if (!position[i])
		{
			position[i] = true;
			arr[depth] = temp[i];
			dfs(i+1,depth+1);
			position[i] = false;
		}
	}
}

int main()
{
	for (int i = 0; i < 3; i++)
	{
		cin >> N;
		if (N == 0)
		{
			return 0;
		}
		for (int j = 1; j <= N; j++)
		{
			cin >> temp[j];
		}
		dfs(1,0);
		memset(arr, 0, sizeof(int) * 13);
		memset(temp, 0, sizeof(int) * 13);
		memset(position, 0, sizeof(int) * 13);
	}		
}

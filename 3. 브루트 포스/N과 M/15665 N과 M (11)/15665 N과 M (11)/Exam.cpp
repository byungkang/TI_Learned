#include <iostream>
#include <algorithm>

using namespace std;

int N, M;

int arr[9] = { 0, };
int temp[9] = { 0, };
bool position[9] = { 0 };

void dfs(int depth)
{
	if (depth == M)
	{
		for (int i = 0; i < depth; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	int temps = 0;
	for (int i = 1; i <= N; i++)
	{
		if (!position[i] && temps != temp[i - 1])
		{
			arr[depth] = temp[i - 1];
			temps = temp[i - 1];
			dfs(depth + 1);
		}
	}
}


int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> temp[i];
	}
	sort(temp, temp + N);
	dfs(0);
}
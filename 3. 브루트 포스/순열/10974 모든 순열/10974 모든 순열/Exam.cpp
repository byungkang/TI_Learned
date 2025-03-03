#include <iostream>

using namespace std;

int arr[9] = { 0 };
bool position[9] = { 0, };

int n;

void dfs(int depth)
{
	if (depth == n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (!position[i])
		{
			position[i] = true;
			arr[depth] = i;
			dfs(depth + 1);
			position[i] = false;
		}
	}
}

int main()
{
	cin >> n;

	dfs(0);
}
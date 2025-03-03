#include <iostream>
#define MAX 9

using namespace std;

int n, m;
int arr[MAX] = { 0, };
bool visited[MAX] = { 0, };

void dfs(int number, int depth)
{
	if (depth == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = number; i <= n; i++)
	{
		if (!visited[i])
		{
			arr[depth] = i;
			dfs(i, depth + 1);
		}
	}

}
int main()
{
	cin >> n >> m;
	dfs(1,0);
}
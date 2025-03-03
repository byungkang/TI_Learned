#include <iostream>
#define MAX 9
using namespace std;

int M, N;

int arr[MAX] = { 0, };
bool visited[MAX] = { 0, };
int count = 1;
void dfs(int num, int cnt)
{
	if (cnt == N)
	{
		for (int i = 0; i < N; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}



	for (int i = num; i <= M; i++)
	{
		if (!visited[i] )
		{		
			arr[cnt] = i;
			visited[i] = true;
			dfs(i+1,cnt + 1);
			visited[i] = false;
		}

	}
}

int main()
{
	cin >> M >> N;
	dfs(1,0);
}
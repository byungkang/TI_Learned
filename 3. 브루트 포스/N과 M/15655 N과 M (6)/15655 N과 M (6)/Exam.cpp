#include <iostream>
#include <algorithm>

using namespace std;

int N, M;

int arr[9] = { 0, };
int temp[9] = { 0, };
bool position[9] = { 0 };

void dfs(int count,int depth)
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

	for (int i = count; i <= N; i++)
	{
		if (!position[i])
		{
			position[i] = true;
			arr[depth] = temp[i - 1];
			dfs(i+1,depth + 1);
			position[i] = false;
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
	dfs(1,0);

}
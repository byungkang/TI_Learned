#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> alpha;
bool position[1001] = { 0 };
void DFS(int input);

int main()
{
	int N, M;
	cin >> N >> M;
	alpha.resize(N + 1);

	for (int i = 0; i < M; i++)
	{
		int start, end;
		cin >> start >> end;
		alpha[start].push_back(end);
		alpha[end].push_back(start);
	}

	int final_count = 0;

	for (int i = 1; i <= N; i++)
	{
		if (!position[i])
		{
			final_count++;
			DFS(i);
		}
	}
	cout << final_count;

}

void DFS(int input)
{
	if (position[input])
	{
		return;
	}

	position[input] = true;

	for (int i : alpha[input])
	{
		if (!position[i])
		{
			DFS(i);
		}
	}
}
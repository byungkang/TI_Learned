#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> alpha;
bool position_d[1001] = { 0, };
bool position_b[1001] = { 0, };

void DFS(int index);
void BFS(int index);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, V;
	cin >> N >> M >> V;

	alpha.resize(N + 1);
	

	for (int i = 1; i <= M; i++)
	{
		int start, end;
		cin >> start >> end;
		alpha[start].push_back(end);
		alpha[end].push_back(start);
	}

	for (int i = 1; i <= N; i++)
	{
		sort(alpha[i].begin(), alpha[i].end());
	}

	DFS(V);
	cout << "\n";
	BFS(V);
	cout << "\n";
}

void DFS(int index)
{
	cout << index << " ";
	position_d[index] = true;

	for (int i : alpha[index])
	{
		if (!position_d[i])
		{
			DFS(i);
		}
	}

}

void BFS(int index)
{	
	queue <int> beta;
	beta.push(index);
	position_b[index] = true;
	
	int temp;

	while (!beta.empty())
	{
		temp = beta.front();
		cout << temp << " ";
		beta.pop();

		for (int i : alpha[temp])
		{
			if (!position_b[i])
			{
				beta.push(i);
				position_b[i] = true;
			}
		}
	}

}
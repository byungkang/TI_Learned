#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> A;
bool position[1001] = { 0, };
bool arrive = false;
void DFS(int node);
void BFS(int node);

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, Start;
	cin >> N >> M >> Start;
	A.resize(N + 1);

	for (int i = 0; i < M; i++)
	{
		int st, en;
		cin >> st >> en;
		A[st].push_back(en);
		A[en].push_back(st);
	}

	for (int i = 1; i <= N; i++)
	{
		sort(A[i].begin(), A[i].end());
	}

	DFS(Start);
	cout << "\n";
	fill(position, position + (N + 1), 0);
	BFS(Start);
	cout << "\n";
}

void DFS(int node)
{
	cout << node << " ";
	position[node] = true;

	for (int i : A[node])
	{
		if (!position[i])
		{
			DFS(i);
		}
	}
}

void BFS(int node)
{
	queue<int> myqueue;
	myqueue.push(node);
	position[node] = true;

	while (!myqueue.empty())
	{
		int now_node = myqueue.front();
		myqueue.pop();
		cout << now_node << " ";

		for (int i : A[now_node])
		{
			if (!position[i])
			{
				position[i] = true;
				myqueue.push(i);
			}55
		}
	}
}

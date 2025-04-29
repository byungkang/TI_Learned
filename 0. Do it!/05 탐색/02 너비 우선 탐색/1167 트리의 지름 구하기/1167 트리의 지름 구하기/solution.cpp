#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> edge;
vector<vector<edge>>A;

bool position[100001] = { 0, };
int m_distance[100001] = { 0, };
void BFS(int node);

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	A.resize(N + 1);

	for (int i = 0; i < N; i++)
	{
		int S;
		cin >> S;
		while (true)
		{
			int E, V;
			cin >> E;
			if (E == -1)
			{
				break;
			}
			cin >> V;
			A[S].push_back(edge(E, V));
		}
	}

	BFS(1);
	int Max = 1;

	for (int i = 2; i <= N; i++)
	{
		if (m_distance[Max] < m_distance[i])
		{
			Max = i;
		}
	}
	fill(m_distance, m_distance + N+1, 0);
	fill(position, position + N+1, 0);
	BFS(Max);
	sort(m_distance + 1, m_distance + N+1);
	cout << m_distance[N] << "\n";
}

void BFS(int node)
{
	queue<int> alpha;
	alpha.push(node);
	position[node] = true;

	while (!alpha.empty())
	{
		int now_node = alpha.front();
		alpha.pop();
		for (edge i : A[now_node])
		{
			if (!position[i.first])
			{
				position[i.first] = true;
				alpha.push(i.first);
				m_distance[i.first] = m_distance[now_node] + i.second;
			}
		}
	}
}
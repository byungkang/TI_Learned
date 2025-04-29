#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int>>> alpha;
bool position[100001] = { 0, };
int m_distance[100001] = { 0, };
void BFS(int node);

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int V;
	cin >> V;
	alpha.resize(V + 1);

	for (int i = 0; i < V; i++)
	{
		int temp;
		cin >> temp;
		while (true)
		{
			int start, dis;
			cin >> start;
			if (start == -1)
			{
				break;
			}
			cin >> dis;
			alpha[temp].push_back(make_pair(start, dis));
		}
	}

	BFS(1);
	int maxPos = 1;

	for (int i = 2; i <= V; i++)
	{
		if (m_distance[maxPos] < m_distance[i])
		{
			maxPos = i;
		}
	}

	fill(position + 1, position + (V+1),0);
	fill(m_distance + 1, m_distance + (V+1), 0);

	BFS(maxPos);

	sort(m_distance + 1, m_distance + (V + 1));

	cout << m_distance[V] << "\n";
}

void BFS(int node)
{
	queue<int>bfs;
	bfs.push(node);
	position[node] = true;

	while (!bfs.empty())
	{
		int temp = bfs.front();
		bfs.pop();
		for (pair<int, int>a : alpha[temp])
		{
			if (!position[a.first])
			{
				position[a.first] = true;
				bfs.push(a.first);
				m_distance[a.first] = m_distance[temp] + a.second;
			}
		}		
	}
}
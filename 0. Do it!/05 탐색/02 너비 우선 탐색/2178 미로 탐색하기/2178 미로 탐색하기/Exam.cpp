#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int A[101][101] = { 0, };
bool position[101][101] = { 0, };
int N, M;
void BFS(int i, int j);

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		string s;
		cin >> s;
		for (int j = 1; j <= M; j++)
		{
			A[i][j] = s[j-1] - '0';
		}
	}

	BFS(1, 1);
	cout << A[N][M];

}

void BFS(int i, int j)
{
	queue<pair<int, int>> myq;
	myq.push(make_pair(i, j));

	while (!myq.empty())
	{
		int now_p[2];
		now_p[0] = myq.front().first;
		now_p[1] = myq.front().second;
		myq.pop();
		position[i][j] = true;

		for (int k = 0; k < 4; k++)
		{
			int x = now_p[0] + dx[k];
			int y = now_p[1] + dy[k];

			if (x >= 1 && y >= 1 && x <= N && y <= M)
			{
				if (A[x][y] != 0 && !position[x][y])
				{
					position[x][y] = true;
					A[x][y] = A[now_p[0]][now_p[1]] + 1;
					myq.push(make_pair(x, y));
				}
			}
		}
	}
}
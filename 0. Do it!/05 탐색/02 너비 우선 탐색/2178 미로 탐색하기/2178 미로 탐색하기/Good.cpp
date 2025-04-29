#include <iostream>
#include <queue>

using namespace std;

bool position[101][101] = { 0, };
int beta[101][101] = { 0, };
int alpha_x[4] = { 1,-1,0,0 };
int alpha_y[4] = { 0,0,-1,1 };

void BFS(int start,int end);
int N, M;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		string s;
		cin >> s;
		for (int j = 1; j <= M; j++)
		{
			beta[i][j] = s[j-1] - '0';
		}
	}

	BFS(1, 1);
	cout << beta[N][M];
}

void BFS(int start, int end)
{
	queue<pair<int, int>> alpha;
	alpha.push(make_pair(start, end));
	position[start][end] = true;

	int temp_x;
	int temp_y;

	while (!alpha.empty())
	{
		temp_x = alpha.front().first;
		temp_y = alpha.front().second;
		alpha.pop();
		
		for (int i = 0; i < 4; i++)
		{
			if (temp_x + alpha_x[i] >= 1 && temp_y + alpha_y[i] >= 1 && temp_x + alpha_x[i] <= N && temp_y + alpha_y[i] <= M)
			{
				if (beta[temp_x + alpha_x[i]] [temp_y + alpha_y[i]] != 0 && !position[temp_x + alpha_x[i]][temp_y + alpha_y[i]])
				{
					beta[temp_x + alpha_x[i]][temp_y + alpha_y[i]] = beta[temp_x][temp_y] + 1;
					alpha.push(make_pair(temp_x + alpha_x[i], temp_y + alpha_y[i]));
					position[temp_x + alpha_x[i]][temp_y + alpha_y[i]] = true;
				}
				
			}
		}
	}

}
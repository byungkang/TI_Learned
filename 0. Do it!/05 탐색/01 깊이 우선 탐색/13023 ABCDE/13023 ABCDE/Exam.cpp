#include <iostream>
#include <vector>

using namespace std;

int N, M;

vector < vector<int>> alpha;
bool position[2001] = { 0, };

void DFS(int input_num, int jarisu, int& final);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	alpha.resize(N);

	for (int i = 0; i < M; i++)
	{
		int start, end;
		cin >> start >> end;
		alpha[start].push_back(end);
		alpha[end].push_back(start);
	}

	int final_result = 0;

	for (int i = 0; i < N; i++)
	{
		if (final_result == 0)
		{
			DFS(i, 1, final_result);
		}
		else
		{
			break;
		}
	}
	cout << final_result;
}

void DFS(int input_num, int jarisu, int& final)
{
	if (jarisu == 5)
	{
		final = 1;
		return;
	}
	position[input_num] = true;

	for (int i : alpha[input_num])
	{
		if (!position[i])
		{
			DFS(i, jarisu + 1, final);
		}
	}

	position[input_num] = false;
}
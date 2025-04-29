#include <iostream>
#include <vector>

using namespace std;

int N, M;

vector < vector<int>> alpha;
bool position[2001] = { 0, };
bool arrive = false;
void DFS(int input_num, int jarisu);

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

	for (int i = 0; i < N; i++)
	{
		DFS(i, 1);
		if (arrive)
		{
			break;
		}
	}

	if (arrive)
	{
		cout << 1 << "\n";
	}
	else
	{
		cout << 0 << "\n";
	}
}

void DFS(int input_num, int jarisu)
{
	if (jarisu == 5 || arrive)
	{
		arrive = true;
		return;
	}

	position[input_num] = true;

	for (int i : alpha[input_num])
	{
		if (!position[i])
		{
			DFS(i, jarisu + 1);
		}
	}

	position[input_num] = false;
}
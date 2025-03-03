#include <iostream>

using namespace std;

int arr[13] = { 0, };
int temp[13] = { 0, };
bool position[13] = { 0, };

int N;

void dfs(int count, int depth, int input)
{
	if (depth == 6)
	{
		for (int i = 0; i < depth; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = count; i <= input; i++)
	{
		if (!position[i])
		{
			position[i] = true;
			arr[depth] = temp[i];
			dfs(i + 1, depth + 1, input);
			position[i] = false;
		}
	}
}

int main()
{
	while (true)
	{
		int alpha;
		cin >> alpha;
		if (alpha == 0)
		{
			break;
		}
		for (int i = 1; i <= alpha; i++)
		{
			cin >> temp[i];
		}
		dfs(1, 0, alpha);
		while (alpha--)
		{
			temp[alpha+1] = 0;
			arr[alpha] = 0;
		}
		cout << "\n";
	}
}

#include <iostream>
#include <algorithm>

using namespace std;

char arr[16] = { 0 };
char temp[16] = { 0 };
bool position[16] = { 0 };

int L, C;


void dfs(int depth, int count)
{
	if (depth == L)
	{
		int alpha = 0;
		int beta = 0;
		for (int i = 0; i < L; i++)
		{
			if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
			{
				alpha++;
			}
			else
			{
				beta++;
			}
		}
		if (alpha >= 1 && beta >= 2)
		{
			for (int i = 0; i < L; i++)
			{
				cout << arr[i];
			}
			cout << "\n";

		}
		return;
	}

	for (int i = count; i <= C; i++)
	{
		if (!position[i])
		{
			position[i] = true;
			arr[depth] = temp[i];	
			dfs(depth + 1,i+1);
			position[i] = false;
		}
	}
}

int main()
{
	cin >> L >> C;

	for (int i = 1; i <= C; i++)
	{
		cin >> temp[i];
	}
	sort(temp, temp + C);
	dfs(0,1);
}
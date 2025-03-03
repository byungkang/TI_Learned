#include <iostream>

using namespace std;

int synergy[21][21] = { 0, };
bool position[21] = { 0, };
bool sum[21] = { 0, };
int team[21] = { 0, };
int N;


void teamselect(int count, int depth, int &final_result)
{
	if (N-1>= depth >= N / 2)
	{
		int value1 = 0;
		int value2 = 0;
		for (int i = 1; i <= N; i++)
		{
			if (position[i] == true)
			{
				for (int j = 1; j <= N; j++)
				{
					if (position[j] == true)
					{
						value1 += synergy[i][j];
					}
				}
			}
			else
			{
				for (int j = 1; j <= N; j++)
				{
					if (position[j] == false)
					{
						value2 += synergy[i][j];
					}
				}
			}
		}
		if (abs(value1 - value2) < final_result)
		{
			final_result = abs(value1 - value2);
		}

	}

	for (int i = count; i <= N; i++)
	{
		if (!position[i])
		{
			position[i] = true;
			teamselect(i+1, depth + 1, final_result);
			position[i] = false;
		}
	}
}




int main()
{
	cin >> N;

	int final_result = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> synergy[i][j];
			final_result += synergy[i][j];
		}
	}

	teamselect(1,0, final_result);

	cout << final_result;
}
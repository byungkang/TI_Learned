#include <iostream>

using namespace std;

int N;
int L;
int arr[100][100];

//경사로는 낮은 칸에 놓으며, L개의 연속된 칸에 경사로의 바닥이 모두 접해야 한다.
//낮은 칸과 높은 칸의 높이 차이는 1이어야 한다.
//경사로를 놓을 낮은 칸의 높이는 모두 같아야 하고, L개의 칸이 연속되어 있어야 한다.

//경사로를 놓은 곳에 또 경사로를 놓는 경우
//낮은 칸과 높은 칸의 높이 차이가 1이 아닌 경우
//낮은 지점의 칸의 높이가 모두 같지 않거나, L개가 연속되지 않은 경우
//경사로를 놓다가 범위를 벗어나는 경우

int find_row(int depth)
{
	int count = 0;
	bool sum_result = true;
	bool position[100] = { 0 };
	for (int i = 0; i < N-1; i++)
	{		
		if (arr[depth][i] == arr[depth][i + 1])
		{
			continue;
		}

		else if (arr[depth][i] - arr[depth][i + 1] == 1)
		{
			int start = i + 1;
			int end = start + L;
			if (end > N)
			{
				end = N;
			}
			int sum = 0;		
			for (int idx = start; idx < end; idx++)
			{
				if (position[idx] == 0)
				{
					sum += arr[depth][idx];
					position[idx] = 1;
				}				
			}
			if (sum == arr[depth][i+1] * L)
			{
				continue;
			}
			else
			{
				return false;
			}
		}

		else if (arr[depth][i] - arr[depth][i + 1] == -1)
		{
			int start = i;
			int end = start - L;
			if (end < 0)
			{
				end = -1;
			}
			int sum = 0;
			for (int idx = start; idx > end; idx--)
			{				
				if (position[idx] == 0)
				{
					sum += arr[depth][idx];
					position[idx] = 1;
				}
			}
			if (sum == arr[depth][i] * L)
			{
				continue;
			}
			else
			{
				return false;
			}
		}

		else
		{
			return false;
		}
	}

	return sum_result;
}

int find_col(int depth)
{
	int count = 0;
	bool sum_result = true;
	bool position[100] = { 0 };
	for (int i = 0; i < N - 1; i++)
	{
		if (arr[i][depth] == arr[i+1][depth])
		{
			continue;
		}

		else if (arr[i][depth] - arr[i + 1][depth] == 1)
		{
			int start = i + 1;
			int end = start + L;
			if (end > N)
			{
				end = N;
			}
			int sum = 0;
			for (int idx = start; idx < end; idx++)
			{
				if (position[idx] == 0)
				{
					sum += arr[idx][depth];
					position[idx] = 1;
				}
			}
			if (sum == arr[i+1][depth] * L)
			{
				continue;
			}
			else
			{
				return false;
			}
		}

		else if (arr[i][depth] - arr[i + 1][depth] == -1)
		{
			int start = i;
			int end = start - L;
			if (end < 0)
			{
				end = -1;
			}
			int sum = 0;
			for (int idx = start; idx > end; idx--)
			{
				if (position[idx] == 0)
				{
					sum += arr[idx][depth];
					position[idx] = 1;
				}
			}
			if (sum == arr[i][depth] * L)
			{
				continue;
			}
			else
			{
				return false;
			}
		}

		else
		{
			return false;
		}
	}

	return sum_result;
}


int main()
{
	cin >> N >> L;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}

	int result = 0;
	for (int i = 0; i < N; i++)
	{
		result += find_row(i);
		result +=  find_col(i);		
	}
	cout << result;
}
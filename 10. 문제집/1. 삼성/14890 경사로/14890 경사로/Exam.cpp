#include <iostream>

using namespace std;

int N;
int L;
int arr[100][100];

//���δ� ���� ĭ�� ������, L���� ���ӵ� ĭ�� ������ �ٴ��� ��� ���ؾ� �Ѵ�.
//���� ĭ�� ���� ĭ�� ���� ���̴� 1�̾�� �Ѵ�.
//���θ� ���� ���� ĭ�� ���̴� ��� ���ƾ� �ϰ�, L���� ĭ�� ���ӵǾ� �־�� �Ѵ�.

//���θ� ���� ���� �� ���θ� ���� ���
//���� ĭ�� ���� ĭ�� ���� ���̰� 1�� �ƴ� ���
//���� ������ ĭ�� ���̰� ��� ���� �ʰų�, L���� ���ӵ��� ���� ���
//���θ� ���ٰ� ������ ����� ���

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
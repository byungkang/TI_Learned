#include <iostream>

using namespace std;

int N;
string board[20];

int makeMinTail(int row)
{
	int ret = 0;

	// �� ���� �������� ���� ���θ� tail ������ �ּҰ� �ǵ��� ���Ѵ�.
	for (int j = 0; j < N; j++)
	{
		int headCnt = 0;

		for (int i = 0; i < N; i++)
		{
			bool head = board[i][j] == 'H';
			if ((row & (1 << i)) != 0)
			{
				head = !head;
			}				
			if (head)
			{
				headCnt++;
			}
		}
		ret += min(headCnt, N - headCnt);
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> board[i];
	}

	int ans = 987654321;
	
	for (int i = 0; i < (1 << N); i++)
	{
		ans = min(ans, makeMinTail(i));
	}

	cout << ans;

	return 0;
}
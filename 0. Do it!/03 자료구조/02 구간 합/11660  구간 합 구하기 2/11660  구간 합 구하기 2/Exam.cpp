#include <iostream>
using namespace std;

int arr[1025][1025] = { 0, };
int temp[1025][1025] = { 0, };
int N, M;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= N; i++)
	{
		temp[1][i] = arr[1][i] + temp[1][i - 1];
		temp[i][1] = arr[i][1] + temp[i - 1][1];
	}

	for (int i = 2; i <= N; i++)
	{
		for (int j = 2; j <= N; j++)
		{
			temp[i][j] = temp[i - 1][j] + temp[i][j - 1] - temp[i - 1][j - 1] + arr[i][j];
		}
	}

	for (int i = 0; i < M; i++)
	{
		int start_x, start_y, end_x, end_y;
		cin >> start_x >> start_y >> end_x >> end_y;

		cout << temp[end_x][end_y] - temp[start_x - 1][end_y] - temp[end_x][start_y - 1] + temp[start_x - 1][start_y - 1] << "\n";
	}
	
	
}
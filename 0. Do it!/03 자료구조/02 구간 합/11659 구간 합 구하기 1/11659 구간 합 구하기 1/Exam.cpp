#include <iostream>

using namespace std;

int N, M;

int arr[100001] = { 0, };
int temp[100002] = { 0 };

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	temp[0] = 0;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		temp[i] = arr[i] + temp[i - 1];
	}



	for (int i = 0; i < M; i++)
	{
		int start, end;
		cin >> start >> end;
		cout << temp[end] - temp[start-1] << "\n";
	}
}
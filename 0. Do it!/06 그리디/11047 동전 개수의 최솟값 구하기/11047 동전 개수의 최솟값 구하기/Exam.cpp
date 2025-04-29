#include <iostream>
#include <algorithm>

using namespace std;

int arr[11] = { 0, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	int count = 0;

	for (int i = N; i >= 1; i--)
	{
		if (arr[i] <= K)
		{
			while (arr[i] <= K)
			{
				K -= arr[i];
				count++;
			}
		}
	}
	cout << count;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[10];

int N, M;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	int count = 0;
	int temp = N - 1;
	while (M != 0)
	{
		for (int i = temp; i >= 0; i--)
		{
			if (arr[i] <= M)
			{				
				M = M - arr[i];
				temp = i;
				count++;
				break;
			}
		}
	}
	cout << count;
}
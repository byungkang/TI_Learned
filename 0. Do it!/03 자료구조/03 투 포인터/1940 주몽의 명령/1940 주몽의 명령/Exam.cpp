#include <iostream>
#include <algorithm>

using namespace std;

int N, M;

int arr[15001] = { 0, };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}


	// 내가 작성한 코드 
	int count = 0;
	for (int i = 1; i <= N - 1; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			int sum = arr[i] + arr[j];
			if (sum == M)
			{
				count++;
			}
		}
	}
	cout << count;

	// 똘똘이 코드 
	int start_index = 1;
	int end_index = N;
	int count_n = 0;
	sort(arr + 1, arr + (N + 1));

	while (start_index < end_index)
	{
		int sum = arr[start_index] + arr[end_index];
		if (sum == M)
		{
			start_index++;
			end_index--;
			count_n++;
			continue;
		}
		else if (sum < M)
		{
			start_index++;
			continue;
		}
		else if (sum > M)
		{
			end_index--;
			continue;
		}

	}
	cout << count_n;
}
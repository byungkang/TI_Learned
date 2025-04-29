#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[100000] = { 0, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	int max = 0;
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		sum += arr[i];
		if (max < arr[i])
		{
			max = arr[i];
		}
	}
	int start = max;
	int end = sum;
	int mid;

	int count = 0;

	while (start <= end)
	{
		mid = (start + end) / 2;
		int temp_sum = 0;
		for (int i = 0; i < N; i++)
		{
			temp_sum += arr[i];
			if (temp_sum > mid)
			{
				count++;
				temp_sum = arr[i];
			}
		}

		if (temp_sum != 0)
		{
			count++;
		}
		if (count > M)
		{
			start = mid + 1;
			count = 0;
		}
		else 
		{			
			end = mid - 1;
			count = 0;
		}
	}

	cout << start;
	
}
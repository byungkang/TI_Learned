#include<iostream>
#include<algorithm>

using namespace std;

int arr[1000001] = { 0, };
int temp_sum[1000001] = { 0, };
int N;

int main()
{
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	
	temp_sum[1] = arr[1];
	int sum_max = temp_sum[1];

	// plus minus ���� �Էµ� ���� �÷������� ���̳ʽ����� üũ + : true, - : false
	bool plusminus = false;

	if (temp_sum[1] > 0)
	{
		plusminus = true;
	}
	for (int i = 2; i <= N; i++)
	{
		if (plusminus == false)
		{
			temp_sum[i] = arr[i];
			sum_max = max(sum_max, temp_sum[i]);

			if (temp_sum[i] >= 0)
			{
				plusminus = true;
			}
		}
		else
		{
			temp_sum[i] = temp_sum[i - 1] + arr[i];

			if (temp_sum[i] < 0)
			{
				plusminus = false;
			}
			else
			{
				sum_max = max(sum_max, temp_sum[i]);
			}
		}
	}

	cout << sum_max;
}


#include <iostream>
#include <algorithm>

using namespace std;

int arr[100000] = { 0, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	
	//��緹���� ������ �� ����, �׷��� �Ǹ� �ּҴ� 9�� ��緹�̸� Input�� �ִ� ��, �ּҴ� 1�� ��緹���̸� Input�� ���� ��
	int start, end, mid;

	int max_sum = 0;
	int max_index = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		if (arr[i] > max_index)
		{
			max_index = arr[i];
		}
		max_sum += arr[i];
	}
	
	start = max_index;
	end = max_sum;
	mid = (end + start) / 2;
	
	// 27

	int blue_indx = 0;

	int final_result = mid;
	while (start <= end)
	{
		int temp = 0;
		for (int i = 0; i < N; i++)
		{
			if ((temp + arr[i]) > mid)
			{
				blue_indx++;
				temp = arr[i];
			}
			else
			{
				temp += arr[i];
			}			
		}
		if (temp != 0)
		{
			blue_indx++;
		}
		
		if (M < blue_indx)
		{
			blue_indx = 0;
			start = mid + 1;
			mid = (end + start) / 2;
		}
		else 
		{
			blue_indx = 0;
			end = mid - 1;
			mid = (end + start) / 2;
		}
	}

	cout << start;
	

	

}
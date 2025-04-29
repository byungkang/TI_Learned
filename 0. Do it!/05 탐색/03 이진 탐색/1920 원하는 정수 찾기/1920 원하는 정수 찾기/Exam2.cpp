#include <iostream>
#include <algorithm>

using namespace std;

int N,M;
int arr[100000] = { 0, };

void binarysearch(int index);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + N);

	cin >> M;
	
	int temp;
	for (int i = 0; i < M; i++)
	{		
		cin >> temp;
		binarysearch(temp);
	}
}


void binarysearch(int index)
{
	int start = 0;
	int end = N-1;

	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (arr[mid] == index)
		{
			cout << 1 << "\n";
			return;
		}
		else if (arr[mid] > index)
		{
			end = mid - 1;
		}
		else if (arr[mid] < index)
		{
			start = mid + 1;
		}
	}
	cout << 0 << "\n";
}
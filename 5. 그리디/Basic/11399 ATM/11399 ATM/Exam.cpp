#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[1001] = { 0, };

int main()
{
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + (N + 1));

	int result = 0;
	int fianl_result = 0;
	for (int i = 1; i <= N; i++)
	{
		result += arr[i];
		fianl_result += result;
	}

	cout << fianl_result;
}

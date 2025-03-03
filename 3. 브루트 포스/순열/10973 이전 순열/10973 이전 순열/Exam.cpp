#include <iostream>

using namespace std;

int arr[10001] = { 0, };


bool pre_permutation(int number)
{
	int i = number - 1;
	while (i > 0 && arr[i] > arr[i - 1])
	{
		i--;
	}
	if (i <= 0)
	{
		return false;
	}

	int j = number - 1;
	while (arr[i - 1] < arr[j])
	{
		j--;
	}
	swap(arr[i - 1], arr[j]);

	for (int k = i, h = number - 1; k < h; k++, h--)
	{
		swap(arr[k], arr[h]);
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	if (pre_permutation(n))
	{
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
	else
	{
		cout << -1;
	}
}
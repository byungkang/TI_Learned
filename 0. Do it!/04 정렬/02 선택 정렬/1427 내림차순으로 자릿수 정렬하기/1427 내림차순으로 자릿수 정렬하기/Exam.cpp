#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int arr[11] = { 0, };

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string input;
	
	cin >> input;

	for (int i = 0; i < input.size(); i++)
	{
		arr[i] = input[i] - '0';
	}

	for (int i = 0; i < input.size() - 1; i++)
	{
		for (int j = 0; j < input.size() - 1 - i; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < input.size(); i++)
	{
		cout << arr[i];
	}

}
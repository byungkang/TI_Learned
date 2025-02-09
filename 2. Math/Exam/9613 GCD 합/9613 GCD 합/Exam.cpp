#include <iostream>

using namespace std;

int divide(int a, int b)
{
	if (a % b == 0)
	{
		return b;
	}
	else
	{
		return divide(b, a % b);
	}
}


int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp[100] = { 0 };
		int count;
		cin >> count;
		for (int j = 0; j < count; j++)
		{
			cin >> temp[j];
		}

		long long value = 0;
		for (int a = 0; a < count; a++)
		{
			for (int b = a + 1; b < count; b++)
			{
				value += divide(temp[a], temp[b]);
			}
		}
		cout << value << "\n";

	}
}
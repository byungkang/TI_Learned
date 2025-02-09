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
	int n,position;
	cin >> n >> position;

	int temp_position[100000] = { 0 };

	int temp_pos;
	for (int i = 0; i < n; i++)
	{
		cin >> temp_pos;
		temp_position[i]=abs(position-temp_pos);
	}

	int result = temp_position[0];

	for (int i = 1; i < n; i++)
	{
		result = divide(result, temp_position[i]);
	}

	cout << result;
}
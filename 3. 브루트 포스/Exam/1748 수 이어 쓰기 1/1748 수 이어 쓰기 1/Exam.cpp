#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string input;
	cin >> input;

	int size = input.size();
	int temp = stoi(input);

	if (temp < 10)
	{
		cout << temp;
		return 0;
	}

	int count = 0;
	int alpha = pow(10, size-1);
	int beta = size;
	int sum = 0;
	for (int i = 1; i < temp / alpha; i++)
	{
		count += alpha * beta;
	}
	count += (temp % alpha + 1) * beta;
	while (alpha>0)
	{
		temp = alpha - 1;
		alpha /= 10;
		beta--;
		count += (temp - alpha + 1) * beta;
	}
	cout << count;
}
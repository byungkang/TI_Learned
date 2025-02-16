#include <iostream>
#include <cmath>
#include <stack>

using namespace std;

int main()
{
	int alpha, beta;
	cin >> alpha >> beta;

	int count;
	cin >> count;

	stack<int>result;
	
	long long temp_result = 0;
	for (int i = count - 1; i >= 0; i--)
	{
		int number;
		cin >> number;
		temp_result += pow(alpha, i) * number;
	}

	while (temp_result)
	{
		result.push(temp_result % beta);
		temp_result /= beta;
	}

	
	while (!result.empty())
	{
		cout << result.top() << " ";
		result.pop();
	}
}
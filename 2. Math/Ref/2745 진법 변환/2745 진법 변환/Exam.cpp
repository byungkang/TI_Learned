#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	// '0' == 48

	string alpha;
	int beta;
	cin >> alpha >> beta;

	reverse(alpha.begin(), alpha.end());
	long long result = 0;

	for (int i = 0; i < alpha.size(); i++)
	{
		int temp;
		if (alpha[i] < 'A')
		{
			temp = alpha[i] - '0';
		}
		else
		{
			temp = alpha[i] - 'A' + 10;
		}
		result += temp * pow(beta, i);
	}
	cout << result;
}
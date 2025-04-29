#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int input;
	cin >> input;

	int dp[100001];

	int count = 2;

	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= input; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}

	cout << dp[input];
}

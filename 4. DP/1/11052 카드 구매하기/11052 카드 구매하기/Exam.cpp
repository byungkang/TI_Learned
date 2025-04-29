#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int input;
int temp[10000] = { 0 };
int dp[1001] = { 0, };

int id(vector<int> N, int input)
{
	vector<int> M(input+1);
	
	
	for (int i = 1; i <= input; i++)
	{
		int temp = 0;
		for (int j = 1; j <= i; j++)
		{
			temp = max(temp, N[j] + M[i - j]);
		}
		M[i] = temp;
	}
	return M[input];
}


int main()
{
	cin >> input;
	vector<int> temp_a(input+1,0);

	for (int i = 1; i <= input; i++)
	{
		cin >> temp_a[i];
	}

	cout << id(temp_a, input);
}
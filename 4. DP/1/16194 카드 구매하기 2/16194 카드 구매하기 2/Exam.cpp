#include <iostream>
#include <vector>


using namespace std;


int input;

int dp(int count, vector<int>M, int beta )
{
	vector<int>N(count+1,0);

	
	for (int i = 1; i <= count; i++)
	{	
		int temp = beta;
		for (int j = 1; j <= i; j++)
		{
			temp = min(temp,M[j] + N[i-j]);
		}
		N[i] = temp;
	}
	return N[count];
}



int main()
{
	cin >> input;
	vector<int> alpha(input+1,0);

	int beta = 0;
	for (int i = 1; i <= input; i++)
	{
		cin >> alpha[i];
		beta += alpha[i];
	}

	cout << dp(input, alpha, beta);
}
#include <iostream>

using namespace std;

bool position[21] = { 0, };
char plusminus[11][11];
int arr[11] = { 0 };
bool final_result = false;

int N;

bool Check(int idx)
{
	int sum = 0;
	for (int i = idx; i >=0; i--)
	{

		sum += arr[i];
		if (sum >= 0 && plusminus[i+1][idx+1] == '-')
		{
			return false;
		}
		else if (sum <= 0 && plusminus[i + 1][idx + 1] == '+')
		{
			return false;
		}
		else if (sum != 0 && plusminus[i + 1][idx + 1] == '0')
		{
			return false;
		}

	}
	return true;
}

void brudpos(int depth)
{
	if (depth == N)
	{
		for (int i = 0; i < depth; i++)
		{
			cout << arr[i] << " ";
		}
		exit(0);
	}
	int temp = 0;
	for (int i = 10; i >= -10; i--)
	{		
		arr[depth] = i;
		if (Check(depth))
		{
			brudpos(depth + 1);
		}	
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = i; j <= N; j++)
		{
			cin >> plusminus[i][j];
		}
	}

	brudpos(0);

}


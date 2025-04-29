#include <iostream>
#include <vector>

using namespace std;

void DFS(int input_num, int jarisu);
bool f_prime(int input_num);

int N;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	DFS(2, 1);
	DFS(3, 1);
	DFS(5, 1);
	DFS(7, 1);
}

void DFS(int input_num, int jarisu)
{
	if (jarisu == N)
	{
		cout << input_num << "\n";
	}
	else if (jarisu < N)
	{
		for (int i = 1; i <= 9; i++)
		{
			if (f_prime(input_num * 10 + i))
			{
				DFS(input_num * 10 + i, jarisu + 1);
			}		
		}		
	}

}

bool f_prime(int input_num)
{
	for (int i = 2; i <= input_num / 2; i++)
	{
		if (input_num % i == 0)
		{
			return false;
		}
	}
	return true;
}
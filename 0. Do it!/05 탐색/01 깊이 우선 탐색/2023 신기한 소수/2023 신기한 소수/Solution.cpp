#include <iostream>
#include <vector>
#include <string>

using namespace std;

void DFS(int number, int jarisu);
bool prime(int num);
vector < vector<int>> alpha;
int N;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	
	// 2, 3, 5, 7¸¸ È°¿ë

	DFS(2, 1);
	DFS(3, 1);
	DFS(5, 1);
	DFS(7, 1);

}

void DFS(int number, int jarisu)
{
	if (jarisu == N)
	{
		if (prime(number))
		{
			cout << number << "\n";
		}
		return;
	}

	for (int i = 1; i <= 9; i+=2)
	{
		if (prime(number * 10 + i))
		{
			DFS(number * 10 + i, jarisu + 1);
		}
	}
}

bool prime(int num)
{
	for (int i = 2; i <= num / 2; i++)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	return true;
}
#include <iostream>

using namespace std;

int find_max(int a, int b)
{
	if (a % b == 0)
	{
		return b;
	}
	else
	{
		return find_max(b, a % b);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int alpha, beta;
	for (int i = 0; i < N; i++)
	{
		cin >> alpha >> beta;
		int max_v = find_max(alpha, beta);
		cout << (alpha * beta) / max_v << "\n";
	}

}
#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int alpha, int beta)
{
	if (alpha % beta == 0)
	{
		return beta;
	}
	else
	{
		return gcd(beta, alpha % beta);
	}
}

int main()
{
	int a, b;
	cin >> a >> b;

	int bigstep = gcd(a, b);

	cout << bigstep << "\n" << bigstep * (a / bigstep) * (b / bigstep);

}
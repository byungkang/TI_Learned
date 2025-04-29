#include <iostream>
#include <string>

using namespace std;

int divide(long long a, long long b)
{
	if (a % b == 0)
	{
		return b;
	}
	else
	{
		return divide(b, a % b);
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long minv, maxv;
	cin >> minv >> maxv;		

	int temp = divide(minv, maxv);
	for (int i = 0; i < temp; i++)
	{
		cout << 1;
	}
}
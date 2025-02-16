# include <iostream>

using namespace std;

int divide(int a, int b)
{
	if (a%b == 0)
	{
		return b;
	}
	else
	{
		divide(b, a % b);
	}
}

int main()
{
	int e, s, m;
	cin >> e >> s >> m;


	if (e == 1 && s == 1 && m == 1)
	{
		cout << 1;
		return 0;
	}

	if (e == 15)
	{
		e = 0;
	}
	if (s == 28)
	{
		s = 0;
	}
	if (m == 19)
	{
		m = 0;
	}
	int result = 15+e;
	while (1)
	{
	if (result % 28 == s)
		{
			while (1)
			{
				if (result % 19 == m)
				{
					cout << result;
					break;
				}
				result += 420;
			}
		}
		if(result % 15 ==e && result % 28 ==s && result % 19 ==m)
		{
			break;
		}
		result += 15;

	}
}


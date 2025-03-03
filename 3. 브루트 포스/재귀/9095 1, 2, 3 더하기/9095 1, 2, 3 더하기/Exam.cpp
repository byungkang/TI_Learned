#include <iostream>

using namespace std;


int combination (int a, int b)
{
	int sum1 = 1;
	int sum2 = 1;
	if (a == b || b == 0)
	{
		return 1;
	}
	else
	{
		for (int i = 0; i < b; i++)
		{
			sum1 *= a - i;
			sum2 *= b - i;
		}
	}
	return sum1/sum2;
}
int main()
{
	int T;
	cin >> T;

	int number;
	for (int i = 0; i < T; i++)
	{
		cin >> number;
		int position;
		int count = 0;
		int position_rd = number / 3;
		int position_nd;
		while (position_rd>=0)
		{
			position = number - position_rd*3;
			if (position >= 2)
			{

				position_nd = position / 2;
				for (int i = 0; i <= position_nd; i++)
				{	
					int position_temp = position - 2 * i;
					if (position_rd != 0)
					{
						count += combination(position_temp+ position_rd+i, i) * combination(position_temp + position_rd, position_rd);		
					}
					else
					{
						count += combination(position_temp + position_rd + i, i);
					}
				}
			}
			else
			{
				count += combination(position + position_rd, position_rd);
			}
			position_rd--;
		}
		cout << count << "\n";
	}
}
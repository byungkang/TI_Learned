#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int alpha, beta;
	cin >> alpha >> beta;

	string output;

	while (alpha != 0)
	{
		int temp = alpha % beta;
		if (alpha % beta > 9)
		{
			temp = temp - 10 + 'A';
			output += temp;
		}
		else
		{
			output += ('0' + temp);
		}
		alpha /= beta;
	}
	reverse(output.begin(), output.end());
	cout << output;

	return 0;

}
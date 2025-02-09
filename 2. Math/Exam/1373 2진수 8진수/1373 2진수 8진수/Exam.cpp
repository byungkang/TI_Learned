#include <iostream>
#include <string>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string input;
	cin >> input;

	while (input.length() % 3 != 0)
	{
		input = '0' + input;
	}

	for (int i = 0; i < input.length(); i += 3)
	{
		int num = (input[i] - '0') * 4 + (input[i + 1] - '0') * 2 + (input[i + 2] - '0') * 1;
		cout << num;
	}


}
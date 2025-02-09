#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input;
	cin >> input;

	int count[26];
	for (int i = 0; i < 26; i++)
	{
		count[i] = -1;
	}


	int temp = 0;
	for (int i = 0; i < input.size(); i++)
	{
		temp = ( - 1 * (97 - int(input[i])));
		if(count[temp] == -1)
		{
			count[temp] = i;
		}
	}
	for (int j = 0; j < 26; j++)
	{
		cout << count[j] << " ";
	}
}
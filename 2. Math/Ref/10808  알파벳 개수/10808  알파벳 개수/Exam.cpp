#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input;
	cin >> input;

	int count[26] = { 0 };

	for (int i = 0; i < input.size(); i++)
	{
		count[input[i] - 97]++;
	}

	for (int i = 0; i < 26; i++)
	{
		cout << count[i] << " ";
	}
}
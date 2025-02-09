#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	string word;
	int len;

	cin >> word;
	len = word.length();
	string arr[len] = {};

	for (int i = 0; i < len; i++)
	{
		arr[i] = word.substr(i, len);
	}
	sort(arr, arr + len);

	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << "\n";
	}
}
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	string result1 = a + b;
	string result2 = c + d;
	long long answer = stoll(result1) + stoll(result2);
	cout << answer;
}
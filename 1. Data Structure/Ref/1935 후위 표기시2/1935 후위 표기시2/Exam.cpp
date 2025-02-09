#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	int n;
	string input;
	cin >> n >> input;

	int temp_num[26];

	stack<double>inbox;
	for (int i = 0; i < n; i++)
	{
		cin >> temp_num[i];
	}

	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] >= 'A' && input[i] <= 'Z')
		{
			inbox.push(temp_num[input[i] - 'A']);
		}
		else
		{
			if (!inbox.empty())
			{
				double temp = inbox.top();
				inbox.pop();
				switch (input[i])
				{
				case '+':
					temp = inbox.top() + temp;
					break;
				case '-':
					temp = inbox.top() - temp;
					break;
				case '*':
					temp = inbox.top() * temp;
					break;
				case '/':
					temp = inbox.top() / temp;
					break;
				}
				inbox.pop();
				inbox.push(temp);
			}
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << inbox.top() << '\n';
}
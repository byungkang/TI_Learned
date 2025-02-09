#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

int main()
{
	string input;
	getline(cin, input);
	stack<char>in_box;

	input += " ";
	for (int i = 0; i < input.size(); i++)
	{		
		if (input[i] == '<')
		{
			if (!in_box.empty())
			{
				while (!in_box.empty())
				{
					cout << in_box.top();
					in_box.pop();
				}
			}
			cout << '<';
			while (input[i] != '>')
			{
				i++;
				cout << input[i];
			}
			continue;
		}
		if (input[i] == ' ')
		{
			while (!in_box.empty())
			{
				cout << in_box.top();
				in_box.pop();
			}
			cout << " ";
			continue;
		}
		in_box.push(input[i]);
	}
}
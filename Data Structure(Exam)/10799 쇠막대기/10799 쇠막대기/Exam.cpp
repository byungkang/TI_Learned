#include<iostream>
#include<stack>

using namespace std;

int main()
{
	string input;
	cin >> input;
	stack<char>in_box;
	
	int result = 0;
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == ')' && input[i - 1] == '(')
		{
			in_box.pop();
			result += in_box.size();
		}
		else if (input[i] == '(')
		{
			in_box.push(input[i]);
		}
		else if (input[i] == ')' && input[i - 1] == ')' )
		{
			in_box.pop();
			result++;
		}
	}
	cout << result;
}
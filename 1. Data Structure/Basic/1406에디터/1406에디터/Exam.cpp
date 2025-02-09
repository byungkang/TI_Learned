#include<iostream>
#include <stack>

using namespace std;

int main()
{
	string input_st;
	cin >> input_st;
	cin.ignore();

	int n; 
	cin >> n;
	stack<char> left;
	stack<char> right;

	for (int j = 0; j < input_st.size(); j++)
	{
		left.push(input_st[j]);
	}
	int now_point = input_st.size();
	char command;
	for (int i = 0; i < n; i++)
	{
		cin >> command;
		if (command == 'L')
		{
			if (now_point == 0)
			{
				continue;
			}
			right.push(left.top());
			left.pop();
			now_point--;
			
		}
		else if (command == 'D')
		{
			if (now_point == left.size()+right.size())
			{
				continue;
			}
			left.push(right.top());
			right.pop();
			now_point++;
		}
		else if (command == 'B')
		{
			if (now_point == 0)
			{
				continue;
			}
			left.pop();
			now_point--;
		}
		else if (command == 'P')
		{
			char alpha;
			cin >> alpha;
			left.push(alpha);
			now_point++;
		}
	}
	while (!left.empty())
	{
		right.push(left.top());
		left.pop();
	}
	char result;
	int countnum = right.size();
	for (int i = 0; i < countnum; i++)
	{
		result = right.top();
		right.pop();
		cout << result;
	}
}
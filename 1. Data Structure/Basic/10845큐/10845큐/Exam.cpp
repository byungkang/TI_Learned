#include <iostream>
#include <queue>

using namespace std;

int main()
{
	queue<int> alpha;
	int n;
	cin >> n;
	cin.ignore();

	string input;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		if (input == "push")
		{
			int input_num;
			cin >> input_num;
			alpha.push(input_num);
		}
		else if (input == "pop")
		{
			if (alpha.empty())
			{
				cout << -1 << "\n";
				continue;
			}
			int result = alpha.front();
			alpha.pop();
			cout << result << "\n";
		}
		else if (input == "size")
		{
			cout << alpha.size() << "\n";
		}
		else if (input == "empty")
		{
			if (alpha.empty())
			{
				cout << 1 << "\n";
			}
			else
			{
				cout << 0 << "\n";
			}
		}
		else if (input == "front")
		{
			if (alpha.empty())
			{
				cout << -1 << "\n";
				continue;
			}
			cout << alpha.front() << "\n";
		}
		else if (input == "back")
		{
			if (alpha.empty())
			{
				cout << -1 << "\n";
				continue;
			}
			cout << alpha.back() << "\n";
		}
	}
}
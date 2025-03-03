#include <iostream>
#include <string>
#include <deque>

using namespace std;

int n_number;
string input;
bool position[21] = { 0, };

int main()
{
	cin >> n_number;

	for (int i = 0; i < n_number; i++)
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);


		cin >> input;
		int input_n;
		if (input == "add")
		{
			cin >> input_n;
			if (!position[input_n])
			{
				position[input_n] = true;
			}
		}
		else if (input == "remove")
		{
			cin >> input_n;
			if (position[input_n])
			{
				position[input_n] = false;
			}
		}
		else if (input == "check")
		{
			cin >> input_n;
			if (position[input_n])
			{
				cout << 1 << "\n";
			}
			else
			{
				cout << 0 << "\n";
			}

		}
		else if (input == "toggle")
		{
			cin >> input_n;
			if (position[input_n])
			{
				position[input_n] = false;
			}
			else
			{
				position[input_n] = true;
			}
		}
		else if (input == "all")
		{
			for (int i = 1; i <= 20; i++)
			{
				position[i] = true;
			}
		}
		else if (input == "empty")
		{
			for (int i = 1; i <= 20; i++)
			{
				position[i] = false;
			}
		}
	}

}
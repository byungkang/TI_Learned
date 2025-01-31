#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int n, call_num;
	cin >> n;
	cin.ignore();
	cin >> call_num;

	queue <int> input_box;

	for (int i = 1; i <= n; i++)
	{
		input_box.push(i);
	}

	cout << "<";

	while (input_box.size() > 1)
	{
		int temp_result;
		for (int i = 0; i < call_num - 1; i++)
		{
			temp_result = input_box.front();
			input_box.pop();
			input_box.push(temp_result);
		}
		cout << input_box.front() << ", ";
		input_box.pop();
	}
	cout << input_box.front() << ">";

}
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
	int n;
	stack<int>in_box;
	int ans[1000001];
	int seq[1000001];
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> seq[i];
	}

	for (int i = n - 1; i >= 0; i--)
	{
		while (!in_box.empty() && in_box.top() <= seq[i])
		{
			in_box.pop();
		}
		if (in_box.empty())
		{
			ans[i] = -1;
		}
		else
		{
			ans[i] = in_box.top();
		}
		in_box.push(seq[i]);
	}

	for (int i = 0; i < n; i++)
	{
		cout << ans[i] << " ";
	}
}
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	stack<int> s;
	vector<char> result;
	int cnt = 1;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;

		while (cnt <= x)
		{
			s.push(cnt);
			cnt++;
			result.push_back('+');
		}
		if (s.top() == x)
		{

			s.pop();
			result.push_back('-');
		}
		else
		{
			cout << "NO";
			return 0;
		}
	}

	for (int j = 0; j < result.size(); j++)
	{
		cout << result[j] << '\n';
	}
}
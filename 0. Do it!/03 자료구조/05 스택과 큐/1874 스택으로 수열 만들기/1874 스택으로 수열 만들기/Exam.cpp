#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	
	cin >> N;

	stack<int> searching;
	vector<char> result;

	// 스택에 입력 할 수 있는 값
	int count = 0;

	// 스택 상단에 채워져 있는 값 
	int temp;

	for (int i = 0; i < N; i++)
	{
		cin >> temp;

		if (count <= temp)
		{
			while (count != temp)
			{
				count++;
				searching.push(count);	
				result.push_back('+');
			}
			searching.pop();
			result.push_back('-');
		}
		else
		{
			if (searching.empty() || searching.top() < temp)
			{
				cout << "NO";
				return 0;
			}
			else
			{
				while (!searching.empty() && searching.top() >= temp)
				{
					searching.pop();
					result.push_back('-');
				}
			}
		}
	}

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << "\n";
	}
}
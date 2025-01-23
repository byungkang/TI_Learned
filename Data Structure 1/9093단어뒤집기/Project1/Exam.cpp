#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;
	// 입력 값을 받고 줄 바꿈
	cin.ignore();
	while (n--)
	{
		string s = "";
		getline(cin, s);
		s += " ";
		stack<char>box;
		for (int i = 0; i < s.size(); i++)
		{
			// 공백 구간일 경우 스택에 쌓인 input들을 출력
			if (s[i] == ' ')
			{
				while (!box.empty())
				{
					cout << box.top();
					box.pop();
				}
				cout << s[i];
			}
			// 공백 구간이 아닐 경우 스택에 input을 push
			else
			{
				box.push(s[i]);
			}
		}
		cout << "\n";
	}
}

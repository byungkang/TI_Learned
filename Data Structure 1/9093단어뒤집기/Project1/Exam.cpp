#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;
	// �Է� ���� �ް� �� �ٲ�
	cin.ignore();
	while (n--)
	{
		string s = "";
		getline(cin, s);
		s += " ";
		stack<char>box;
		for (int i = 0; i < s.size(); i++)
		{
			// ���� ������ ��� ���ÿ� ���� input���� ���
			if (s[i] == ' ')
			{
				while (!box.empty())
				{
					cout << box.top();
					box.pop();
				}
				cout << s[i];
			}
			// ���� ������ �ƴ� ��� ���ÿ� input�� push
			else
			{
				box.push(s[i]);
			}
		}
		cout << "\n";
	}
}

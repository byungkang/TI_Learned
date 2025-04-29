#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int arr[1000001] = { 0, };
bool position[10000001] = { 0, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	// 범위 지정
	int temp = sqrt(10000000);

	position[1] = true;
	// 소수 찾기
	for (int i = 2; i <= temp; i++)
	{
		if (position[i] == true)
		{
			continue;
		}
		for (int j = i * i; j <= 10000000; j = j + i)
		{
			position[j] = true;
		}
	}

	for (int i = N; i <= 10000000; i++)
	{
		if (position[i] == false)
		{
			string temp = to_string(i);
			string alpha="";
			for (int i = temp.size() - 1; i >= 0; i--)
			{
				alpha += temp[i];
			}
			if (alpha == temp)
			{
				cout << stoi(alpha);
				break;
			}
		}
	}
}


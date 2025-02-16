#include <iostream>

#define MAX 1000000

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int inbox[MAX] = { 0 };

	for (int i = 2; i*i <= MAX; i++)
	{
		if (inbox[i] == 0)
		{
			for (int j = i * i; j <= MAX; j += i)
			{
				inbox[j] = 1;
			}
		}
	}

	int count = 0;
	int input;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		for (int i = 2; i <= input / 2; i++)
		{
			if (inbox[i] == 0 && inbox[input - i] == 0  )
			{
				count++;
			}
		}
		cout << count << "\n";
		count = 0;
	}
}
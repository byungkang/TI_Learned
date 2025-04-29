#include <iostream>
#include <algorithm>

using namespace std;

int N, M;

int arr[1000001] = { 0, };
bool position[1000001] = { 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	int temp = sqrt(M);
	position[1] = true;


	for (int i = 1; i <= temp; i++)
	{
		if (position[i] = true)
		{
			continue;
		}
		for (int j = i + i; j <= M; j = j + i)
		{
			position[j] = true;
		}
	}

	for (int i = N; i <= M; i++)
	{
		if (position[i] == false)
		{
			cout << i << "\n";
		}
	}
}
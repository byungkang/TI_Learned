#include <iostream>
#include <queue>

using namespace std;

#define NUMBER 10000001


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	queue<int> box;
	long long temp_box[NUMBER] = { 0 };
	for (int i = 2; i * i < NUMBER; i++)
	{
		if (temp_box[i] == 0)
		{
			box.push(i);
			for (int j = i * i; j < NUMBER; j += i)
			{
				temp_box[j] = 1;
			}
		}
	}

	int n;
	cin >> n;

	int count = box.front();
	while (n != count)
	{
		if (n % count == 0)
		{
			cout << count << "\n";
			n /= count;
		}
		else
		{
			box.pop();
			count = box.front();
		}
	}
	cout << count << "\n";

}
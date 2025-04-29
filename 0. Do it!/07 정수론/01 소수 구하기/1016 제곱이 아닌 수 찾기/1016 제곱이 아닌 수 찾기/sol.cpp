#include <iostream>

using namespace std;

long long min_v, max_v;

long long arr[1000000] = { 0, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	cin >> min_v >> max_v;

	long long temp_answer = max_v - min_v +1;
	
	for (long long i = 2; i*i <= max_v; i++)
	{
		long long ret = min_v / (i * i);
		if (min_v % (i * i) != 0)
		{
			ret++;
		}
		while (ret * (i * i) <= max_v)
		{
			if (arr[ret * (i * i) - min_v] == false)
			{
				arr[ret * (i * i) - min_v] = true;
				temp_answer--;
			}
			ret++;
		}
	}

	cout << temp_answer;
}



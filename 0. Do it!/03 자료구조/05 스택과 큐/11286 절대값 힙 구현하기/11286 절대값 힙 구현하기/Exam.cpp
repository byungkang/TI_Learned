#include <iostream>
#include <queue>

using namespace std;

struct compare
{
	bool operator()(int o1, int o2)
	{
		int first_abs = abs(o1);
		int second_abs = abs(o2);
		if (first_abs == second_abs)
		{
			return o1 > o2;
		}
		else
		{
			return first_abs > second_abs;
		}
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	priority_queue<int,vector<int>,compare> alpha;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int request;
		cin >> request;

		if (request == 0)
		{
			if (alpha.empty())
			{
				cout << "0\n";
			}
			else
			{
				cout << alpha.top() << "\n";
				alpha.pop();
			}
		}
		else
		{
			alpha.push(request);
		}
	}
	
}
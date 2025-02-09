#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int se[1000001] = { 0 };
	int counting[1000001] = { 0 };
	int n;
	cin >> n;

	stack <int> alpha;
	stack <int> index;
	int* out = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> se[i];
		counting[se[i]]++;
	}
	
	for (int i = n - 1; i >= 0; i--)
	{
		while (!alpha.empty() && alpha.top() <= counting[se[i]])
		{
			alpha.pop();
			index.pop();
		}
		if (alpha.empty())
		{
			out[i] = -1;
		}
		else
		{
			out[i] = index.top();

		}
		alpha.push(counting[se[i]]);
		index.push(se[i]);
	}

	for (int i = 0; i < n; i++)
	{
		cout << out[i] << " ";
	}

	delete[] out;
	out = NULL;

}
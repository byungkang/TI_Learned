#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int a,b;
	cin >> a >> b;

	int length = b + 1;
	int* in_box = new int[length];

	for (int i = 0; i < length; i++)
	{
		in_box[i] = true;
	}

	for (int i = 2; i <= b; i++)
	{
		if (in_box[i])
		{
			if (i >= a)
			{
				cout << i << '\n';
			}			
		}
		for (int j = i * 2; j <= b; j += i)
		{
			in_box[j] = false;
		}

	}

	delete[] in_box;
	in_box = NULL;
}5
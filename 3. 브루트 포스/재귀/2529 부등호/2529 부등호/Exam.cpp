#include <iostream>
#include <string>

using namespace std;

char up_down[9];
int arr[10] = { 0, };
bool position[10] = { 0, };
int N;

void find(int depth, string &max, string&min)
{
	if (depth == N)
	{
		string alpha;
		for (int i = 0; i <= depth; i++)
		{
			alpha += arr[i] + '0';
		}
		if (max < alpha)
		{
			max = alpha;
		}
		if (min > alpha)
		{
			min = alpha;
		}
		return;
	}



	for (int i = depth; i < N; i++)
	{
		if (up_down[i] == '<')
		{
			int temp = arr[depth + 1];
			for (int j = 0; j <= 9; j++)
			{
				if (j > arr[depth] && !position[j])
				{
					position[j] = true;
					arr[depth + 1] = j;
					find(depth + 1, max,min);
					position[j] = false;
				}
			}
			if (temp == arr[depth + 1])
			{
				break;
			}
		}
		else
		{
			int temp = arr[depth + 1];
			for (int j = 0; j <= 9; j++)
			{
				if (j < arr[depth] && !position[j])
				{
					position[j] = true;
					arr[depth+1] = j;
					find(depth + 1, max,min);
					position[j] = false;
				}
			}
			if (temp == arr[depth + 1])
			{
				break;
			}
		}
	}			
		
}

int main()
{
	cin >> N;

	string min;
	string max;
	for (int i = 0; i < N; i++)
	{
		cin >> up_down[i];
		min += (9 - i) + '0';
	}
	
	for (int a = 0; a <= 9; a++)
	{
		position[a] = true;
		arr[0] = a;
		find(0, max,min);
		position[a] = false;
	}
	
	cout << max << "\n" << min;
}


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int arr[2000];

int main() {
    int num;
    int result = 0;
    int val;

    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + num);

    for (int i = 0; i < num; i++) 
    {
        val = arr[i]; 
        int l = 0;
        int r = num - 1;
        int sum;
        while (l < r) 
        {
            sum = arr[l] + arr[r];
            if (sum == val) 
            {
                if (l != i && r != i) 
                {
                    result++;
                    break;
                }
                else if (l == i) l++;
                else if (r == i) r--;
            }
            else if (sum < val) l++;
            else r--;
        }
    }

    cout << result;
    return 0;
}
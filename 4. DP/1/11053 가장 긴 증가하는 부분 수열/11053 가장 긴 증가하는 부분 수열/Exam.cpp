#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    scanf("%d", &N);

    int arr[1001];
    for (int i = 1; i <= N; i++)
        scanf("%d", &arr[i]);

    int dp[1001];
    for (int i = 1; i <= N; i++)
        dp[i] = 1;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    sort(dp, dp + N + 1);
    printf("%d", dp[N]);
}
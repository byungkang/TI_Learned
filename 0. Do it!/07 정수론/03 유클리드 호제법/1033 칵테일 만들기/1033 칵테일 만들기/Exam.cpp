#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

vector<tuple<int, int, int>> A[10];
bool visited[10];
long lcm = 1;
long D[10];
long gcd(long a, long b);
void DFS(int v);
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b, p, q;
        cin >> a >> b >> p >> q;

        A[a].push_back(make_tuple(b, p, q));
        A[b].push_back(make_tuple(a, q, p));

        lcm = lcm * (p * q / gcd(p, q));
    }

    D[0] = lcm;
    DFS(0);

    long mgcd = D[0];
    for (int i = 1; i < n; i++) {
        mgcd = gcd(mgcd, D[i]);
    }

    for (int i = 0; i < n; i++) {
        cout << D[i] / mgcd << ' ';
    }

    return 0;
}

long gcd(long a, long b) {
    while (b != 0) {
        long temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

void DFS(int v) {
    visited[v] = true;

    for (tuple<int, int, int> i : A[v]) {
        int next = get<0>(i);
        if (!visited[next]) {
            D[next] = D[v] * get<2>(i) / get<1>(i);
            DFS(next);
        }
    }
}
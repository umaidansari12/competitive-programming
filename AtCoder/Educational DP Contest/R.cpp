#pragma GCC optimize("O3")
#pragma GCC target("sse4")

#include <bits/stdc++.h>

using namespace std;

#define deb(x) cout << #x << " is " << x << "\n"
#define int long long
#define mod 1000000007
#define PI acos(-1)

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

template <typename T>
using max_heap = priority_queue<T>;

template <typename... T>
void read(T &... args) {
    ((cin >> args), ...);
}

template <typename... T>
void write(T &&... args) {
    ((cout << args), ...);
}

template <typename T>
void readContainer(T &t) {
    for (auto &e : t) read(e);
}

template <typename T>
void writeContainer(T &t) {
    for (const auto &e : t) write(e, " ");
    write("\n");
}

vector<vector<int>> multiply(vector<vector<int>> &X, vector<vector<int>> &Y, int n) {
    vector<vector<int>> ans(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                ans[i][j] = (ans[i][j] + (X[i][k] * Y[k][j]) % mod) % mod;
            }
        }
    }
    return ans;
}

vector<vector<int>> f(vector<vector<int>> &arr, int x, int n) {
    if (x == 1) {
        return arr;
    }
    int y = x / 2;
    vector<vector<int>> temp = f(arr, y, n);
    vector<vector<int>> ans = multiply(temp, temp, n);
    if (x % 2 == 1) {
        ans = multiply(ans, arr, n);
    }
    return ans;
}

void solve(int tc) {
    int n, k, ele;
    read(n, k);
    vector<vector<int>> arr(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            read(ele);
            if (ele == 1) {
                arr[i][j] = 1;
            }
        }
    }
    arr = f(arr, k, n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans = (ans + arr[i][j]) % mod;
        }
    }
    write(ans);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int tc = 1;
    // read(tc);
    for (int curr = 1; curr <= tc; curr++) solve(curr);
    return 0;
}
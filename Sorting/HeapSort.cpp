#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define f(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
void swaap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}

void heapify(vector<int> &arr, int n)
{
    for (int i = n / 2; i >= 0; i--)
    {
        int parent = i;
        int comp = 0;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n)
            comp = left;
        if (right < n)
            comp = arr[right] > arr[left] ? right : comp;
        if (comp != 0)
        {
            if (arr[parent] < arr[comp])
                swaap(arr[parent], arr[comp]);
        }
    }
}

void heapSort(vector<int> &arr, int n)
{
    if (n == 1)
        return;
    heapify(arr, n);
    swaap(arr[0], arr[n - 1]);
    heapSort(arr, n - 1);
}
int main()
{
    fast_cin();
    vector<int> arr = {56, 5, 3, 6, 23, 45, 67, 1, 34, 100, 2, 5};
    heapSort(arr, arr.size());
    // for (auto elem : arr)
    // {
    //     cout << elem << " ";
    // }
    // // heapify(arr, arr.size());
    // cout << endl;
    for (auto elem : arr)
    {
        cout << elem << " ";
    }
    return 0;
}
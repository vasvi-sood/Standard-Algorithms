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
void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}
int bring_pivot_right_place(int i, int j, int elem /*this is the pivot*/, vector<int> &arr)
{
    cout << "pivot " << arr[elem] << endl;
    while (i < j)
    {
        while (!(arr[j] <= arr[elem]))
        {
            j--;
        }
        while (!(arr[i] > arr[elem]))
        {
            i++;
        }
        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[elem], &arr[j]);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return j;
}
void QuickSort(int i, int k, vector<int> &arr)
{
    if (k == i + 1 || k == i)
        return;
    int j = bring_pivot_right_place(i, k, i /*this is the pivot*/, arr);
    QuickSort(i, j, arr);
    QuickSort(j + 1, k, arr);
}

int main()
{
    fast_cin();
    ll t;
    vector<int> arr = {2, 4, 56, 1, 34, 67, 89, 10, 23};
    arr.push_back(INT32_MAX);
    QuickSort(0, arr.size() - 1, arr);
    arr.pop_back();
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
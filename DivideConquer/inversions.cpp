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
// #include <utility>
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
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
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
pair<vector<int>, int> SortAndCount(vector<int> arr, int n)
{
    if (n == 1)
        return make_pair(arr, 0);

    vector<int> leftarr(n / 2);
    copy_n(arr.begin(), n / 2, leftarr.begin());
    auto left = SortAndCount(leftarr, n / 2);
    vector<int> larr = left.first;
    int lcount = left.second;

    vector<int> rightarr(n - (n / 2));
    copy(arr.begin() + n / 2, arr.end(), rightarr.begin());
    std::pair<vector<int>, int> right = SortAndCount(rightarr, n - (n / 2));
    vector<int> rarr = right.first;
    int rcount = right.second;

    int i = 0, j = 0, scount = 0;
    vector<int> newarr(n);
    for (int k = 0; k < n; k++)
    {
        if (i >= n / 2)
        {
            newarr[k] = rarr[j];
            j++;
        }
        else if (j >= n - (n / 2))
        {
            newarr[k] = larr[i];
            i++;
        }
        else if (larr[i] <= rarr[j])
        {
            newarr[k] = larr[i];
            i++;
        }
        else if (larr[i] > rarr[j])
        {
            newarr[k] = rarr[j];
            j++;
            scount += (n / 2) - i;
        }
    }

    // return make_pair(arr, 0);
    return make_pair(newarr, lcount + rcount + scount);
}
int main()
{
    fast_cin();
    ll n;
    cin >> n;
    vector<int> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    pair<vector<int>, int> a = SortAndCount(arr, arr.size());
    arr = a.first;
    int count = a.second;

    cout << count;
    return 0;
}
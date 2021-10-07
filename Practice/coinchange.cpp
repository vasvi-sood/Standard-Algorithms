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

int coinChange(vector<int> coins, int amount)
{
    sort(coins.begin(), coins.end());
    vector<vector<int>> arr(coins.size() + 1, vector<int>(amount + 1, -1));
    for (int i = 0; i < arr.size(); i++)
        arr[i][0] = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        int coin = coins[i - 1];
        for (int j = 1; j < arr[0].size(); j++)
        {
            int price = j;
            int r = price % coin;
            int req = arr[i - 1][r];
            if (price < coin)
                arr[i][j] = arr[i - 1][j];
            else if (price % coin == 0)
                arr[i][j] = price / coin;
            else if (req == -1)
                arr[i][j] = arr[i - 1][j];
            else
                arr[i][j] = (price / coin) + req;
        }
    }
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return arr[coins.size()][amount];
}

int main()
{
    fast_cin();
    ll t;
    coinChange({186, 419, 83, 408}, 6249);
    return 0;
}
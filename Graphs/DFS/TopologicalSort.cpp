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

void dfs(int node, vector<vector<int>> edge, vector<int> &visit, vector<int> &arr, int &pos) //accept the argument as reference
{
    visit[node] = 1;

    for (int j : edge[node])
    {
        if (!visit[j])
        {
            dfs(j, edge, visit, arr, pos);
        }
    }
    arr[pos--] = node; //arr[pos]=node and then pos--;
}
int main()
{
    fast_cin();
    vector<int> visit(8, 0);
    vector<int> order;
    vector<vector<int>> edge(8);
    edge[0].push_back(1);
    edge[1].push_back(5);
    edge[2].push_back(1);
    edge[2].push_back(3);
    edge[3].push_back(6);
    edge[3].push_back(7);
    edge[4].push_back(5);
    int pos = 7;
    vector<int> arr(8);
    for (int i = 0; i < 8; i++)

    {
        if (!visit[i])
        {
            // order = {};
            dfs(i, edge, visit, arr, pos); //arr and visit updated
                                           // for (auto elem : order)
                                           // {
                                           //     arr[pos] = elem;
                                           //     pos--;
                                           // }
                                           //the dfs updates the arr as well
        }
    }
    for (int i = 0; i < 8; i++)
    {
        cout << char(arr[i] + 65) << " -> ";
    }

    return 0;
}
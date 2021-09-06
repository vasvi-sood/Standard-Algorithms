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
int bfs_tot(vector<vector<int>> arr)
{
    int count = 0;
    vector<int> exp(arr.size(), -1); //create an unexplored list
    queue<int> q;
    for (int i = 1; i < arr.size(); i++)
    {
        if (exp[i] == -1)
        {
            q.push(i); //i is unexplored

            //conducting the bfs
            while (!q.empty())
            {
                int parent = q.front();
                q.pop();
                for (auto j : arr[parent])
                {
                    if (exp[j] == -1) //if j is unexplored
                    {
                        q.push(j);
                        exp[j] = 1;
                    }
                }
            }
            count++; //every time a new bfs, has to be started
        }
    }
    return count;
}
int main()
{
    vector<vector<int>> arr(11);

    arr[1].push_back(5);
    arr[3].push_back(5);
    arr[5].push_back(3);
    arr[5].push_back(1);
    arr[5].push_back(7);
    arr[5].push_back(4);
    arr[4].push_back(5);
    arr[7].push_back(5);

    arr[2].push_back(4);
    arr[4].push_back(2);

    // arr[6].push_back(8);
    // arr[6].push_back(10);
    // arr[8].push_back(6);
    // arr[10].push_back(6);

    int total_components = bfs_tot(arr);
    cout << total_components << endl;
}
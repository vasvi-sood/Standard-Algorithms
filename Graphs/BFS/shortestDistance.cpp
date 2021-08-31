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

vector<int> bfs(vector<vector<int>> arr, int start)
{
    vector<int> layer(arr.size(), -1);
    //layer tells us which layer the node belongs with respect to source
    layer[start] = 0;
    queue<int> q;
    q.push(start); //push starting node
    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        //grab the first elemnt check its children
        //i is it's child node value
        for (auto i : arr[parent])
        {
            if (layer[i] == -1)
            {
                layer[i] = layer[parent] + 1;
                q.push(i);
            }
        }
    }
    return layer;
}
int main()
{
    //creating a list for connectected vertices
    vector<vector<int>> arr;
    for (int i = 0; i <= 7; i++)
    {
        vector<int> a;
        arr.push_back(a);
    }

    arr[0].push_back(1);
    arr[0].push_back(2);
    arr[0].push_back(3);
    arr[0].push_back(4);

    arr[1].push_back(0);
    arr[1].push_back(5);
    arr[1].push_back(5);

    arr[2].push_back(0);
    arr[2].push_back(6);

    arr[3].push_back(0);

    arr[4].push_back(0);

    arr[5].push_back(1);
    arr[5].push_back(1);
    arr[5].push_back(6);

    arr[6].push_back(2);
    arr[6].push_back(5);
    arr[6].push_back(7);

    arr[7].push_back(5);
    arr[7].push_back(6);

    vector<int> distance_from_0 = bfs(arr, 0);
    for (int i = 0; i < distance_from_0.size(); i++)
        cout << i << " : " << distance_from_0[i] << endl;
    cout << endl
         << "distance from 7th node f" << endl;
    vector<int> distance_from_7 = bfs(arr, 7);
    for (int i = 0; i < distance_from_7.size(); i++)
        cout << i << " : " << distance_from_7[i] << endl;
}
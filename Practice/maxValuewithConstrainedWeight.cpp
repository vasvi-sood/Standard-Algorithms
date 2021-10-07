#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int w = 80;
int maxvalue(int sum, int i, bool included, vector<int> &arr, vector<int> &value)
{
    if (i >= arr.size())
        return 0;
    if (included == true && arr[i] + sum > w)
        return 0;
    int add = 0, val = 0;
    if (included)
    {
        add = arr[i];
        val = value[i];
    }
    int val1 = maxvalue(sum + add, i + 1, true, arr, value);
    int val2 = maxvalue(sum + add, i + 1, false, arr, value);
    // cout << "for i " << i << endl;
    // cout << max(val1, val2) + val << endl;
    return max(val1, val2) + val;
}
int main()
{
    vector<int> arr = {20, 10, 5, 30, 7, 60, 80, 2};
    vector<int> value = {1, 1, 2, 2, 2, 1, 1, 2};
    cout << maxvalue(0, 0, true, arr, value) << endl;
    cout << maxvalue(0, 0, false, arr, value) << endl;
}
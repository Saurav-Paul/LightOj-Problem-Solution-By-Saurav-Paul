// http : //lightoj.com/volume_showproblem.php?problem=1016
/*Saurav Paul*/
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, w;
    cin >> n >> w;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int dummy, x;
        cin >> dummy >> x;
        v.emplace_back(x);
    }
    sort(v.begin(), v.end());

    int cnt = 0;
    for (int i = 0; i < n;)
    {
        int j = i + 1;
        while (j < n && v[j] - v[i] <= w)
            ++j;
        i = j;
        ++cnt;
    }
    cout << cnt << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int testcase;
    cin >> testcase;
    for (int t = 1; t <= testcase; t++)
    {
        cout << "Case " << t << ": ";
        solve();
    }

    return 0;
}

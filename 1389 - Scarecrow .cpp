/*Saurav Paul*/
#include <bits/stdc++.h>
using namespace std;
void solve()
{
  int n;
  string s;
  cin >> n >> s;
  int cnt = 0;
  for (int i = 1; i < n; i++)
  {
    if (s[i - 1] == '.')
    {
      ++cnt;
      s[i] = s[i - 1] = '#';
      if (i < n - 1)
        s[i + 1] = '#';
    }
  }
  cout << cnt + (s[n - 1] == '.') << endl;
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

				/*Saurav Paul*/
#include<bits/stdc++.h>
using namespace std;

using pi = pair<int, int>;
char s[15][15];

void solve() {
  int n;
  scanf("%d", &n);
  pi start;
  int total = 0 , cnt = 0;
  for (int i = 0; i < n; i++)
  {
    scanf("%s", s[i]);
    for (int j = 0; j < n; j++)
    {
      if(s[i][j]=='A'){
        start = {i, j};
      }
      if(s[i][j] != '#' && s[i][j] != '.'){
        total++;
      }
    }
  }

  int move = 0;
  auto check = [&](int x, int y, char c) {
    bool ok = false;
    if(x < 0 || y < 0)
      return ok;
    if(x > n-1 || y > n-1)
      return ok;

    if(s[x][y] == '.' || s[x][y] == c)
      ok = true;
    return ok;
  };
 

  while (cnt < total)
  {
    char c = 'A' + cnt ;
    vector<vector<int>> vis(n + 1, vector<int>(n + 1));

    queue<pair<pi, int>> Q;
    Q.push({start, 0});
    bool paisi_na = true;
    while (Q.empty() == false)
    {
      pair<pi, int> P = Q.front(), t;
      Q.pop();
      int x = P.first.first, y = P.first.second, w = P.second;
      if(vis[x][y])
        continue;
      vis[x][y] = 1;
 
      if (s[x][y] == c)
      {
        paisi_na = false;
        move += w;
        ++cnt;
        start = {x, y};
        s[x][y] = '.';
        break;
      }
      if (check(x,y+1,c) && vis[x][y+1]==0)
      {
        t = {{x, y+1}, w + 1};
        Q.push(t);
      }
      if (check(x, y - 1, c) && vis[x][y - 1] == 0)
      {
        t = {{x, y - 1}, w + 1};
        Q.push(t);
      }
      if (check(x + 1, y, c) && vis[x + 1][y] == 0)
      {
        t = {{x + 1, y}, w + 1};
        Q.push(t);
      }
      if (check(x - 1, y, c) && vis[x - 1][y] == 0)
      {
        t = {{x - 1, y}, w + 1};
        Q.push(t);
      }
    }
    if(paisi_na)
      break;
  }
  if(cnt < total)
    puts("Impossible");
  else
    printf("%d\n", move);
}

int main()
{
  int testcase;
  scanf("%d", &testcase);
  for (int i = 1; i <= testcase; i++){
    printf("Case %d: ",i);
    solve();
  }

    return 0;
}

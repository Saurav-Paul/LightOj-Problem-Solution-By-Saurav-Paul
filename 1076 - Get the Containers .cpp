				/*Saurav Paul*/
#include<bits/stdc++.h>
using namespace std;

void solve() {
	int n , k;
	cin >> n >> k;
	vector<int> v(n);
	int low = 0, high = 1e9;
	for(auto &x : v)
		cin >> x , low = max(low,x);

	while(low < high){
		int mid = (low + high) >> 1;
		int cnt = 1;
		int curr = 0;
		for (auto x : v)
		{
			if(curr + x <= mid){
				curr += x;
			}
			else{
				cnt++;
				curr = x;
			}
		}
	
		if (cnt > k)
			low = mid + 1;
		else
			high = mid;

	}
	cout << low << "\n";
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

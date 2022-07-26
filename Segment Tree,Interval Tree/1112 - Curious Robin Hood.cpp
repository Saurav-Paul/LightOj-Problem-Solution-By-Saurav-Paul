  
/**
 *    author        : Saurav Paul 
 *    created       : 26/07/2022 22:57:27
 *    Problem Name  : Curious Robin Hood
 *    Problem Limit : 2000 ms , 128 MB
 *    Problem Url   : https://lightoj.com/problem/curious-robin-hood
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;

using ll = long long int ;


class BIT {
    vector<long long int> tree ;

	public:

    BIT(long long int n){
        tree.assign(n+1, 0) ;
    }

	void add(long long int index, long long int value)
	{
		while(index <= tree.size()){
            tree[index] += value;
            index += index & (-index) ;
        }
	}

	void remove(long long int index, long long int removeValue)
	{
		while(index <= tree.size()){
			tree[index] -= removeValue;
			index += index & (-index);
		}
	}

	long long int sum(long long int st, long long int sp)
	{
		return query(sp) - query(st - 1) ;
	}

	long long int query(long long int idx)
	{
		long long int sum = 0 ;
        while(idx > 0){
            sum += tree[idx] ;
            idx -= idx & (-idx) ;
        }
        return sum ;
	}
};

class TC{

    public :
    void solve(){
		long long int n, q;
		cin >> n >> q;

		BIT magic_box(n) ;
		vector<long long int> v(n + 1);

		for(int i = 1 ; i <= n ; i++){
			long long int val;
			cin >> val;
			magic_box.add(i,val) ;
			v[i] = val ;
		}

		while(q--){
			long long int type;
			cin >> type;
			long long int idx, value, st, sp;
			switch(type){
				case 1:
				 	cin >> idx;
					magic_box.remove(idx + 1, v[idx+1]) ;
					cout << v[idx + 1] << endl;
					v[idx+1] = 0 ;
					break;
				case 2:
					cin >> idx >> value;
					magic_box.add(idx + 1, value);
					v[idx + 1] += value ;
					break;
				case 3:
					cin >> st >> sp;
					cout << magic_box.sum(st + 1, sp + 1) << endl ;
			}
		}
    }
};

int main(){
    ios_base::sync_with_stdio(false);

    int testcases = 1;
    cin >> testcases ;
    for(int i = 1 ; i <= testcases ; i ++){
		cout << "Case " << i << ":" << endl;
        TC tc;
        tc.solve() ;
    }

    return 0 ;
}

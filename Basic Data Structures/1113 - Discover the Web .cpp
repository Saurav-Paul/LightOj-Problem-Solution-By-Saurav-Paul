				/*Saurav Paul*/
#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

void solve(int cn){
	cout << "Case "<<cn <<":"<< endl;
	vector<string > history;
	string url ="http://www.lightoj.com/";
	history.emplace_back(url);
	int pos = 0,high = 0, lim = 0;
	
	while(cin >> url and url != "QUIT") {
		if(url == "VISIT" ){
				cin >> url ;
				cout << url << endl ;
				pos ++;
				if(pos > lim)
					history.emplace_back(url) ;
				else history[pos] = url ;
				high = pos ;
				lim = max(lim , pos ) ;
		}
		else if(url == "BACK" ){
			if(pos == 0 ){
				cout << "Ignored" << endl;
			}
			else{
				pos --;
				cout << history[pos] << endl;
			}
		}
		else if(url == "FORWARD"){
			if(pos == high){
				cout << "Ignored" << endl;
			}
			else{
				pos ++;
				cout << history[pos] << endl;
			}
		}
		else
			assert(false);
	}
	
}
int main()
{
	ios_base::sync_with_stdio(false) ;
	int t ;
	cin >> t;
	for(int i = 1 ; i <= t ; i++){
		solve(i);
	}
    return 0;
}

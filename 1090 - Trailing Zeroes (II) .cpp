				/*Saurav Paul*/
#include<bits/stdc++.h>
using namespace std;

using ll = long long int ;
const int nax = 1e6 + 10;
vector< ll > two(nax+5), five(nax+5) ;

void pre_cum() {
	
	for(int x : {2,5} ){
		for(int i = x ; i < nax ; i+=x){
			if(x==2) two[i] = two[i/x] + 1;
			else five[i] = five[i/x] + 1;
		}
	}
	for(int i= 1 ; i < nax ; i++){
		two[i] += two[i-1] ;
		five[i] += five[i-1] ;
	}
}

ll f(ll num ,ll base ){
	ll cnt = 0;
	
	while(num%base == 0 and num > 0 ){
		cnt ++;
		num /= base ;
	}
	
	return cnt ;
}

void solve() {
	ll n , r, p , q ;
	scanf("%lld%lld%lld%lld",&n,&r,&p,&q) ;
	/*
	 * nCr * p^q 
	 * 	if p have a zero , then p will have zero 
	 * 	after calculate p^q , the number of zero * q 
	 * 
	 * Now, only problem remain that, how to calculate nCr in a
	 * 	efficient manner, so that i can find out
	 * 	the number of zero's .
	 * 
	 * Obeservation , 5 * 2 = 10
	 * 
	 * We can precompute to find the number of 5 and 2
	 * 
	 * nCr  = n! /( (n-r)! * r! )
	 * 
	 * n = 5 , r = 2
	 * nCr = n! / ( (n-r)! * r! )
	 * 1 * 2 * 3 * 4 * 5 / 1 * 2 * 3 * 1 * 2
	 * 4 * 5 / 1 * 2
	 *
	 * 
	 * Test case 1 :
	 * n = 10 , r = 4 , p = 1, q = 1;
	 * p * q = 1 , so we can ignore them 
	 * nCr = 7 * 8 * 9 * 10 / 1 * 2 * 3 * 4
	 * => 7 * 9 * 10 / 1 * 3
	 * 
	 */ 

	 	 
	 ll number_of_two = two[n] - two[n-r] - two[r] 
								+ ( f(p,2) * q ) ;
	 
	 ll number_of_five = five[n] - five[n-r] - five[r] 
								+ (f(p,5) * q ) ;
	 ll total_zero = min(number_of_five, number_of_two ) ;
	 
	 printf("%lld\n",total_zero) ;
	
}

int main()
{
	pre_cum() ;
	int testcase ;
	scanf("%d",&testcase) ;
	for(int t = 1 ; t <= testcase ; t ++){
		printf("Case %d: ",t) ;
		solve () ;
	}

    return 0;
}

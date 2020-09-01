				/*Saurav Paul*/
#include<bits/stdc++.h>
using namespace std;

double find_area(double ad,double de,double ae){
	double p = (ad + de + ae) /2;
	double ade = sqrt(p * (p-ad) * (p-de) * (p-ae) );
	return ade ;
}

void solve(){
	double ab , ac , bc , rat ;
	scanf("%lf%lf%lf%lf",&ab,&ac,&bc,&rat);
	
	double low = 0.0 , high = ab ;
	while( high - low > 0.0000001 ){
		double ad = (high + low ) / 2.0 ;

		double ae = ( ad * ac ) / ab;
		double de = (ad * bc ) / ab ;

		double ade = find_area(ad,de,ae);
		double abc = find_area(ab,bc,ac);
		
		double bdec = abc - ade ;
		double newrat = ade/bdec ;

		if(newrat > rat ) high = ad ;
		else low = ad ;
	}
	printf("%.9lf\n",low);
}
int main()
{
	int t ; scanf("%d",&t);
	for(int i = 1 ; i <= t ; i++){
		printf("Case %d: ",i);
		solve();
	}

    return 0;
}

#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

const int mx=1000000;
int nanugi=1000000007;
int mod[mx+1]={1, };

ll POW(int n, int k){
	if(k==0)
	  return 1;
	ll p=POW(n, k/2);
	p=p*p%nanugi;
	return p*(k%2?n:1)%nanugi;
}

ll ncr(int n, int k){
    return mod[n]*POW(mod[k], nanugi-2)%nanugi*POW(mod[n-k], nanugi-2)%nanugi;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int a, b, m, i;
	ll s=1;
	for(i=1; i<=mx; i++){
		s*=i; s%=nanugi;
		mod[i]=s;
	}
	m=1;
	for(i=0; i<m; i++){
	    int x, y;
		cin>>a>>b;
		
		if(a%2 != 0){
		    cout<<"0\n";
		    continue;
		}
		x=a/2;
		if((b-x)%3 != 0){
		    cout<<"0\n";
		    continue;
		}
		y=(b-x)/3;
		if(y<0){
		    cout<<"0\n";
		    continue;
		}
		int ans=POW(3, x)*ncr(x+y, x)%nanugi;
		cout<<ans<<"\n";
	}
	
}
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fore(i, n) for(int i=0;i<n;i++)
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define MOD 1000000007

ll fun1(ll a1, ll k1, ll a2, ll k2, ll n){
	ll ans = 0;
	ll l1 = n/k1;
	ans+=min(l1, a1);
	n-=k1*min(l1,a1);

	ans+=n/k2;

	return ans;
}
ll fun2(ll a1, ll k1, ll a2, ll k2, ll n){
	ll ans = 0;
	n-=(k1-1)*a1;
	n-=(k2-1)*a2;
	if(n<=0)
		return 0;

	return min(a1+a2, n);
}
int main(){

	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	ll a1,k1,a2,k2,n;
	cin>>a1>>a2>>k1>>k2>>n;

	if(k1<k2)
		cout<<fun2(a2,k2,a1,k1,n)<<" "<<fun1(a1,k1,a2,k2,n);
	else
		cout<<fun2(a1,k1,a2,k2,n)<<" "<<fun1(a2,k2,a1,k1,n);
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fore(i, n) for(int i=0;i<n;i++)
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define MOD 1000000007

int main(){

	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	int n;
	cin>>n;

	string s,t;
	cin>>s>>t;

	queue<int > v1;
	queue<int > v2;

	int fal=0, tru=0;
	fore(i,n){
		if(s[i]!=t[i]){
			if(s[i] == 'a'){
				v1.push(i+1);
				tru++;
			}
			else{
				v2.push(i+1);
				fal++;
			}
		}
	}

	ll ans = 0;
	ans+=fal/2 + tru/2;
	ll left = (fal%2)+(tru%2);
	if(left%2 !=0 )
		cout<<-1;
	else{
		ans+=left;
		cout<<ans<<endl;

		while(v1.size()>1){
			cout<<v1.front()<<" ";
			v1.pop();
			cout<<v1.front()<<endl;
			v1.pop();
		}
		while(v2.size()>1){
			cout<<v2.front()<<" ";
			v2.pop();
			cout<<v2.front()<<endl;
			v2.pop();
		}

		if(!v1.empty()){
			int a1 = v1.front();
			int a2 = v2.front();
			cout<<a1<<" "<<a1<<endl;
			cout<<a1<<" "<<a2<<endl;
		}
	}
	return 0;
}
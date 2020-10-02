#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fore(i, n) for(int i=0;i<n;i++)
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define MOD 1000000007

ll dpP[200001] = {0};
ll dpN[200001] = {0};
bool arr[200001];


int main(){

	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	int N;
	cin>>N;
	memset(dpP, 0, sizeof(dpP));
	memset(dpN, 0, sizeof(dpN));
	memset(arr, false, sizeof(arr));

	fore(i, N){
		int k;
		cin>>k;
		if(k>=0)
			arr[i] = true;
		else
			arr[i] = false;
	}

	dpP[0] = arr[0]?1:0;
	dpN[0] = arr[0]?0:1;

	ll p=dpP[0], n=dpN[0];

	for(int i=1;i<N;i++){
		if(arr[i]){
			dpP[i] = dpP[i-1]+1;
			dpN[i] = dpN[i-1];
		}
		else{
			dpN[i] = dpP[i-1] + 1;
			dpP[i] = dpN[i-1];
		}

		p+=dpP[i];
		n+=dpN[i];
	}

	cout<<n<<" "<<p;
	

	return 0;
}
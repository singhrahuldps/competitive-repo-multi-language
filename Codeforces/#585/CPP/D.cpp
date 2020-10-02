#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fore(i, n) for(int i=0;i<n;i++)
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define MOD 1000000007

int arr[200001];
int main(){

	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	int N;
	cin>>N;
	memset(arr, -1, sizeof(arr));
	queue<int > left, right;
	fore(i, N){
		char k;
		cin>>k;
		if(k!='?')
			arr[i] = k-'0';
	}

	int lSum=0, rSum = 0;
	for(int i=0;i<N/2;i++){
		if(arr[i]>=0)
			lSum+=arr[i];
		else
			left.push(i);

		if(arr[N-i-1]>=0)
			rSum+=arr[N-i-1];
		else
			right.push(N-i-1);
	}

	bool turn = false;
	while(!(left.empty() && right.empty())){
		if(!turn){
			// cout<<"m"<<endl;
			if(lSum>=rSum){
				if(!left.empty()){
					left.pop();
					lSum+=9;
				}else if(!right.empty()){
					right.pop();
				}else{
					break;
				}
			}
			else{
				if(!right.empty()){
					right.pop();
					rSum+=9;
				}else if(!left.empty()){
					right.pop();
				}else{
					break;
				}	
			}
		}else{
			// cout<<"b"<<endl;
			if(lSum>=rSum){
				if(!right.empty()){
					rSum += min((lSum - rSum),9);
					right.pop();
				}else if(!left.empty()){
					left.pop();
				}else{
					break;
				}	
			}else{
				if(!left.empty()){
					lSum += min((rSum - lSum),9);
					left.pop();
				}else if(!right.empty()){
					right.pop();
				}else{
					break;
				}	
			}

		}

		turn = !turn;
	}
	// cout<<lSum<<" "<<rSum;
	if(lSum == rSum)
		cout<<"Bicarp";
	else
		cout<<"Monocarp";
	return 0;
}
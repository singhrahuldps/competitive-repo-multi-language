dp[][][]=-1;
int func (int index, int sum, int num)
{
	if (index==n) {
		if (sum==K && num==L) {
			return 1;
		}
		else {
			return 0;
		}
	}
	if (dp[index][sum][num]!=-1) {
		return dp[index][sum][num];
	}
	int ans=func(index+1, sum, num);
	ans+=func(index+1, sum+array[index], num+1);
	dp[index][sum][num]=ans;
	return ans;
}
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int dp[1000001];
int main()
{
	int n;
	cin >> n;
	
	int idx = 1;
	while (idx!=n)
	{
		if(idx*2 <= n)
		if (dp[idx * 2] == 0 || dp[idx * 2] > dp[idx]+1)
		{
			dp[idx * 2] = dp[idx] + 1;
		}
		if (idx * 3 <= n)
		if (dp[idx * 3] == 0 || dp[idx * 3] > dp[idx] + 1)
		{
			dp[idx * 3] = dp[idx] + 1;
		}
		if (idx +1 <= n)
		if (dp[idx +1] == 0 || dp[idx +1] > dp[idx] + 1)
		{
			dp[idx+1] = dp[idx] + 1;
		}
			idx++;
	}


	cout << dp[n] << endl;
	return 0; 
}
#include <iostream>
#include <vector>
using namespace std;

int max(int a,int b ,int c) {
	return (a > b) ? ((c > a  ) ? c : a) : (b < c) ? c : b;


}
int main()
{


	int n; 
	cin >> n;
	vector<int> v(n+1);
	


	for (int i = 1; i <= n; i++)
	{
		int temp; 
		cin >> temp;

		v[i] = temp;

	}
	v[0] = 0;

	vector<vector<long long int >> dp(3);

	dp[0].resize(n+1);
	dp[1].resize(n+1);
	dp[2].resize(n + 1);

	dp[0][0] = 0;
	dp[1][0] = 0;
	dp[2][0] = 0;

	 int max_ = 0;
	for (int i = 1; i <= n; i++)
	{
		
		dp[0][i]= max(dp[0][i-1] ,dp[1][i - 1], dp[2][i - 1]);

		dp[1][i] = dp[0][i - 1] + v[i];
		dp[2][i] = dp[1][i - 1] + v[i];
		
		int temp = max(dp[0][i], dp[1][i], dp[2][i]);
		if (max_ < temp)
			max_ = temp;
	}


	cout << max_ << endl;


	return 0 ; 
}



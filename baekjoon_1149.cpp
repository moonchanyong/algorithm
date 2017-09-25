#include <iostream>
int dp[3][1000];
#define max_(a, b) (a<b)? a:b // ÀÛÀº°Å ¤»¤»¤»
using namespace std;
int main()
{
	int n;
	cin >> n;
	
	int r,g,b;
	cin >> r >> g >> b;

	dp[0][0] = r;
	dp[1][0] = g;
	dp[2][0] = b;


	for (int i = 1; i < n; i++)
	{

		cin >> r >> g >> b;
		dp[0][i] = (max_(dp[1][i - 1]+r, dp[2][i - 1]+r) ) ;
		dp[1][i] =( max_(dp[0][i - 1]+g, dp[2][i - 1]+g) );
		dp[2][i] =( max_(dp[1][i - 1]+b , dp[0][i - 1]+b));
	}

	int answer = 100000000;
	for (int i = 0; i < 3; i++)
	{
		if (answer>dp[i][n - 1])
		{
			answer = dp[i][n - 1];

		}
	}
	


	cout << answer << endl;
	return 0;
}
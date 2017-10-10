#include<iostream> 
#include<string> 
#include<vector>
#include<algorithm>


using namespace std;
int n;
vector<int> v(301);
unsigned long long int dp(int cc  ,int sum)
{
	if (cc == 0 )
	{
		return sum;
	}
	long long int max = 0;
	long long int temp;

	for (int i = 1; i <= cc; i++)
	{

		temp = dp(cc-i, sum + v[i]);
		if (max < temp)
			max = temp;
	}

	return max;
}


int main()
{

	
	cin >> n;
	unsigned long long int answer;

	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
		
	}

	answer = dp(n,0);



			cout << answer << "\n";

	
	

	return 0;
}
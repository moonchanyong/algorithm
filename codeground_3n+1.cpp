//cdoeground_3n+1
/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>

using namespace std;

unsigned long long  Answer;

int odd(int a)
{
	return ((a*3) + 1);
}
int even(int a)
{
	return a / 2;
}






int main(int argc, char** argv)
{
	int T, test_case;
	/*
	The freopen function below opens input.txt file in read only mode, and afterward,
	the program will read from input.txt file instead of standard(keyboard) input.
	To test your program, you may save input data in input.txt file,
	and use freopen function to read from the file when using cin function.
	You may remove the comment symbols(//) in the below statement and use it.
	Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	But before submission, you must remove the freopen function or rewrite comment symbols(//).
	*/

	// freopen("input.txt", "r", stdin)
	

	
	int dp[64] ;

	for (int i = 1200; i > 1; i--)
	{
		int j = i;
		int length = 0;
		while (j !=1)
		{
			if (j & 1)// È¦¼ö 
			{
				j = odd(j);
				length++;
			}
			else//Â¦¼ö  
			{
				j= even(j);
				length++;
			}
		}
		if(length<64)
		dp[length] = i;
	}
	dp[0] = 1;



	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		unsigned long long int p = 1;
		int k = 0;
		scanf("%d", &k);
		// Print the answer to standard output(screen).
		
		
		printf("Case #%d\n", test_case+1);
		cout << dp[k] << " " << (p<<k)<< endl;



	}














	return 0;//Your program should return 0 on normal termination.
}
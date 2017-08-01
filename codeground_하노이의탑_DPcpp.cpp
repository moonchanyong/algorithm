// codeground_하노이의탑_DP

/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <vector>

using namespace std;

int Answer;
int n;

void dp(int n, int a , int b , int c) 
{

	if (n == 1 )
	{
		
		printf("%d -> %d\n",a,b);

		return;
	}
	dp(n - 1, a, c, b);
	dp(1, a, b, c);
	dp(n-1,c,b,a);
	

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

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////

		cin >> n; // 접시 개수 
		
		cout << "Case #" << test_case + 1 << endl;


		dp(n,1,3,2);
		

			
			


		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).
	}

	return 0;//Your program should return 0 on normal termination.
}
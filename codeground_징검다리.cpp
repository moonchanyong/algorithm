//codeground_징검다리 
/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>

using namespace std;

unsigned long long int Answer;

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
	//선언부 
	int n, k, l;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////

		// 입려부 
		cin >> n >> k >> l;

		unsigned int ** map = new unsigned  int *[k + 1];
		for (int i = 0; i <= k; i++)
			map[i] = new unsigned int[n + 1]();

		int *jr = new int[n]();

		for (int i = 0; i < l; i++)
		{
			int a;
			cin >> a;
			jr[a] = -1;
			}
	

		int i = 1;
		while (i <=n)  
		{
			// DP 실행 문찬용 DP !!!

			if (jr[i] == -1) // 지뢰라면 
			{
				i++;
				continue;
			}


			if (i <= k)
			{
				map[i][i] += 1; // 돈 한개짜리로 하는거 

			}



			for (int j = 1; j <= k ; j++)
			{
				if((i-j)>=1)
				map[j][i] += map[0][i - j] + 1000000009 - map[j][i - j];
				if (map[j][i] >= 1000000009)
					map[j][i] %= 1000000009;
			}

		


			
			for (int j = 1; j <= k; j++)
			{
				map[0][i] += map[j][i]; //합산저장 
				if (map[0][i] > 1000000009)
					map[0][i] %= 1000000009;
			}

			i++;
			
		}


		
		
		Answer = map[0][n];
		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).
		printf("Case #%d\n", test_case+1);
		printf("%d\n", Answer);
	}

	return 0;//Your program should return 0 on normal termination.
}
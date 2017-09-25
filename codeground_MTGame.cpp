/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>

using namespace std;

int Answer;




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
	for (test_case = 0; test_case < 25; test_case++)
	{



		char s[7] = {};
		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		int a, b, c;
		cin >> a >> b >> c;  //입력 
		for (int game = 0; game < c; game++) //게임수만큼 반복
		{
			int temp = 0;

			int n, k;
			char me[1000001] = {};
			cin >> n >> k;
			// 초기 설정 
			me[0] = 'a';
			for (int i = 1; i <= a*k + b; i++)
			{
				if (i < a + 1)
					me[i] = 'b';
				else
					me[i] = 'a';
			}
			// 메모리 제이션 증가 

			if (n > a*k + b)
				for (int meme = a*k + b + 1; meme <= n; meme++)
				{

					me[meme] = 'b';
					for (int i = a; i <= a*k; i++)
					{
						int check = 0;

						for (int j = b; j <= b*k; j++)
						{
							if (meme >= i + j)
							{
								if (me[meme - i - j] == 'a')
									check++;
								if (check != j - b + 1)
									break;
							}


						}

						if (check == (b*k - b + 1))
						{
							me[meme] = 'a';
							break;
						}
					}


				}




			s[game] = me[n];

		}
		cout << "Case #" << test_case + 1 << endl;
		for (int i = 0; i < c; i++) printf("%c", s[i]);
		printf("\n");
		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).

	}

	return 0;//Your program should return 0 on normal termination.
}
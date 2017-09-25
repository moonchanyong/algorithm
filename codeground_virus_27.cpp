// 코드그라운드_바이러스 
/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include<vector>
#include<queue>
using namespace std;
int K, l, n, m;
vector<vector<int>> map;
int Answer;

queue <vector<int>> q;
int recrusive(int i, vector<int> v)  // make a array for answer 
{



	do {

		if (!q.empty())
		{
			v = q.front();
			q.pop();
		}





		// v체크 // n+1 일때 n까지 넣은값들 확인   

		if (i > 0)
		{

			vector<int> e(n + 1);

			// -1 표시
			for (int k = 0; k < v.size(); k++)
				for (int j = 1; j <= n; j++)
				{
					if (map[v[k]][j] == 1)
					{
						map[v[k]][j] = -1;
						map[j][v[k]] = -1;
					}

				}




			//confirm 생성;
			for (int j = 1; j <= n; j++)
			{
				for (int k = 1; k <= n; k++)
				{

					if (map[j][k] == 1) // 행 1개수 셈 
						e[j] += 1;

				}

			}


			int num = 0;
			for (int j = 1; j <= n; j++) //
			{
				if (num < v.size())
					if (v[num] == j)
					{
						if (j == n)  // 다통과 
						{
							int sum = 0;
							// 폐기배여 다합해서  dp 에 표시 
							for (int k = 0; k < v.size(); k++)
								sum += v[k]; // 폐기번호 다합침 
							return sum;

						
						}

						num++;
						continue;

					}


				if (e[j] < K) // K개이하 							
					break;


				// K확인 k개이상 통신되야하고

				if (n - v.size() - l - 1 < e[j]) // L개이하 			
					break;


				// L확인 어느 1개라도 감염되면 l개이상이어야한다 
				if (j == n)  // 다통과 
				{
					int sum = 0;
					// 폐기배여 다합해서  dp 에 표시 
					for (int k = 0; k < v.size(); k++)
						sum += v[k]; // 폐기번호 다합침 
		
					return sum;
					
				}

			}











			// -1 표시
			for (int k = 0; k < v.size(); k++)
				for (int j = 1; j <= n; j++)
				{
					if (map[v[k]][j] == -1)
					{
						map[v[k]][j] = 1;
						map[j][v[k]] = 1;
					}

				}






		}


		if ( (n - v.size()) > l+1) //폐기하고남은게 L개 이하이면			
		for (int j = i; j <= n; j++)   // n+1 들어오면 실행안함 
		{



			vector<int> v2;
			v2.assign(v.begin(), v.end());
			v2.push_back(j);
			q.push(v2);



		}


	}while (!q.empty());


	return n*(n + 1) / 2;
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

		if (!q.empty())
		{
			queue<vector<int>> newone;
			q.swap(newone);
		}
		cin >> K >> l;
		cin >> n >> m;

		map.clear();
		map.resize(n + 1);
		for (int i = 1; i <= n; i++)
			map[i].resize(n + 1);

		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			map[a][b] = 1;
			map[b][a] = 1;
		} // 입력부 종료


		vector<int> temp;

		vector<int> e(n+1);
		
		//confirm 생성;
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{

				if (map[j][k] == 1) // 행 1개수 셈 
					e[j] += 1;

			}

		} // e 생성 



		int check = 0;
		// 0확인 
		int num = 0;
		for (int j = 1; j <= n; j++) //
		{
			


			if (e[j] < K) // K개이하 							
				break;


			// K확인 k개이상 통신되야하고

			if (n - l - 1  < e[j]) // L개이하 			
				break;

			// L확인 어느 1개라도 감염되면 l개이상이어야한다 
			if (j == n)  // 다통과 
			{
				
				check = 1;;
			}

		}



		if (!check)
		{
			Answer = recrusive(1, temp);
		}
		else 
			Answer = 0;

		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
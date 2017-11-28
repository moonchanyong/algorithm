#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
/*
문제 7 
vector<vector<int>> solution(vector<vector<int>> matrix) {
	vector<vector<int>> answer;
	
	int n = matrix[0].size();
	
	vector<int> h;
	vector<int> w;

	for (int i = 0; i < n; i++)
	{
		int temp = 0; 
		for (int j = 0; j < n; j++)
		{
			temp += matrix[i][j];
			


		}
		h.push_back(temp);
		
		temp = 0;
		for (int j = 0; j < n; j++)
		{
			temp += matrix[j][i];



		}

		w.push_back(temp);
	}
	
	answer.resize(n);
	for (int i = 0; i < n; i++)
	{
		
		for (int j = 0; j < n; j++)
		{
			answer[i].push_back(h[i]+w[j]-matrix[i][j]);			
		}
	}
	
	
	
	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다. 
	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j < n; j++)
		{
			cout << answer[i][j] << " ";
		}cout << "\n";
	}
	return answer;
}
*/

// 문제 8 

/*
vector<int> solution(vector<vector<int>> customer, int K) {
	vector<int> answer;
	vector<bool> check(1000001);
	vector<bool> check2(1000001); // 예약중취소 
	queue<int> q;

	for (int i = 0; i < customer.size(); i++)
	{

		switch (customer[i][1])
		{

		case 0:
			if (check[customer[i][0]])
			{
				
					check[customer[i][0]] = 0;
					K++;
					if (!q.empty())
					{
						if (check2[q.front()])
						{
							check2[q.front()] = 0;							
							q.pop();
						}
						
						if (!q.empty())
						{

							check[q.front()] = 1;
							q.pop();
							K--;
						}
						
					}
				
			}
			else
			{
				check2[customer[i][1]] = 1;
			}
			break;

		case 1:
			
			if (K > 0)
			{
				if (check2[customer[i][0]])
				{
					check2[customer[i][0]] = 0;
					break;
				}
				else
				{
					check[customer[i][0]] = 1;
					K--;
				}
			}
			else if (K == 0)
			{
				q.push(customer[i][0]);
			}
			break;


		}

	}

	for (int i = 1; i < 1000001; i++)
	{
		if (check[i])
			answer.push_back(i);
	}


	return answer;
}
*/

//문제 4 
/*
int solution(int l, vector<int> v) {
	int answer = 0;
	v.push_back(0);
	v.push_back(l);
	sort(v.begin(), v.end());

	int max = 0;
	for (int i = 1; i < v.size(); i++)
	{
		if (max < (v[i] - v[i - 1]))
		{
			max = (v[i] - v[i - 1]);
		}
	}
	cout << max << "\n";
	if (max & 1) //홀수
	{
		answer = (max / 2) + 1;
	}
	else
	{
		answer = max / 2;
	}
	return answer;
}
*/
//문제 6번


vector<int> solution(int N, vector<vector<int> > relation)
{
	vector<int> answer(N);
	
	vector<vector<bool>> gr(N+1);
	for (int i = 1; i < N+1; i++)
	{
		gr.resize(N + 1);
	}


	for (int i = 0; i < relation.size(); i++) //연결관계 확인
	{
		gr[relation[i][0]][relation[i][1]] = 1;
		gr[relation[i][1]][relation[i][0]] = 1;
	}


	for (int i = 1; i <= N;i++)
	{
		vector<bool> check(N + 1);
		
		for (int j = 1 ; j <= N ; j++)
		{
			if (gr[i][j] && !check[j])
			{
				check[j] = 1;
				
				for (int k = 1; k <= N; k++)
				{
					if (gr[j][k])
						check[k] = 1;
				}

			}
		}
		int count = 0;
		for (int j = 0; j < check.size(); j++)
		{
			if (check[j])
				count++;
		}
		answer.push_back(count);
	}
	
	
	return answer;
}


/*
int solution(int x, int y, int r, int d, vector<vector<int> > target)
{
	int answer = 0;


	for (int i = 0; i < target.size(); i++)
	{
		float len = sqrt((target[i][0] * target[i][0]) + (target[i][1] * target[i][1]));
		//길이 내에있나
		if ((float)d >= len)
		{
			float gak = asin( ( (x*target[i][1]) -(y*target[i][0]))   / ( sqrt((x*x)+(y*y)) * len ) );
		
			if (60 >= gak)
			{	// 각도 내 있나
				answer++;
			}

		}
	}




		
	



	return answer;
}





// 



int solution(vector<vector<int>> p)
{
	queue<int> q;
	vector <bool>check(1001);
	vector<vector<bool>> gr(1001);
	for (int i = 1; i < 1001; i++)
	{
		gr.resize(1001);
	}

	for (int i = 0; i < p.size(); i++)
	{
		gr[p[i][0]][p[i][1]] = 1;
		gr[p[i][1]][p[i][0]] = 1;
		if (!check[p[i][0]])
		{
			check[p[i][0]] = 1;
			q.push(p[i][0]);
		}
		if (!check[p[i][1]])
		{
			check[p[i][1]] = 1;
			q.push(p[i][1]);
		}
	}
	vector<int> v;
	while (!q.empty())
	{
		v.push_back(q.front);
		q.pop();
	}
	int answer = 0;
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = i+1; j < v.size(); j++)
		{
			if (gr[v[i]][v[j]] && gr[v[j]][v[i]])
				answer++;
		}

	}
	return answer;
	
}

*/
/*
int solution(vector<vector<int>> p)
{
	queue<int> q;
	vector <bool>check(1001);
	vector<vector<bool>> gr(1001);
	for (int i = 1; i < 1001; i++)
	{
		gr[i].resize(1001);
	}

	for (int i = 0; i < p.size(); i++)
	{
		gr[p[i][0]][p[i][1]] = 1;
		if (!check[p[i][0]])
		{
			check[p[i][0]] = 1;
			q.push(p[i][0]);
		}
		if (!check[p[i][1]])
		{
			check[p[i][1]] = 1;
			q.push(p[i][1]);
		}
	}
	vector<int> v;
	while (!q.empty())
	{
		v.push_back(q.front());
		q.pop();
	}
	int answer = 0;
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = i + 1; j < v.size(); j++)
		{
			if (gr[v[i]][v[j]] && gr[v[j]][v[i]])
				answer++;

		}

	}
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}

	return answer;

}

int main()
{

	vector<vector<int> > test(5);
	test[0].push_back(1);
	test[0].push_back(3);
	test[1].push_back(3);
	test[1].push_back(1);
	test[2].push_back(3);
	test[2].push_back(5);
	test[3].push_back(2);
	test[3].push_back(5);
	test[4].push_back(5);
	test[4].push_back(3);
	solution(test);
	return 0;
}
*/

/*
int solution(vector<vector<int> > seat)
{
	int answer = 0;
	vector<vector<bool>> check(100001);
	for (int i = 1; i < 100001; i++)
	{
		check[i].resize(100001,0);
	}

	for (int i = 0; i < seat.size(); i++)
	{
		if (!check[seat[i][0]][seat[i][1]])
			answer++;
		check[seat[i][0]][seat[i][1]] = 1;
	}

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다. 
	

	return answer;
}*/







long long solution(int n, int r, int c) {
	long long answer = 0;


	long long  gun = (c - 1) + r;

	if (gun <= n) // 증가 
	{

		long long s = (gun - 1)*(gun - 2) / 2;
		long long e = (gun)*(gun - 1) / 2;
		if (gun & 1) // 홀수 
		{
			answer = s + c;
		}
		else
		{
			answer = e - c+1;
		}


	}
	else
	{
		long long s = (n - 1)*(n) / 2;
		long long temp = 0;
		for (int i = 1; i <= (gun-n); i++)
		{
			temp+=(n-i);
		}

		long long e = s + temp;
		if (gun & 1) // 홀수 
		{
			answer = s + (n-r)+1;
		}
		else
		{
			answer = e -(n-r);
		}

	}

	
	

	return answer;
}





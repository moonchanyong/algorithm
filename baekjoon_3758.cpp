#include<string>
#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<unordered_set>
#include <algorithm>

using namespace std;
#define ppp(x) cout << x 



bool sumcmp(int a, int b)
{
	return a > b; 

}



int main(){


	int T;
	cin >> T;
	for (int test_case = 0; test_case < T; test_case++)
	{


		int n, k, t, m;
		cin >> n >> k >> t >> m;

		vector<vector<int>> log(n + 1);
		for (int i = 1; i < n + 1; i++)
		{
			log[i].assign(k + 1,0);
		}

		vector<int> sum(n + 1);
		vector<int> last(n + 1);
		vector<int> count(n + 1);
		sum[0] = -11111111;
		count[0] = 100000000;
		last[0] = 10000000;
		int a, b, c;
		for (int i = 0; i < m; i++)
		{
			cin >> a >> b >> c;

			if (log[a][b] < c)
			{
				sum[a] += c - log[a][b];
				log[a][b] = c;
			}
			count[a] ++;
			last[a] = i;
		}
		queue<int> q;
		int temp = sum[t];
		for (int i = 1; i < n + 1; i++)
		{
			if (sum[t] == sum[i]) // 점수동점자 확인
			{
				q.push(i);

			}
		}

		int count_s = 0;

		sort(sum.begin(), sum.end(), sumcmp); //내림차순학인

		for (int i = 0; i < n + 1; i++)
		{
			count_s++;
			if (temp == sum[i]) // 동점자 만난면 브레이크 
			{				
				break;
			}
		}

		if (q.size() == 1)
		{ // sort 해서 출력 
			cout << count_s << " \n";
			continue;
		}
		else
		{  // 제출횟수비교 

			temp = count[t];
			int idx = q.size();
			int count_c = 0;
			while (idx > 0)
			{

				if (temp > count[q.front()])
					count_c++;


				if (count[q.front()] == temp)
				{
					q.push(q.front());
				}

				q.pop();
				idx--;
			}

			if (q.size() == 1)
			{

				cout << count_s + count_c  << " \n";
				continue;
			}
			else // 마지막 제출 비교 
			{

				temp = last[t];
				idx = q.size();
				int count_l = 0;
				while (idx > 0)
				{
					if (last[q.front()] < temp)
					{
						count_l++;
					}
					q.pop();
					idx--;
				}


				cout << count_s + count_c  + count_l << " \n";
				continue;

			}

		}




	}


	
		return 0;
	}





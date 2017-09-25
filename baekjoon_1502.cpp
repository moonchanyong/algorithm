#include <iostream>
#include <stack>

using namespace std;

int map[101][101]; // visit check
pair<int,int> s;
pair<int, int> e;
bool answer; 
int m, n;
stack<pair<int,int>> stk;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};

void re(pair<int ,int> p)
{



	if (p.first == e.first && p.second == e.second )
	{
	
		if (m*n - 1 == stk.size())
		{
			answer = 1;
			return ;
		}
		else
		{
			return;
		}
	}


	for (int i = 0; i < 4; i++)
	{

		if (p.first + dx[i] >= 0 && p.first + dx[i] < m && p.second + dy[i] >= 0 && p.second + dy[i] < n) // 범위만족 
		{
			//p.first + dx[i] 
			// p.second + dy[i] 
			if (!map[p.first + dx[i]][p.second + dy[i]]) // visitcheck 안되있을때 
			{

				map[p.first + dx[i]][p.second + dy[i]] = 1;
				pair<int, int> temp;
				temp.first = p.first + dx[i];
				temp.second = p.second + dy[i];
				stk.push(temp);
				re(temp);
				if (answer)
					return ;
				stk.pop();
				map[p.first + dx[i]][p.second + dy[i]] = 0;


			}



		}


	}

	



}





int main()
{



	int T; 
	cin >> T;

	for (int testcase = 0; testcase < T; testcase++)
	{
		answer = 0;
		if (!stk.empty())
		{
			stack<pair<int, int>> ss;
			ss.swap(stk);
		}

		cin >> m >> n;
		
			
		cin >> s.first >> s.second;
		cin >> e.first >> e.second;

		s.first -= 1;
		s.second -= 1;
		e.first -= 1;
		e.second -= 1;

		map[s.first][s.second]=1;


		re(s);


		map[s.first][s.second] = 0;
		cout << ((answer != 1) ? -1 : 1) << "\n";


		if (answer) {
			// 출력  1 , -1
			while (!stk.empty())
			{

				cout << stk.top().first + 1 << " " << stk.top().second + 1 << "\n";
				map[stk.top().first][stk.top().second] = 0;
				stk.pop();
			}
			cout << s.first + 1 << " " << s.second + 1 << "\n";
		} 
			
		

	

	
}




	return 0;
}
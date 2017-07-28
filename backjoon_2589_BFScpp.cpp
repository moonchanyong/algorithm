//백준_2589_BFS
#include <vector> 
#include <iostream>
#include <queue>
using namespace std;
vector<vector<char>> v;
vector<vector<bool>> visited;
queue<int> qx;
queue<int> qy;
queue<int> counti;
int n,c;
int answer = 0;
int county = 0;
int bfs(int a,int b)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0;j < c; j++)
			visited[i][j] = false;
	}
	int x =0, y = 0;


	county += 1;


	qx.push(a);
	qy.push(b);
	counti.push(county);
	
	do {
		
		x = qx.front();
		y = qy.front();
		county=counti.front();
		qx.pop();
		qy.pop();
		counti.pop();
		visited[x][y] = true;
		if (answer < county)
			answer = county;
		if (x != 0 && (v[x - 1][y] == 'L') &&  (visited[x-1][y] !=true)) // 위 
		{
			qx.push(x - 1);
			qy.push(y);
			counti.push(county + 1);
		}
		if (x != n-1 && (v[x + 1][y] == 'L' )&& (visited[x + 1][y] != true)) // 위 
		{
			qx.push(x + 1);
			qy.push(y);
			counti.push(county + 1);
		}
		if (y != 0 && (v[x ][y-1] == 'L') && (visited[x ][y-1] != true)) // 위 
		{
			qx.push(x );
			qy.push(y-1);
			counti.push(county + 1);
		}
		if (y != n-1 && (v[x][y+1] == 'L') &&( visited[x][y+1] != true)) // 위 
		{
			qx.push(x);
			qy.push(y+1);
			counti.push(county + 1);
		}

	} while (qx.empty() == false);

	
	return 0;
}

int main(int argc, char** argv)
{
	
	int a, b;
	char s;
		cin >> n >> c ; // n : 행 c : 열

		v.resize(n);
		visited.resize(n);
		for (int i = 0; n > i; i++)
			visited[i].resize(c); //선언부 

		for (int i = 0; n > i; i++)
		{
			for (int j = 0; c > j;j++) {
			cin >> s;
			v[i].push_back(s);
		}
		}// 입력 

		for(int i = 0 ; i < n ; i++)
			for (int j = 0; j < n; j++)
			{
				if (v[i][j] == 'W' )
					continue;

			if (v[i][j] == 'L')
				{					
				county = 0;
				bfs(i, j);
								
				}
			}
		
		cout << (answer-1) << endl;
	
	return 0;//Your program should return 0 on normal termination.
}
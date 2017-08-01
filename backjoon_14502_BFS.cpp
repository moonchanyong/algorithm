//baekjoon_14502_BFS

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int x, y, dir;
int w = 0, n = 0, temp;
struct pair2 {
	int x;
	int y;
	pair2(int a , int b) {
		x = a;
		y = b;
	}
};
pair2 p(0,0);
queue<pair2> q1;

queue<pair2> q;

vector<vector<int>> map(10);
vector<vector<int>> visited(10);


int answer = 0;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0 , 1, 0,-1};
void bfs() 
{
	
	temp = 0;
	while (!q.empty())
	{

		p =q.front();
		q.pop(); // 제거 

		for (int j = 0; j < 4; j++)
		{
			if (0 <= (p.x + dx[j]) && (p.x + dx[j]) < w && 0 <= (p.y + dy[j]) && (p.y + dy[j]) < n)
			{
				if (visited[p.x + dx[j]][p.y + dy[j]] == 0)
				{
					visited[p.x + dx[j]][p.y + dy[j]] = 2;
					
					q.push(pair2(p.x + dx[j],p.y + dy[j]));
				}
			}
		}
			

	}
		for (int j = 0; j < w; j++)
		for (int i = 0; i < n; i++)
		{
			
			if (visited[j][i] == 0)
			{
				temp += 1;
				
			}
			
		} // 입력부 종료 



		if ( answer < temp)
			answer = temp;

}



int main(int argc, char** argv)
{

	
	cin >> w>> n;
	

	

	for (int j = 0; j < w; j++)
		for (int i = 0; i < n; i++)
		{
			cin >> temp;
			map[j].push_back(temp);
			if (temp == 2)
			{
				
				p.x = j;
				p.y = i;

				q1.push(p);
			}
		} // 입력부 종료 


	// BFS 이용 
	


	for (int k = 0; k < w*n; k++)
	{

		
		for (int k1 = k + 1; k1 < w*n; k1++)
		{

	
			for (int k2 = k + 2; k2 < w*n; k2++)
			{

				visited.clear();
				visited.assign(map.begin(), map.end());
				q = q1;
				if (visited[k / n][k%n] != 0)
					continue;
				visited[k / n][k%n] = 1;
				if (visited[k1 / n][k1%n] != 0)
					continue;
				visited[k1 / n][k1%n] = 1;
				if (visited[k2 / n][k2%n] != 0)
					continue;
				visited[k2 / n][k2%n] = 1;

				bfs();
				



			}
		}
	}

	


	cout << answer << endl;


	return 0;//Your program should return 0 on normal termination.
}
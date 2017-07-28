//백준_2606_DFS
#include <vector> 
#include <iostream>
#include <string.h>
using namespace std;
vector<vector<int>> v;
vector<bool> visited;
int answer = 0;
void dfs(int i)
{	
	visited[i] = true;
	if(i!=1)
	answer += 1;
	for (int j = 0; j<v[i].size(); j++)
	{
		if(visited[v[i][j]] !=true) //false이면 방문 
		dfs(v[i][j]);
	}


}

int main(int argc, char** argv)
{
	int n,c;
	int a, b;

		cin >> n; // 노드 수
		cin >> c; // 연결 수 


		v.resize(n + 1);
		visited.resize(n + 1);
		for (int i = 0; c > i; i++)
		{
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}

		dfs(1);
		cout << answer << endl;
	return 0;//Your program should return 0 on normal termination.
}
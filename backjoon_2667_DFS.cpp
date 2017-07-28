//πÈ¡ÿ_2667_DFS
#include <vector> 
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
vector<vector<char>> v;
vector<vector<bool>> visited;
int n;
int answer = 0;
int county = 0;
void dfs(int a,int b)
{
	county += 1;
	visited[a][b] = true;
	if(a != 0)
	if (v[a - 1][b] == '1' && visited[a - 1][b] != true ) // ¿ß 
		dfs(a - 1, b);
	if(b != 0)
	if (v[a][b - 1] == '1' && visited[a][b - 1] != true ) // øﬁ 
		dfs(a, b - 1);
	if(a != n - 1)
	if (v[a+1][b] == '1' && visited[a+1][b] != true ) // øﬁ 
		dfs(a+1, b );
	if(b != n - 1)
	if (v[a][b + 1] == '1' && visited[a][b + 1] != true ) // øﬁ 
		dfs(a, b + 1);
		
		

}

int main(int argc, char** argv)
{
	vector<int> count;
	int a, b;
	char s;
		cin >> n; // ≥ÎµÂ ºˆ
		


		v.resize(n);
		visited.resize(n);
		
		for (int i = 0; n > i; i++)
			visited[i].resize(n);

		for (int i = 0; n > i; i++)
		{
			for (int j = 0; n > j;j++) {
			cin >> s;
			v[i].push_back(s);
		}
		}

	


	

		for(int i = 0 ; i < n ; i++)
			for (int j = 0; j < n; j++)
			{
				if (v[i][j] == '0' || visited[i][j]==true)
					continue;

			if (v[i][j] == '1')
				{
					answer += 1;
					county = 0;
					dfs(i, j);
					count.push_back(county);
				}
			}
		
		cout << answer << endl;
		sort(count.begin(),count.end());
		for(int i = 0 ; i < count.size() ; i++)
			cout << count[i] << endl;

	//	cout << answer << endl;
	return 0;//Your program should return 0 on normal termination.
}
// A C++ program to find maximal Bipartite matching.
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;



vector<int> m_;

int m, n;

bool find_(vector<vector<bool> > map, int u, vector<bool> visited, vector<int>& m_)
{

	for (int v = 0; v < n; v++)
	{
	
		if (map[u][v] && !visited[v])
		{
			visited[v] = true; // Mark v as visited

			
			if ((m_[v] < 0) || (find_(map, m_[v], visited, m_)))
			{
				m_[v] = u;
				return true;
			}
		}
	}
	return false;
}

int max_find(vector<vector<bool> > map)
{

	m_.resize(n,-1);



	int result = 0; 
	for (int u = 0; u < m; u++)
	{

		vector<bool> visited(n);



		if (find_(map, u, visited, m_))
			result++;
	}
	return result;
}


int main()
{


	cin >> m >> n;
	
	vector<vector<bool> > map(m);
	for (int i = 0; i < m; i++)
	{
		map[i].resize(n);
	}

	for (int i = 0; i < m; i++)
	{
		int a;
		cin >> a;
		for (int j = 0; j < a; j++)
		{
			int b;
			cin >> b;
			map[i][b - 1] = 1;
		}
		
	}


	int answer;
	answer= max_find(map);
	cout << answer << "\n";
	return 0;
}
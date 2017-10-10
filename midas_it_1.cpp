#include<iostream> 
#include<string> 
#include<vector>
#include<algorithm>

using namespace std;


int main()
{

	int n , m ,k;
	cin >> n >> m >> k;
	


	vector<vector<bool> >map(n);
	for (int i = 0; i < n; i++)
	{
		map[i].resize(m,0);
	}

	int r, c1, c2;
	for (int i = 0; i < k; i++)
	{
		cin >> r >> c1 >> c2;
		
		for (int j = c1-1; j < c2; j++)
		{
			map[r - 1][j] = 1;
		}


	}
	
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!map[i][j])
			{
				count++;
			}
		}
	}

	cout << count << "\n";
	return 0;
}
#include<iostream> 
#include<string> 
#include<vector>
#include<algorithm>
#include<queue>
#include<map>

using namespace std;




int main() {

	int n, m;

	cin >> n;
	cin >>	m;
	char a, b;
	vector<int> check(n,0);

	vector<vector<char> > mmap(n);
	queue<int> q;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		mmap[a-'A'].push_back(b);
		check[b - 'A'] ++;
		
	}
	char temp;
	vector<int> chk(n, 0);
	for (int i = 0; i < n; i++)
	{
		temp = 'A' + i;

		if (check[i] == 0 && !chk[i])
		{
			cout << temp;
			chk[i] = 1;
			if (mmap[i].size() != 0)
			{
				for (int j = 0; j < mmap[i].size(); j++)
				{
					check[mmap[i][j] - 'A']--;

				}
				i = -1;

			}
		

		}
		




	}
	cout << "\n";


	
	return 0;
}
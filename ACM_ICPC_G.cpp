#include <iostream>
#include <string>
#include <queue>



using namespace std;





struct p {

	int x, y;
	p(int a,int b) {
		x = a;
		y = b;
	};

};
queue<p> q;
//vector<ss> q;
int main()
{

	p temp(0,0) ;
	short dx[] = { -1, 0 , 1 , 0 };
	short dy[] = { 0 , -1 , 0 , 1 };
	short m, n;

	cin >> m >> n;
	//1000까지 
	
	short ** map = new short*[m]();
	for (int i = 0; i < m; i++)
		map[i] = new short[n]();
	bool check = 1;
	bool ** visited = new bool*[m]();
	for (int i = 0; i < m; i++)
		visited[i] = new bool[n]();

	bool input = 0;
	string s;
	for (int i = 0; i < m; i++)
	{
		cin >> s;

		for (int j = 0; j < n; j++)
		{
		
		if (s[j] == 49)
			input = 0;				
		else
		{
			input = 1;
			if (i==0)
			{
				check = 0;
				visited[i][j] = 1;
				temp = p(i, j);
				q.push(temp);
			}
		}
		map[i][j] = input;


		}

	}
	check = 0;
	while (!q.empty())
	{
		temp = q.front();
		q.pop();


		


		for (int i = 0; i < 4; i++)
		{
			if (temp.x + dx[i] >= 0 && temp.y + dy[i] >= 0 && temp.x + dx[i] < m && temp.y + dy[i] < n) // 배열범위 체크 
			{

				if (map[temp.x + dx[i]][temp.y + dy[i]] && !visited[temp.x + dx[i]][temp.y + dy[i]]) // visited + 다음 값있나 
					{


					
						visited[temp.x + dx[i]][temp.y + dy[i]] = 1; 

						if ( temp.x + dx[i] == m - 1)
						{
							check = 1;

						}
						q.push(p(temp.x + dx[i], temp.y + dy[i])); 
					}

				
						








			}

			if (check)
				break;

		}


		if (check)
			break;




	}










	cout << ((check) ? "YES" : "NO") << endl;



	return 0;
}
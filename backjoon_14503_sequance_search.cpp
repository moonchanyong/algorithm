//baekjoon_14503_sequance_search

#include <iostream>
#include <vector>

using namespace std;
int x, y, dir;

int answer = 0;



int main(int argc, char** argv)
{

	
	int w=0, n=0,temp;
	cin >> w>> n;
	
	vector<vector<bool>> visited(w);
	vector<vector<int>> map(w);
	cin >> x >> y >> dir;

	for (int j = 0; j < w; j++)
		for (int i = 0; i < n; i++)
		{
			cin >> temp;
			map[j].push_back(temp);
			if(temp == 1 )
			visited[j].push_back(true);
			else 
			visited[j].push_back(false);
		} // 입력부 종료 


	// DFS 위상정렬 이용 
	int check = 0;

	map[x][y] = 2; //현재위치 청소 
	answer++;

	while (1)
	{
		/*printf("\n\n\n");
		for (int j = 0; j < w; j++)
		{
			for (int i = 0; i < n; i++)
			{
				printf("%d ", map[j][i]);


			}
			printf("\n");
		}
		printf("x : %d  y : %d dir : %d", x, y, dir);
		*/
		if (check == 4)
		{
			if (dir == 0)
			{
				if (map[x + 1][y] != 1) //뒤쪽이 벽이아닐때 
				{
					x = x + 1;
					y = y;
					check = 0;
					continue;
				}
				else
				{
					break;
				}
			}
			else if (dir == 1)
			{
				if (map[x][y - 1] != 1)
				{
					x = x;
					y = y - 1;
					check = 0;
					continue;
				}
				else
				{
					break;
				}
			}
			else if (dir == 2)
			{
				if (map[x - 1][y] != 1)
				{
					x = x - 1;
					y = y;
					check = 0;
					continue;
				}
				else
				{
					break;
				}
			}
			else if (dir == 3)
			{
				if (map[x][y + 1] != 1)
				{
					x = x;
					y = y + 1;
					check = 0;
					continue;
				}
				else
				{
					break;
				}
			}

		}

		if (dir == 0)
		{
			if (map[x][y - 1] == 0) //왼쪽에 청소 가능한 경우 실행 
			{
				x = x;
				y = y - 1;
				map[x][y] = 2;
				answer += 1;
				dir--;
				if (dir == -1)
					dir = 3;
				check = 0;
			}
			else
			{
				dir--;
				if (dir == -1)
					dir = 3;
				check++;


			}
		}
		else if (dir == 1)
		{
			if (map[x - 1][y] == 0)
			{
				x = x - 1;
				y = y;
				map[x][y] = 2;
				answer += 1;
				dir--;
				if (dir == -1)
					dir = 3;
				check = 0;

			}
			else
			{
				dir--;
				if (dir == -1)
					dir = 3;
				check++;


			}
		}
		else if (dir == 2)
		{
			if (map[x][y + 1] == 0)
			{
				x = x;
				y = y + 1;
				map[x][y] = 2;
				answer += 1;
				dir--;
				if (dir == -1)
					dir = 3;
				check = 0;
			}
			else
			{
				dir--;
				if (dir == -1)
					dir = 3;
				check++;

			}
		}
		else if (dir == 3)
		{
			if (map[x + 1][y] == 0)
			{
				x = x + 1;
				y = y;
				map[x][y] = 2;
				answer += 1;
				dir--;
				if (dir == -1)
					dir = 3;
				check = 0;
			}
			else
			{

				dir--;
				if (dir == -1)
					dir = 3;
				check++;
			}
		}
	}


	cout << answer << endl;


	return 0;//Your program should return 0 on normal termination.
}
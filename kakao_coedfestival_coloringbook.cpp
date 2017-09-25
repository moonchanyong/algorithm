#include <vector>
#include <queue>

using namespace std;

struct p {
	int x;
	int y;

};

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> map) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;
	int dx[4] = {1 , -1 , 0 , 0 };
	int dy[4] = {0 , 0 , -1 , 1 };

	vector<vector<bool>> visited(m);
	for (int i = 0; i < m; i++)
	{
		visited[i].resize(n);
	}
	int count=0;
	p temp;
	int max_area = 0;
	for (int i = 0; i < m; i++)
	{

		for (int j = 0; j < n; i++)
		{

			if (map[i][j] == 0 || visited[i][j])
				continue;

			queue<p> q;
			int area_count = 1;			
			temp.x = i;
			temp.y = j;
			
			q.push(temp);
			while (!q.empty())
			{
				temp = q.front();
				q.pop();
				
				for (int k = 0; k < 4; k++)
				{
					if (temp.x + dx[k] >= 0 && temp.x + dx[k] < m && temp.y + dy[k] >= 0 && temp.y + dy[k] < n)
					{
						// visited chceck
						if (!visited[temp.x + dx[k]][temp.y + dy[k]] && map[temp.x + dx[k]][temp.y + dy[k]] == map[temp.x ][temp.y]) // 가능 
						{

							visited[temp.x + dx[k]][temp.y + dy[k]] = 1;
							p temp_;
							temp_.x = temp.x + dx[k];
							temp_.y = temp.y + dy[k];
							
							q.push(temp_);
							area_count++;
						}

					}


				}





			}

				count++;
				if (max_area < area_count)
					max_area = area_count;
		}



	}





		vector<int> answer(2);
	answer[0] = count;
	answer[1] = max_area;
	return answer;
}
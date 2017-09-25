#include<vector>
using namespace std;
#define MAX(X,Y,Z) ((X>Y)? ((X>Z)? X:Z ): ((Y>Z)? Y : Z ) )

int solution(vector<vector<int> > land)
{
	int answer = 0;
	int map[5][100000];
	map[0][0] = land[0][0];
	map[1][0] = land[0][1];
	map[2][0] = land[0][2];
	map[3][0] = land[0][3];

	for (int i = 1; i < land.size(); i++)
	{
		for (int k = 0; k < 4; k++)
		{
			if (k == 0)
				map[k][i] = MAX(map[1][i - 1], map[2][i - 1], map[3][i - 1]) + land[i][k];
			else if (k == 1)
				map[k][i] = MAX(map[0][i - 1], map[2][i - 1], map[3][i - 1]) + land[i][k];
			else if (k == 2)
				map[k][i] = MAX(map[1][i - 1], map[0][i - 1], map[3][i - 1]) + land[i][k];
			else if (k == 3)
				map[k][i] = MAX(map[1][i - 1], map[2][i - 1], map[0][i - 1]) + land[i][k];
		}

	}
	if (map[0][land.size() - 1] > map[1][land.size() - 1])
		return MAX(map[0][land.size() - 1], map[2][land.size() - 1], map[3][land.size() - 1]);
	else
		return MAX(map[1][land.size() - 1], map[2][land.size() - 1], map[3][land.size() - 1]);
}
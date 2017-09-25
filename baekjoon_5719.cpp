//baekjoon_5719
/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

struct sun {
	int y = 0;
	int w = 0;
	int his[500][2];
	int c = 0;
	sun() {};
	sun(sun temp, int i, int ww)
	{

		memcpy(his, temp.his, temp.c * sizeof(int) *2);
		c = temp.c;
		his[c][0] = temp.y;
		his[c][1]= i;
		y = i;
		w = ww;



		c++;
		//his = d; // ���߿� �ʿ��Ҷ� 

	}
};

bool operator<(sun a, sun b) {
	return a.w > b.w; //�����ź��� ��� 

}
priority_queue<sun> q;


// ���ͽ�Ʈ�� �ּ� ��� ���� 

int daikstra(int s, int d, int** &map, int n , int swit)
{
	priority_queue<sun> q2;
	// ����� 

	int *values = new int[n]();

	memset(values, 10000, n * sizeof(int));

	// ���ͽ�Ʈ�� ���� 
	sun temp = sun();
	temp.y = s;
	q.push(temp);
	sun re;
	int check = 1;

	while (!q.empty())
	{
		temp = q.top();
		q.pop();


		if (temp.y == d)
		{
			re = temp;

			q2.push(re);

			check = 0;

		}
		else
			for (int i = 0; i < n; i++)
			{
				if (map[temp.y][i] != 0 &&( temp.w + map[temp.y][i]) <= values[i]) // values ����  �۴ٸ� 
				{
					values[i] = temp.w + map[temp.y][i]; // �ּ� ��
					q.push(sun(temp, i, temp.w + map[temp.y][i]));
				}
			}


	}
	if (check)
		return -1;
	if (swit)
	{
		re = q2.top();
		return re.w;
	}

	// ���� �� ��� ����	
	re = q2.top();
	for (int i = 0; i < re.c; i++)
	{
		map[re.his[i][0]][re.his[i][1]] = 0;
		// ��� ������ 

	/* printf("%d , %d ���� \n", re.his[i][0] , re.his[i][1]);
		printf("-----------------------------------------\n");
		for (int j = 0; j < n; j++)
		{
		for (int k = 0; k < n; k++)
		printf("%d ", map[j][k]);

		printf("\n");
		}
	*/	
	}
	q2.pop();
	while (1)
	{
		if (q2.empty())
			return -1;
		if (re.w != q2.top().w)
		{
			return  0;
		}
		else //���ٸ� ����� 
		{
			check = 1;
			re = q2.top();
			for (int i = 0; i < re.c; i++) //check �̹� ������ ������� 
			{
				if (map[re.his[i][0]][re.his[i][1]] == 0)
				{
					check = 0;
					break;
				}
				 
			
			}
			if(1)
			for (int i = 0; i < re.c; i++) //check �̹� ������ ������� 
			{
			
					map[re.his[i][0]][re.his[i][1]] = 0;
	
			}

		}
		q2.pop();

	}

	// ����ġ ���� 
	

}


int main(int argc, char** argv)
{
	int answer = 0;
	int  n, m;
	int s, d;
	int temp2;
	while (1)
	{
	
		cin >> n >> m;
		if (!n || !m) //�Ѵ� 0 
			break;
	
		cin >> s >> d;

		//�����
		int **map = new int*[n]();
		for (int i = 0; i < n; i++)
			map[i] = new int[n]();

	
		// �Էº� 
		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			cin >> map[a][b];

		} // �Էº� ���� 

		  //�ݺ� ���ͽ�Ʈ�� ����  ���� �޶��������� 

		temp2 = daikstra(s, d, map, n , 0 );
		temp2 = daikstra(s, d, map, n , 1);
		

		// �� �޶����� ��� 
		printf("%d\n", temp2);

	}




	return 0;//Your program should return 0 on normal termination.
}
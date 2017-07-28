//����_7569_BFS
#include <vector> 
#include <iostream>
#include <queue>
using namespace std;
vector<vector<vector<int>>> v;


int n, c, f, counta = 0;
int answer = 0;
struct pair3 {
	int x;
	int y;
	int z;
	int count;
};
queue<pair3> q;
int main()
{


	int s;
	cin >> n >> c >> f; // n : �� c : �� // �� 

	v.resize(f);
	for (int i = 0; i < f; i++)
		v[i].resize(c);

	for (int k = 0; f > k; k++)
	{
		for (int i = 0; c > i; i++)
		{
			for (int j = 0; n > j; j++) {
				cin >> s;
				v[k][i].push_back(s);
			
				if (1 == v[k][i][j])
				{
					
					q.push(pair3{ k,i,j,0 });
				
				}
			}
		}// �Է� 
	}



	int i, j, k, cc;
	struct pair3 temp;



	while (!q.empty())
	{


		temp = q.front();
		q.pop();
		k = temp.x;
		i = temp.y;
		j = temp.z;
		cc = temp.count;
		if (cc > answer)
			answer = cc;
		// ��
		if (k+1 < f )
			if (v[k + 1][i][j] == 0)
			{
				q.push(pair3{ k + 1,i,j,cc + 1 });
				v[k + 1][i][j] = 1;
			}
		//�� 
		if (i-1 >= 0)
			if (v[k][i - 1][j] == 0)
			{
				q.push(pair3{ k,i - 1,j,cc + 1 });
				v[k][i - 1][j] = 1;
			}
		// �� 
		if (j-1>= 0)
			if (v[k][i][j - 1] == 0)
			{
				q.push(pair3{ k,i,j - 1,cc + 1 });
				v[k][i][j - 1] = 1;
			}
		// ��
		if (j+1 < n )
			if (v[k][i][j + 1] == 0)
			{
				q.push(pair3{ k,i,j + 1,cc + 1 });
				v[k][i][j + 1] = 1;
			}
		// �� 
		if (k-1 >= 0)
			if (v[k - 1][i][j] == 0)
			{
				q.push(pair3{ k - 1,i,j,cc + 1 });
				v[k - 1][i][j] = 1;
			}
		// �Ʒ�
		if (i+1 < c )
			if (v[k][i + 1][j] == 0)
			{
				q.push(pair3{ k,i + 1,j,cc + 1 });
				v[k][i + 1][j] = 1;
			}
	/*
		for (int k = 0; f > k; k++)
		{
			printf("%d�� -----------------------\n",k);
			for (int i = 0; c > i; i++)
			{
				for (int j = 0; n > j; j++) {

					printf("%d ",v[k][i][j]);
				}
				printf("\n ");
			} // ��� 
		}
		*/
	}

	
	for (int k = 0; f > k; k++)
	{
		for (int i = 0; c > i; i++)
		{
			for (int j = 0; n > j; j++) {


				if (v[k][i][j] == 0)
				{
					printf("-1\n");
					return 0;
				}
				if (v[k][i][j] == -1)
					counta += 1;
			}
		}
	}// �Է� 
	
	printf("%d\n", answer);


	return 0;//Your program should return 0 on normal termination.
}
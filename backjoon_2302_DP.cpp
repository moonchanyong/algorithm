//백준_2302_DP
#include <vector> 
#include <iostream>
#include <queue>
using namespace std;
int arr[1000][3];
int choose[1000]; // 0~2값만 가짐 
int answer = 0;
int dx[] = {0,1,2};


void DP(int i)
{


}

int main()
{
	int n, m , temp;
	int seat[41];
	cin >> n >> m;
	int d[41];
	for (int i = 1; i <= m; i++)
	{
		cin >> temp;
		seat[temp] = -1; // 고정석 -1로표시 
	}
	seat[0] = -1;
	d[0] = 0;
	d[1] = 1;
	for (int i = 2; i <= n; i++)
	{

		if (seat[i] == -1 || seat[i - 1] == -1)
			d[i] = d[i - 1];
		else if (seat[i - 2] == -1)
			d[i] = d[i - 1] * 2;
		else
		{
			d[i] = d[i - 2] + d[i - 1];
		}

	}

	cout << d[n] <<endl;


	return 0;//Your program should return 0 on normal termination.
}
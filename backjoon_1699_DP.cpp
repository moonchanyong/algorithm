//น้มุ_1699_DP
#include <math.h> 
#include <iostream>
#include <queue>
using namespace std;



int main()
{
	int arr[100001][1] = {};
	int n, temp;
	int answer = 10000;
	int count = 0;
	int a, b;
	
		scanf("%d", &n); 






		arr[0][0] = 0;
		arr[1][0] = 1;
	
		for (int i = 1; i <= n; i++)
		{
			
			if( i > 0 && i < 317) //1~316
				arr[i*i][0] = 1;

			if (arr[i][0] == 1)
				continue;

			
			
			
			for (int j = 1; j <= (int)sqrt(i); j++)
			{
			

				count = 1 + arr[i-j*j][0];
				if (arr[i][0] <= 0)
				{
					arr[i][0] = count;
				}
				if (arr[i][0] > count && count > 0)
				{
					arr[i][0] = count;
				}
			}
		
		}
		

		printf("%d\n", arr[n][0]);
	




	
	
		return 0;//Your program should return 0 on normal termination.
}


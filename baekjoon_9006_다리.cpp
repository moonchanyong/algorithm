#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<double> v_left;
vector<double> v_right;





int main()
{

	double Answer = 0;
	int t;

	cin >> t;

	for (int test_cast = 0; test_cast <t; test_cast++)
	{
		Answer = 0;

		int n, m;
		cin >> n >> m;


		v_left.resize(n, 0);
		v_right.resize(m, 0);

		for (int i = 0; i < n; i++)
		{
			cin >> v_left[i]; // 왼쪽 강집			
		}

		for (int i = 0; i < m; i++)
		{
			cin >> v_right[i]; // 오른쪽 강집 										

		}

		sort(v_left.begin(), v_left.end());
		sort(v_right.begin(), v_right.end());

		int a;
		int a2;
		int a_num = m;
		if (n & 1) // 홀수 
		{
			a = n / 2;
			a2 = n / 2;
		}		
		else
		{
			a = n / 2;
			a2 = n / 2 + 1;
		}
		int b ;
		int b2;
		int b_num = n;
		if (m & 1) // 홀수 
		{
			b= m / 2;
			b2 = m / 2;
		}
		else
		{
			b = m / 2;
			b2 = m / 2 + 1;
		}
		

		a = v_left[a];
		a2= v_left[a2];
		
		b = v_right[b];
		b2 = v_right[b2];		

		if (a2 > b2) //swap
		{
			int temp; 
			temp = a;
			a = b;
			b = temp;

			temp = a2;
			a2 = b2;
			b2 = temp;

			temp = a_num;
			a_num = b_num;
			b_num = temp;

			
		}

		
		if( a2 < b)  // 완전 떨어져 있는경우 
		{
			if (a_num > b_num)
			{
				Answer = a2;

			}
			else if (a_num < b_num)
			{
				Answer = b;

			}
			else if (a_num == b_num)
			{
				Answer = a2;
			}

		}
		else if (a < b) // 한쪽만 걸칠 경우 
		{
			if (a_num > b_num)
			{
				Answer =  b;

			}
			else if (a_num < b_num)
			{
				Answer = b;

			}
			else if (a_num == b_num)
			{
				Answer = b;
			}
		}
		else  // 내부포함일경우 
		{
			if (a_num > b_num)
			{
				Answer = a;

			}
			else if (a_num < b_num)
			{
				Answer = a;

			}
			else if (a_num == b_num)
			{
				Answer = a;
			}

		}

		printf("%.1f\n",Answer);
	}

	return 0;
}
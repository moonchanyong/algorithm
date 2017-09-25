#include <iostream>
#include <vector>

using namespace std;


vector<vector<int>> v(2);




int main()
{

	int Answer = 0;
	int t;

	cin >> t;

	for (int test_cast = 0; test_cast <t; test_cast++)
	{
		Answer = 0;

		int n;
		cin >> n;


		v[0].resize(n, 0);
		v[1].resize(n, 0);



		int right_go = 0;
		int right_sum = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> v[0][i]; // x값 			
		}
		int dx = v[0][0];
		for (int i = 0; i < n; i++)
		{
			cin >> v[1][i]; // 배수 							
			right_go += v[1][i]; // 전체 곱 
			
		}

		int left_go = 0;
		int nn;

		
		for(int i = 0; i < n; i++)
		{
			left_go += v[1][i];
			right_go -= v[1][i];

			if (left_go >= right_go)
			{
				nn = i;
				break;

			}

		}
	


		cout << v[0][nn] << endl;
	}


	return 0;
}
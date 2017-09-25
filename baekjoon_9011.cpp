#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;




int answer;

int main()
{




	int T;
	cin >> T;
	for (int test_case = 0; test_case < T; test_case++)
	{
		int n;
		cin >> n;
		vector<int> answer(n+1 , -1);  // answer[n] 은 남은개수 
		answer[n] = n;
		vector <int>r(n);
		vector <int>check(n,-1);
		for (int i = 0; i < n; i++)
		{
			cin >> r[i];
		}

		bool an = 0;

		for (int i = n-1; i >= 0; i--)
		{

			if (r[i] >= answer[n])
			{
				an = 1;
				break;
			}

			int count = 0;
			for (int j = 0; j < n; j++)
			{

				if (check[j] == -1)
					count++;

				if (count == r[i]+1 )
				{
					answer[i] = j+1 ;
					check[j] = 1 ;
					break;
				}

			}
			if (answer[i] == -1)
			{
				an = 1;
				break;
			}
		}


		if (!an)
		{
			for (int i = 0; i < n; i++)
			{
				cout << answer[i] << " ";

			}			cout << "\n";
		}
		else
		{
			cout << "IMPOSSIBLE" << "\n";
		}
	


	}





	return 0;
}
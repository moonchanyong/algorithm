#include<iostream> 
#include<string> 
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<inttypes.h>
using namespace std;



int main()
{
	
	int T;
	cin >> T;

	for (int test_case = 0; test_case < T; test_case++)
	{
		int answer = -1;
		int m, n, x, y;

		cin >> m >> n >> x >> y;

		if (m < n) // n에작은거 설정 
		{
			swap(m, n);
			swap(x, y);

		}

		int idx = 0;

		while(idx*m + x <= m*n || idx*n + y <= m*n)
		{

			if (((m*idx) + x) % n == y)
				answer = m*idx + x;

			if (((n*idx) + y) % m == x)
				answer = (n*idx) + y;

			if (answer != -1)
				break;
			idx++;

		}

		

		cout << answer << "\n";
		

	}
	



	return 0;
}
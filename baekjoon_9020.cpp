#include <iostream>
#include <vector>

using namespace std;

#include <unordered_set>




int main()
{
	

	int T;
	cin >> T;
	for (int test_case = 0; test_case < T; test_case++)
	{

		unordered_set<int> sset;
		pair<int, int> answer;
		int n;
		cin >> n;
		vector<bool> v(n+1) ;
		
		vector<int> values;
		for (int i = 2; i < n; i++)
		{
			if (!v[i])
			{
				values.push_back(n-i);
				sset.insert(i);

			}
			int s = 2;
			while (s*i < n)
			{
				v[s*i] = 1;
				s++;


			}

		} // 소수값 모으기 // pass

		int ch =10000000;


		// 소수값 으로 조합 찾아내기  // 차이가 가장 작은것 
		for (int i = 0; i < values.size(); i++)
		{

			if (sset.count(values[i]))
			{
				int temp = 2 * values[i] - n;
				if (0 > temp)
					temp *= -1;
				if (ch > temp)
				{
					answer.first = values[i];
					answer.second = n - values[i];
					ch = temp;
				}


			}
				
		}

		
		if(answer.first < answer.second)
		cout << answer.first << " " << answer.second << "\n";
		else 
			cout <<  answer.second << " " << answer.first << "\n";
	}

	




	return 0;
}
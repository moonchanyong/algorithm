#include<iostream> 
#include<string> 
#include<vector>
#include<algorithm>
#include<queue>
#include<string>

using namespace std;


int main()
{

	int n;
	cin >> n;
	
	vector<int> v(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());  // 오름차순 

	int temp_count = 0;
	int count = 0;
	int cursor = 0;
	for (int i = 0; i < n; i++) // 기본포인터
	{
		
		temp_count = 0;
		for ( ; cursor < n; cursor++)
		{
			if (v[cursor] > v[i] + 4) //범위 벗어남 
			{
				temp_count = cursor - i;				
				break;
			}

			

		}

		if (count < temp_count)
		{
			count = temp_count;
		}
	}

	cout << n - count + 1 << "\n";

	return 0;
}
#include<iostream> 
#include<string> 
#include<vector>
#include<algorithm>

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

	
	int count = 0;
	
	int stand = 1000000;

	for (int i = 1; i < n; i++) // 기본포인터
	{
		if (v[i] - v[i - 1] < stand)
		{
			stand = v[i] - v[i - 1];
		}
	}



	for (int i = 0; i < n-1; i++)
	{
		if (v[i] + stand != v[i + 1])
		{
			count += ((v[i + 1] - v[i]) / stand) - 1;
		}


	}




	cout << count  << "\n";

	return 0;
}
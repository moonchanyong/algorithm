#include<iostream> 
#include<string> 
#include<vector>
#include<algorithm>


using namespace std;


int main()
{


	//freopen("input.txt", "r", stdin);



	int n, m, k;
	cin >> n >> m >> k;

	int a, b;
	int part;
	int sum = n + m;
	a = n / 2;
	b = 2 * m;

	if (m >= a && b <= n)
	{
		if (a < b)
		{
			part = b;
		}
		else
			part = a;
	}
	else if (m >= a && b > n)
	{
		part = a;
	}
	else if (m < a && b <= n)
	{
		part = b;
	}




	while (true)
	{
		a = part * 2;
		b = part;
		if (sum - a - b >= k || part == 0)
		{
			break;
		}
		part--;
	}



	cout << part << "\n";


	return 0;
}
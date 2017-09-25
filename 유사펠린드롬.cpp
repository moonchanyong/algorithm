#include <iostream>
#include <queue>
#include<vector>
#include<algorithm>

using namespace std;
int n, k, l;
char str[10000];
short check[10000][10000] = {};

bool greedy(int s , int e , int count ) {


	if (e - s == 1 && str[e] != str[s])
	{
		check[s][e] = -1;
		return false;
	}
	else if (e - s == 1 && str[e] == str[s])
	{
		check[s][e] = 1;
		return true;
	}
	if (count == 1 || e-s == 2)
	{
		int cou = 0;
		for (int i = s; i <= (s+e)/2; i++)
		{
			if (str[i] != str[(s + e) - i])
				break;
			cou++;
		}
		if ((double)k / l <= (double)2 * cou / (e - s + 1))//조건만족
		{
			check[s][e] = 1;
			return true;
		}
		else
		{
			check[s][e] = -1;
			return false;
		}
	}

	int c, d;
	for (int i = s+2; i < e; i++)
	{

		if (check[s][i-1] == 0)
			c = greedy(s, i-1, 1);
		else if (check[s][i-1] == 1)
			c = true;
		else if (check[s][i-1] == -1)
			c = false;

		if (check[i][e] == 0)
			d=greedy(i, e, count - 1);
		else if (check[i][e] == 1)
			d = true;
		else if (check[i][e] == -1)
			d = false;
		
		if (c&&d)
			return true;
	
	}



	return 0;
}

int main()
{



	cin >> n >> k >> l;

	for (int i = 0; i < n; i++)
	{
		cin >> str[i];
	}
	int count = 0;
	
	
	while (true) {
		count++;

		if (greedy(0, n - 1, count))
		{
			
			break;
		}
		if (n / 2 == count)
		{
			count = 0;
			break;
		}
	}

	cout << count << endl;

	return 0;
}

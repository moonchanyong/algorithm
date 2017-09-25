#include <iostream>
#include <queue>


using namespace std;


int main()
{

	int n;  
	cin >> n;

	priority_queue<int> q;
	

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		q.push(temp);
	}


	int k= 0;


	for (int i = 0; i < n; i++)
	{
		k++;
		int temp;
		temp = q.top();
		q.pop();
		if (temp >= k)
			continue;
		else
		{
			k -= 1;
			break;
		}

	}

	


	cout << k << endl;


	return 0;
}
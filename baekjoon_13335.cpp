#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{

	int n, w, l;
	cin >> n >> w >> l;
	int count = 0;
	int sum=0;

	vector<int>  v;
	queue<int> wq;
	for (int i = 0; i < w; i++)
	{
		wq.push(0);
	}// wq 사이즈 w개 

	
	queue<int>q;
	for (int i = 0; i < n; i++)
	{
		int temp;

		cin >> temp;
		q.push(temp);
		
	
		
	}
	sum = 0;
	count = 0;
	while (!wq.empty())
	{

		sum -= wq.front();
		wq.pop();
		


		if (q.empty())
		{
			
			count++;
				continue;

		}

		if (sum + q.front() <= l)
		{
			
			wq.push(q.front());
			sum += q.front();
			q.pop();
			count++;
			continue;
			

		}
		else // 드어가면안됨 
		{
				wq.push(0);
				count++;
		}

	

	}


	


	cout << count<< endl;

}
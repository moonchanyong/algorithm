#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

vector<int> pibo;

stack <int> stk;
int answer;

int main()
{

	int a = 1;
	int b = 1;
	int temp;	
	pibo.push_back(0);
	pibo.push_back(1);
	while (true)
	{
		temp = a + b;
		if (temp >= 1000000000)
			break;
		pibo.push_back(temp);	
		
		a = b;
		b = temp;
	}




	int T;
	cin >> T;
	for (int test_case = 0; test_case < T; test_case++)
	{

		answer = 1000000000;
		int n;
		cin >> n;
		

		while (true)
		{
			
			for (int i = pibo.size()-1; i >= 0; i--)
			{

				if (pibo[i] <= n)
				{
					stk.push(pibo[i]);
					n -= pibo[i];
					break;
				}


			}

			if (n == 0)
				break;

		}


		

		// cursor 오른쪽찾음 


		while (!stk.empty())
		{
			cout << stk.top() << " ";
			stk.pop();
		} cout << "\n";


	}





	return 0;
}
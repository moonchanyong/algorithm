//����_9084_DP
#include <vector> 
#include <iostream>
using namespace std;

int n = 0;
vector<int> answer;
int temp = 0;

int main()
{

	int tast_case = 0;

	cin >> tast_case;

	for (int z = 0; z < tast_case; z++)
	{
		// ���� ������ 



		cin >> n; // coin�� �Է� 
		vector<int> coins;
		int value = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> temp;
			coins.push_back(temp);
		}

		cin >> value; // �� �Է� 

		vector<int> values(value + 1, 0);


		for (int i = 0; i < n; i++)
		{
			if (coins[i] <= value)
			{

				values[coins[i]] ++;

				for (int j = 1; j <= value; j++)
				{
					if (j < coins[i]) continue;

					values[j] += values[j - coins[i]];


				}
			}
		}


		answer.push_back(values[value]);



	} // test_case for�� ���� 

	for (int z = 0; z < tast_case; z++)
	{
		cout << answer[z] << endl;
	}


	return 0;//Your program should return 0 on normal termination.
}


#include<iostream> 
#include<string> 
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;



// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
int main() {

	string x, y;

	cin >> x >> y;
		

	int temp_count = 0;
	int max_count = 0;

	for (int i = 0; i <= (y.size() - x.size()) ; i++)
	{
		temp_count = 0;
		for (int j = 0; j < x.size(); j++)
		{

			if (x[j] == y[i+j])
			{
				temp_count++;
			}

		}
		if (temp_count > max_count)
			max_count = temp_count;
	}
	
	cout << x.size() - max_count << "\n";





	
	
	return 0;
}
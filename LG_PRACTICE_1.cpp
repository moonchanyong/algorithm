#include<iostream> 
#include<string> 
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<inttypes.h>
using namespace std;



unordered_map<int, int> mmap;

struct line {

	short x1, y1, x2, y2;

};
priority_queue<int> qx;
priority_queue<int> qy;
int main()
{
	int T;
	cin >> T;
	for (int Test_case = 0; Test_case < T; Test_case++)
	{


		int64_t n, m;
		cin >> n >> m;
		int64_t count = 0;
		if (n < m)
			swap(n, m);

		int64_t d = n - m;

		// ���� �˾Ƴ��� 




		// ���� 1�ɶ����� Ȯ�ο����ϱ� 


		while (true)
		{

			int64_t temp = n - m;
			int64_t idx = 0;
			if (temp == 0)
				break;
			while (temp != 1)
			{
				temp >>= 1;
				idx++;
			}
			if (idx == 0)
				break;

			temp = m;
			bool check = 1;
			int64_t check_count = -1;
			temp >>= idx;
			while (check)
			{
				check_count++;
				check &= temp;
				temp >>= 1;
			} // ����� Ȯ�� 

			if (check_count == 0)
				count += pow(2, idx + 1) + check_count - 1;
			else
			{
				count += pow(2, idx + 1) + check_count;
			}
			m += pow(2, idx);
		}

		cout << count << "\n";
	}
	// �� ���� 
	
	return 0;
}
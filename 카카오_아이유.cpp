#include <queue>

using namespace std;
struct ss {
	int star; //���� �� 
	int cross; // ���� �� 
	int n;
};

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
int solution(int n) {
	int answer = 1;


	queue<ss> q;

	//������ �˾Ƴ��� 
	long long int a = 5;
	long long int b = 5;
	while (true)
	{



		if (n < a)
		{
			answer = 0;
			break;
		}
		else if (a <= n  &&  n <= b)
		{
			break;
		}

		// ������ 

		a -= 2 * answer;
		a *= 3;
		a += 2 * (answer + 1);

		b *= 3;
		b += 2;


		answer++;
	}


	//DP�� ��� �������� �������� Ȯ��;




	return answer;
}
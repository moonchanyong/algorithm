#include <queue>

using namespace std;
struct ss {
	int star; //깍은 수 
	int cross; // 남은 수 
	int n;
};

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n) {
	int answer = 1;


	queue<ss> q;

	//별개수 알아내기 
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

		// 별개수 

		a -= 2 * answer;
		a *= 3;
		a += 2 * (answer + 1);

		b *= 3;
		b += 2;


		answer++;
	}


	//DP로 몇개의 조합으로 가능한지 확인;




	return answer;
}
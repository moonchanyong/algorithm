//baekjoon_13458_산수

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n = 0;
int b = 0, c = 0, maxnum = 0;
vector<int> v;
vector<int> value;
int ju[2];
long answer = 0;
int main(int argc, char** argv)
{

	
	cin >> n; // 시험장 수
	v.resize(n,0);
	value.resize(n,0);
	for (int i = 0; i < n; i++)
	{

		cin >> v[i];
		
	}
	
	cin >> ju[0] >> ju[1];  // b 총감독관 커버능력 , c 부감독관 커버능력

	
	for (int i = 0; i < n; i++)
	{
		if (v[i] > 0)
		{
			v[i] -= ju[0];
			answer++;
		}

		if (v[i] > 0)
		{
			answer += v[i] / ju[1];
			
			if (v[i] % ju[1] > 0)
				answer++;

		}
	}
	
	



	cout << answer << endl;


	return 0;//Your program should return 0 on normal termination.
}
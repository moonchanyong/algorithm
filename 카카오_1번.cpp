#include<iostream>
#include<vector>
#include <string>
// ������(gaelly) : be myself
using namespace std;

vector<vector<int>> check;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;
	check.resize(n);
	for (int i = 0; i < n; i++)
	{
		check[i].resize(n);
	} // ���簡��

	int temp = 0;
	//arr1 üũ 
	for (int j = 0; j < n; j++)
	{
		temp = arr1[j];
		for (int i = n - 1; i >= 0; i--)
		{
			if (temp & 1) //1�϶� 
			{
				check[j][i] = 1;
			}

			
			temp >>= 1;


		}
	}

	for (int j = 0; j < n; j++)
	{
		temp = arr2[j];
		for (int i = n - 1; i >= 0; i--)
		{
			if (check[j][i]) //�̹�1
			{

				temp >>= 1;
				continue;
			}
			if (temp & 1) //1�϶� 
			{
				check[j][i] = 1;
			}


			temp >>= 1;


		}
	}


	for (int j = 0; j < n; j++)
	{

		answer.push_back("");
		for (int i =0; i < n; i++)
		{
			if (check[j][i]) //�̹�1
			{
				answer[j] +="#" ;
				
			}
			else
			{
				answer[j] += " ";
			}
			


		}
	}




	return answer;
}
int main() {

	solution(5, { 9,20,28,18,11 }, { 30,1,21,17,28 });



	return 0;

}
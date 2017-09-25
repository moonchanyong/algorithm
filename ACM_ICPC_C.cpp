#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;


struct ss {
	int x;
	int type;
	bool operator<(ss a)
	{

		return x < a.x;
	}
};

int main()
{
	vector<ss> v;
	
	int length = 2000000000;	
	int s, e;	
	int k, n;
	ss temp;

	// 입력 
	cin >> k >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> temp.x >> temp.type;
		v.push_back(temp);

	}
	sort(v.begin(),v.end());


	vector<int> check(k + 1, 1000000001);
	check[0] = 0;

	int min = v[0].x, max ;

	for (int i = 0; i < n; i++)
	{

		if (check[v[i].type] == 1000000001)
			check[0]++;


			max = v[i].x;
		

		if (min ==  check[v[i].type] )
		{
			
				check[v[i].type] = v[i].x;

				auto result=min_element(check.begin()+1, check.end());
				
				min = check[result-check.begin()];
			

		}
		else 
			check[v[i].type] = v[i].x;

		if (check[0] == k)
		{



			
	

			if (max - min< length)
			{
				s = min;
				e = max;
				length = max-min ;
			}
			



		}

	}


	if ((s + e) / 2 < 0) //음수이면 
	{
		if((s*-1 + e*-1)%2 == 1) //홀수 
		printf("%d", (s + e) / 2 -1 );
		else
		printf("%d", (s + e) / 2);

	}
	else
	
		printf("%d", (s + e) / 2);
	
	
	return 0;
}
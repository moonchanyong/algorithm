#include<string>
#include<iostream>

using namespace std;
string s;
#define ppp(x) cout << x
#define rm(x) s.erase(s.begin() +x)

int main()
{


	int T;
	cin >> T;
	for (int test_case = 0; test_case < T; test_case++)
	{
		cin >> s;
		int idx = 1; 
		
		if(s.size()%2 !=1)
		while (idx <s.size())
		{
			if (idx == 0)
				idx++;
			if (s[idx-1] == '('&& s[idx] == ')')
			{
				rm(idx);
				rm(idx - 1);
				idx -= 2;
			}

				idx++;

		}

		if (s.size() > 0)
			ppp("NO\n");
		else
			ppp("YES\n");


	}




}
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>
using namespace std;

double seta;

int n, k, l;
queue<string> q;

int main()
{
	unordered_map<string, int> mape;
	vector<vector<string>>  v(26);

	cin >> n >> k >> l;

	seta =(double) k / l;

	string s;
	cin >> s;

	string temp;

	for (int i = 0; i< n; i++)
	{  
		for (int j = i+1; j < n; j++)
		{
			if (s[i] == s[j])
			{
				temp.assign(s.begin() + i, s.begin() + j+1);

				if (mape.count(temp) > 0)
				{
					
					continue;
				}
				else //없을때 
				{

					int count = 1;
					int ssw = temp.size();
					for (int ee = 1; ee < ssw / 2; ee++)
					{

						if (temp[ee] != temp[ssw - ee - 1])
							break;

						count++;
					}

					if ((double)k / l <= (double)2 * count / ssw)
					{
						mape.insert({ temp, 1 });
						v[temp[0]-'a'].push_back(temp);
					}

				}
			}

		}

	}
/*
	mape.clear();
	unordered_map <string, int> map;

	
	while (!q.empty())
	{
		
		temp = q.front();
		q.pop();
		int count = 1;
		int ssw = temp.size();
		for (int i = 1; i < ssw/2; i++)
		{

			if (temp[i] != temp[ssw - i - 1])
				break;

			count ++ ;
		}

		if ((double)k / l <= (double)2 * count / ssw)
			map.insert({ temp, 1 });
	} //정제함 
	*/
	vector<int> dp(n+1,0);
	dp[0] = 1;
	temp = "";
	//string temp2 = "";
	queue<int> q;
	q.push(0); int i;
	string temp2;
	while(!q.empty())
	{
		i = q.front();
		q.pop();
		temp = "";
		if (i >= n)
			continue;
	if(dp[i]!=0)
			for (int j = 0; j < v[s[i]-'a'].size(); j++) //문자열 s
			{
			
				temp = v[s[i]-'a'][j];	
				if (n <= i + v[s[i] - 'a'][j].size()-1)
					continue;
				temp2.assign(s.begin()+i, s.begin()+i+v[s[i]-'a' ][j].size());
			if ((temp==temp2))
			{
				if ((dp[i  + v[s[i]-'a'][j].size()] > dp[i] + 1 || dp[i  + v[s[i]-'a'][j].size()] == 0) && dp[i] != 0)
				{
					dp[i  + v[s[i]-'a'][j].size()] = dp[i] + 1;
					q.push(i + v[s[i]-'a'][j].size());
				}
			}



		}
	}

	
	if (dp[n] > 0)
	{
		cout << dp[n] -1<< endl;

	}
	else
	{
		cout << 0 << endl;
	}



//	int answer =find_s(s);

//	cout << answer << endl;


	}

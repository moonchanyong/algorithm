#include <iostream>
#include <queue>
#include<vector>
#include<algorithm>
using namespace std;

 struct ss{
	int x;
	int y;

};
 bool comp(ss a , ss b){
	 return a.x < b.x;
 }
 
 struct cmpy
 {
	 bool operator () (ss& a, ss& b)
	 {
		 return a.y>b.y;
	 }
 };
 struct cmpx
 {
	 bool operator () (ss& a, ss& b)
	 {
		 return a.x>b.x;
	 }
 };
 
 priority_queue <ss, vector<ss>, cmpy> q1;
priority_queue<ss,vector<ss>,cmpx> q2;


vector<ss> v;
int main()
{
	
	int n;
	cin >> n;
	int a, b;
	
	for (int i = 0; i < n; i++)
	{
		ss temp;
		cin >> a >> b;
		if (a > b)
		{
			int temps = a;
			a = b;
			b = temps;

		}
		temp.x = a;
		temp.y = b;
		q1.push(temp);
		v.push_back(temp);
	}
	int max = 0;
	int d;
	cin >> d;
	sort(v.begin(),v.end(),comp);
	
	for (int i = 0; i < n && !q1.empty(); i++)
	{
		
		while (v[i].x + d >= q1.top().y) {
			q2.push(q1.top()); q1.pop(); if (q1.empty()) break;}
		
		if(!q2.empty())
			while (v[i].x > q2.top().x ) 
			{
				q2.pop(); if (q2.empty())break;
			}
		




		if (max < q2.size())
			max = q2.size();

	}

	cout << max << endl;
	return 0;
}

#include <string>
#include <vector>
#include<queue>
#include<unordered_set>
using namespace std;

typedef pair<string, int> P;


struct Order
{
	bool operator()(P const& a, P const& b) const
	{
		return a.second > b.second ;
	}
};
priority_queue< P, vector<P>, Order > q;

unordered_set<string> sset;


int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	int time = 1;
	vector<int> check(cacheSize,0);

	int cursor = 0;
	string temp;


	for (int i = 0; i < cities.size(); i++)
	{
		for (int j = 0; j < cities[i].size(); j++)
		{

			if (65 <= cities[i][j]&& 90 >= cities[i][j]) // 대문자 
			{
				cities[i][j] += 32;
			}
			/*else if (97 <= cities[i][j] && 122 >= cities[i][j]) //소문자
			{

				

			}*/

		}
	}


	if(cacheSize !=0)
	while (cursor < cities.size())
	{
	
		temp = cities[cursor];
			//이미 캐시에있다
			if (sset.count(temp) == 1) // 안에있을때 
			{
				answer += 1;
				
				
				queue< P> temp_q;
				P tep;
				while (true)
				{					
					if (q.top().first == temp)
					{
						tep = q.top();
						q.pop();
						tep.second = cursor;
						q.push(tep);
						break;
					}
					temp_q.push(q.top());
					q.pop();
				}
				while (!temp_q.empty())
				{
					q.push(temp_q.front());
					temp_q.pop();
				}


			}
			else 		//	캐시에없다
			{				
				answer += 5;
				if (q.size() < cacheSize) //여유 있을때 
				{
					sset.insert(temp);
					q.push({ temp,cursor });
				}
				else
				{
					// 지우기
					sset.erase(q.top().first);
					q.pop();

					//넣기 이번꺼 
					sset.insert(temp);
					q.push({ temp,cursor });
				}

			}

			cursor++;
	}
	else
	{
		answer = 5 * cities.size();
	}

	return answer;
}




int main() {
	
	solution(1,{  "NewYork", "Pangyo","Jeju", "newyork", "NewYork" });

	

	string s = "azAZ ";
	

	printf("%d %d %d %d %d \n", 'A', 'a', '0', '9' , '10');

	printf("%d %d %d %d %d ", s[0], s[1], s[2], s[3], s[4]);
	s.erase(4);
	return 0;

}
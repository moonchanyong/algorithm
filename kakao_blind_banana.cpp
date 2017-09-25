#include <map>
#include <vector>

using namespace std;

map<string, int> bag;
int solution(vector<string> strs, string t)
{
	int answer = -1;

	for (int i = 0; i < strs.size(); i++) {

		bag.insert(map<string, int>::value_type(strs[i], 1));


	}


	int length = t.size();
	vector<int> v(length);

	for (int i = -1; i < length; i++)
	{
		string temp = "";

		for (int j = i + 1; j < length && j <= i + 5; j++)
		{
			if (i >= 0)
				if (v[i] == 0)
					break;

			temp += t.at(j);

			if (bag.count(temp)) // ÀÖ´Ù¸é 
			{
				if (i >= 0)
				{
					if (v[j] == 0 || v[j] > (v[i] + 1))
					{
						v[j] = v[i] + 1;

					}
				}
				else
					if (v[j] == 0)
						v[j] = 1;
			}
		}


	}

	if (v[length - 1] != 0)
		return v[length - 1];
	else
		return -1;

}
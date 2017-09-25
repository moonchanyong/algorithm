#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;





int main()
{



	int t;

	cin >> t;

	for (int test_cast = 0; test_cast <t; test_cast++)
	{

		vector<char> v_extra;
		vector<char> v_;
		string s;
		char temp;


		cin >> s;

		for (int i = 0; i < s.size(); i++)
		{
			temp = s.at(i);

			if (temp == '<')
			{
				if (v_.size() == 0)
				{
					continue;
				}


				v_extra.push_back(v_[v_.size() - 1]);
				v_.erase(v_.begin() + v_.size() - 1);
			}
			else if (temp == '>')
			{
				if (v_extra.size() == 0)
				{
					continue;
				}

				v_.push_back(v_extra[v_extra.size() - 1]);
				v_extra.erase(v_extra.begin() + v_extra.size() - 1);
			}
			else if (temp == '-')
			{
				if (v_.size() == 0)
				{
					continue;
				}
				v_.erase(v_.begin() + v_.size() - 1);

			}
			else // 숫자및 값 
			{
				v_.push_back(temp);
			}

		}

		while(v_extra.size() >0)
			{
			v_.push_back(v_extra[v_extra.size() - 1]);
			v_extra.erase(v_extra.begin() + v_extra.size() - 1);
		}


		for (int i = 0; i < v_.size(); i++)
		{
			printf("%c", v_[i]);
		}printf("\n");

		/*
		if (v_.size() > 0)
		{
		vector<char> tem;
		v_.swap(tem);

		}

		if (v_extra.size() > 0)
		{
		vector<char> tem;
		v_extra.swap(tem);
		}
		*/

	}

	return 0;
}
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	string s;
	cin >> s;

	int length = s.size();
	int sum = 0;
	int piece = 0;
	for (int i = 0; i < length-1; i++)
	{
		if (s.at(i) == '('&& s.at(i + 1) == ')') // 잘리는경우 
		{

			sum += piece ;
			i++;
			continue;
		}
		else if (s.at(i) == '(')
			piece += 1;
		else if (s.at(i) == ')')
		{
			piece -= 1;
			sum += 1;
		}

	}

	cout << sum+1 << endl;

	return 0;
}
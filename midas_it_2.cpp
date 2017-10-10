#include<iostream> 
#include<string> 
#include<vector>
#include<algorithm>


using namespace std;


int main()
{

	int n;
	cin >> n;

	for (int tc = 0; tc < n; tc++)
	{
		string str;

		cin >> str;
		int leng = str.size();
		int count = 0;
		for (int i = 0; i < leng; i++)
		{

			if (i >= leng - 1 - i)
			{
				break;
			}
			if (str[i] - 'a' > str[leng - 1 - i] - 'a')
			{
				swap(str[i], str[leng - 1 - i]);
			}
			
			if (str[i] - 'a' == str[leng - 1 - i] - 'a')
			{
				continue;
			}
			else
			{
				count += (str[leng - 1 - i] - 'a') - (str[i] - 'a');
			}

		}

		cout << count << "\n";

	}

	return 0;
}
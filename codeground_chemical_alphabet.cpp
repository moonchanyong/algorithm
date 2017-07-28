/* Please use the chemical symbols in the periodic table below when you solve this problem.
"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al",
"Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe",
"Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr",
"Y","Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb",
"Te", "I", "Xe", "Cs", "Ba", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au",
"Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Rf", "Db", "Sg",
"Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Fl", "Lv", "La", "Ce", "Pr", "Nd",
"Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Ac",
"Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md",
"No", "Lr"   */

/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/
#include <map> 
#include <iostream>
#include <string.h>
using namespace std;
typedef std::multimap<char,char> Mymap;
typedef std::multimap<char, char>::iterator iter;
int Answer;


int main(int argc, char** argv)
{
	iter ii;
	Mymap dic = {
		{'h','0' },{'h','e'},{ 'l','i' },{ 'b','e' },{ 'b','0' },{ 'c','0' },{ 'n','0' },{ 'o','0' },{ 'f','0' }
		,{ 'n','e' },{ 'n','a' },{ 'm','g' },{ 'a','l' },{ 's','i' },{ 'p','o' },{ 's','0' }
		,{ 'c','l' },{ 'a','r' },{ 'k','0' },{ 'c','a' },{ 's','c' },{ 't','i' },{ 'v','0' }
		,{ 'c','r' },{ 'm','n' },{ 'f','e' },{ 'c','o' },{ 'n','i' },{ 'c','u' },{ 'z','n' }
		,{ 'g','a' },{ 'g','e' },{ 'a','s' },{ 's','e' },{ 'b','r' },{ 'k','r' },{ 'r','b' }
		,{ 's','r' },{ 'y','0' },{ 'z','r' },{ 'n','b' },{ 'm','o' },{ 't','c' },{ 'r','u' }
		,{ 'r','h' },{ 'p','d' },{ 'a','g' },{ 'c','d' },{ 'i','n' },{ 's','n' }
		,{ 's','b' },{ 't','e' },{ 'i','0' },{ 'x','e' },{ 'c','s' },{ 'b','a' },{ 'h','f' },{ 't','a' }
		,{ 'w','0' },{ 'r','e' },{ 'o','s' },{ 'i','r' },{ 'p','t' },{ 'a','u' },{ 'h','g' },{ 't','i' }
		,{ 'p','b' },{ 'b','i' },{ 'p','o' },{ 'a','t' },{ 'r','n' },{ 'f','r' },{ 'r','a' },{ 'r','f' }
		,{ 'd','b' },{ 's','g' },{ 'b','h' },{ 'h','s' },{ 'm','t' },{ 'd','s' },{ 'r','g' },{ 'c','n' }
		,{ 'f','l' },{ 'l','v' },{ 'l','a' },{ 'c','e' },{ 'p','r' },{ 'n','d' },{ 'p','m' },{ 's','m' }
		,{ 'e','u' },{ 'g','d' },{ 't','b' },{ 'd','y' },{ 'h','o' },{ 'e','r' },{ 't','m' }
		,{ 'y','b' },{ 'l','u' },{ 'a','c' },{ 't','h' },{ 'p','a' },{ 'u','0' },{ 'n','p' },{ 'p','u' }
		,{ 'a','m' },{ 'c','m' },{ 'b','k' },{ 'c','f' },{ 'e','s' },{ 'f','m' },{ 'm','d' },{ 'n','o' }
		,{ 'l','r' }

		/* 
		"", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al",
		"Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe",
		"Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr",
		"Y","Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb",
		"Te", "I", "Xe", "Cs", "Ba", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au",
		"Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Rf", "Db", "Sg",
		"Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Fl", "Lv", "La", "Ce", "Pr", "Nd",
		"Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Ac",
		"Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md",
		"No", "Lr"   */
	};


	int T, test_case;
	/*
	The freopen function below opens input.txt file in read only mode, and afterward,
	the program will read from input.txt file instead of standard(keyboard) input.
	To test your program, you may save input data in input.txt file,
	and use freopen function to read from the file when using cin function.
	You may remove the comment symbols(//) in the below statement and use it.
	Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	But before submission, you must remove the freopen function or rewrite comment symbols(//).
	*/

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		char *p = new char[50001];
		Answer = 0;
		int checkpoint = 0;
		int check1 = 1;
		int check2 = 1;
		int check3 = 1;
		int check11 = 1;
		int check22 = 1;
		int check33 = 1;


		int n = 0;

		/////////////////////////////////////////////////////////////////////////////////////////////

		cin >> p;
		for (int i = 0; p[i] != '\0';i++)
			n++;

		int **arr = new int*[n]; for (int i = 0; i < n; ++i) {
			arr[i] = new int[3]; memset(arr[i], 0, sizeof(int) * 3); // 메모리 공간을 0으로 초기화 }
		}

		// 이차원 배열 값 설정 
		for (int i = 0; p[i] != '\0';i++)
		{
			ii = dic.lower_bound(p[i]);

			if (ii != dic.upper_bound(p[i]))
				for (; ii != dic.upper_bound(p[i]); ii++)
				{
				
					if (((ii->second)=='0'))
						arr[i][1] = 1;					
					if (((ii->second) == p[i + 1]))
						arr[i][2] = 1;
				}
			
				arr[i][0] = 1;
			

		} // input for 

	if(n!=0)
		for (int i = 0; i < n;)
		{
			if (i != n - 1)
			{
				if (arr[i][1] && arr[i + 1][1] )
				{

					i += 2;
					
				}
				else if (arr[i][1] && arr[i + 1][2] )
				{
					
					i++;
					
				}
				else if (arr[i][2] && arr[i + 1][0])
				{
					
					i += 2;
					
				}
				else
				
					break;
			}
			else if (i == n - 1) 
			{
				if (arr[i][1] || arr[i-1][2])
					i++;
				else
				{

					break;
				}
			}
		
			
			if (i == n)
				Answer = 1;
			
		//cout << arr[i][0] << arr[i][1] << arr[i][2] << endl;
		}// processing for
		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout <<( Answer==1?"YES":"NO") << endl;
		delete[] p;
		for (int i = 0; i < n; ++i) { delete[] arr[i]; } delete[] arr;

		}

	return 0;//Your program should return 0 on normal termination.
}
#include<iostream> 
#include<string> 
#include<vector>
#include<algorithm>

using namespace std;

vector <int> check_vec;

class list {
public:
	int x, y, cost;
	bool operator()(list i, list j) { return i.cost < j.cost; }
};

int disjoint(int x, vector<int> &uf) {
	if (x == uf[x])
	{
		check_vec[x] = 1;
		check_vec[0] += 1;
	}
	return (x != uf[x]) ? uf[x] = disjoint(uf[x], uf) : x;
}

int main() {
	int n, m;

	cin >> n >> m;

	vector <int> uf(n + 1);
	vector <list> v(m);
	check_vec.resize(n + 1,0);
	for (int i = 1; i <= n; i++) uf[i] = i;

	for (int i = 0; i < m; i++)
		cin >> v[i].x >> v[i].y >> v[i].cost;

	sort(v.begin(), v.end(), list());

	int ans = 0;

	for (int i = 0; i < m; i++)
		if (disjoint(v[i].y, uf) != disjoint(v[i].x, uf)) {
			uf[disjoint(v[i].y, uf)] = uf[v[i].x];
			ans += v[i].cost;
		}

	bool check = 0;

	for (int i = 1; i <= n; i++)
	{
		if (check_vec[i])
			continue;

		check = 1;
	}


	if (check)
		cout << -1;
	else
		cout << ans;

}
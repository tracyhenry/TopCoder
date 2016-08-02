#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#define LL long long
#define pi 3.1415926535897932384626433
#define sqr(a) ((a)*(a))
using namespace std;

class BearKRoads {
private:
	vector<int> x, a, b, v, chosen;
	int K, ans;
	void dfs(int);

public:
	int maxHappy(vector <int> _x, vector <int> _a, vector <int> _b, int _K);
};

int BearKRoads::maxHappy(vector <int> _x, vector <int> _a, vector <int> _b, int _K)
{
	K = _K;
	a = _a, b = _b, x = _x;
	ans = 0;
	v.resize(x.size());
	chosen.clear();
	dfs(1);
	return ans;
}

void BearKRoads::dfs(int step)
{
	if (step == K + 1)
	{
		//calculate happiness
		int happy = 0;
		for (int edge : chosen)
			happy += x[a[edge]] + x[b[edge]];
		for (int i = 0; i < (int) x.size(); i ++)
			if (v[i])
				happy -= x[i] * (v[i] - 1);
		ans = max(ans, happy);
		return ;
	}
    //find max
    int max_edge = -1;
    int max_happy = 0;
    for (int i = 0; i < (int) a.size(); i ++)
	{
		int happy = x[a[i]] + x[b[i]];
		if (v[a[i]])
			happy -= x[a[i]];
		if (v[b[i]])
			happy -= x[b[i]];
		if (happy > max_happy)
			max_happy = happy, max_edge = i;
	}
	//let's go
	for (int i = 0; i < (int) a.size(); i ++)
		if (a[i] == a[max_edge] || a[i] == b[max_edge] ||
			b[i] == a[max_edge] || b[i] == b[max_edge])
		{
			v[a[i]] ++, v[b[i]] ++;
			chosen.push_back(i);
			dfs(step + 1);
			chosen.pop_back();
			v[a[i]] --, v[b[i]] --;
		}
}

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!

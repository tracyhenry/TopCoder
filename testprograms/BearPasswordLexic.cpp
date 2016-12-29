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

class BearPasswordLexic {
private:
	vector<int> x, p;
	string ans;
	void dfs(int, int);
public:
	string findPassword(vector <int> x);
};

void BearPasswordLexic::dfs(int N, int last)
{
	if (N == 0)
	{
		unordered_map<int, int> m;
		for (int i = 1; i <= (int) x.size(); i ++)
			for (int len : p)
				if (len >= i)
					m[i] += (len - i + 1);
		bool ok = true;
		for (int i = 1; i <= (int) x.size(); i ++)
			if (x[i - 1] != m[i])
				ok = false;
		if (ok)
		{
			int l = 0, r = (int) p.size() - 1;
			string cur = "";
			for (int i = 0; i < (int) p.size(); i ++)
			{
				char c = (i % 2 ? 'b' :'a');
				int len = (i % 2 ? p[r --] : p[l ++]);
				for ( ; len; len --)
					cur += c;
			}
			if (ans == "" || cur < ans)
				ans = cur;
		}
		return ;
	}
	for (int cur = 1; cur <= min(last, N); cur ++)
	{
		p.push_back(cur);
		dfs(N - cur, cur);
		p.pop_back();
	}
}

string BearPasswordLexic::findPassword(vector <int> _x)
{
	x = _x;
	p.clear();
	int N = x.size();
	ans = "";
	dfs(N, N + 1);
	return ans;
}

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!

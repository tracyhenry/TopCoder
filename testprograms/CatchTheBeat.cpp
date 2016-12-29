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
#define LL long long
#define pi 3.1415926535897932384626433 
#define sqr(a) ((a)*(a))
using namespace std;
	
class CatchTheBeat {
public:
	int maxCatched(int n, int x0, int y0, int a, int b, int c, int d, int mod1, int mod2, int offset);
};

struct node
{
	int x, y;
	
	node() {}
	node(int _x, int _y) : x(_x), y(_y) {}
	int operator < (const node &o) const
	{
		return (y < o.y) || (y == o.y && x < o.x);
	}
};

int x[1010100], y[1010100];
int f[1010100], C[1010100];

vector<node> r;
int total;

void ins(int x, int v)
{
	for (int i = x; i <= total; i += ((i) & (-i)))
			C[i] = max(C[i], v);
}

int ask(int x)
{
	int ans = -1000000;
	for (int i = x; i; i -= ((i) & (-i)))
		ans = max(ans, C[i]);
	return ans;
}
	
int CatchTheBeat::maxCatched(int n, int x0, int y0, int a, int b, int c, int d, int mod1, int mod2, int offset) 
{
	x[0] = x0;
	for (int i = 1; i < n; i ++)
		x[i] = (int) (((LL) x[i - 1] * (LL) a + (LL) b) % (LL) mod1);
	for (int i = 0; i < n; i ++)
		x[i] -= offset;
	
	y[0] = y0;
	for (int i = 1; i < n; i ++)
		y[i] = (int) (((LL) y[i - 1] * (LL) c + (LL) d) % (LL) mod2);
	
	r.clear();
	r.push_back(node(0, 0));
	map<int, int> MM; MM.clear();
	
	for (int i = 0; i < n; i ++)
	{
		if (x[i] + y[i] < 0 || -x[i] + y[i] < 0)
			continue;
		r.push_back(node(x[i] + y[i], -x[i] + y[i]));
		MM[x[i] + y[i]] = 0;
	}
	
	total = 0; MM[0] = 0;
	for (map<int, int>::iterator it = MM.begin(); it != MM.end(); it ++)
		it->second = ++ total; 
	sort(r.begin(), r.end());
	//dp
	int ans = 0;
	f[0] = 0;
	
	for (int i = 1; i <= total; i ++)
		C[i] = -1000000;
	
	ins(MM[0], 0);
	
	for (int i = 1; i < r.size(); i ++)
	{
		f[i] = ask(MM[r[i].x]) + 1;
		ans = max(ans, f[i]);
		ins(MM[r[i].x], f[i]);
	}
	
	return ans;
}

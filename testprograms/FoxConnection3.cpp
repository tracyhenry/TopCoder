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
	
class FoxConnection3 {
public:
	long long minimalSteps(vector <int> x, vector <int> y);
};

struct shape
{
	int n, m;
	vector<pair<int, int> > coor;
	
	int operator == (const shape &o) const
	{
		if (n != o.n || m != o.m || coor.size() != o.coor.size())
			return 0;
		for (int i = 0; i < coor.size(); i ++)
			if (coor[i] != o.coor[i])
				return 0;
		return 1;
	}
};


const int dir[4][2] = {0, 1, 0, -1, -1, 0, 1, 0};
const int inf = 1000000000;

int n;
vector<shape> s;
vector<pair<int, int> > coor;
set<pair<int, int> > used;

void insShape()
{
	int u, d, l, r;
	u = r = -inf;
	d = l = inf;
	
	for (int i = 0; i < n; i ++)
	{
		l = min(l, coor[i].first);
		r = max(r, coor[i].first);
		d = min(d, coor[i].second);
		u = max(u, coor[i].second);
	}
	
	int nn = r - l + 1;
	int mm = u - d + 1;
		
	shape curShape;
	curShape.n = nn;
	curShape.m = mm;
	curShape.coor.clear();

	for (int i = 0; i < n; i ++)
	{
		int curx = coor[i].first - l;
		int cury = coor[i].second - d;
		curShape.coor.push_back(make_pair(curx, cury));
	}
	sort(curShape.coor.begin(), curShape.coor.end());

	bool occurred = false;
	for (int i = 0; i < s.size(); i ++)
		if (curShape == s[i])
		{
			occurred = true;
			break;
		}
	if (not occurred)
		s.push_back(curShape);
}
			
void dfs(int k)
{
	if (k == n)
	{
		insShape();
		return ;
	}
	
	//possible next steps
	set<pair<int, int> > next;
	next.clear();
	
	for (int i = 0; i < k; i ++)
	{
		int curx = coor[i].first;
		int cury = coor[i].second;
		
		for (int d = 0; d < 4; d ++)
		{
			int nx = curx + dir[d][0];
			int ny = cury + dir[d][1];
			
			if (! used.count(make_pair(nx, ny)))
				next.insert(make_pair(nx, ny));
		}
	}
	
	//dfs
	for (set<pair<int, int> >::iterator it = next.begin(); it != next.end(); it ++)
	{
		int curx = it->first;
		int cury = it->second;
		
		used.insert(make_pair(curx, cury));
		coor.push_back(make_pair(curx, cury));		
		dfs(k + 1);
		
		coor.pop_back();
		used.erase(make_pair(curx, cury));
	}
}
	
void makeShape()
{
	coor.clear();
	coor.push_back(make_pair(0, 0));
	used.clear();
	used.insert(make_pair(0, 0));

	dfs(1);
}

long long FoxConnection3::minimalSteps(vector <int> x, vector <int> y) 
{
	n = max(x.size(), y.size());
	s.clear();

	makeShape();

	LL ans = 1LL << 60LL;
	for (int sid = 0; sid < s.size(); sid ++)
	{
		int p[6];
		for (int i = 0; i < n; i ++)
			p[i] = i;

		while (1)
		{
			LL sum = 0;
			vector<int> coors;

			//x
			coors.clear();
			for (int i = 0; i < n; i ++)
				coors.push_back(x[i] - s[sid].coor[p[i]].first);
			sort(coors.begin(), coors.end());

			for (int i = 0; i < n; i ++)
				sum += abs((LL) coors[i] - (LL) coors[n / 2]);

			//y
			coors.clear();
			for (int i = 0; i < n; i ++)
				coors.push_back(y[i] - s[sid].coor[p[i]].second);
			sort(coors.begin(), coors.end());

			for (int i = 0; i < n; i ++)
				sum += abs((LL) coors[i] - (LL) coors[n / 2]);

			ans = min(ans, sum);

			if (! next_permutation(p, p + n))
				break;
		}
	}

	return ans;
}

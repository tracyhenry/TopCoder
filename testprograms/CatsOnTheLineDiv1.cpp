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
	
class CatsOnTheLineDiv1 {
public:
	int getNumber(vector <int> position, vector <int> count, int time);
};


struct node
{
	LL pos, count;
	
	node() {}
	node(LL _pos, LL _count) : pos(_pos), count(_count) {}
	
	int operator < (const node &o) const
	{
		return pos < o.pos || pos == o.pos && count < o.count;
	}
}a[1010];

int n;
LL T;
LL opt[1010];
LL ok[1010][1010];
LL inf = 1LL << 50LL;
int suc[1010], pre[1010];

int CatsOnTheLineDiv1::getNumber(vector <int> position, vector <int> count, int time) 
{
	n = position.size();
	T = (LL) time;
	for (int i = 1; i <= n; i ++)
		a[i] = node((LL) position[i - 1], (LL) count[i - 1]);
	
	sort(a + 1, a + 1 + n);
	// pre suc
	suc[0] = 1;
	pre[n + 1] = n;
	for (int i = 1; i <= n; i ++)
	{
		suc[i] = n * 2;
		for (int j = i + 1; j <= n; j ++)
			if (a[j].pos - a[i].pos > T)
			{
				suc[i] = j;
				break;
			}
		pre[i] = 0;
		for (int j = 1; j < i; j ++)
			if (a[i].pos - a[j].pos > T)
				pre[i] = j;				
	}
	
	//make ok
	for (int i = 1; i <= n; i ++)
	{
		LL lastPos = -inf;
		for (int j = i; j <= n; j ++)
		{
			LL startLeft = max(lastPos + 1, a[j].pos - T);
			LL endRight = startLeft + a[j].count - 1;			
			if (endRight - a[j].pos > T)
			{
				for (int k = j; k <= n; k ++)
					ok[i][k] = 0;
				break;
			}
			ok[i][j] = 1;
			lastPos = endRight;
		}
	}
	
	if (ok[1][n])
		return 0;
	//dp
	for (int i = 1; i <= n; i ++)
		opt[i] = inf;
	opt[0] = 0;
	for (int i = 1; i <= n; i ++)
	{
		int pre = 0;
		for (int j = 0; j < i; j ++)
			if (a[i].pos - a[j].pos + 1 > 2 * T + 1)
				pre = j;
		for (int j = 0; j <= pre; j ++)
			if (j + 1 > pre || ok[j + 1][pre])
				opt[i] = min(opt[i], opt[j] + 1);
	}
	
	LL ans = inf;
	for (int i = 1; i <= n; i ++)
	{
//		cout << i << " : " << opt[i] << " " << ok[i + 1][n] << endl;
		if (i == n || ok[i + 1][n])
			ans = min(ans, opt[i]);
	}
	return ans;
}

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!

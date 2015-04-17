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
	
class ThePermutationGame {
public:
	int findMin(int N);
};

int mod = 1000000000 + 7;
int pr[101010], u[101010];
int nPr = 0;

int ThePermutationGame::findMin(int N) 
{
	//make pr
	memset(u, 0, sizeof(u));
	nPr = 0;
	for (int i = 2; i <= N; i ++)
		if (! u[i])
		{
			pr[++ nPr] = i;
			for (int j = i; j <= N; j += i)
				u[j] = 1;
		}
	//
	int ans = 1;
	for (int i = 1; i <= nPr; i ++)
	{
		int x = pr[i];
		int m = 0;
		for (int j = x; j <= N; j += x)
		{
			int cur = j, tot = 0;
			while (cur % x == 0)
				cur /= x, tot ++;
			m = max(m, tot);
		}
		for (int j = 1; j <= m; j ++)
			ans = (int) ((LL) ans * (LL) x % (LL) mod);
	}
	return ans;
}

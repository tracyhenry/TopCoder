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
	
class ClosestRabbit {
public:
	double getExpected(vector <string> board, int r);
};

double C(int n, int k)
{
	double ans = 1.0;
	for (int i = 1; i <= k; i ++)
		ans = ans * (n - i + 1) / i;
	return ans;
}
	
int smaller(int x, int y, int i, int j, int p, int q)
{
	int d1 = sqr(x - i) + sqr(y - j);
	int d2 = sqr(p - i) + sqr(q - j);
	if (d1 < d2) return 1;
	if (d1 > d2) return 0;
	if (x < p) return 1;
	if (x > p) return 0;
	if (y < q) return 1;
	if (y > q) return 0;
	return 0;
}
	
double ClosestRabbit::getExpected(vector <string> board, int r) 
{
	double ans = 0;
	int n = board.size();
	int m = board[0].size();
	int empty = 0;
	
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++)
			if (board[i][j] == '.')
				empty ++;
	
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++)
			if (board[i][j] == '.')
				for (int p = 0; p < n; p ++)
					for (int q = 0; q < m; q ++)
						if (board[p][q] == '.')
						{
							if (p < i || p == i && q <= j)
								continue;
							int avail = 0;
							for (int x = 0; x < n; x ++)
								for (int y = 0; y < m; y ++)
									if (board[x][y] == '.' && (x != i || y != j) && (x != p || y != q))
									{
										if (smaller(x, y, i, j, p, q))
											continue;
										if (smaller(x, y, p, q, i, j))
											continue;
										avail ++;
									}
							if (avail + 2 < r)
								continue;
							
							ans += C(avail, r - 2) / C(empty, r);
						}
	return ans;
}

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!

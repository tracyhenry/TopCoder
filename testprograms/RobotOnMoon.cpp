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
	
class RobotOnMoon {
public:
	int longestSafeCommand(vector <string> board);
};

int dir[4][2] = {0, 1, 0, -1, -1, 0, 1, 0};

int RobotOnMoon::longestSafeCommand(vector <string> board) 
{
	int n = board.size();
	int m = board[0].size();
	
	int sx = 0, sy = 0;
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++)
			if (board[i][j] == 'S')
				sx = i, sy = j;

	int ans = 0;
	for (int d = 0; d < 4; d ++)
	{
		int x = sx, y = sy;
		while (1)
		{
			x += dir[d][0];
			y += dir[d][1];
			if (x < 0 || x >= n || y < 0 || y >= m)
				break;
			if (board[x][y] == '#')
				return -1;
			ans ++;
		}
	}
	return ans;
}

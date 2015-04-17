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
	
class BichromePainting {
public:
	string isThatPossible(vector <string> board, int k);
};

int u[40][40];
string BichromePainting::isThatPossible(vector <string> board, int k) 
{
	int n = board.size();
	int m = board[0].size();

	//iterations
	memset(u, 0, sizeof(u));
	while (1)
	{
		bool flag = false;
		for (int i = 0; i + k - 1 < n; i ++)
		{
			for (int j = 0; j + k - 1 < m; j ++)
			{
				bool black = false;
				bool white = false;
				for (int x = i; x < i + k; x ++)	
					for (int y = j; y < j + k; y ++)
					{
						if (u[x][y])
							continue;
						if (board[x][y] == 'B')
							black = true;
						if (board[x][y] == 'W')
							white = true;
					}
				
				if (! black && ! white)
					continue;
				if (black && white)
					continue;
				
				//got one
				flag = true;
				for (int x = i; x < i + k; x ++)
					for (int y = j; y < j + k; y ++)
						u[x][y] = 1;
				break;
			}
			if (flag)
				break;
		}
		if (not flag)
			break;
	}
/*	for (int i = 0; i < n; i ++)
	{
		for (int j = 0; j < m; j ++)
			cout << u[i][j] << " ";
		cout << endl;
	}
*/
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++)
			if (! u[i][j] && board[i][j] == 'B')
				return "Impossible";
	return "Possible";
}

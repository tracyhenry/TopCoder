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
#include <cmath>
#include <cstdlib>
#include <ctime>
#define LL long long
#define pi 3.1415926535897932384626433 
#define sqr(a) ((a)*(a))
using namespace std;

vector<int> getSplitNumbers(string s)
{
	for (int i = 0; i < s.size(); i ++)
		if (! isdigit(s[i])) s[i] = ' ';
	vector<int> ans;
	ans.clear();
	if (! s.size()) return ans;
	for ( ; ; )
	{
		int j = s.find(" ");
		if (j == string::npos)
		{
			ans.push_back(atoi(s.c_str()));
			return ans;
		}
		int x;
		sscanf(s.c_str(), "%d", &x);
		ans.push_back(x);
		s.erase(0, j + 1);
	}
	return ans;
}
	
class MeetInTheMaze {
public:
	string getExpected(vector <string> maze);
};

#define S 60

const int d[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

struct node
{
	int x, y;
	node() {}
	node (int x_, int y_) : x(x_), y(y_) {}
};

int D[S][S][S][S], P[S][S];
int u[S][S];

node q[1 << 20];
int f, r;
vector<node> R, F;

int gcd(int a, int b)
{
	return (b) ? gcd(b, a % b) : a;
}

string MeetInTheMaze::getExpected(vector <string> maze) 
{
	int N = maze.size(), M = maze[0].size();
	for (int i = 0; i < N; i ++)
		for (int j = 0; j < M; j ++)
			for (int p = 0; p < N; p ++)
				for (int q = 0; q < M; q ++)
					D[i][j][p][q] = -1;
	//BFS to make D[][][][]
	for (int sx = 0; sx < N; sx ++)
		for (int sy = 0; sy < M; sy ++)
		{
			if (maze[sx][sy] == '#') continue;
			memset(u, 0, sizeof(u));
			u[sx][sy] = 1, f = 0, r = 1, q[1] = node(sx, sy);
			D[sx][sy][sx][sy] = 0;
			for ( ; f != r; )
			{
				f ++; f %= (1 << 20);
				int x = q[f].x, y = q[f].y;
				for (int dir = 0; dir < 4; dir ++)
				{
					int nx = x + d[dir][0], ny = y + d[dir][1];
					if (nx >= 0 && nx < N && ny >= 0 && ny < M && maze[nx][ny] != '#' && ! u[nx][ny])
						D[sx][sy][nx][ny] = D[sx][sy][x][y] + 1, u[nx][ny] = 1, r ++, r %= (1 << 20), q[r] = node(nx, ny);
				}
			}
		}
	//make R, F
	R.clear(), F.clear();
	for (int i = 0; i < N; i ++)
		for (int j = 0; j < M; j ++)
		{
			if (maze[i][j] == 'R') R.push_back(node(i, j));
			if (maze[i][j] == 'F') F.push_back(node(i, j));
		}
	//ans
	LL ans = 0LL;
	for (int RR = 0; RR < R.size(); RR ++)
		for (int FF = 0; FF < F.size(); FF ++)
		{
			int x1 = R[RR].x, y1 = R[RR].y;
			int x2 = F[FF].x, y2 = F[FF].y;
			f = r = 0;
			memset(u, 0, sizeof(u));
			for (int i = 0; i < N; i ++)
				for (int j = 0; j < M; j ++)
					P[i][j] = -1;
			for (int i = 0; i < N; i ++)
				for (int j = 0; j < M; j ++)
				{
					if (D[x1][y1][i][j] == -1 || D[x2][y2][i][j] == -1) continue;
					u[i][j] = 1; P[i][j] = D[x1][y1][i][j] + D[x2][y2][i][j];
					r ++, r %= (1 << 20);
					q[r] = node(i, j);
				}
			//SPFA
			int v = 0;
			for ( ; f != r; )
			{
				f ++, f %= (1 << 20);
				int x = q[f].x, y = q[f].y;
				v ++;
				if (v < 50000)	u[x][y] = 0;
				for (int dir = 0; dir < 4; dir ++)
				{
					int nx = x + d[dir][0], ny = y + d[dir][1];
					if (nx >= 0 && nx < N && ny >= 0 && ny < M && maze[nx][ny] != '#' && (P[nx][ny] == -1 || P[x][y] + 1 < P[nx][ny]))
					{
						P[nx][ny] = P[x][y] + 1;
						if (! u[nx][ny])
							u[nx][ny] = 1, r ++, r %= (1 << 20), q[r] = node(nx, ny);
					}
				}
			}
			for (int i = 0; i < N; i ++)
				for (int j = 0; j < M; j ++)
					if (maze[i][j] == 'L')
					{
						if (P[i][j] == -1) return "";
						ans += P[i][j];
					}
		}
	LL totalL = 0;
	for (int i = 0; i < N; i ++)
		for (int j = 0; j < M; j ++)
			if (maze[i][j] == 'L') totalL ++;
	totalL *= (LL) R.size() * (LL) F.size();

	LL G = gcd(ans, totalL);
	ans /= G;
	totalL /= G;
	
	char Buf[1000];
	sprintf(Buf, "%lld/%lld", ans, totalL);
	
	string v = string(Buf);
	return v;
}






// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, string p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	MeetInTheMaze *obj;
	string answer;
	obj = new MeetInTheMaze();
	clock_t startTime = clock();
	answer = obj->getExpected(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p1 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
	if (hasAnswer) {
		res = answer == p1;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	vector <string> p0;
	string p1;
	
	{
	// ----- test 0 -----
	string t0[] = {"#########","####F####","##L...R##","####L####","#########"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "9/2";
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"LR","RF"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "2/1";
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"..F.#...","L.F.#..L","..F.#...",".R.#..L.","...#....","..R#.L.."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "";
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {".L..L..L..","..........","..........","..........","........R.","...R......","..........","..........","..........",".......F.."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "40/3";
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"#.#....#...#.#","#...#..#......",".L#...#R#..#F.","#...#......#..","#......#.....#",".R.....F....L.","##..#.......#.","#........##...",".F...##L#..#R#"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "362/27";
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	string t0[] = {"LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLFLLLLLLLLLFLLLL","LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL","LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL","LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL","LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL","LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL","LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL","LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL","LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLFFLLLLLLLLLLRLLLL","LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL","LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL","LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL","LLLLLLLLLLLLLLLLLLLLLLLLLLLLRLLLLLFLLLLLLLLLLLLLLF","LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL","LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLF","LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLFLLL","LLLLLLLLLLLRLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL","LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLRRL","LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL"
			"LLLL","LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL","LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLRLLLLLLLLLLLLLLLL","LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLR","LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL","LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLRLLL","LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL","LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLRLLLLLL","LLLLLLLLLLLLLLLLLLLLLLLRLLLLLLLLLLLLLLLLLLLLLLLLLL","LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL","LLLLLLLLLLLLLLLLRLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL","LLLLLLLLLFFLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL","FLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL","LLLLLLLLLLLLLLLLRLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL","LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL","LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL","LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLRLLLLLLLLLLLLLL","LLLLLLLLLLLLLLLLLLLLLLFLLLLLLLLLLLLLLLLLLLLLLLLLLL","LLLLLLLLLLLLLLLLFLLLLLLLLLRLLLLLLLLLLLLLLLLLLLRLLL","LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL"
			"LLLLLLLLLL","LLLLLLLFLLLLLLLLLLLLLLLLRLLLLLLLLLRLLLLLLLLLLLLRLL","LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLRLLLLL","LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL","LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL","LLLFLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL","LLLLLLLLLLLLLLLLLLLLLLLLLFLLLLLLLLLLLLLLLLLLLLLLLL","LLLLLLLLLLLLLLLLLLLLFLLLLLLLLLLLLLLLLLLLLLLLLLLLLL","FLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL","LLLLLLLLLRLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL","LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL","LLLLLLLLLFLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL","LLLLLLLLLLLLLLLLLLLLLLLLLLLFLLLLLLLLLLLLLLLLLLLLLL"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "210623/4100";
	all_right = KawigiEdit_RunTest(5, p0, true, p1) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!

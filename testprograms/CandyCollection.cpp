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
	
class CandyCollection {
public:
	int solve(vector <int> Type1, vector <int> Number1, vector <int> Type2, vector <int> Number2);
};

struct node
{
	node() {}
	node(int _x, int _w) : x(_x), w(_w) {}
	int x, w;
};

const int inf = 1000000000;

int u[2][2010];
int tot[2][2010];
node adj[2][2010][2];
int N;

int f[2010][2];

void ins(int type, int x, int y, int w)
{
	int cur = tot[type][x] ++;
	adj[type][x][cur] = node(y, w);
}

int make(int shape, int flavor)
{
	if (flavor == adj[0][shape][0].x)
		return adj[0][shape][1].w + 1;
	return adj[0][shape][0].w + 1;
}

int CandyCollection::solve(vector <int> Type1, vector <int> Number1, vector <int> Type2, vector <int> Number2) 
{
	N = Type1.size();
	//make adj[][][]
	memset(tot, 0, sizeof(tot));
	for (int i = 0; i < N; i ++)
	{
		ins(0, i, Type1[i], Number1[i]);
		ins(1, Type1[i], i, Number1[i]);
		ins(0, i, Type2[i], Number2[i]);
		ins(1, Type2[i], i, Number2[i]);
	}
	
	memset(u, 0, sizeof(u));
	int totAns = 0;
	for (int i = 0; i < N; i ++)
		if (! u[1][i])
		{
			vector<int> who[2];
			who[0].clear(), who[1].clear();
			who[0].push_back(-1);
			who[1].push_back(-1);
			
			int curType = 1, curId = i;
			
			for ( ; ; )
			{
				who[curType].push_back(curId);
				u[curType][curId] = 1;
				
				int nextId = -1;
				for (int p = 0; p < 2; p ++)
				{
					int next = adj[curType][curId][p].x;
					if (! u[curType ^ 1][next])
					{
						nextId = next;
						break;
					}
				}
				if (nextId == -1)
					break;
				curType ^= 1;
				curId = nextId;
			}
			
			
			//dp
			int n = who[0].size() - 1;
			int curMin = inf;
			
			//1 does not make 0
			for (int i = 1; i <= n; i ++)
				f[i][0] = f[i][1] = inf;
			
			f[1][0] = 0;
			f[1][1] = make(who[0][1], who[1][2]);
			
			for (int i = 1; i < n; i ++)
			{
				//make w
				int w0, w1;
				w0 = make(who[0][i + 1], who[1][i + 1]);
				w1 = make(who[0][i + 1], (i + 2 > n ? who[1][1] : who[1][i + 2]));
				
				f[i + 1][0] = min(f[i + 1][0], f[i][0] + w0);
				f[i + 1][0] = min(f[i + 1][0], f[i][1]);
				
				f[i + 1][1] = min(f[i + 1][1], f[i][0] + max(w0, w1));
				f[i + 1][1] = min(f[i + 1][1], f[i][1] + w1);
			}
			curMin = min(curMin, f[n][1]);
			
			//1 makes 0
			for (int i = 1; i <= n; i ++)
				f[i][0] = f[i][1] = inf;
			
			f[1][0] = make(who[0][1], who[1][1]);
			f[1][1] = make(who[0][1], who[1][2]);
			f[1][1] = max(f[1][1], f[1][0]);
			
			for (int i = 1; i < n; i ++)
			{
				//make w
				int w0, w1;
				w0 = make(who[0][i + 1], who[1][i + 1]);
				w1 = (i + 2 > n ? 0 : make(who[0][i + 1], who[1][i + 2]));
				
				f[i + 1][0] = min(f[i + 1][0], f[i][0] + w0);
				f[i + 1][0] = min(f[i + 1][0], f[i][1]);
				
				f[i + 1][1] = min(f[i + 1][1], f[i][0] + max(w0, w1));
				f[i + 1][1] = min(f[i + 1][1], f[i][1] + w1);
			}
			curMin = min(curMin, f[n][1]);
			totAns += curMin;
		}
	return totAns;
}
	

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, vector <int> p2, vector <int> p3, bool hasAnswer, int p4) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p2.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p2[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p3.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p3[i];
	}
	cout << "}";
	cout << "]" << endl;
	CandyCollection *obj;
	int answer;
	obj = new CandyCollection();
	clock_t startTime = clock();
	answer = obj->solve(p0, p1, p2, p3);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p4 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p4;
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
	
	vector <int> p0;
	vector <int> p1;
	vector <int> p2;
	vector <int> p3;
	int p4;
	
	{
	// ----- test 0 -----
	int t0[] = {0,0};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {1,1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {1,1};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {1,1};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 2;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {0,0};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {2,5};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {1,1};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {2,5};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 3;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {0,0,2,3};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {1,1,2,2};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {1,1,3,2};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {1,1,2,2};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 5;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {0,1,2,3};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {5,5,10,13};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {1,2,3,0};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {8,8,10,15};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 20;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	int t0[] = {12,9,0,16,9,18,12,3,6,0,8,2,10,6,5,2,14,10,5,13};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {895,704,812,323,334,674,665,142,712,254,869,548,645,663,758,38,860,724,742,530};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {1,4,7,11,15,8,18,13,17,17,19,14,7,11,4,1,15,19,3,16};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {779,317,36,191,843,289,107,41,943,265,649,447,806,891,730,371,351,7,102,394};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 5101;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, true, p4) && all_right;
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

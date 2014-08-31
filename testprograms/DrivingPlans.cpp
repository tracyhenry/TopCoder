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
	
class DrivingPlans {
public:
	int count(int N, vector <int> A, vector <int> B, vector <int> C);
};

int inf = 1000000000;
int base = 5000000;
int d[5050], u[5050], c[5050];
int e[5050];
int q[1010100];
int f, r;

vector<pair<int, int> > adj[5050];

int DrivingPlans::count(int N, vector <int> A, vector <int> B, vector <int> C) 
{
	for (int i = 1; i <= N; i ++)
		adj[i].clear();
	for (int i = 0; i < A.size(); i ++)
	{
		int x = A[i];
		int y = B[i];
		int w = C[i];
		adj[x].push_back(make_pair(y, w));
		adj[y].push_back(make_pair(x, w));
	}
	
	//spfa1
	memset(u, 0, sizeof(u));
	f = 0, r = 1;
	q[1] = 1;
	for (int i = 1; i <= N; i ++)
		d[i] = inf;
	d[1] = 0;
	
	while (f < r)
	{
		f = (f + 1) % base;
		int x = q[f];
		u[x] = 0;
		for (int i = 0; i < adj[x].size(); i ++)
		{
			int next = adj[x][i].first;
			int w = adj[x][i].second;
			if (d[x] + w < d[next])
			{
				d[next] = d[x] + w;
				if (! u[next])
					u[next] = 1, r = (r + 1) % base, q[r] = next;
			}
		}
	}

	//spfa2
	memset(u, 0, sizeof(u));
	f = 0, r = 1;
	q[1] = N;
	for (int i = 1; i <= N; i ++)
		e[i] = inf;
	e[N] = 0;
	
	while (f < r)
	{
		f = (f + 1) % base;
		int x = q[f];
		u[x] = 0;
		for (int i = 0; i < adj[x].size(); i ++)
		{
			int next = adj[x][i].first;
			int w = adj[x][i].second;
			if (e[x] + w < e[next])
			{
				e[next] = e[x] + w;
				if (! u[next])
					u[next] = 1,  r = (r + 1) % base, q[r] = next;
			}
		}
	}
	
	for (int i = 0; i < A.size(); i ++)
	{
		int x = A[i];
		int y = B[i];
		int w = C[i];
		if (w) continue;
		if (d[x] + e[x] == d[N])
			return -1;
		if (d[y] + e[y] == d[N])
			return -1;
	}
	
	//
	vector<pair<int, int> > sa; sa.clear();
	for (int i = 1; i <= N; i ++)
		sa.push_back(make_pair(d[i], i));
	sort(sa.begin(), sa.end());
	
	memset(c, 0, sizeof(c));
	c[1] = 1;
	for (int i = 0; i < sa.size(); i ++)
	{
		int cur = sa[i].second;
		for (int j = 0; j < adj[cur].size(); j ++)
		{
			int next = adj[cur][j].first;
			int w = adj[cur][j].second;
			if (d[cur] + w == d[next])
			{
				c[next] = c[next] + c[cur];
				c[next] %= 1000000009;
			}
		}
	}	
		
	return c[N];
}
	





// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, vector <int> p1, vector <int> p2, vector <int> p3, bool hasAnswer, int p4) {
	cout << "Test " << testNum << ": [" << p0 << "," << "{";
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
	DrivingPlans *obj;
	int answer;
	obj = new DrivingPlans();
	clock_t startTime = clock();
	answer = obj->count(p0, p1, p2, p3);
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
	
	int p0;
	vector <int> p1;
	vector <int> p2;
	vector <int> p3;
	int p4;
	
	{
	// ----- test 0 -----
	p0 = 4;
	int t1[] = {1,1,2,3};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {2,3,4,4};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {1,1,1,1};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 2;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 4;
	int t1[] = {1,1,2,3};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {2,3,4,4};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {1,1,1,0};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = -1;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 20;
	int t1[] = {4, 18, 11, 16, 19, 3, 12, 11, 9, 10, 19, 13, 17, 2, 9, 10, 20, 18, 13, 9, 4, 7, 7, 3, 4, 2, 4, 8, 7, 19, 5, 3, 7, 18, 1, 20, 20, 8, 7, 6, 4, 19, 9, 19, 2, 14, 4, 14, 13, 16, 14, 2, 14, 11, 11, 19, 17, 11, 8, 20, 15, 12, 7, 3, 8, 4, 20, 15, 5, 15, 17, 20, 11, 18, 8, 7, 20, 14, 14, 9, 3, 16, 1, 17, 4, 20, 20, 11, 11, 13, 20, 2, 14, 8, 12, 18, 13, 5, 16, 8, 11, 13, 6, 3, 15, 10, 20, 4, 2, 13, 14, 11, 6, 15, 6, 13, 6, 5, 13, 15, 1, 5, 13, 2, 11, 1, 5, 7, 8, 10, 4, 17, 2, 3, 17, 8, 3, 12, 16, 6, 18, 6, 3, 18, 17, 5, 3, 15, 9, 8, 14, 15, 12, 4, 16, 7, 20, 1, 5, 11, 1, 18, 18, 17, 12, 18, 18, 13, 4, 2, 9, 1, 15, 15, 4, 20, 12, 12, 4, 11, 5, 16, 18, 11, 10, 6, 16, 2, 6, 14};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] ={13, 15, 1, 19, 6, 19, 3, 8, 15, 19, 20, 8, 2, 14, 10, 14, 5, 7, 19, 19, 19, 15, 3, 9, 20, 5, 15, 19, 12, 18, 19, 20, 16, 10, 4, 17, 10, 14, 9, 13, 5, 2, 13, 17, 3, 5, 17, 18, 10, 17, 12, 10, 1, 16, 20, 11, 18, 6, 9, 13, 20, 19, 6, 8, 16, 3, 12, 19, 8, 8, 7, 7, 15, 9, 6, 10, 1, 9, 3, 1, 18, 20, 12, 10, 7, 2, 9, 5, 17, 15, 14, 4, 7, 17, 9, 11, 1, 1, 4, 2, 9, 17, 1, 6, 10, 3, 8, 18, 9, 14, 16, 7, 10, 14, 9, 12, 17, 16, 3, 16, 16, 13, 7, 12, 14, 8, 9, 5, 18, 5, 14, 9, 1, 16, 14, 10, 1, 8, 10, 4, 6, 15, 17, 13, 12, 3, 11, 5, 4, 7, 6, 3, 10, 12, 13, 19, 6, 10, 17, 12, 7, 1, 2, 1, 15, 16, 5, 2, 11, 15, 16, 19, 17, 1, 8, 18, 5, 6, 10, 2, 6, 2, 12, 13, 11, 16, 12, 7, 2, 19};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {42579, 11971, 62807, 54022, 16705, 77182, 54950, 21301, 17223, 5747, 80798, 10208, 1619, 67377, 13262, 4754, 95268, 10973, 57107, 7515, 14528, 22944, 63946, 69667, 66270, 71346, 24236, 46899, 8996, 2263, 14470, 3616, 40786, 8010, 9135, 22303, 86545, 57400, 5721, 40402, 28998, 56876, 49592, 58495, 20306, 3969, 43967, 12764, 62854, 4473, 32733, 62623, 15894, 14178, 12598, 68200, 56232, 51495, 39384, 23691, 90506, 22232, 3469, 30283, 7123, 62654, 58566, 9708, 61369, 56607, 45259, 67562, 77908, 5252, 30194, 18983, 75405, 18016, 87683, 2122, 74919, 26776, 16839, 64242, 1292, 23922, 73283, 82670, 9705, 66815, 91299, 42348, 23737, 11596, 14717, 65937, 51714, 19863, 39494, 9977, 60685, 1388, 11312, 60477, 3961, 82929, 33899, 12265, 49361, 67608, 64523, 54964, 22452, 793, 9190, 34875, 41790, 68492, 20075, 63730, 48629, 71577, 43871, 34644, 78701, 41506, 21985, 27706, 44636, 8723, 25029, 50980, 51483, 23160, 68996, 52646, 71789, 24667, 59769, 2177, 14442, 26413, 18687, 54844, 36263, 91652, 8982, 4762, 7013, 33663, 27206, 86890, 27979, 7704, 3085, 13236, 64093, 11140, 72965, 45968, 7843, 3130, 54613, 53102, 31940, 51759, 16733, 231, 53672, 66584, 46507, 5393, 68203, 15101, 32371, 78535, 36702, 5527, 20275, 11324, 31175, 2854, 19969, 11093, 73947, 37317, 31790, 43640, 40171, 10501};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 4096;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
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

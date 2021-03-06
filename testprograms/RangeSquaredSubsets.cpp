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
	
class RangeSquaredSubsets {
public:
	long long countSubsets(int nlow, int nhigh, vector <int> x, vector <int> y);
};

set<int> S;
vector<int> cx, cy;
int n, inf = 1000000000;
int L[60][60][60], R[60][60][60], U[60][60][60], D[60][60][60];


long long RangeSquaredSubsets::countSubsets(int nlow, int nhigh, vector <int> x, vector <int> y) 
{
	n = x.size(); S.clear();
	cx.clear(), cy.clear();
	
	for (int i = 0; i < x.size(); i ++)
		S.insert(x[i]);
	for (set<int>::iterator i = S.begin(); i != S.end(); i ++)
		cx.push_back(*i);
	
	S.clear();
	for (int i = 0; i < y.size(); i ++)
		S.insert(y[i]);
	for (set<int>::iterator i = S.begin(); i != S.end(); i ++)
		cy.push_back(*i);
	
	//L
	for (int i = 0; i < cy.size(); i ++)
		for (int j = i; j < cy.size(); j ++)
			for (int curX = 0; curX < cx.size(); curX ++)
			{
				L[i][j][curX] = -inf;
				for (int k = 0; k < n; k ++)
					if (y[k] >= cy[i] && y[k] <= cy[j] && x[k] < cx[curX])
						L[i][j][curX] = max(L[i][j][curX], x[k]);
			}
	//R
	for (int i = 0; i < cy.size(); i ++)
		for (int j = i; j < cy.size(); j ++)
			for (int curX = 0; curX < cx.size(); curX ++)
			{
				R[i][j][curX] = inf;
				for (int k = 0; k < n; k ++)
					if (y[k] >= cy[i] && y[k] <= cy[j] && x[k] > cx[curX])
						R[i][j][curX] = min(R[i][j][curX], x[k]);
			}
	
	//U
	for (int i = 0; i < cx.size(); i ++)
		for (int j = i; j < cx.size(); j ++)
			for (int curY = 0; curY < cy.size(); curY ++)
			{
				U[i][j][curY] = inf;
				for (int k = 0; k < n; k ++)
					if (x[k] >= cx[i] && x[k] <= cx[j] && y[k] > cy[curY])
						U[i][j][curY] = min(U[i][j][curY], y[k]);
			}

	//D
	for (int i = 0; i < cx.size(); i ++)
		for (int j = i; j < cx.size(); j ++)
			for (int curY = 0; curY < cy.size(); curY ++)
			{
				D[i][j][curY] = -inf;
				for (int k = 0; k < n; k ++)
					if (x[k] >= cx[i] && x[k] <= cx[j] && y[k] < cy[curY])
						D[i][j][curY] = max(D[i][j][curY], y[k]);
			}
	
	int ans = 0;
	for (int x1 = 0; x1 < cx.size(); x1 ++)
		for (int x2 = x1; x2 < cx.size(); x2 ++)
			for (int y1 = 0; y1 < cy.size(); y1 ++)
				for (int y2 = y1; y2 < cy.size(); y2 ++)
				{
					int l = inf, r = -inf, u = - inf, d = inf;
					for (int k = 0; k < n; k ++)
						if (x[k] >= cx[x1] && x[k] <= cx[x2] && y[k] >= cy[y1] && y[k] <= cy[y2])
							l = min(l, x[k]), r = max(r, x[k]), d = min(d, y[k]), u = max(u, y[k]);
					if (l != cx[x1] || r != cx[x2] || d != cy[y1] || u != cy[y2]) continue;
					l = L[y1][y2][x1] + 1;
					r = R[y1][y2][x2] - 1;
					u = U[x1][x2][y2] - 1;
					d = D[x1][x2][y1] + 1;
					int flag = 1;
					if (nhigh < cx[x2] - cx[x1] || r - l + 1 < nlow) flag = 0;
					if (nhigh < cy[y2] - cy[y1] || u - d + 1 < nlow) flag = 0;
					if (u - d + 1 < cx[x2] - cx[x1] || r - l + 1 < cy[y2] - cy[y1]) flag = 0;
					ans += flag;
		//			if (flag) cout << cx[x1] << " " << cx[x2] << " " << cy[y1] << " " << cy[y2] << endl;
				}
	return ans;
}





// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, vector <int> p2, vector <int> p3, bool hasAnswer, long long p4) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << "{";
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
	RangeSquaredSubsets *obj;
	long long answer;
	obj = new RangeSquaredSubsets();
	clock_t startTime = clock();
	answer = obj->countSubsets(p0, p1, p2, p3);
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
	int p1;
	vector <int> p2;
	vector <int> p3;
	long long p4;
	
	{
	// ----- test 0 -----
	p0 = 5;
	p1 = 5;
	int t2[] = {-5,0,5};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {0,0,0};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 5ll;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 10;
	p1 = 10;
	int t2[] = {-5,0,5};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {0,0,0};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 5ll;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 1;
	p1 = 100;
	int t2[] = {-5,0,5};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {0,0,0};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 6ll;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 3;
	p1 = 100000000;
	int t2[] = {-1,-1,-1,0,1,1,1};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {-1,0,1,1,-1,0,1};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 21ll;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 64;
	p1 = 108;
	int t2[] = {-56,-234,12,324,-12,53,0,234,1,12,72};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {6,34,2,235,234,234,342,324,234,234,234};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 26ll;
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

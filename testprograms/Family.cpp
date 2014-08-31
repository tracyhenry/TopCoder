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
#include <cstring>
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
	
class Family {
public:
	string isFamily(vector <int> parent1, vector <int> parent2);
};

int g[220][220];
int N;
int u[220], flag;

void dfs(int x)
{
	for (int i = 0; i < N; i ++)
		if (g[x][i])
		{
			if (u[i])
			{
				if (u[i] == u[x]) flag = 0;
			}
			else 
			{
				u[i] = 3 - u[x];
				dfs(i);
			}
		}
}

string Family::isFamily(vector <int> parent1, vector <int> parent2) 
{
	memset(g, 0, sizeof(g));
	N = parent1.size();
	for (int i = 0; i < N; i ++)
		if (parent1[i] != -1)
			g[parent1[i]][parent2[i]] = g[parent2[i]][parent1[i]] = 1;
	
	flag = 1;
	memset(u, 0, sizeof(u));
	for (int i = 0; i < N; i ++)
		if (! u[i])
		{	
			u[i] = 1;
			dfs(i);
		}
	if (flag) return "Possible"; else return "Impossible";
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, bool hasAnswer, string p2) {
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
	cout << "}";
	cout << "]" << endl;
	Family *obj;
	string answer;
	obj = new Family();
	clock_t startTime = clock();
	answer = obj->isFamily(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p2 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
	if (hasAnswer) {
		res = answer == p2;
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
	string p2;
	
	{
	// ----- test 0 -----
	int t0[] = {-1,-1,0};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {-1,-1,1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "Possible";
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {-1,-1,-1,-1,-1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {-1,-1,-1,-1,-1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "Possible";
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {-1,-1,0,0,1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {-1,-1,1,2,2};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "Impossible";
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {-1,-1,-1,-1,1,-1,0,5,6,-1,0,3,8,6};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {-1,-1,-1,-1,3,-1,4,6,5,-1,5,4,6,1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "Possible";
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	int t0[] = {-1,-1,-1,2,2,-1,5,6,4,6,2,1,8,0,2,4,6,9,-1,16,-1,11};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {-1,-1,-1,1,0,-1,1,4,2,0,4,8,2,3,0,5,14,14,-1,7,-1,13};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "Impossible";
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
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

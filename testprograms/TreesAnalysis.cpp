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
	
class TreesAnalysis {
public:
	long long treeSimilarity(vector <int> tree1, vector <int> tree2);
};

int label[10100];
vector<int> adj[2][10100];
int u[10100], sum[2][10100];
int n;

void dfs1(int x, int p, int q)
{
	label[x] = 1;
	for (int i = 0; i < adj[0][x].size(); i ++)
	{
		int y = adj[0][x][i];
		if (x == p && y == q) continue;
		if (x == q && y == p) continue;
		if (! label[y])
			dfs1(y, p, q);
	}
}

void dfs2(int x)
{
	u[x] = 1;
	sum[0][x] = sum[1][x] = 0;
	sum[label[x]][x] ++;
	for (int i = 0; i < adj[1][x].size(); i ++)
	{
		int y = adj[1][x][i];
		if (! u[y])
		{
			dfs2(y);
			sum[0][x] += sum[0][y];
			sum[1][x] += sum[1][y];
		}
	}
}
	
long long TreesAnalysis::treeSimilarity(vector <int> tree1, vector <int> tree2) 
{
	n = tree1.size() + 1;
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < 2; j ++)
			adj[j][i].clear();
	
	for (int i = 0; i < tree1.size(); i ++)
	{
		int x = i, y = tree1[i];
		adj[0][x].push_back(y);
		adj[0][y].push_back(x);
	}
	for (int i = 0; i < tree2.size(); i ++)
	{
		int x = i, y = tree2[i];
		adj[1][x].push_back(y);
		adj[1][y].push_back(x);
	}
	
	LL ans = 0;
	for (int k = 0; k < tree1.size(); k ++)
	{
		int p = k, q = tree1[k];
		memset(label, 0, sizeof(label));
		dfs1(p, p, q);
		
		memset(u, 0, sizeof(u));
		dfs2(0);
		
		for (int i = 1; i < n; i ++)
		{
			int cur = 0;
			
			cur = max(cur, sum[0][i]);
			cur = max(cur, sum[1][i]);
			cur = max(cur, sum[0][0] - sum[0][i]);
			cur = max(cur, sum[1][0] - sum[1][i]);
			ans += sqr((LL) cur);
		}
	}
	return ans;
}	

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, bool hasAnswer, long long p2) {
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
	TreesAnalysis *obj;
	long long answer;
	obj = new TreesAnalysis();
	clock_t startTime = clock();
	answer = obj->treeSimilarity(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
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
	long long p2;
	
	{
	// ----- test 0 -----
	int t0[] = {1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 1ll;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {2,4,1,0};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {1,4,4,4};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 111ll;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {1,2,3,4};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {1,2,3,4};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 128ll;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {2,3,4,4,5,8,5,6,10,8};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {9,0,1,0,3,0,5,0,7,10};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 6306ll;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	int t0[] = {222,261,167,133,174,150,165,311,208,268,111,222,154,277,282,201,46,124,194,331,4,216,111,275,72,322,137,216,241,48,72,101,232,165,151,263,139,16,122,140,84,135,314,106,309,126,102,151,208,27,242,93,83,314,136,77,82,215,16,232,286,156,294,38,67,204,206,137,174,282,188,143,84,279,236,136,158,10,65,332,122,44,329,62,174,67,102,216,245,296,287,307,93,197,169,268,266,294,157,277,95,68,214,135,211,127,82,108,212,161,243,212,207,119,119,158,97,290,21,217,230,85,171,13,138,294,304,204,318,115,70,210,195,223,37,164,149,3,164,328,316,108,330,48,38,324,222,193,50,41,184,93,148,41,151,139,106,301,264,80,249,110,244,109,212,223,279,330,67,27,301,165,236,194,3,157,1,217,311,87,105,4,286,37,6,31,111,66,230,227,244,322,196,65,69,305,112,133,231,68,153,206,309,248,329,58,69,69,328,0,29,233,243,305,167,80,65,194,190,179,142,196,324,206,134,50,272,261,10,147,329,322,14,142,169,21,296,284,241,55,304,150,166,230,167,304,87,156,156,97,274,324,196,101,82,106,260,242,233,207,305,10,166,53,18,154,233,217,296,263,168,138,30,115,135,188,98,309,292,204,150,210,332,330,166,96,70,24,229,215,201,285,40,287,142,68,133,208,268,161,310,41,203,73,275,184,163,227,89,110,328,108,112,125,164,127,179,267,221,49,139,1,84,136,38,6,70,246,243,3,188,297};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {174,262,195,288,157,278,36,133,230,273,222,138,97,23,189,141,296,55,45,301,81,199,188,289,187,164,113,58,138,300,289,282,329,91,130,178,92,143,48,81,311,133,151,286,171,196,199,80,83,121,65,151,277,136,49,111,58,36,259,14,31,9,136,181,122,324,249,114,9,37,259,242,165,174,34,36,298,92,301,237,178,82,65,295,110,311,274,235,68,56,259,180,195,52,110,68,140,71,52,296,290,115,213,82,209,209,74,178,302,131,99,205,296,309,288,180,329,71,143,58,152,273,196,7,169,88,231,331,213,181,80,249,170,246,16,127,75,276,332,174,21,180,163,78,242,312,295,199,89,142,85,195,115,119,95,94,279,290,3,33,93,284,20,47,47,78,331,271,113,179,249,331,92,324,9,71,232,46,28,289,80,28,80,134,20,280,277,48,205,107,52,320,4,191,160,182,189,227,295,115,54,195,78,292,189,273,301,69,305,36,222,167,326,106,48,45,74,61,181,311,292,270,201,34,314,218,214,92,269,18,37,151,142,209,11,227,327,198,28,272,152,22,47,143,332,253,273,35,78,130,295,223,181,329,18,238,300,186,274,99,300,322,41,185,311,288,198,2,37,83,238,133,122,178,107,106,66,238,69,90,38,109,246,278,288,250,321,269,130,28,115,122,33,185,275,99,130,99,152,268,133,249,180,30,210,201,324,29,290,143,3,269,68,106,230,1,269,29,120,259,324,328,23,243,9,61,14,118,199,146,237,14};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 11478648052ll;
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

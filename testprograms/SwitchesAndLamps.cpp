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
	
class SwitchesAndLamps {
public:
	int theMin(vector <string> switches, vector <string> lamps);
};

string s[1010], l[1010];
int g[100][100], tot[100], u[100];

int SwitchesAndLamps::theMin(vector <string> switches, vector <string> lamps) 
{
	int n = switches[0].size();
	for (int i = 0; i < n; i ++)
		s[i] = l[i] = "";
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < switches.size(); j ++)
			s[i] += switches[j][i];
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < lamps.size(); j ++)
			l[i] += switches[j][i];
	
	memset(g, 0, sizeof(g));
	memset(tot, 0, sizeof(tot));
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < n; j ++)
			if (l[i] == s[j]) g[i][j] = 1, tot[i] ++;
	for (int i = 0; i < n; i ++)
		if (tot[i] == 0) return -1;
	
	int ans = 0;
	for ( ; ; )
	{
		int flag = 0;
		memset(u, 0, sizeof(u));
		for (int i = 0; i < n; i ++)
		{
			if (tot[i] == 1) continue;
			flag = 1;
			for (int j = 0; j < n; j ++)
				if (g[i][j]) u[j] ++;
		}
		if (! flag) break;
		int id = -1, max = 0;
		for (int i = 0; i < n; i ++)
			if (u[i] > max)
				max = u[i], id = i;
		ans ++;
		for (int i = 0; i < n; i ++)
			if (g[i][id]) tot[i] --;
	}
	return ans;
}
								


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <string> p0, vector <string> p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p1[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	SwitchesAndLamps *obj;
	int answer;
	obj = new SwitchesAndLamps();
	clock_t startTime = clock();
	answer = obj->theMin(p0, p1);
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
	
	vector <string> p0;
	vector <string> p1;
	int p2;
	
	{
	// ----- test 0 -----
	string t0[] = {"NYNN","NNYN"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"NNNY","NNYN"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 1;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"YYN","YNY","YYN"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"YNY","NYY","YNY"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 0;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"NYYYNYNNYYYNYNNNNY","NYYYNYNNYYYNYNNNNY"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"YYYNNNYNNYNYNYNYNY","YYYNNNYNNYNYYNNYNY"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = -1;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"YYNNN","NNYYN"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"NYNNY","NNNYY"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = -1;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"YNNYNNYNYY","NYNNYNYNYN","YNYNYYYYYN","NNYYNYNYNN"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"NYYNYNNYNY","NYYYNNYNNN","YYYYNYNNYY","YNNNNYNYYN"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 2;
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
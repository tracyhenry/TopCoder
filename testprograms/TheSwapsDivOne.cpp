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
	
class TheSwapsDivOne {
public:
	double find(vector <string> sequence, int k);
};

double F[2][101010], Pow[1010100], s_Pow[1010100];
double S[101010];
int cur;
int n;

double TheSwapsDivOne::find(vector <string> sequence, int k) 
{
	string s;
	for (int i = 0; i < sequence.size(); i ++)
		s += sequence[i];
	n = s.size();
	//F
	cur = 0;
	for (int i = 1; i <= n; i ++)
		F[cur][i] = s[i - 1] - 48;
	
	double P1 = 1.0 / (double(n) * double(n - 1) / 2);
	double P2 = 1.0 - P1 * double(n - 1);
	double sum = 0;
	for (int i = 1; i <= n; i ++)
		sum += double(s[i - 1] - 48);

	//
	Pow[0] = 1;
	for (int i = 1; i <= k; i ++)
		Pow[i] = Pow[i - 1] * double(P2 - P1);
	s_Pow[0] = 1;
	for (int i = 1; i <= k; i ++)
		s_Pow[i] = s_Pow[i - 1] + Pow[i];
	
	for (int i = 1; i <= n; i ++)
		F[cur ^ 1][i] = Pow[k] * F[cur][i] + P1 * sum * s_Pow[k - 1];
	cur ^= 1;
	
	double P = 1.0 / (double(n) * double(n + 1) / 2);
	S[0] = 0;
	for (int i = 1; i <= n; i ++)
		S[i] = S[i - 1] + F[cur][i];
	double ans = 0;
	for (int i = 1; i <= n; i ++)
		for (int j = i; j <= n; j ++)
			ans += P * (S[j] - S[i - 1]);
	return ans;
}
	







// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <string> p0, int p1, bool hasAnswer, double p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}" << "," << p1;
	cout << "]" << endl;
	TheSwapsDivOne *obj;
	double answer;
	obj = new TheSwapsDivOne();
	clock_t startTime = clock();
	answer = obj->find(p0, p1);
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
		res = answer == answer && fabs(p2 - answer) <= 1e-9 * max(1.0, fabs(p2));
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
	int p1;
	double p2;
	
	{
	// ----- test 0 -----
	string t0[] = {"4","77"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1;
	p2 = 10.0;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"4","77"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 47;
	p2 = 10.0;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"1","1","1","1","1","1","1"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1000000;
	p2 = 3.0;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"572685085149095989026478064633266980348504469","19720257361","9","69"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 7;
	p2 = 98.3238536775161;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
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

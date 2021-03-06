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
#include <string>
#include <cstring>
#include <ctime>
#define LL long long
#define pi 3.1415926535897932384626433 
#define sqr(a) ((a)*(a))
using namespace std;
	
class PalindromePermutations {
public:
	double palindromeProbability(string word);
};

int tot[30];
double fac[60];

double PalindromePermutations::palindromeProbability(string word) 
{
	memset(tot, 0, sizeof(tot));
	for (int i = 0; i < word.size(); i ++)
		tot[word[i] - 97] ++;
	
	int odd = 0;
	for (int i = 0; i < 26; i ++)
		if (tot[i] & 1) odd ++;
	
	if (odd > 1)
		return 0;
	
	int len = (int) word.size();
	len /= 2;
	
	vector<int> div; div.clear();
	for (int i = 0; i < 26; i ++)
		if (tot[i] > 1)
			div.push_back(tot[i] / 2);
	
	
	//make fac[]
	fac[0] = 1;
	for (int i = 1; i <= (int) word.size(); i ++)
		fac[i] = fac[i - 1] * (double) i;
	
	double ans = fac[len];
	cout << ans << endl;
	for (int i = 0; i < div.size(); i ++)
		ans /= fac[div[i]], cout << fac[div[i]] << " " << div[i] << endl;
	ans /= fac[word.size()];
	for (int i = 0; i < 26; i ++)
		ans *= fac[tot[i]];
	
	return ans;
}
	
	


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, string p0, bool hasAnswer, double p1) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"";
	cout << "]" << endl;
	PalindromePermutations *obj;
	double answer;
	obj = new PalindromePermutations();
	clock_t startTime = clock();
	answer = obj->palindromeProbability(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == answer && fabs(p1 - answer) <= 1e-9 * max(1.0, fabs(p1));
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
	
	string p0;
	double p1;
	
	{
	// ----- test 0 -----
	p0 = "haha";
	p1 = 0.3333333333333333;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = "xxxxy";
	p1 = 0.2;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = "xxxx";
	p1 = 1.0;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = "abcde";
	p1 = 0.0;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhff";
	p1 = 0.025641025641025637;
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
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

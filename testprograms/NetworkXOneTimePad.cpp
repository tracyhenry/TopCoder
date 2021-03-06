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
	
class NetworkXOneTimePad {
public:
	int crack(vector <string> plaintexts, vector <string> ciphertexts);
};

set<string> s;

string Xor(string a, string b)
{
	string ans = "";
	for (int i = 0; i < a.size(); i ++)
		ans += char(48 + ((a[i] - 48)^(b[i] - 48)));
	return ans;
}

int NetworkXOneTimePad::crack(vector <string> plaintexts, vector <string> ciphertexts) 
{
	s.clear();
	for (int i = 0; i < plaintexts.size(); i ++)
		for (int j = 0; j < ciphertexts.size(); j ++)
			s.insert(Xor(plaintexts[i], ciphertexts[j]));
	int ans = 0;
	for (set<string>::iterator i = s.begin(); i != s.end(); i ++)
		ans ++;
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
	NetworkXOneTimePad *obj;
	int answer;
	obj = new NetworkXOneTimePad();
	clock_t startTime = clock();
	answer = obj->crack(p0, p1);
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
	string t0[] = {"110","001"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"101","010"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 2;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"00","01","10","11"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"00","01","10","11"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 4;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"01","10"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"00"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 2;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"000","111","010","101","110","001"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"011","100"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 6;
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

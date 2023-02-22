#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;
int mass(char c) {
	return c == 'H' ? 1 : (c == 'O' ? 16 : 12);
}
int main() {
	string s;
	cin >> s;
	stack<int> st;
	int temp1, temp2, res = 0;
	for (char c : s) {
		if (isalpha(c)) {
			st.push(mass(c));
		}
		else if (isdigit(c)) {
			temp1 = st.top();
			st.pop();
			st.push(temp1 * (c-'0'));
		}
		else if (c == '(') {
			st.push(-1);
		}
		else if (c == ')') {
			temp2 = 0;
			while (st.top() != -1) {
				temp2 += st.top();
				st.pop();
			}
			st.pop();
			st.push(temp2);
		}
	}
	while (!st.empty()) {
		res += st.top();
		st.pop();
	}
	cout << res;
	return 0;
}

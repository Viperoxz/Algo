#include <iostream>
#include <stack>
using namespace std;
void transform(string expression) {
	stack<char> s;
	for (char symbol : expression) {
		if (isalpha(symbol)) {
			cout << symbol;
		}
		else if (symbol == ')') {
			cout << s.top();
			s.pop();
		}
		else if (symbol != '(')
			s.push(symbol);
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string expression;
		cin >> expression;
		transform(expression);
		cout << "\n";
	}
	return 0;
}

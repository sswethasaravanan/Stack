#include <bits/stdc++.h> 
using namespace std; 
int prec(char c) 
{
	if (c == '^') 
		return 3; 
	else if (c == '/' || c == '*') 
		return 2; 
	else if (c == '+' || c == '-') 
		return 1; 
	else
		return -1; 
} 
void infixToPostfix(string s) 
{
	stack<char> st; 
	string result; 
	for (int i = 0; i < s.length(); i++) 
	{ 
		char c = s[i];
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') 
			|| (c >= '0' && c <= '9')) 
			result += c;
		else if (c == '(') 
			st.push('(');
		else if (c == ')') { 
			while (st.top() != '(') { 
				result += st.top(); 
				st.pop(); 
			} 
			st.pop(); 
		}
		else { 
			while (!st.empty() 
				&& prec(s[i]) <= prec(st.top())) { 
				result += st.top(); 
				st.pop(); 
			} 
			st.push(c); 
		} 
	} 
	while (!st.empty()) { 
		result += st.top(); 
		st.pop(); 
	} 
	cout << "The Postfix Value is :"<<result << endl; 
} 
int evaluatePostfix(string exp)
{
	stack<int> st;
	for (int i = 0; i < exp.size(); ++i) {
		if (isdigit(exp[i]))
			st.push(exp[i] - '0');
		else {
			int val1 = st.top();
			st.pop();
			int val2 = st.top();
			st.pop();
			switch (exp[i]) {
			case '+':
				st.push(val2 + val1);
				break;
			case '-':
				st.push(val2 - val1);
				break;
			case '*':
				st.push(val2 * val1);
				break;
			case '/':
				st.push(val2 / val1);
				break;
			}
		}
	}
	return st.top();
}
int main() 
{ 
	string exp;
	cout<<"Enter the Infix Value :";
	cin >> exp; 
	infixToPostfix(exp); 
	return 0; 
}
int main()
{
	string exp = "231*+9-";
	cout << "postfix evaluation: " << evaluatePostfix(exp);
	return 0;
}

// assignment04.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <cctype>
#include <cstring>
#include <stack>

using namespace std;

void evaluateStackTops(stack<double>& numbers, stack<char>& operations) {
	double op1, op2;
	op2 = numbers.top();
	numbers.pop();
	op1 = numbers.top();
	numbers.pop();
	switch (operations.top()) {
	case '+': numbers.push(op1 + op2);
		break;
	case '-': numbers.push(op1 - op2);
		break;
	case '*': numbers.push(op1 * op2);
		break;
	case '/': numbers.push(op1 / op2);
		break;
	}
	operations.pop();
}

void evaluatePostFix(stack<double>& numbers, stack<char>& operations) {
	double op1, op2;
	op2 = numbers.top();
	numbers.pop();
	op1 = numbers.top();
	numbers.pop();
	switch (operations.top()) {
	case '+': numbers.push(op2 + op1);
		break;
	case '-': numbers.push(op2 - op1);
		break;
	case '*': numbers.push(op2 * op1);
		break;
	case '/': numbers.push(op2 / op1);
		break;
	}
	operations.pop();
}


double readAndEvaluatePostFix(istream& ins) {
	const char DECIMAL = '.';
	const char RIGHTPAREN = ')';
	stack<double> numbers;
	stack<char> operations;
	double number;
	char symbol;
	while (ins && ins.peek() != '\n') {
		if (isdigit(ins.peek()) || (ins.peek() == DECIMAL)) {
			ins >> number;
			numbers.push(number);
		}
		else if (strchr("+-*/", ins.peek()) != NULL) {
			ins >> symbol;
			operations.push(symbol);
		}
		else if (ins.peek() == RIGHTPAREN) {
			ins.ignore();
			evaluatePostFix(numbers, operations);
		}
		else {
			ins.ignore();
		}
	}
	return numbers.top();
}

double readAndEvaluate(istream& ins) {
	const char DECIMAL = '.';
	const char RIGHTPAREN = ')';
	stack<double> numbers;
	stack<char> operations; 
	double number;
	char symbol;
	while (ins && ins.peek() != '\n') {
		if (isdigit(ins.peek()) || (ins.peek() == DECIMAL)) {
			ins >> number;
			numbers.push(number);
		}
		else if (strchr("+-*/", ins.peek()) != NULL) {
			ins >> symbol;
			operations.push(symbol);
		}
		else if (ins.peek() == RIGHTPAREN) {
			ins.ignore();
			evaluateStackTops(numbers, operations);
		}
		else {
			ins.ignore();
		}
	}
	return numbers.top();
}

int main()
{
	double answer;
	cout << "Type a fully parenthsized expression" << endl;
	answer = readAndEvaluatePostFix(cin);
	cout << "That evaluates to " << answer << endl;
}

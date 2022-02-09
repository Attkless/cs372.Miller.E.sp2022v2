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

double readAndEvaluate(istream& ins) {

	const char RIGHTPAREN = ')';
	stack<double> numbers;
	stack<char> operations; 
	double number;
	char symbol;
	while (ins && ins.peek() != '\n') {
		if (isdigit(ins.peek()))
		{
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
	const char RIGHTPAREN = ')';
	stack<double> numbers;
	stack<char> operations;
	double number;
	char symbol;
	while (ins && ins.peek() != '\n') {
		if (isdigit(ins.peek())) {
			ins >> number;
			numbers.push(number);
		}
		else if (strchr("+-*/", ins.peek()) != NULL) {
			ins >> symbol;
			operations.push(symbol);
			evaluatePostFix(numbers, operations);
		}
		
		else {
			ins.ignore();
		}
	}
	return numbers.top();
}

void evaluatePreFix(stack<double>& numbers, stack<char>& operations) {
	if (numbers.size() < 2 || operations.size() < 1) { return; }
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

double readAndEvaluatePreFix(istream& ins) {
	const char RIGHTPAREN = ')';
	stack<double> numbers;
	stack<char> operations;
	double number;
	char symbol;
	while (ins && ins.peek() != '\n') {
		if (strchr("+-*/", ins.peek()) != NULL) {
			ins >> symbol;
			operations.push(symbol);
			
		}
		else if (isdigit(ins.peek())) {
			ins >> number;
			numbers.push(number);
			evaluatePreFix(numbers, operations);
		}
		
		else {
			ins.ignore();
		}

			
		
	}
	return numbers.top();
}





int main()
{
	double answer, prefixAnswer, postfixAnswer;
	// Fully parenthsized expression portion
	cout << "Type a fully parenthsized expression" << endl;
	answer = readAndEvaluate(cin);
	cout << "That evaluates to " << answer << endl;
	cin.ignore(10800, '\n');
	// post fix notation portion
	cout << "Type an expression that is in post fix notation: ";
	postfixAnswer = readAndEvaluatePostFix(cin);
	cout << "That evaluates to " << postfixAnswer << endl;
	cin.ignore(10800, '\n');
	// pre fix notation portion 
	cout << "Type an expression that is in the pre fix notation: ";
	prefixAnswer = readAndEvaluatePreFix(cin);
	cout << "That evaluates to " << prefixAnswer << endl;
	return 0;
}

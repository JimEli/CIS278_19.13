/*************************************************************************
* Title: Postfix Evaluator
* File: CIS278_Week15_19.13.cpp
* Author: James Eli
* Date: 1/19/2018
*
* Exercise 19.13 on page 836 – 837, Postfix Evaluation
* Write a program that evaluates a valid postfix expression such as
*   6 2 + 5 * 8 4 / -
* The program should read a postfix expression consisting of digits and
* operators into a string. Using modified versions of the stack functions
* implemented earlier in this chapter, the program should scan the
* expression and evaluate it. The algorithm is as follows:
*   1) While you have not reached the end of the string, read the
*   expression from left to right. If the current character is a digit,
*     Push its integer onto the stack (the integer value of a digit
*     character is its value in the computer’s character set minus the
*     value of ‘0’ in the computer’s character set).
*   Otherwise. If the current character is an operator,
*     Pop the two top elements off the stack into variables x and y,
*     Calculate y operator x.
*   Push the result of the calculation onto the stack.
*   2) When you reach the end of the string, pop the top value of the
*   stack. This is the result of the postfix expression.
*
* [Note: In step 2 above, if the operator is '/', the top of the stack
* is 2 and the next element in the stack is 8, then pop 2 into x, and
* pop 8 into y, evaluate 8 / 2 and push the result, 4 back onto the top
* of the stack. This note also applies to operator '-'.] The arithmetic
* operations allowed in an expression are
*    + addition
*    - subtraction
*    * multiplication
*    / division
*    ^ exponentiation
*    % remainder
*
* [Note: We assume left-to-right associativity for all operators for the
* purpose of this exercise.] The sack should be maintained with stack
* nodes that contain an int data member and a pointer to the next stack
* node. You may want to provide the following functional capabilities:
*   a) function evaluatePostfixExpression that evaluates the postfix
*      expression
*   b) function calculate that evaluates the expression op1 operator op2
*   c) function push that pushes a value onto the stack
*   d) function pop that pops a value off the stack
*   e) function isEmpty that determines if the stack is empty
*   f) function printStack that prints the stack
*
* Notes:
*  (1) Compiled with MS Visual Studio 2017 Community (v141).
*
* Submitted in partial fulfillment of the requirements of PCC CIS-278.
*************************************************************************
* Change Log:
*   01/19/2018: Initial release. JME
*************************************************************************/
#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <utility>

using namespace std;

// Valid expression operator characters.
const string VALID_OPERATORS = "+-*/^%";

// Trim trailing ws from string.
static void trim(string& s)
{
	const string ws = " \f\n\r\t\v";
	size_t p;

	s.erase(0, s.find_first_not_of(ws));

	if ((p = s.find_last_not_of(ws)) != string::npos)
		s.erase(p + 1);
}

// Pop and return item from stack.
int pop(stack<string> &stack)
{
	if (stack.empty())
		throw runtime_error("empty_stack");

	string token = stack.top();
	stack.pop();

	string::size_type pos = 0;
	return stoi(token, &pos);
}

// Push item onto stack.
void push(stack<string> &stack, string &token)
{
	string::size_type pos = 0;
	stoi(token, &pos);

	if (pos != token.length()) 
		throw runtime_error("invalid_chars");

	stack.push(token);
}

// Attempt to evaluate expression.
bool evalExpression(string &expression)
{
	stack<string> stack;
	stringstream ss(expression);
	string token;

	// Parse and evaluate expression.
	while (getline(ss, token, ' ')) {
		try
		{
			// Attempt to push token onto stack.
			if (token != "")
				push(stack, token);
		}
		catch (invalid_argument)
		{
			if (token.length() == 1 && token.find_first_not_of(VALID_OPERATORS))
			{
				// Evaluate operand.
				int op1 = pop(stack);
				int op2 = pop(stack);
				switch (token[0])
				{
				case '+':
					stack.push(to_string(op2 + op1));
					break;

				case '-':
					stack.push(to_string(op2 - op1));
					break;

				case '*':
					stack.push(to_string(op2 * op1));
					break;

				case '/':
					stack.push(to_string(op2 / op1));
					break;

				case '^':
					stack.push(to_string(/*************************************************************************
* Title: Postfix Evaluator
* File: CIS278_Week15_19.13.cpp
* Author: James Eli
* Date: 1/19/2018
*
* Exercise 19.13 on page 836 – 837, Postfix Evaluation
* Write a program that evaluates a valid postfix expression such as
*   6 2 + 5 * 8 4 / -
* The program should read a postfix expression consisting of digits and
* operators into a string. Using modified versions of the stack functions
* implemented earlier in this chapter, the program should scan the
* expression and evaluate it. The algorithm is as follows:
*   1) While you have not reached the end of the string, read the
*   expression from left to right. If the current character is a digit,
*     Push its integer onto the stack (the integer value of a digit
*     character is its value in the computer’s character set minus the
*     value of ‘0’ in the computer’s character set).
*   Otherwise. If the current character is an operator,
*     Pop the two top elements off the stack into variables x and y,
*     Calculate y operator x.
*   Push the result of the calculation onto the stack.
*   2) When you reach the end of the string, pop the top value of the
*   stack. This is the result of the postfix expression.
*
* [Note: In step 2 above, if the operator is '/', the top of the stack
* is 2 and the next element in the stack is 8, then pop 2 into x, and
* pop 8 into y, evaluate 8 / 2 and push the result, 4 back onto the top
* of the stack. This note also applies to operator '-'.] The arithmetic
* operations allowed in an expression are
*    + addition
*    - subtraction
*    * multiplication
*    / division
*    ^ exponentiation
*    % remainder
*
* [Note: We assume left-to-right associativity for all operators for the
* purpose of this exercise.] The sack should be maintained with stack
* nodes that contain an int data member and a pointer to the next stack
* node. You may want to provide the following functional capabilities:
*   a) function evaluatePostfixExpression that evaluates the postfix
*      expression
*   b) function calculate that evaluates the expression op1 operator op2
*   c) function push that pushes a value onto the stack
*   d) function pop that pops a value off the stack
*   e) function isEmpty that determines if the stack is empty
*   f) function printStack that prints the stack
*
* Notes:
*  (1) Compiled with MS Visual Studio 2017 Community (v141).
*
* Submitted in partial fulfillment of the requirements of PCC CIS-278.
*************************************************************************
* Change Log:
*   01/19/2018: Initial release. JME
*   03/20/2018: Corrected exponentiation operation. JME
*************************************************************************/
#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <utility>

using namespace std;

// Valid expression operator characters.
const string VALID_OPERATORS = "+-*/^%";

// Trim leading/trailing ws from string.
static void trim(string& s)
{
	const string ws = " \f\n\r\t\v";
	size_t p;

	s.erase(0, s.find_first_not_of(ws));

	if ((p = s.find_last_not_of(ws)) != string::npos)
		s.erase(p + 1);
}

// Pop and return item from stack.
int pop(stack<string> &stack)
{
	if (stack.empty())
		throw runtime_error("empty_stack");

	string token = stack.top();
	stack.pop();

	string::size_type pos = 0;
	return stoi(token, &pos);
}

// Push item onto stack.
void push(stack<string> &stack, string &token)
{
	string::size_type pos = 0;
	stoi(token, &pos);

	if (pos != token.length()) 
		throw runtime_error("invalid_chars");

	stack.push(token);
}

// Attempt to evaluate expression.
bool evalExpression(string &expression)
{
	stack<string> stack;
	stringstream ss(expression);
	string token;

	// Parse and evaluate expression.
	while (getline(ss, token, ' ')) {
		try
		{
			// Attempt to push token onto stack.
			if (token != "")
				push(stack, token);
		}
		catch (invalid_argument)
		{
			if (token.length() == 1 && token.find_first_not_of(VALID_OPERATORS))
			{
				// Evaluate operand.
				int op1 = pop(stack);
				int op2 = pop(stack);
				switch (token[0])
				{
				case '+':
					stack.push(to_string(op2 + op1));
					break;

				case '-':
					stack.push(to_string(op2 - op1));
					break;

				case '*':
					stack.push(to_string(op2 * op1));
					break;

				case '/':
					stack.push(to_string(op2 / op1));
					break;

				case '^':
					stack.push(to_string(pow(op2, op1)));
					break;

				case '%':
					stack.push(to_string(op2 % op1));
					break;

				default:
					break;
				}
			}
			else
				throw runtime_error("invalid_chars");
		}
	}

	if (stack.size() == 1) 
	{
		cout << "Result = " << pop(stack) << endl;
		return true;
	}

	return false;
}

int main() 
{
	string expression;

	// Program instructions.
	cout << "Postfix Expression Evaluator\n\nEnter an expression, separate"
		    " operands/operators with spaces, (i.e., \"6 2 + 5 * 8 4 / -\"): ";

	// Input expression.
	getline(cin, expression);
	// Trim leading/trailing whitespace.
	trim(expression);

	try
	{
		if (!evalExpression(expression))
			cout << "Could not evaluate your expression: \"" << expression << "\"" << endl;
	}
	catch (const runtime_error& e)
	{
		if (e.what() == "empty_stack")
			cout << "Prematurely reached end of evaluation stack, invalid expression.\n";
		else 
			cout << "Invalid characters found in expression.\n";
	}

	return 0;
}
op2 ^ op1));
					break;

				case '%':
					stack.push(to_string(op2 % op1));
					break;

				default:
					break;
				}
			}
			else
				throw runtime_error("invalid_chars");
		}
	}

	if (stack.size() == 1) {
		cout << "Result = " << pop(stack) << endl;
		return true;
	}

	return false;
}

int main() {
	string expression;

	// Program instructions.
	cout << "Postfix Expression Evaluator\n\nEnter an expression, separate"
		    " operands/operators with spaces, (i.e., \"6 2 + 5 * 8 4 / -\"): ";

	// Input expression.
	getline(cin, expression);
	// Trim leading/trailing whitespace.
	trim(expression);

	try
	{
		if (!evalExpression(expression))
			cout << "Could not evaluate your expression: \"" << expression << "\"" << endl;
	}
	catch (const runtime_error& e)
	{
		if (e.what() == "empty_stack")
			cout << "Prematurely reached end of evaluation stack, invalid expression.\n";
		else 
			cout << "Invalid characters found in expression.\n";
	}

	return 0;
}

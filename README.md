# Pima CC CIS278 Week #15
## Exercise 19.13 
### Postfix Expression Evaluator

Exercise 19.13 on page 836 – 837, C++ How to Program, 10/e, Deitel

Write a program that evaluates a valid postfix expression such as
```text
   6 2 + 5 * 8 4 / -
```
The program should read a postfix expression consisting of digits and operators into a string. Using modified versions of the stack functions implemented earlier in this chapter, the program should scan the expression and evaluate it. The algorithm is as follows:
```text
1) While you have not reached the end of the string, read the expression from left to right. 
   If the current character is a digit,
     Push its integer onto the stack (the integer value of a digit
     character is its value in the computer’s character set minus the
     value of ‘0’ in the computer’s character set).
  Otherwise. If the current character is an operator,
     Pop the two top elements off the stack into variables x and y,
     Calculate y operator x.
  Push the result of the calculation onto the stack.
2) When you reach the end of the string, pop the top value of the stack. 
   This is the result of the postfix expression.
```
[Note: In step 2 above, if the operator is '/', the top of the stack is 2 and the next element in the stack is 8, then pop 2 into x, and pop 8 into y, evaluate 8 / 2 and push the result, 4 back onto the top of the stack. This note also applies to operator '-'.] 

The arithmetic operations allowed in an expression are
```text
   + addition
   - subtraction
   * multiplication
   / division
   ^ exponentiation
   % remainder
```
[Note: We assume left-to-right associativity for all operators for the purpose of this exercise.] 

The sack should be maintained with stack nodes that contain an int data member and a pointer to the next stack node. You may want to provide the following functional capabilities:
```text
  a) function evaluatePostfixExpression that evaluates the postfix expression
  b) function calculate that evaluates the expression op1 operator op2
  c) function push that pushes a value onto the stack
  d) function pop that pops a value off the stack
  e) function isEmpty that determines if the stack is empty
  f) function printStack that prints the stack
```

Notes:
* Compiled with MS Visual Studio 2017 Community (v141).
* Submitted in partial fulfillment of the requirements of PCC CIS-278.

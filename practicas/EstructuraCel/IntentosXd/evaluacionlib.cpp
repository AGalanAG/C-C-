// FILE: calc.cxx
// Basic calculator program to evaluate a fully parenthesized arithmetic expression.
// The purpose is to illustrate a fundamental use of stacks.
#include <cctype> // Provides isdigit
#include <cstdlib> // Provides EXIT_SUCCESS
#include <cstring> // Provides strchr
#include <iostream> // Provides cout, cin, peek, ignore
#include <stack> // Provides the stack template class
using namespace std;
// PROTOTYPES for functions used by this demonstration program:
// Precondition: The next line of characters in the istream ins is a fully parenthesized
// expression formed from non-negative numbers and the four operations +, -, *, and /.
// Postcondition: A line has been read from the istream ins, and this line has been evaluated
// as an arithmetic expression. The value of the expression has been returned by the function.
// Precondition: The top of the operations stack contains +, -, *, or /, and the numbers stack
// contains at least two numbers.
// Postcondition: The top two numbers have been popped from the numbers stack, and the top
// operation has been popped from the operations stack. The two numbers have been
// combined using the operation (with the second number popped as the left operand). The
// result of the operation has then been pushed back onto the numbers stack.


double read_and_evaluate(istream& ins);
void evaluate_stack_tops(stack<double>& numbers, stack<char>& operations);


int main( )
{
double answer;
    cout << "Type a fully parenthesized arithmetic expression:" << endl;
    answer = read_and_evaluate(cin);
    cout << "That evaluates to " << answer << endl;
return EXIT_SUCCESS;
}
double read_and_evaluate(istream& ins)
// Library facilities used: cstring, iostream, stack
{
const char DECIMAL = '.';
const char RIGHT_PARENTHESIS = ')';
    stack<double> numbers;
    stack<char> operations; double number;
char symbol;
// Loop continues while istream is not “bad” (tested by ins) and next character isn’t newline.
while (ins && ins.peek( ) != '\n')
    {
if (isdigit(ins.peek( )) || (ins.peek( ) == DECIMAL))
        {
            ins >> number;
            numbers.push(number);
        }
else if (strchr("+-*/", ins.peek( )) != NULL)
        {
            ins >> symbol;
            operations.push(symbol);
        }
else if (ins.peek( ) == RIGHT_PARENTHESIS)
        {
ins.ignore( );
            evaluate_stack_tops(numbers, operations);
        }
else
ins.ignore( );
    }
return numbers.top( );
}

void evaluate_stack_tops(stack<double>& numbers, stack<char>& operations)
// Library facilities used: stack
{
double operand1, operand2;
    operand2 = numbers.top( );
numbers.pop( );
    operand1 = numbers.top( );
numbers.pop( );
switch (operations.top( ))
    {
case '+': numbers.push(operand1 + operand2); break;
case '-': numbers.push(operand1 - operand2); break;
case '*': numbers.push(operand1 * operand2); break;
case '/': numbers.push(operand1 / operand2); break;
    }
operations.pop( );
}

#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

bool is_balanced(char string& expression)
// Postcondition: A true return value indicates that the parentheses in the given expression
// are balanced. Otherwise the return value is false.
// Library facilities used: stack, string (and using namespace std)
{
// Meaningful names for constants
const char LEFT_PARENTHESIS = '('; const char RIGHT_PARENTHESIS = ')';
stack<char> store;
// Stack to store the left parentheses as they occur
string::size_type i; // An index into the string
char next;
bool failed = false;//
// The next character from the string
Becomes true if a needed parenthesis is not found
for (i = 0; !failed && (i < expression.length( )); ++i)
{
next = expression[i];
if (next == LEFT_PARENTHESIS)
store.push(next);
else if ((next == RIGHT_PARENTHESIS) && (!store.empty( )))
store.pop( ); // Pops the corresponding left parenthesis
else if ((next == RIGHT_PARENTHESIS) && (store.empty( ))) failed = true;
}
return (store.empty( ) && !failed);
}




int main(int argc, char *argv[]) {
	
	if(){
		
		
	}
	
	
	return 0;
}

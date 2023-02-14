// programa: pila01.cpp
// un simple ejemplo del uso de la plantilla stack

#include <cstdlib>
#include <iostream>
#include <stack>

using namespace std;

int main(int argc, char *argv[])
{
  stack<char> s;
  for (int i='A'; i <= 'Z'; i++)
    s.push(i);

  while (! s.empty() )
  {
    cout << s.top() << " " ;
    s.pop();
  }

  cout << endl;
  system("PAUSE");
  return EXIT_SUCCESS;
}

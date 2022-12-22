#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main() 
{
	cout << "Enter:" <<endl;
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
		if ((s[0] == ')') || (s[0] == '}') || (s[0] == ']')) 
		{
			cout << " !";
			break;
		}

	stack <char> stack;
	stack.push(s[0]); //adding elements
	int flag = 0;
	for (int i = 1; i < s.length(); i++)
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			stack.push(s[i]); //filling
		else if (stack.empty() && ((s[i] == ')') || (s[i] == ']') || (s[i] == '}'))) //checking for emptiness
		{
			flag = 1;
			break;
		}
		else if (!stack.empty() && (s[i] == ')') && (stack.top() == '(') || (s[i] == ']') && (stack.top() == '[') || (s[i] == '}') && (stack.top() == '{')) //checking for the emptiness of the top element
			stack.pop(); //delete top element
		else
			break;


	if (stack.empty() && flag == 0)
		cout << "Right" << endl;
	else
		cout << "Wrong" << endl;
}

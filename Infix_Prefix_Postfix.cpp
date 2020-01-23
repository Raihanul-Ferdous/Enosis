/// ALL OKAY.

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;
stack <char> stk;
string cns;
stack <string> stk2;

bool op(char x)
{
	if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^')
		return true;
	else
		return false;
}

int precidence(char x)
{
	if (x == '^')
		return 3;
	else if (x == '*' || x == '/')
		return 2;
	else
		return 1;
	return 0;
}

string infix_postfix(string infix)
{
	string postfix = "";
	infix = infix + ')';
	stk.push('(');
	for (int i = 0; i < infix.length(); i++)
	{

		if (stk.empty())
			break;
		if (infix[i] == ')')
		{
			while (stk.top() != '(')
			{
				postfix += stk.top();
				stk.pop();
			}
			stk.pop();
		}
		else if (infix[i] == '(')
		{
			stk.push(infix[i]);
		}
		else if (!op(infix[i]))
			postfix += infix[i];
		else
		{
			char x = stk.top();
			while (precidence(infix[i]) < precidence(x))
			{

				postfix += x;
				stk.pop();
				x = stk.top();
			}
			stk.push(infix[i]);
		}
	}
	return postfix;
}

string postfix_infix(string postfix)
{
	string infix = "";
	postfix += ')';
	int i = 0;
	while (postfix[i]!=')')
	{
		if (!op(postfix[i]))
		{
			cns = "";
			cns += postfix[i];
			stk2.push(cns);
		}
		else
		{
			string k1, k2;
			k2 = stk2.top();
			stk2.pop();
			k1 = stk2.top();
			stk2.pop();
			string k;
			k = "(" + k1 + postfix[i] + k2 + ")";
			stk2.push(k);
		}
		i++;
	}
	infix += stk2.top();
	string ainfix = "";
	for (int i = 1; i < infix.length() - 1; i++)
		ainfix += infix[i];
	return ainfix;
}

string infix_prefix(string infix)
{
	string prefix;
	reverse(infix.begin(), infix.end());
	for (int i = 0; i < infix.length(); i++)
	{
		if (infix[i] == '(')
		{
			infix[i] = ')';
			i++;
		}
		else if (infix[i] == ')')
		{
			infix[i] = '(';
			i++;
		}
	}
	prefix = infix_postfix(infix);
	reverse(prefix.begin(), prefix.end());
	return prefix;
}

int main()
{
	string infix,postfix,ainfix,prefix;
	cin >> infix;
	postfix = infix_postfix(infix);
	ainfix = postfix_infix(postfix);
	prefix = infix_prefix(infix);
	cout << endl << "Postfix: " << postfix << endl << "Infix: " << ainfix << endl
					 << "Prefix: " << prefix << endl;
	return 0;
}

///5*(6+2)-(8/4)
///(A+(B-C)^2)-(C+D/2)
///A+(B*C-(D/E^F)*G)*H

#include<iostream>
#include "Tools.h"
#include "Definitions.h"
#include "Lexer.h"
using namespace std;
using namespace Lexer;
int main ()
{
	Tools::Tuple<int*,int> A,B;
	//cout<<1.0+5;
	string D="hola mama como estas aprendi a volar";
	char a=' ';
	Lexer::DeleteSpace(D,a);
	//D.erase(4,6);
	cout<<D;
	return 0;
}


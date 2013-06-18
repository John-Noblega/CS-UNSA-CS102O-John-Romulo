#ifndef LEXER_H
#define LEXER_H
#include <string>
namespace Lexer 
{
	typedef std::string StreamLex;
	
	StreamLex DeleteSpace(StreamLex &,char);
}

#endif


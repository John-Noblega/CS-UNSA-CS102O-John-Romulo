#include "Lexer.h"
namespace Lexer
{
StreamLex DeleteSpace(StreamLex &Value,char elem)
{
	bool existElem=true;
	unsigned posElem=0;
	while(existElem)
	{
		posElem=Value.find(elem);
		if(posElem<Value.size())
			Value.erase(posElem,posElem+1);
		else
			existElem=false;
	}
	return Value;
}
}

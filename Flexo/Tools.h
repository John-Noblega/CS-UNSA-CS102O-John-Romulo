#ifndef TOOLS_H
#define TOOLS_H
#include <string>
typedef std::string StreamLex; 
namespace Tools
{
template<typename T,typename D> 
	class Tuple
	{
		private:
			T _firstValue;
			D _secondValue;
		public:
			Tuple()
			: _firstValue(0),_secondValue(0)
			{
			}
			Tuple(T NewFirstValue, D NewSecondValue)
			: _firstValue(NewFirstValue),_secondValue(NewSecondValue)
			{
			}
			inline T getFValue() const
			{
				return _firstValue;
			}
			inline D getSValue() const
			{
				return _secondValue;
			}
			inline void setFValue(T NewFirstValue, D NewSecondValue)
			{
				_firstValue=NewFirstValue;
				_secondValue=NewSecondValue;
			}
			inline bool operator ==(Tuple const& Expr)const
			{
				return _firstValue==Expr._firstValue&&_secondValue==Expr._secondValue;
			}
			
	};
	class Lexer
	{
		private:
			StreamLex _Val;
			
		public:
			Lexer();
			Lexer(StreamLex const &);
	};
}
#endif

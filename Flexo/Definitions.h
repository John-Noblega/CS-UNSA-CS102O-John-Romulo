#ifndef DEFINITIONS_H
#define DEFINITIONS_H
#include <string>
#include "Tools.h"
#include <vector>
namespace Definitions 
{
	class TokenInfo;
	typedef std::string T;//
	typedef char A;//asociatividad 
	typedef char TVS;//caracter que representa al Token
	typedef unsigned int TP;//precendencia del operador
	class Token
	{
		private:
			static std::vector<Tools::Tuple<TVS,TP> > Symbols;
			T t_Label;
			A t_Priority;
			TokenInfo * t_ptrinfo;
		public:
			Token()
				:t_Label(""),t_Priority(0)
			{
			}
			Token(T const & newLabel,A const & newPriority)
				:t_Label(newLabel),t_Priority(newPriority)
			{
			}
			
			inline T GetLabel()const
			{
				return t_Label;
			}
			
			inline A GetPriority()const
			{
				return t_Priority; 
			}
			bool operator ==(Token const& ); 
			
	};
	
	// ya fué evaluado?
	typedef bool Turn;	
	typedef bool Associativity;
	typedef double returnType;
	//izquierda es 0, derecha 1
	class TokenInfo
	{
		protected:
			Token * ti_Token;
			Turn ti_OnorOff;
			Associativity ti_LoR;
		public:
			TokenInfo()
				:ti_Token(0),ti_OnorOff(0),ti_LoR(0)
			{
			}
			TokenInfo(Token* & ptrToken,bool newOnorOff,bool newLoR)
				:ti_Token(ptrToken),ti_OnorOff(newOnorOff),ti_LoR(newLoR)
			{				
			}
			//virtual 
	};
};

#endif


#ifndef TOKEN_H
#define TOKEN_H
#include <string>
/**Define la etiqueta de un token como un string*/
typedef std::string L;
class TokenInfo;
namespace DFTS
{
    class Token
    {
        public:
            Token();
            virtual ~Token();
        protected:
            L mt_Label;
            TokenInfo *mt_ptrTI;
    };
}
#endif // TOKEN_H

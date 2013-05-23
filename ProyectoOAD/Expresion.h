#ifndef EXPRESION_H
#define EXPRESION_H

typedef float tValue;

class Expresion
{
    public:
        Expresion();
        virtual tValue eval()=0;
        virtual ~Expresion();
    protected:
    private:
};

#endif // EXPRESION_H

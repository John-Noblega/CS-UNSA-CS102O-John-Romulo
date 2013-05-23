#ifndef STACKTYPE_H
#define STACKTYPE_H


template<class E>
class StackType: public listDinamicType<E>{
public:
void initializeStack();
void destroyStack();
void push(const E& newItem);
E top();
void pop();
StackType(int );
StackType(StackType<E>& otherStack);
~StackType();
};
StackType::StackType()
{
    //ctor
}

StackType::~StackType()
{
    //dtor
}


#endif // STACKTYPE_H

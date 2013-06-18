#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <boost/tokenizer.hpp>
using namespace std;
using namespace boost;
typedef tuple<string,int> T;
typedef map<string,vector<int>> R;
bool Esta(const string &A,const string &B)
{
	std::size_t found;
	found=B.find(A);
	if (found!=std::string::npos)
		return 1;
	else
		return 0;
}
R Neighbours(vector<string>&symbols,const string& stream)
{
    string TempValue=stream;
    unsigned int tam=1;
    R Proximidad;
    for(register unsigned int i=0;i<symbols.size();++i)
    {
        bool ThereIs=Esta(symbols[i],stream);
        vector<int> Prox;
        while(ThereIs)
        {
            std::size_t found;
            found=stream.find(symbols[i]);
            Prox.push_back(found);
            cout<<stream.erase(found,tam);
            //ThereIs=Esta(symbols[i],stream);
        }
        sort(Prox.begin(),Prox.begin()+Prox.size());

    }
    return Proximidad;
}
vector<string> Tokenizer(const string &A,const vector<string> &symbols)
{
	string C=A;
	vector<string> R;
	while(C!="")
	{

	}
	return R;
}


int main(int, char**)
{
    string text = "token, test   string";

    char_separator<char> sep(", ");
    tokenizer<char_separator<char>> tokens(text, sep);
    for (const auto& t : tokens) {
        cout << t << "." << endl;
    }
}

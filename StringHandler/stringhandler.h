#ifndef STRINGHANDLER_H_
#define STRINGHANDLER_H_

#include <string>

using namespace std;

class StringHandler {
private:
    string m_text;
    int m_length;
public:
    StringHandler(string text, const int length);
    StringHandler();
    virtual ~StringHandler();
    string reverse();
    string printVowels();
    string isPalindrom();
    string returnASCII();
    string returnASCIISum();
    string signSearch(char wanted);
    void    setHandler();


};

#endif

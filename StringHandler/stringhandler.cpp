#include "StringHandler.h"
#include <string>
#include <iostream>


using namespace std;

StringHandler::StringHandler(string text, const int length)
    : m_text(text), m_length(length){

}

StringHandler::StringHandler(){

}

StringHandler::~StringHandler() {

}

/*
 *Inversion of the input string.
 */
string StringHandler::reverse(){

    string revString = "";
    for(int i = 0; i < m_length; ++i)
    {
        revString += m_text.at(m_length-1-i);
    }
    return revString;

}

/*
 * Checking if the input string is a palindrome
 */
string StringHandler::isPalindrom(){


        for(auto& i : m_text)
        {
            if(!isalpha(i))
            {

                return "Not enter a word! Try again";

            }
        }


    for(int i=0; i<m_length; ++i)
    {
        if(m_text.at(i) != m_text.at(m_length-1-i))
        {
            return "Is not a palindrome!";
        }
    }
    return "Is a palindrome!";
}

/*
 * Returning the ASCII values of the characters of the string.
 */
string StringHandler::returnASCII(){

    string text;
    for(int i=0; i<m_length; ++i)
    {
        text += to_string(static_cast<int>(m_text.at(i)))+", ";
    }
    text.erase(text.end()-2,text.end());
    return text;
}

/*
 * Returning the ASCII sum of the characters.
 */
string StringHandler::returnASCIISum(){

    int sum = 0;
    for(int i=0; i < m_length; ++i)
        {
            sum += static_cast<int>(m_text.at(i));
        }
    return to_string(sum);
}

/*
 * Returning the number of each vowel contained in the string.
 */
string StringHandler::printVowels(){

    int acount = 0, ecount = 0, icount = 0, ocount = 0, ucount = 0;

    for( int i=0; i < m_length; ++i)
    {
        switch(m_text.at(i)){
            case 'a':
                ++acount;
                break;
            case 'A':
                ++acount;
                break;
            case 'e':
                ++ecount;
                break;
            case 'E':
                ++ecount;
                break;
            case 'i':
                ++icount;
                break;
            case 'I':
                ++icount;
                break;
            case 'o':
                ++ocount;
                break;
            case 'O':
                ++ocount;
                break;
            case 'u':
                ++ucount;
                break;
            case 'U':
                ++ucount;
                break;
            }
    }
            return "A: "+ to_string(acount) + " - E: " + to_string(ecount) + " - I: " + to_string(icount)
                    + " - O: " + to_string(ocount) + " - U: " + to_string(ucount);


}

/*
 * Searching for a specific sign the user puts in.
 */
string StringHandler::signSearch(char c){

    int sum = 0;
    for(int i = 0; i < m_length; ++i)
    {
        if(m_text.at(i)==c)
        {
            ++sum;
        }
    }
    string s(1,c);
    return s +": "+to_string(sum);

}

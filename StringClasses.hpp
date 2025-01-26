#ifndef StringClasses_h
#define StringClasses_h

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

namespace strings
{
    
class String
{
    std::string s;
    public:
    String();

    String(const std::string& str);

    String(const char* str);
    
    std::string getstr() const;

};

class BlockString
{
    std::vector<String> v;
    public:
    BlockString (const std::vector<String>& a = {});

    BlockString (const String& s);

    std::vector<String> getvect() const;

    BlockString operator+ (const BlockString & a);

    String operator[] (int n);

    char operator() (int n);
};

BlockString operator+ (const BlockString & a, const String& s);
BlockString operator+ ( const String& s, const BlockString & a);

BlockString operator* (BlockString& bs, int n);
BlockString operator* (int n, BlockString& bs);
BlockString operator* (String& bs, int n);
BlockString operator* (int n, String& bs);

}
#endif


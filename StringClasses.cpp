#include "StringClasses.hpp"
using namespace strings;

    String::String() : s("\0") {}

    String::String(const std::string& str) : s(str) {}

    String::String(const char* str) : s(str) {}
    
    std::string String::getstr() const {return s;}

    BlockString::BlockString (const std::vector<String>& a) : v(a) { }

    BlockString::BlockString (const String& s) {v ={}; v.push_back(s.getstr());}

    std::vector<String> BlockString::getvect() const {return v;}

    BlockString BlockString::operator+ (const BlockString & a)
    {
        std::vector<String> vect = v;
        for (const String& x : a.v) vect.push_back(x.getstr());
        return BlockString(vect);
    }

    String BlockString::operator[] (int n) 
    {
        if (n >= v.size() || n < 0) 
        {
            std::cout << "ERROR!\n";
            return 0;
        }
        return v[n];
    }

    char BlockString::operator() (int n)
    {
        int i = 0;
        for (const String& s : v)
        {
            for (const char c : s.getstr())
            {
                if (i == n) return c;
                ++i;
            }
        }
        std::cout << "ERROR!\n";
        return '!';
    }

    BlockString strings::operator+ (const BlockString & a, const String& s)
    {
        std::vector<String> b = a.getvect();
        b.push_back(s);
        return BlockString(b);
    }

    BlockString strings::operator+ ( const String& s, const BlockString & a)
    {
        std::vector<String> b = a.getvect();
        b.insert(b.begin(), s);
        return BlockString(b);
    }

    BlockString strings::operator* (BlockString& bs, int n)
    {
        std::vector<String> multbs = bs.getvect();
        for (int i = 0; i < n-1; ++i)
        {
            for (const String& x : bs.getvect()) multbs.push_back(x.getstr());
        }
        return BlockString(multbs);
    }

    BlockString strings::operator* (int n, BlockString& bs)
    {
        return bs * n;
    }

    BlockString strings::operator* (String& bs, int n)
    {
        std::vector<String> multbs = {bs.getstr()};
        for (int i = 0; i < n-1; ++i) multbs.push_back(bs);
        return BlockString(multbs);
    }

    BlockString strings::operator* (int n, String& bs)
    {
        return bs * n;
    }
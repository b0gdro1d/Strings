#ifndef Ostream_h
#define Ostream_h

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "StringClasses.hpp"
#include "SampleClasses.hpp"

namespace strings
{
    enum Output { plain, array, other};
    class OStream
    {
        std::ostream& os;
        Output t = other;
        public:
        OStream(std::ostream& s);
        template <typename T> 
        OStream operator<<(const T& name)
        {
            os << name;
            return *this;
        }
        OStream& operator<<(Output outtype);
        OStream& operator<<(const String& s);
        OStream& operator<<(const BlockString& bs);
        OStream& operator<<(const BlockSample& bs);
    };

    inline OStream cout = std::cout;
}

#endif
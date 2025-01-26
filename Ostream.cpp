#include "Ostream.hpp"
using namespace strings;

OStream::OStream(std::ostream& s) : os(s) {}

OStream& OStream::operator<<(Output outtype)
{
    t = outtype;
    return *this;
}

OStream& OStream::operator<<(const String& s)
{
    os << s.getstr();
    return *this;
}

OStream& OStream::operator<<(const BlockString& bs)
{
    if (t == array)
    {
        os << "{";
        for (int i = 0; i < bs.getvect().size() - 1; ++i)
        {
            String x = bs.getvect()[i];
            os <<"\"" << x.getstr() <<"\",  ";
        }
        String x = bs.getvect()[bs.getvect().size() - 1];
        os <<"\"" << x.getstr() <<"\"}";
    }
    if (t == plain) 
    {
        for (const String& x : bs.getvect()) os << x.getstr();
    }
    return *this;
}

OStream& OStream::operator<<(const BlockSample& bs)
{
    if (t == array)
    {
        os << "{";
        for (int i = 0; i < bs.getsam().size(); ++i)
        {
            Sample x = bs.getsam()[i];
            os << " {";
            for (int j = 0; j < x.getsam().size() - 1; ++j) os << x.getsam()[j] << ", ";
            os << x.getsam()[x.getsam().size() - 1] << "} ";
        }
        os << "}";
    }
    if (t == plain) 
    {
        for (const Sample& x : bs.getsam()) 
        {
            for (int y: x.getsam()) os << y;
        }
    }
    return *this;
}
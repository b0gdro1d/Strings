#include "SampleClasses.hpp"
using namespace strings;

    Sample::Sample (const std::vector<int>&  a) : v(a) { }

    std::vector<int> Sample::getsam() const {return v;}

    void Sample::setter(int i, int val)
    {
        v[i] = val;
        return;
    }

    BlockSample Sample::operator()(const BlockSample& g)
    {
        std::vector<std::vector<int>> x = {{v}};
        BlockSample h (x);
        return h(g);
    }

    String Sample::operator() (const String& s)
    {
        std::string str = "";
        for (int i = 0; i < v.size(); ++i)
        {
            if (v[i] < 0 || v[i] >= s.getstr().length()) str += "?";
            else str += s.getstr()[v[i]];
        }
        return String(str);
    }

    String Sample::operator() (const BlockString& bs)
    {
        std::string str = "", res = "";
        int length = 0;
        for (const String& x : bs.getvect()) 
        {
            length += x.getstr().length();
            str += x.getstr();
        }
        for (int i = 0; i < v.size(); ++i)
        {
            if (v[i] < 0 || v[i] >= length) res += "?";
            else res += str[v[i]];
        }
        return String(res);
    }

    BlockSample Sample::operator+ (const BlockSample& a)
    {
        std::vector<Sample> vect = {v};
        for (Sample& x : a.getsam()) vect.push_back(x);
        return BlockSample(vect);
    }

    BlockSample::BlockSample (const std::vector<Sample>& a) : w(a) { }
    BlockSample::BlockSample (const Sample& a) {w ={}; w.push_back(a.getsam());}
    BlockSample::BlockSample (const std::vector<std::vector<int>>& a) 
    {
        w = {};
        for (std::vector<int> x : a ) w.push_back(x);
    }

    std::vector<Sample> BlockSample::getsam() const {return w;}

    BlockSample BlockSample::operator+ (const Sample& s)
    {
        std::vector<Sample> vect = w;
        vect.push_back(s);
        return BlockSample(vect);
    }

    BlockSample BlockSample::operator+ (const BlockSample& a)
    {
        std::vector<Sample> vect = w;
        vect.insert(vect.end(), a.w.begin(), a.w.end());
        return BlockSample(vect);
    }

    BlockSample BlockSample::operator* (int n)
    {
        std::vector<Sample> vect = w;
        for (int i = 0; i < n - 1; ++i) vect.insert(vect.end(), w.begin(), w.end());
        return BlockSample(vect);
    }

    Sample BlockSample::operator[] (int n)
    {
        if (n >= w.size() || n < 0) 
        {
            std::cout << "ERROR!\n";
            return {};
        }
        return w[n];
    }

    BlockString BlockSample::operator() (std::string s)
    {
        std::vector<String> res = {};
        for (Sample& x : w)
        {
            res.push_back(x(s));
        }
        return BlockString(res);
    } 

    BlockString BlockSample::operator() (const BlockString& bs)
    {
        std::vector<String> res = {};
        for (Sample& x : w)
        {
            res.push_back(x(bs));
        }
        return BlockString(res);
    }

    BlockSample BlockSample::operator() (const BlockSample& g)
    {
        std::vector<Sample>  h = w;
        std::vector<int> tmp ={};
        for (const Sample& x : g.w) for (int i : x.getsam()) tmp.push_back(i);
        for (int n = 0; n < h.size(); ++n)
        {
            for ( int m = 0; m < h[n].getsam().size(); ++m)
            {
                int i = h[n].getsam()[m];
                if (i >= tmp.size() || i < 0) h[n].setter(m, -1);
                else 
                {
                    h[n].setter(m, tmp[i]);
                }
            }
        }
        return BlockSample(h);
    }
    
BlockSample strings::operator* (int n, const BlockSample& a)
{
    BlockSample b(a);
    return b * n;
}

BlockSample strings::operator* (const Sample& a, int n)
{
    BlockSample vect(a);
    return vect * n;
}

BlockSample strings::operator* (int n, const Sample& a)
{
    return a * n;
}
#ifndef SampleClasses_h
#define SampleClasses_h

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "StringClasses.hpp"

namespace strings {

class BlockSample;

class Sample 
{
    std::vector<int> v;

    public:
    Sample (const std::vector<int>&  a = {});

    std::vector<int> getsam() const;

    void setter(int i, int val);

    String operator() (const String& s);

    String operator() (const BlockString& bs);

    BlockSample operator+ (const BlockSample& a);
    BlockSample operator()(const BlockSample& g);
    
};

class BlockSample
{
    std::vector<Sample> w;

    public:
    BlockSample (const std::vector<Sample>& a = {});
    BlockSample (const Sample& a);
    BlockSample (const std::vector<std::vector<int>>& a);

    std::vector<Sample> getsam() const;

    BlockSample operator+ (const Sample& s);

    BlockSample operator+ (const BlockSample& a);

    BlockSample operator* (int n);

    Sample operator[] (int n);

    BlockString operator() (std::string s);

    BlockString operator() (const BlockString& bs);

    BlockSample operator() (const BlockSample& g);
    
};

BlockSample operator* (int n, const BlockSample& a);

BlockSample operator* (const Sample& a, int n);

BlockSample operator* (int n, const Sample& a);

}

#endif
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "StringClasses.hpp"
#include "SampleClasses.hpp"
#include "Ostream.hpp"

int main()
{
    std::string s = "abc";
    strings::String a , b = "a" , c = s;
    strings::BlockString bstr = a + b * 1 + 2 * c ;
    strings::cout << strings::array << bstr << '\n';
    strings::cout << strings::plain << bstr << '\n'; // Prints aabcabc
    strings::cout << bstr (3) << ' ' << bstr [3] << '\n'; // c abc
    std::ofstream fil ("a .txt");
    strings::OStream fout (fil);
    fout << strings::plain << bstr << '\n'; // Prints aabcabc to file a . txt
    fil.close(); // Closes file a . txt
    std::vector<std::vector<int>> v = {{4 , 3 , 2 , 1 , 0} , {3 , 5 , 10} , {0}};
    strings::BlockSample f(v);
    strings::cout << strings::array << f(bstr) << '\n'; // {" acbaa " , " cb ?" , " a "}
    strings::cout << strings :: plain << f (bstr) << '\n'; // acbaacb ? a
    v = {{1 , 2 , 1} , {4 , 5, 5}};
    strings::BlockSample g ( v );
    strings::cout << strings :: array << g (bstr) << '\n'; // {" aba " , " abb "}
    strings::cout << strings :: plain << g (bstr) << '\n'; // abaabb
    strings::BlockSample fg = f (g); // fg = {{5 , 4, 1 , 2 , 1} , {4 , 5 , -1} , {1}}
    strings::cout << strings::array << f << '\n' << g << '\n' << fg << '\n';
    strings::cout << strings::array << fg (bstr) << '\n';
    strings::cout << strings :: plain << fg (bstr) << '\n'; // baabaab ? a
    strings::Sample shift_left(std::vector<int>({1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 0}));
    strings::BlockSample h = shift_left (fg);
    strings::cout << strings::array << h (c) << '\n'; // {"? bcb ??? b ?"}
    strings::cout << strings::plain << h (c) << '\n'; // ? bcb ??? b ?
    shift_left = std::vector <int>({1 , 2 , 0});
    strings::Sample shift_right ( std :: vector < int >({2 , 0 , 1}));
    f = shift_left * 1 + 2 * shift_right;
    strings::cout << strings::array << f (s) << '\n'; // {" bca " , " cab " , " cab "}
    strings::cout << strings::plain << f (s) << '\n'; // bcacabcab
    a = "b";
    bstr = (shift_right + shift_left(shift_right))(a + b * 2);
    strings::cout << strings::array << bstr << '\n'; // {" aba " , " baa "}
    strings::cout << strings::plain << bstr << '\n'; // ababaa
    return 0;
}
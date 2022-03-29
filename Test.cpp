
/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Kirill Perevalov>
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "mat.hpp"
#include "doctest.h"
#include <string>
#include <algorithm>
#include <stdexcept>
using namespace std;
using namespace ariel;


/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) { //mohek spaces eridat shurat ve tab
	 input.erase(remove(input.begin(),input.end(),' '),input.end()); //mohek be tvah
	 input.erase(remove(input.begin(),input.end(),'\t'),input.end()); 
	 input.erase(remove(input.begin(),input.end(),'\r'),input.end()); 
	 input.erase(remove(input.begin(),input.end(),'\n'),input.end());
    return input;
}
TEST_CASE("Good input")
{
    //1
    CHECK(nospaces(mat(11, 7, '@', '-')) == nospaces("@@@@@@@@@@@\n@---------@\n@-@@@@@@@-@\n@-@-----@-@\n@-@@@@@@@-@\n@---------@\n@@@@@@@@@@@"));
    //2
    CHECK(nospaces(mat(13, 11, '@', '-')) == nospaces("@@@@@@@@@@@@@\n@-----------@\n@-@@@@@@@@@-@\n@-@-------@-@\n@-@-@@@@@-@-@\n@-@-@---@-@-@\n@-@-@@@@@-@-@\n@-@-------@-@\n@-@@@@@@@@@-@\n@-----------@\n@@@@@@@@@@@@@"));
    //3
    CHECK(nospaces(mat(13, 9, '@', '-')) == nospaces("@@@@@@@@@@@@@\n@-----------@\n@-@@@@@@@@@-@\n@-@-------@-@\n@-@-@@@@@-@-@\n@-@-------@-@\n@-@@@@@@@@@-@\n@-----------@\n@@@@@@@@@@@@@"));
    //4
    CHECK(nospaces(mat(5, 3, '@', '-')) == nospaces("@@@@@\n@---@\n@@@@@")); 
    //5
    CHECK(nospaces(mat(7, 3, '@', '-')) == nospaces("@@@@@@@\n@-----@\n@@@@@@@"));
    //6
    CHECK(nospaces(mat(3, 5, '@', '-')) == nospaces("@@@\n@-@\n@-@\n@-@\n@@@"));
    //7
    CHECK(nospaces(mat(3, 1, '$', '+')) == nospaces("$$$"));
    //8
    CHECK(nospaces(mat(5, 1, '$', ';')) == nospaces("$$$$$"));
    //9
    CHECK(nospaces(mat(7, 1, '#', '@')) == nospaces("#######"));
    //10
    CHECK(nospaces(mat(9, 1, '(', '-')) == nospaces("((((((((("));
    
                                                
                                                 
                                                           
 

}
TEST_CASE("Bad input")
{
    //1
    CHECK_THROWS(mat(0, 0, '@', '-'));
    //2
    CHECK_THROWS(mat(0, 7, '@', '-'));
    //3
    CHECK_THROWS(mat(9, 0, '@', '-'));
    //4
    CHECK_THROWS(mat(-7, 7, '@', '-'));
    //5
    CHECK_THROWS(mat(7, -1, '@', '-'));
    //6
    CHECK_THROWS(mat(-9, -7, '@', '-'));
    //7
    CHECK_THROWS(mat(2, 2, '@', '-'));
    //8
    CHECK_THROWS(mat(4, 7, '@', '-'));
    //9
    CHECK_THROWS(mat(7, 4, '@', '-'));
    //10
    CHECK_THROWS(mat(4, 3, '@', '@'));
    
 
}
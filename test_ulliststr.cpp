#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite
using namespace std;

int main(int argc, char* argv[])
{
    ULListStr* dat = new ULListStr();
    ULListStr* dat2 = new ULListStr();
    // ^test edge cases (when list goes past to ensure it is being allocated properly)
    //ULListStr* empty = new ULListStr();
    // ^test when empty for expected errors
    //ULListStr* easy = new ULListStr();
    // ^simple test runs how it should
    //easy->push_back("x");
    //easy->push_front("y");
    //easy->push_back("z");
    dat2->push_front("a");
    dat2->push_back("b");
    dat->push_back("y");
    dat->push_front("x");
    cout << dat2->front() << " " << dat2->back() << endl;
    cout << dat->front() << " " << dat->back() << endl;
    //cout << easy->get(0) << " " << easy->get(1) << " " << easy->get(2) << endl;
    //cout << easy->size() << endl;
    //easy->pop_back();
    //cout <<  easy->back() << endl;
    //easy->pop_front();
    //cout << easy->front() << endl;
    //easy->pop_front();
    //cout << easy->size() << endl;
    //easy->push_back("x");
    //easy->pop_back();
    //cout << easy->size() << endl;
    //cout << empty->size() << endl;
    //cout << dat->get(32) << endl;
    //cout << empty->back() << endl;
    //cout << empty->front() << endl;
    //empty->pop_back();
    //empty->pop_front();
    return 0;
}

#ifndef binary_hpp
#define binary_hpp
#include <iostream>
#include <cmath>
#include <cstring>


using namespace std;
const int SIZE = 8;

class Digit{

private:

    int dec;
    int bin[SIZE];

public:

    int binToDec(int *binBuf);
    pair<int, int*> binSum (Digit *a);
    int *getReverse (int *toReverse);
    pair<int, int*> binSubstr (Digit *a);
    pair<int, int*> binMultip(Digit *a);
    void printResult ();
    void printValues ();
    int getDec ();

    Digit(int number);
    Digit(pair<int, int*> result);
    ~Digit();

};

int Digit::getDec (){
    return this->dec;
}
 int Digit::binToDec(int *binBuf){

     int decBuf = 0;
     int pointer = 0;
     for(int i = SIZE-1; i > 0; --i, pointer++)
         if (binBuf[i] == 1)
             decBuf += pow(2,pointer);

     if (binBuf[0]==1) decBuf =-decBuf;
     return decBuf;

 }


#endif /* binary_hpp */


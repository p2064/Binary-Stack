#include "binary_hpp"


 pair<int, int*> Digit::binSum (Digit *a){

     int *pointerToArr1 = nullptr;
     int *pointerToArr2 = nullptr;
     int binBuf[SIZE];
     int decBuf;

     if (((this->dec + a->dec) > pow(2,SIZE-1)-1) || -(this->dec + a->dec) < -pow(2,SIZE-1) || (this->dec + a->dec) < -pow(2,SIZE-1)) throw runtime_error("Invalid values in calculation");
     this->dec < 0 ? pointerToArr1 = getReverse(this->bin) : pointerToArr1 = this->bin;
     a->dec < 0 ? pointerToArr2 = getReverse(a->bin) : pointerToArr2 = a->bin;

     int carry = 0;
     for(int i = SIZE-1; i >= 0 ; --i)
     {
         binBuf[i] = ((pointerToArr2[i] ^ pointerToArr1[i]) ^ carry);
         carry = ((pointerToArr2[i] & pointerToArr1[i]) | (pointerToArr2[i] & carry)) | (pointerToArr1[i] & carry);
     }

     pair<int, int[SIZE]> result;
     memset(result.second, 0 , 4*SIZE);
     if (binBuf[0] == 1 && this->dec + a->dec == -pow(2, SIZE-1))
     {
         decBuf = -pow(2, SIZE-1);
         result.first = decBuf;
         memcpy(result.second, binBuf, 4*SIZE);

         return result;
     }

     memcpy(result.second, binBuf, 4*SIZE);
     if (binBuf[0] == 1) getReverse(binBuf);
     decBuf = binToDec(binBuf);
     result.first = decBuf;

     return result;
 }



 int* Digit::getReverse (int *toReverse){

     int binOne[SIZE];
     memset(binOne, 0, 4*SIZE);
     binOne[SIZE-1] = 1;
     int buffer[SIZE];

     for(int i = 1; i <=SIZE-1 ; ++i)
         buffer[i] = toReverse[i]==1 ? 0 : 1;

     int c = 0;
     for(int i = SIZE-1; i > 0 ; --i)
     {
         toReverse[i] = ((buffer[i]^ binOne[i]) ^ c);
         c = ((buffer[i] & binOne[i]) | (buffer[i]& c)) | (binOne[i] & c);
     }

     return toReverse;
 }


pair<int, int*> Digit::binSubstr (Digit *a){

    if (a->dec > 0)
        a->bin[0]=1;
    else
        a->bin[0]=0;

      if ((this->dec - a->dec) < -pow(2,SIZE-1)) throw runtime_error("Invalid values in calculation");
    a->dec = (-a->dec);

    return this->binSum(a);
}


 pair<int, int*> Digit::binMultip(Digit *a){

     int decBuf;
     int binBuf[SIZE];
     memset(binBuf, 0, 4*SIZE);
     pair<int, int[SIZE]> result;

     if (abs(a->dec)==1)
     {
         memcpy(result.second, this->bin, 4*SIZE);
         result.second[0] = this->bin[0] ^ a->bin[0];
         result.first =  this->binToDec(result.second);

         return result;
     }

     int *pointerToArr = nullptr;

     if (((this->dec * a->dec) > pow(2,SIZE-1)-1) || -(this->dec * a->dec) < -pow(2,SIZE-1) || (this->dec * a->dec) < -pow(2,SIZE-1)) throw runtime_error("Invalid values in calculation");;
     this->dec < 0 ? pointerToArr = getReverse(bin) : pointerToArr = this->bin;

     int buffer[SIZE];
     memset(buffer, 0, 4*SIZE);
     int multipCount = abs(a->dec);

     for(int i = SIZE-1; i >= 0 ; --i)
         buffer[i] = pointerToArr[i];

     for (int i = 1; i<=multipCount-1; i++)
     {
         int carry = 0;
         for(int i = SIZE-1; i >= 0 ; --i)
         {
             binBuf[i] = ((buffer[i] ^ pointerToArr[i])  ^ carry);
             carry = ((buffer[i] & pointerToArr[i]) | (buffer[i]  & carry) | (pointerToArr[i] & carry));
             buffer[i] = binBuf[i];
         }
     }

     memcpy(result.second, binBuf, 4*SIZE);
     if (result.second[0] == 1 && this->dec * a->dec == -pow(2, SIZE-1))
     {
         decBuf = -pow(2, SIZE-1);
         result.first = decBuf;
         return result;
     }

     else if ((this->bin[0] ==1 && a->bin[0]==0))
     {
         this->getReverse(result.second);
         result.second[0]=1;
     }

     else if (this->bin[0] == 0 && a->bin[0] == 1) result.second[0]=1;
     else if (this->bin[0] == 1 && a->bin[0] == 1)
     {
         result.second[0] = 0;
         this->getReverse(result.second);
     }

     decBuf = binToDec(result.second);
     result.first = decBuf;
     if (result.second[0] == 1) getReverse(result.second);

     return result;
 }

 void Digit::printResult (){

     cout<<"Bin Result: ";
     for (auto i : this->bin) cout<<i;
     cout<<endl;
     cout<<"Dec Result: "<<this->dec;
     cout<<endl;

 }

 void Digit::printValues (){

     cout<<"Bin: ";
     for (auto i : this->bin) cout<<i;
     cout<<endl;
     cout<<"Dec: "<<this->dec<<endl;

 }

 Digit::Digit(int number){

     this->dec = number;
     int absNumber = abs(number);

     int pointer = 0;
     for (int i=SIZE-1; i>=0; i--,pointer++)
         this->bin[pointer] = (absNumber>>i)&1;

     if (number < 0) this->bin[0] = 1;

 }

 Digit::Digit(pair<int, int*> result){

     this->dec = result.first;
     for(int i = 0; i <= SIZE-1; ++i, result.second++)
         this->bin[i] = *result.second;

     if (result.first < 0) this->bin[0] = 1;

 }

Digit::~Digit(){}

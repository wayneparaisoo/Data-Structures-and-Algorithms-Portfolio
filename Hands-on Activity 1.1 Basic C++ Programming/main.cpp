#include <iostream>

int fNum = 10;
int sNum = 11;

void sumOfTwo(int fNum, int sNum);
void greaterNum(int fNum, int sNum);
void logicOper(bool fBool, bool sBool);

int main(){
    sumOfTwo(fNum,sNum);
    greaterNum(fNum,sNum);
    logicOper(true, true);
}

void sumOfTwo(int fNum, int sNum){
    std::cout<<"The sum of the two numbers is: "<<fNum+sNum<< std::endl;
}

void greaterNum(int fNum, int sNum){
    if (fNum > sNum){
        std::cout<<fNum<<" is greater than "<< sNum<<std::endl;
    }
    else {
        std::cout <<fNum<<" is less than "<<sNum<<std::endl;
    }
}

void logicOper(bool fBool, bool sBool){
     if (fBool && sBool) {
        std::cout<<"AND: TRUE"<<std::endl;
    }
    else{
        std::cout<<"AND: FALSE"<<std::endl;
    }

    if (fBool || sBool) {
        std::cout<<"OR: TRUE"<<std::endl;
    }
    else{
        std::cout<<"OR: TRUE"<<std::endl;
    }

    
    if (!(fBool && sBool)) {
        std::cout<<"NOT: TRUE"<<std::endl;
    }
    else{
        std::cout<<"NOT: FALSE"<<std::endl;
    }
}
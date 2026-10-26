#include <iostream>
#include <queue>

void display(std::queue<char> copyQ);

int main(){
    std::queue<char> myQ;

    myQ.push('W');
    myQ.push('A');
    myQ.push('Y');
    myQ.push('N');
    myQ.push('E');
    display(myQ);

    //empty
    std::cout << "Is the queue empty?: " << myQ.empty()<< std::endl;

    //size
    std::cout << "The length of the queue is: " << myQ.size()<< std::endl;

    //front
    std::cout << "The front of the queue is: " << myQ.front()<< std::endl;

    //back
    std::cout<< "The back of the queue is: " << myQ.back()<< std::endl;

    //pop
    std::cout << "Popping the front"<< std::endl;
    myQ.pop();
    display(myQ);

    //push
    std::cout << "Pushing to the back" << std::endl;
    myQ.push('A');
    display(myQ);
    return 0;
}

void display(std::queue<char> copyQ){
    std::queue<char> c = copyQ;
    while(!c.empty()){
        std::cout<<" "<<c.front();
        c.pop();
    }
    std::cout<<std::endl;
}
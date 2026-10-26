#include <iostream>
#include "queueLL.h"

int main(){
    qNode<char>* front = nullptr;
    qNode<char>* back = nullptr;

    enqueue('W', &front, &back);
    std::cout<< front->data <<" "<< back->data<< std::endl;

    enqueue('A', &front, &back);
    std::cout<< front->data <<" "<< back->data<< std::endl;

    enqueue('Y', &front, &back);
    std::cout<< front->data <<" "<< back->data<< std::endl;

    enqueue('N', &front, &back);
    std::cout<< front->data <<" "<< back->data<< std::endl;

    enqueue('E', &front, &back);
    std::cout<< front->data <<" "<< back->data<< std::endl;

   checkFront(front);
   checkBack(back);
   display(front);


   dequeue(&front, &back);
   display(front);
   checkFront(front);
   checkBack(back);


    return 0;
}
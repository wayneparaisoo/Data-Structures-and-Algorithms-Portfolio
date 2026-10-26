#include <iostream>
#include "queueSupp.h"

int main(){
    Printer myPrinter;

    std::cout << "Adding jobs to the queue:" << std::endl;
    myPrinter.addJob(Job(424556, "James Mahoraga", 8));
    myPrinter.addJob(Job(492387, "Alliesha Paraiso", 19));

    std::cout<<std::endl;
    std::cout <<"Processing jobs in the queue:" << std::endl;
    myPrinter.processJob();

    std::cout<<std::endl;
    std::cout <<"Adding more jobs to the queue:" << std::endl;
    myPrinter.addJob(Job(978497, "Peter Parker", 14));
    myPrinter.addJob(Job(897429, "Maynerd Parker", 18));

    std::cout<<std::endl;
    std::cout <<"Processing remaining jobs in the queue:" << std::endl;
    myPrinter.processAllJobs();

    std::cout<<std::endl;
    std::cout <<"Processing remaining jobs in the queue:" << std::endl;
    myPrinter.processAllJobs();

    return 0;
}
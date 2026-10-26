#ifndef QUEUESUPP_H
#define QUEUESUPP_H

#include <iostream>
#include <string>

class Job{
    public:
        int jobID, pages;
        std::string name;

        Job(){
            jobID = 0;
            name = "";
            pages = 0;
        }
        Job(int i, std::string n, int p){
            jobID = i;
            name = n;
            pages = p;
        }
};


template<typename T>
class qNode{
    public:
        T data;
        qNode<T>* next;
};

template <typename T>
qNode<T>* new_node(T newData){
    qNode<T>* newNode = new qNode<T>;
    newNode->data = newData;
    newNode->next = nullptr;
    return newNode;
}

template<typename T>
void enqueue(T newData, qNode<T>** frontPtr, qNode<T>** backPtr){
    qNode<T>* newNode = new_node(newData);

    if((*frontPtr) == nullptr && (*backPtr)==nullptr){
        (*frontPtr) = newNode;
        (*backPtr) = newNode;
    }

    (*backPtr)->next = newNode;
    (*backPtr) = newNode; 
}

template<typename T>
void dequeue(qNode<T>** frontPtr, qNode<T>** backPtr){
    qNode<T>* deleteNode = nullptr;
    deleteNode = (*frontPtr);

    if((*frontPtr)->next == nullptr && (*backPtr)->next == nullptr){
        (*frontPtr) = nullptr;
        (*backPtr) = nullptr;
        delete deleteNode;
        return;
    }

    (*frontPtr) = (*frontPtr)->next;
    deleteNode->next = nullptr;
    delete deleteNode;

}

template <typename T>
bool isEmpty(qNode<T>** frontPtr){
    return (*frontPtr) == nullptr;
}

class Printer{
    private:
        qNode<Job>* front;
        qNode<Job>* back;
    
    public:
        Printer(){
        front = nullptr;
        back = nullptr;
    }

        void addJob(Job newJob){
        enqueue(newJob, &front, &back);
        std::cout << "Job added to the queue: " << newJob.name << std::endl;
        std::cout << "Job ID: " << newJob.jobID << std::endl;
        std::cout << "Pages: " << newJob.pages << std::endl;
    }

    void processJob(){
        if(isEmpty(&front)){
            std::cout << "No jobs in the queue to process." << std::endl;
            return;
        }
        Job jobToProcess = front->data;
        std::cout << "Processing job: " << jobToProcess.name << std::endl;
        std::cout << "Job ID: " << jobToProcess.jobID << std::endl;
        std::cout << "Pages: " << jobToProcess.pages << std::endl;
        dequeue(&front, &back);
    }

    void processAllJobs(){
        if(isEmpty(&front)){
            std::cout << "No jobs in the queue to process." << std::endl;
            return;
        }
        while(!isEmpty(&front)){
            processJob();
        }
    }
};



#endif
#include <iostream>
#include <string>

class Fruit{
    private:
        std::string fruitName;
        int fruitPrice;
        int fruitQuantity;

    public:
        Fruit(std::string newName, int newPrice=0, int newQuantity=0){
                fruitName = std::move(newName);
                fruitPrice = newPrice;
                fruitQuantity = newQuantity;

                std::cout << "Constructor Called." << std::endl;
        }

        ~Fruit(){
            std::cout << "Destructor Called." << std::endl;
        }

        Fruit(const Fruit &copyFruit){
            std::cout << "Copy Constructor Called" << std::endl;
            fruitName = copyFruit.fruitName;
            fruitPrice = copyFruit.fruitPrice;
            fruitQuantity = copyFruit.fruitQuantity;
        }

        Fruit& operator=(const Fruit& other){
            std::cout << "Copy Assignment Operator Called" << std::endl;

            if (this == &other)   // self-assignment check
                return *this;

            fruitName = other.fruitName;
            fruitPrice = other.fruitPrice;
            fruitQuantity = other.fruitQuantity;

            return *this;
        }

        std::string GetName() const { return fruitName; }
        int GetPrice() const { return fruitPrice; }
        int GetQuantity() const { return fruitQuantity; }

        int CalculateSum() const {
            return fruitPrice * fruitQuantity;
        }

        void Display(){
            std::cout << "Name: " << fruitName 
                        << ", Price: " << fruitPrice 
                        << ", Quantity: " << fruitQuantity 
                        << ", Subtotal: " << CalculateSum() << std::endl;
        }
        
    };

class Vegetable{
    private:
        std::string vegName;
        int vegPrice;
        int vegQuantity;
 
    public:
        Vegetable(std::string newName ="", int newPrice=0, int newQuantity=0){
                vegName = std::move(newName);
                vegPrice = newPrice;
                vegQuantity = newQuantity;
                std::cout << "Constructor Called." << std::endl;
        }

        ~Vegetable(){
            std::cout << "Destructor Called." << std::endl;
        }

        Vegetable(const Vegetable &copyVeg){
            std::cout << "Copy Constructor Called" << std::endl;
            vegName = copyVeg.vegName;
            vegPrice = copyVeg.vegPrice;
            vegQuantity = copyVeg.vegQuantity;
        }

        Vegetable& operator=(const Vegetable& other){
            std::cout << "Copy Assignment Operator Called" << std::endl;

            if (this == &other)   // self-assignment check
                return *this;

            vegName = other.vegName;
            vegPrice = other.vegPrice;
            vegQuantity = other.vegQuantity;

            return *this;
        }

        std::string GetName() const { return vegName; }
        int GetPrice() const { return vegPrice; }
        int GetQuantity() const { return vegQuantity; }

        int CalculateSum(){
            return vegPrice * vegQuantity;
        }

        void Display(){
            std::cout << "Name: " << vegName << ", Price: " << vegPrice 
                        << ", Quantity: " << vegQuantity 
                        << ", Subtotal: " << CalculateSum() << std::endl;
        }
};

int main(){

    const int fruitCount = 2;
    int vegCount = 2;

    
    Fruit** fruits = new Fruit*[fruitCount];
    fruits[0] = new Fruit("Apple", 10, 7);
    fruits[1] = new Fruit("Banana", 5, 8);

    Vegetable** vegetables = new Vegetable*[vegCount];
    vegetables[0] = new Vegetable("Broccoli", 15, 12);
    vegetables[1] = new Vegetable("Lettuce", 8, 10);

  
    std::cout << "\n--- Fruits ---\n";
        for (int i = 0; i < fruitCount; i++){
            fruits[i]->Display();
        }

    std::cout << "\n--- Vegetables ---\n";
        for (int i = 0; i < vegCount; i++){
            vegetables[i]->Display();
        }
  
    int total = 0;
    for (int i = 0; i < fruitCount; i++) total += fruits[i]->CalculateSum();
    for (int i = 0; i < vegCount; i++) total += vegetables[i]->CalculateSum();
    std::cout << "\nGrand Total: " << total << std::endl;


    for (int i = 0; i < vegCount; i++){
        if (vegetables[i]->GetName() == "Lettuce"){
            delete vegetables[i];          
           
            for (int j = i; j < vegCount - 1; j++)
                vegetables[j] = vegetables[j+1];
            vegCount--; 
            break;
        }
    }

}
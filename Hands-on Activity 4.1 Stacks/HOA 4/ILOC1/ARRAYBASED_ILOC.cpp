#include <iostream>
#include <string>

const int maxCap = 100;
char stack[maxCap];
int top = -1;

bool isEmpty() {
    return top == -1;
}

void push(char symbol) {
    top++;
    stack[top] = symbol;
}

char pop() {
    char symbol = stack[top];
    top--;
    return symbol;
}

bool isMatch(char opening, char closing) {
    if (opening == '(' && closing == ')') return true;
    if (opening == '{' && closing == '}') return true;
    if (opening == '[' && closing == ']') return true;
    return false;
}

int main() {
    std::string expression;
    std::cout << "Enter Expression: ";
    std::cin >> expression;

    bool balanced = true;

    for (size_t i = 0; i < expression.length(); i++) {
        char ch = expression[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty()) {
                balanced = false;
                break;
            }
            char opening = pop();
            if (!isMatch(opening, ch)) {
                balanced = false;
                break;
            }
        }
    }

    if (!isEmpty()) {
        balanced = false;
    }

    if (balanced) {
        std::cout << "Balanced" << std::endl;
    } else {
        std::cout << "Unbalanced" << std::endl;
    }

    return 0;
}
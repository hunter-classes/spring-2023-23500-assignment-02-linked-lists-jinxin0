#include <ios>
#include <iostream>
#include "List.h"

int main()
{
    List *l = new List();
    std::cout << l->toString() << " " << l->length() << "\n";
    l->insert(0,"a");
    std::cout << l->toString() << " " << l->length() << "\n";
    l->insert(0,"b");
    l->insert(0,"c");
    l->insert(0,"d");
    try {
        l->insert(10,"x");
    } catch (std::exception e){
        std::cout << "Insert x didn't work\n";
    }
    std::cout << l->toString() << "\n";
    l->insert(2,"inserted at 2");
    std::cout << l->toString() << "\n";
    l->insert(5,"inserted at end");
    std::cout << l->toString() << " " << l->length() << "\n";
    
    std::cout << l->get(2) << '\n';
    std::cout << std::boolalpha << l->contains("b") << '\n';
    l->remove(3);
    std::cout << std::boolalpha << l->contains("b") << '\n';
    std::cout << l->toString() << " " << l->length() << "\n";

    return 0;
}


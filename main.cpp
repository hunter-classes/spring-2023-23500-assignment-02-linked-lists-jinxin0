#include <ios>
#include <iostream>
#include "List.h"
#include "OList.h"

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
    
    std::cout << std::boolalpha << l->contains("b") << '\n';
    std::cout << l->get(2) << '\n';
    l->remove(3);
    std::cout << std::boolalpha << l->contains("b") << '\n';
    std::cout << l->toString() << " " << l->length() << "\n";

    delete l;
    std::cout << "-----------------------------\n";

    OList *o = new OList();
    std::cout << o->toString() << " " << o->length() << "\n";
    o->insert("a");
    std::cout << o->toString() << " " << o->length() << "\n";
    o->insert("b");
    o->insert("c");
    o->insert("d");
    std::cout << o->toString() << "\n";
    o->insert("b");
    o->insert("k");
    o->insert("0");
    std::cout << o->toString() << " " << o->length() << "\n";
    
    std::cout << o->get(4) << '\n';
    std::cout << std::boolalpha << o->contains("c") << '\n';
    o->remove(4);
    std::cout << std::boolalpha << o->contains("c") << '\n';
    std::cout << o->toString() << " " << o->length() << "\n";

    o->reverse();
    std::cout << o->toString() << " " << o->length() << "\n";

    delete o;
    return 0;
}


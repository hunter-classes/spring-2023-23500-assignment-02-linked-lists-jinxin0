#pragma once

#include <iostream>
#include <string>

#include "Node.h"

class OList{
    private:
        Node *head;
    public:
        OList();
        ~OList();

        void insert(std::string data);
        std::string toString(); // for testing purposes
        bool contains(std::string item);
        std::string get(int loc);
        void remove(int loc);
        void reverse();
        int length();
};


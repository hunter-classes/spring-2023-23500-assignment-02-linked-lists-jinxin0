#pragma once

#include <iostream>
#include <string>

#include "Node.h"

class List{
    private:
        Node *head;
    public:
        List();
        void insert(std::string data);
        void insert(int loc, std::string data); //0 indexed
        int length();

        std::string toString(); // for testing purposes

        /* 1 */
        /* ------------------- */

        ~List();

        void remove(int loc);

        std::string get(int loc);
        bool contains(std::string item);
};


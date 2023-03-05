#include <bits/types/struct_tm.h>
#include <cstdlib>
#include <iostream>
#include "Node.h"
#include "OList.h"

OList::OList()
    : head(nullptr)
{
}

OList::~OList()
{
    Node *current_node = this->head;
    Node *next_node = nullptr;

    while (current_node != nullptr)
    {
        next_node = current_node->getNext();
        delete current_node;
        current_node = next_node;
    }
}

// insert in order
void OList::insert(std::string data)
{
    Node *tmp = new Node(data);
    Node *previous_node = nullptr;
    Node *current_node = this->head;

    while (current_node != nullptr && data > current_node->getData())
    {
        previous_node = current_node;
        current_node = current_node->getNext();
    }

    if (previous_node != nullptr)
    {
        tmp->setNext(current_node);
        previous_node->setNext(tmp);
    }
    else
    {
        if (current_node != nullptr)
            tmp->setNext(current_node);
        this->head = tmp;
    }
}

std::string OList::toString()
{
    Node *tmp = this->head;
    std::string result = "";
    while (tmp != nullptr)
    {
        result = result + tmp->getData();
        result = result + "-->";
        tmp = tmp->getNext();
    }
    result = result + "nullptr";
    return result;
}

bool OList::contains(std::string item)
{
    for (Node *current_node = this->head; current_node != nullptr; current_node = current_node->getNext())
        if (current_node->getData() == item)
            return true;

    return false;
}

std::string OList::get(int loc)
{
    if (loc >= this->length())
        return "";

    Node *current_node = this->head;
    for (int current_location = 0; current_location != loc; current_location++)
        current_node = current_node->getNext();

    return current_node->getData();
}

void OList::remove(int loc)
{
    if (loc >= this->length())
        return;

    Node *previous_node = nullptr;
    Node *current_node = this->head;

    for (int current_location = 0; current_location != loc; current_location++)
    {
        previous_node = current_node;
        current_node = current_node->getNext();
    }

    if (loc == 0)
        this->head = this->head->getNext();
    else
        previous_node->setNext(current_node->getNext());
    delete current_node;
}

void OList::reverse()
{
    Node *previous_node = nullptr;
    Node *current_node = this->head;

    while (current_node != nullptr)
    {
        this->head = current_node;
        current_node = current_node->getNext();
        this->head->setNext(previous_node);
        previous_node = this->head;
    }
}

/*
   Alternate solution:
   make a private variable to store the length
   and just return it here.

   Change all the insert/delete/remove type
   routines to upate that variable 
*/
int OList::length()
{
    int count = 0;
    Node *walker = head;
    while (walker != nullptr)
    {
        count++;
        walker = walker->getNext();
    }
    return count;
}

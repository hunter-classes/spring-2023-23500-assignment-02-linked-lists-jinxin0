#include <cstdlib>
#include <iostream>
#include "Node.h"
#include "List.h"

List::List()
    : head(nullptr)
{
}

// insert at the "front" (head)
void List::insert(std::string data)
{
    Node *tmp = new Node(data);
    tmp->setNext(head);
    head = tmp;
}

/*
   insert at loc
   We need a pointer to the node BEFORE
   the location where we want to insert 

   Piggybacking 
*/
void List::insert(int loc, std::string data)
{
    Node *walker, *trailer;
    walker = this->head; // start of the list
    trailer = nullptr; // one behind

    while(loc>0 && walker != nullptr)
    {
        loc=loc-1;

        /* trailer will always be one node
           behind walker */
        trailer=walker;
        walker = walker->getNext();

    }

    // At this point, trailer points to the Node
    // BEFORE where we want to insert


    // test to see if we're trying to
    // insert past the end 
    if (loc > 0)
    {
        // do something to indicate this is invalid
        throw std::out_of_range("Our insert is out of range");
    }

    Node *newNode = new Node(data);
    // Inserting at true location 0
    // will have trailer == nullptr
    // - we have to treat that as a special case
    if (trailer == nullptr)
    {
        newNode->setNext(head);
        head = newNode;
    } else 
    {
        // do the regular case 
        newNode->setNext(walker);
        trailer->setNext(newNode);
    }
}

/*
   Alternate solution:
   make a private variable to store the length
   and just return it here.

   Change all the insert/delete/remove type
   routines to upate that variable 
*/
int List::length()
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

std::string List::toString()
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


List::~List()
{
    if (this->length() == 0)
        return;

    Node *previous_node;
    Node *current_node = this->head;

    do
    {
        previous_node = current_node;
        current_node = current_node->getNext();
        free(previous_node);
    } while (current_node != nullptr);
}

void List::remove(int loc)
{
    if (loc >= this->length())
        return;

    Node *previous_node = this->head;
    Node *current_node = previous_node->getNext();

    if (loc == 0)
    {
        free(previous_node);
        this->head = current_node;
        return;
    }

    int current_location = 1;
    while (current_location++ != loc)
    {
        previous_node = current_node;
        current_node = current_node->getNext();
    }

    previous_node->setNext(current_node->getNext());
    free(current_node);
    return;
}

std::string List::get(int loc)
{
    if (loc >= this->length())
        return "";

    Node *current_node = this->head;

    int current_location = 0;
    while (current_location++ != loc)
        current_node = current_node->getNext();

    return current_node->getData();
}

bool List::contains(std::string item)
{
    for (Node *current_node = this->head; current_node != nullptr; current_node = current_node->getNext())
        if (current_node->getData() == item)
            return true;

    return false;
}



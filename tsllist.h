//Daniel Farone
//CSCI 3110-001
//Project #3
//Due: 02/24/22
//This file fully implements the TSLList class template being almost identitical to "intsllist.h" from proj 2
//other than name changes and its implementation as a class template to store custom objects.
//This file defines functions that insert a rectangle area in order to the list, delete the area of a rectangle,
//delete all instances of an area measurement from the list, or clear all area values in the list.
#ifndef TSLLIST_H
#define TSLLIST_H
#include<iostream>

template <typename T>
class TSLList 
{
    public:

        // Constructor
        TSLList() {
            head = nullptr;
        }

        //D Destructor
        ~TSLList() {
            clearList();
        }

        // prints the info content and address of each node in the list
        void printAll() const 
        {
            for (TSLLNode *tmp = head; tmp != nullptr; tmp = tmp->next)
                std::cout << "->" << tmp->info;
            std::cout << std::endl;
        }

        // Inserts node in order (see assignment specification for details)
        void insertInOrder(T el)
        {
        	TSLLNode *trail = head;
           	TSLLNode *lead = nullptr;
            TSLLNode *newNode = new TSLLNode;
            newNode->info = el;
            newNode->next = nullptr;
    
            //empty list case
            if(head == nullptr)
                    head = newNode;
            //in order non-empty list and non-duplicate case for a new entry less than the head value (no duplicates)
            else if(newNode->info < head->info)
            {
                    newNode->next = head;
                    head = newNode;
            }
            //for entries greater than the head value in the list and duplicate entries
            else
            {
                    while(trail != nullptr && trail->info <= newNode->info)
                    {
                            lead = trail;
                            trail = trail->next;
                    }
                    lead->next = newNode;
                    newNode->next = trail;
            }
        }
        // Deletes an occurrence of argument (see assignment specification for details)
        T deleteVal(T el)
        {
            //initializes an integer to store the value to be returned
            T deleted_val;
            TSLLNode *lead = head;
            TSLLNode *trail = nullptr;
            //if list is empty
            if(head == nullptr)
                    std::cout << "This list is empty!" << std::endl;
            //deleting first value, set lead to head
            else if(head->info == el)
            {
                    deleted_val = head->info;
                    delete head;
                    head = head->next;
            }
            //deleting any other value in the list
            else
            {
                    while(lead != nullptr && lead->info != el)
                    {
                            trail = lead;
                            lead = lead->next;
                    }
                    if(lead != nullptr)
                    {
                            trail->next = lead->next;
                            deleted_val = lead->info;
                            delete lead;
                    }
            //for values not found in the list
                    else
                            deleted_val = 0;
            }
            return deleted_val;
        }
        // Deletes all occurrences of argument (see assignment specification for details)
        void deleteAllVal(T el)
        {
            TSLLNode *trail = head;
            TSLLNode *lead;
            TSLLNode *tmp = nullptr;
            //if list is empty
            if(head == nullptr)
                    std::cout << "This list is empty!" << std::endl;
            //if deleting first value, set lead to head
            if(head->info == el)
            {
                    head = nullptr;
            }
            lead = trail;
            //list is not empty find the first instance of the value
            while(trail != nullptr && lead->info != el)
            {
                    trail = lead;
                    lead = lead->next;
            }
            //loop to delete every instance of the specified value
            while(lead != nullptr && lead->info == el)
            {
                    tmp = lead;
                    lead = lead->next;
                    delete tmp;
            }
            trail->next = lead;
            if(head == nullptr)
                    head = lead;
        }

        // Clears the list (deallocates memory - see assignment specification for details)
        void clearList()
        {
            TSLLNode *tmp = head;
            if(head == nullptr)
            {
                    std::cout << "This list is empty. Nothing to be cleared." << std::endl;
            }
            while(tmp != nullptr)
            {
                    head = head->next;
                    std::cout << "clearing " << tmp->info << std::endl;
                    delete tmp;
                    tmp = head;
            }
        }


    private:
        // Node stored in linked list
        struct TSLLNode {
            TSLLNode(T el = T()) {
                info = el;
                next = nullptr;
            }
            T info;
            TSLLNode *next;
        };
        TSLLNode *head;
};           

#endif

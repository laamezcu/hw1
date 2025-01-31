/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>
using namespace std;

void printList(Node*& list) {
  if (list != NULL) {
    cout << list->value << " ";
    printList(list->next);
  }
}

void deleteList(Node*& list) {
  if (list != NULL) {
    deleteList(list->next);
    delete list;
    list = nullptr;
  }
}

int main(int argc, char* argv[])
{
    Node* five = new Node(5, nullptr);
    Node* four = new Node(4, five);
    Node* three = new Node(3, four);
    Node* two = new Node(2, three);
    Node* one = new Node(1, two);
    Node* odds = nullptr;
    Node* evens = nullptr;
    //Node* in = nullptr;
    Node* in = one;
    split(in, odds, evens);
    cout << "Odds: ";
    printList(odds);
    cout << endl;
    cout << "Evens: ";
    printList(evens);
    cout << endl;
    if (in == NULL) {
        cout << "in empty" << endl;
    }
    deleteList(odds);
    deleteList(evens);
    return 0;
}

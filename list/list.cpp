#pragma once
#include "list.hpp"

namespace lasd {

/* ************************************************************************** */

//Specific constructor Node
template<typename Data>
List<Data>::Node::Node(const Data& value) {
    element = value;
    next = nullptr;
}

template<typename Data>
List<Data>::Node::Node(Data&& value) noexcept {
    std::swap(element, value);
    next = nullptr;
}

//Copy Constructor Node
template<typename Data>
List<Data>::Node::Node(const Node& nodo) {
    this->element = nodo.element;
    this->next = nodo.next;
}

//Move constructor
template<typename Data>
List<Data>::Node::Node(Node&& nodo) noexcept {
    std::swap(element, nodo.element);
    std::swap(next, nodo.next);
}

//Comparison operator Node
template<typename Data>
bool List<Data>::Node::operator==(const Node& nodo) const noexcept {
    if (element != nodo.element) {
        return false;
    } return true;
}

template<typename Data>
bool List<Data>::Node::operator!=(const Node& nodo) const noexcept {
    return !(*this == nodo);
}

//Default constructors (List)
template<typename Data>
List<Data>::List() {
    First = nullptr;
    Last = nullptr;
}

//Specific constructor (list)
template<typename Data>
List<Data>::List(const MappableContainer<Data>& con) {
    unsigned long index = 0;
    if(con.Size()==0) {
        First = nullptr;
        Last = nullptr;
    }
    else {
        First = nullptr;
        Last = nullptr;
    con.Map(
        [this](const Data & dat) {
            InsertAtBack(dat);
        }
    );
    }
}

template<typename Data>
List<Data>::List(MutableMappableContainer<Data>&& con) {
    unsigned long index = 0;
    if(con.Size()==0) {
        First = nullptr;
        Last = nullptr;
    }
    else {
        First = nullptr;
        Last = nullptr;
    con.Map(
        [this](Data & dat) {
            InsertAtBack(std::move(dat));
        }
    );
    }
}

//Copy constructors List
template<typename Data>
List<Data>::List(const List<Data>& otherList) {
    if(this != &otherList) {
        if(otherList.First==nullptr) {
            First=nullptr;
            Last=nullptr;
            size=0;
        }
        else {
            struct Node* current;
            current = otherList.First;
            struct Node* node = new Node(current->element);

            First=node;
            Last=First;

            current=current->next;
            while(current != nullptr) {
                struct Node* newnode = new Node(current->element);
                Last->next = newnode;
                Last = newnode;
                current = current->next;
            }
            size = otherList.size;
        }
    }
}

//Move constructor List
template<typename Data>
List<Data>::List(List<Data>&& otherList) noexcept {
    size = otherList.size;
    otherList.size = 0;
    First = otherList.First;
    Last = otherList.Last;
    otherList.First = nullptr;
}

//Destructor List
template<typename Data>
List<Data>::~List(){
    Node* current = First;
    while(current != nullptr) {
        Node* to_delete = current;
        current = current->next;
        delete to_delete;
    }
}

//Copy assignment list
template<typename Data>
List<Data>& List<Data>::operator=(const List<Data>& toCopy) {
    List<Data> *tmp = new List<Data>(toCopy);
    std::swap(*tmp, *this);
    delete tmp;
    return *this;
}

//Move assignment list
template<typename Data>
List<Data>& List<Data>::operator=(List<Data>&& toMove) noexcept {
    std::swap(First, toMove.First);
    std::swap(Last, toMove.Last);
    std::swap(size, toMove.size);
    return *this;
}

//Comparison operator - list
template<typename Data>
bool List<Data>::operator==(const List<Data>& lista) const noexcept {
    if(size == lista.size) {
        struct Node* current = First;
        struct Node* tmp = lista.First;
        for(unsigned long j = 0; j<size; j++) {
            if(current->element != tmp->element) {
                return false;
            }
            current = current -> next;
            tmp = tmp -> next;
        }
        return true;
    } return false;
}
// !=
template<typename Data>
bool List<Data>::operator!=(const List<Data>& list) const noexcept {
    return !(*this == list);
}

//RemoveFromFront List
template<typename Data>
void List<Data>::RemoveFromFront() {
    struct Node* current;
    if(First == nullptr)
        throw std::length_error("Access to an empty list.");
    else if(First == Last) {
        size--;
        First = nullptr;
        Last = nullptr;
    } else {
        current = First;
        First = First->next;
        size--;
        delete current;
    }
}

//FrontNRemove
template<typename Data>
Data& List<Data>::FrontNRemove() {
    Node* current = nullptr;
    if(First == nullptr)
        throw std::length_error("Access to an empty list");
    else if(First == Last) {
        size--;
        current = First;
        First = nullptr;
        Last = nullptr;
        return current->element;
    } else {
        current = First;
        First = First->next;
        size--;
        return current->element;
    }
}

//InsertAtFront (cpy)
template<typename Data>
void List<Data>::InsertAtFront(const Data& value) {
    struct Node* newNode;
    newNode = new Node(value);

    newNode->next = First;
    First = newNode;
    size++;
    if(Last == nullptr)
        Last = newNode;
}

//InsertAtFront (mv)
template<typename Data>
void List<Data>::InsertAtFront(Data&& value) noexcept {
    struct Node* newNode;
    newNode = new Node(std::move(value));

    newNode->next = First;
    First = newNode;
    size++;

    if(Last == nullptr)
        Last = newNode;
}

//InsertAtBack (cpy)
template<typename Data>
void List<Data>::InsertAtBack(const Data& value) {
    struct Node* newNode;
    newNode = new Node(value);

    if(!First){
        First = newNode;
        Last = newNode;
        size++;
    } else {
        struct Node* tmp = First;
        while(tmp->next) tmp = tmp->next;
        tmp->next = newNode;
        size++;

        Last = tmp->next;
    }
}

//InsertAtBack (mv)
template<typename Data>
void List<Data>::InsertAtBack(Data&& value) noexcept {
    struct Node* newNode;
    newNode = new Node(std::move(value));

    if(!First) {
        First = newNode;
        Last = newNode;
        size++;
    } else {
        struct Node* tmp = First;
        while(tmp->next) tmp = tmp->next;
        tmp->next = newNode;
        size++;
        Last = tmp->next;
    }
}

template<typename Data>
void List<Data>::Clear(){
    struct Node* tmp;

    while(First != nullptr) {
        tmp = First;
        First = First->next;
    }
    Last = nullptr;
    size = 0;
    First = nullptr;

    delete tmp;
}

template<typename Data>
bool List<Data>::Exists(const Data& dat) const noexcept {
    if(First == nullptr) return false;
    if(First->element == dat) {
        return true;
    }
    Node* tmp = First;
    while(tmp->next != nullptr) {
        if(dat == tmp->next->element) return true;
        tmp = tmp -> next;
    }
    return false;
}

//Insert/InsertMove/Remove dictionary
template<typename Data>
bool List<Data>::Insert(const Data & toInsert) {
    if(Exists(toInsert)) return false;
    InsertAtBack(toInsert); return true;
}

template<typename Data>
bool List<Data>::Insert(Data&& toInsert) {
    if(Exists(toInsert)) return false;
    InsertAtBack(toInsert); return true;
}

template<typename Data>
bool List<Data>::Remove(const Data & toRemove) {
    if(First == nullptr) return false;
    if(First->element == toRemove) {
        RemoveFromFront();
        return true;
    }
    Node* tmp = First;
    while(tmp->next != nullptr) {
      if(toRemove == tmp->next->element) {
        Node* toDelete = tmp->next;        
        tmp->next = tmp->next->next;
        delete toDelete;
        --size;
        return true;
      }  
      tmp = tmp->next;  
    } 
    return false;
}

//Front functions - list
template<typename Data>
const Data& List<Data>::Front() const {
    if(First != nullptr) {
        return First->element;
    } else {
        throw std::length_error("Empty list");
    }
}
template<typename Data>
Data& List<Data>::Front() {
    if(First != nullptr) {
        return First->element;
    } else {
        throw std::length_error("Empty list");
    }
}

//Back functions - list
template<typename Data>
const Data& List<Data>::Back() const {
    if(size != 0) {
        return Last->element;
    } else {
        throw std::length_error("Access to an empty list");
    }
}
template<typename Data>
Data& List<Data>::Back() {
    if(size != 0) {
        return Last->element;
    } else {
        throw std::length_error("Access to an empty list");
    }
}

//Operator [] functions list
template<typename Data>
const Data& List<Data>::operator[](const unsigned long j) const {
    if(j < size) {
        struct Node* current;
        current = First;
        for(unsigned long i = 0; i < j; i++) {
            current = current->next;
        }
        return current->element;
    } else {
        throw std::out_of_range("Access to index " + std::to_string(j) + "forbidden. Actual list lenght: " + std::to_string(size));
    }
}
template<typename Data>
Data& List<Data>::operator[](const unsigned long j) {
    if (j < size) {
        struct Node *current;
        current = First;
        for (unsigned long i = 0; i < j; i++) {
            current = current->next;
        }
        return current->element;
    } else {
        throw std::out_of_range(
                "Access to index " + std::to_string(j) + "forbidden. Actual list lenght: " + std::to_string(size));
    }
}

template<typename Data>
void List<Data>::Map(MapFunctor fun) const {
    PreOrderMap(fun, First);
}

template<typename Data>
void List<Data>::Map(MutableMapFunctor fun) {
    PreOrderMap(fun, First);
}

template<typename Data>
void List<Data>::PreOrderMap(MapFunctor fun) const {
    PreOrderMap(fun, First);
}

template<typename Data>
void List<Data>::PreOrderMap(MutableMapFunctor fun) {
    PreOrderMap(fun, First);
}

template<typename Data>
void List<Data>::PostOrderMap(MapFunctor fun) const {
    PostOrderMap(fun, First);
}

template<typename Data>
void List<Data>::PostOrderMap(MutableMapFunctor fun) {
    PostOrderMap(fun, First);
}
/*FOLD
template<typename Data>
void List<Data>::Fold(FoldFunctor fun, void* punt) const {
    PreOrderFold(fun, punt, First);
}


template<typename Data>
void List<Data>::PreOrderFold(FoldFunctor fun, void* punt) const {
    PreOrderFold(fun, punt, First);
}


template<typename Data>
void List<Data>::PostOrderFold(FoldFunctor fun, void* punt) const {
    PostOrderFold(fun, punt, First);
}
*/


//Map (protected) functions
template<typename Data>
void List<Data>::PreOrderMap(MutableMapFunctor fun, Node* curr) {
    for(; curr != nullptr; curr = curr->next) {
        fun(curr->element);
    }
}
template<typename Data>
void List<Data>::PostOrderMap(MutableMapFunctor fun, Node* curr) { 
    if(curr==nullptr) return; 
    PostOrderMap(fun, curr->next);
    fun(curr->element);
}

//Map (protected) functions // NonMutable
template<typename Data>
void List<Data>::PreOrderMap(MapFunctor fun, Node* curr) const {
    for(; curr != nullptr; curr = curr->next) {
        fun(curr->element);
    }
}
template<typename Data>
void List<Data>::PostOrderMap(MapFunctor fun, Node* curr) const { 
    if(curr==nullptr) return; 
    PostOrderMap(fun, curr->next);
    fun(curr->element);
}

//Fold (protected) functions
template<typename Data>
void List<Data>::PreOrderFold(FoldFunctor fun, void* acc, Node* curr) {
    if(curr == nullptr) return;
    fun(curr->element, acc);
    PreOrderFold(fun, acc, curr->next);
}

template<typename Data>
void List<Data>::PostOrderFold(FoldFunctor fun, void* acc, Node* curr) {
    if(curr == nullptr) return;
    PostOrderFold(fun, acc, curr);
    fun(curr->element, acc);
}
/* ************************************************************************** */

}

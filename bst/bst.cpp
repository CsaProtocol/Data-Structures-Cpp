#pragma once
#include "bst.hpp"

namespace lasd {

/* ************************************************************************** */

template<typename Data>
BST<Data>::BST(const MappableContainer<Data>& con) : BinaryTreeLnk<Data>::BinaryTreeLnk(con) {}

template<typename Data>
BST<Data>::BST(MutableMappableContainer<Data>& con) : BinaryTreeLnk<Data>::BinaryTreeLnk(con) {}

template<typename Data>
BST<Data>::BST(const BST<Data>& bt) : BinaryTreeLnk<Data>::BinaryTreeLnk(bt) {}

template<typename Data>
BST<Data>::BST(BST<Data>&& bt) noexcept : BinaryTreeLnk<Data>::BinaryTreeLnk(std::move(bt)) {}

//Cpy && move assignment
template<typename Data>
BST<Data>& BST<Data>::operator=(const BST& bt) {
    BinaryTreeLnk<Data>::operator=(bt);
    return *this;
}
template<typename Data>
BST<Data>& BST<Data>::operator=(BST<Data>&& bt) noexcept {
    BinaryTreeLnk<Data>::operator=(std::move(bt));
    return *this;
}

// == and !=
template<typename Data>
bool BST<Data>::operator==(const BST<Data>& bt) const noexcept {
    if(size == bt.Size()) {
        BTInOrderIterator<Data> it1(*this);
        BTInOrderIterator<Data> it2(bt);
    for(; !it1.Terminated(); ++it1,++it2) {
        if(*it1 != it2) {
            return false;
        }
    }
    return true;
    } return false;
}

template<typename Data>
bool BST<Data>::operator!=(const BST<Data>& bt) const noexcept {
    return !(*this == bt);
}

template<typename Data>
Data& BST<Data>::Min() const {
    if(root != nullptr) {
        return FindPointerToMin(root)->element;
    } else {
        throw std::length_error("Lenght error.");
    }
}

template<typename Data>
Data& BST<Data>::Max() const {
    if(root != nullptr) {
        return FindPointerToMax(root)->element;
    } else {
        throw std::length_error("Lenght error.");
    }
}

/* ************************************************************************** */

}

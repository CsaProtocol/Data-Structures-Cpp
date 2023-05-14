#pragma once
#include "binarytreelnk.hpp"

namespace lasd {

/* ************************************************************************** */

template<typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(const Data& toCopy) { element = toCopy; }

template<typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(Data&& toMove) noexcept {element = toMove; }

template<typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::HasLeftChild() {return left!=nullptr;}
template<typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::HasRightChild() {return right!=nullptr;}

template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::LeftChild() const {
    if(left==nullptr)
        throw std::out_of_range("Out of range.");
    return left;
}
template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::RightChild() const {
    if(right==nullptr)
        throw std::out_of_range("Out of range.");
    return right;
}

template<typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const MappableContainer<Data>& con) {
    con.Map(
            [this](const Data& x) {
                Insert(Root(),x);
            });
}
template<typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(MutableMappableContainer<Data>& con) {
    con.Map(
            [this](const Data& x) {
                Insert(Root(),x);
            });
}

template<typename Data>
void BinaryTreeLnk<Data>::Insert(typename BinaryTreeLnk<Data>::NodeLnk& point, Data& val) {
    if (point == NULL) {
        point = new BinaryTreeLnk<Data>::NodeLnk(val);
        return;
    } if (!point.HasLeftChild()) {
        insert(point->left, val);
    } else {
        insert(point->right, val);
    }
}

template<typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const BinaryTreeLnk<Data>& bt) {
    if(bt.root != nullptr) {
        root = Copy(bt);
        size = bt.Size();
    }
}

template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* BinaryTreeLnk<Data>::Copy(const BinaryTreeLnk<Data>& toCopy) {
    BinaryTreeLnk<Data>::NodeLnk* bt;
    rcCopy(&bt, toCopy.Root());
    return bt;
}

template<typename Data>
void BinaryTreeLnk<Data>::rcCopy(BinaryTreeLnk<Data>::NodeLnk** copied, const BinaryTreeLnk<Data>::NodeLnk* toCopy) {
    (*copied) = new NodeLnk(toCopy->Element());
    if(toCopy->HasLeftChild()) {
        rcCopy(&(*copied)->left, &toCopy->LeftChild());
    }
    if(toCopy->HasRightChild()) {
        rcCopy(&(*copied)->right, &toCopy->RightChild());
    }
}

template<typename Data>
void BinaryTreeLnk<Data>::deleteTree(BinaryTreeLnk<Data>::NodeLnk*& toDelete) noexcept {
    if(toDelete->HasRightChild())
        deleteTree(toDelete->right);
    if(toDelete->HasLeftChild())
        deleteTree(toDelete->left);

    delete toDelete;
    toDelete = nullptr;
    size--;
}

template<typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(BinaryTreeLnk<Data>&& bt) noexcept {
    std::swap(root, bt.root);
    std::swap(size, bt.size);
}

template<typename Data>
BinaryTreeLnk<Data>::~BinaryTreeLnk() noexcept {
    BinaryTreeLnk<Data>::Clear();
}

//Cpy and Mv
template<typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(const BinaryTreeLnk<Data>& bt) {
    if(this == &bt) {
        return *this;
    }
}
template<typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(BinaryTreeLnk<Data>&& bt) noexcept {
    if(this == &bt)
        return *this;
    BinaryTreeLnk<Data>::Clear();
    std::swap(root, bt.root);
    std::swap(size, bt.size);
    return *this;
}

// == from MutableBinaryTree
template<typename Data>
bool BinaryTreeLnk<Data>::operator==(const BinaryTreeLnk<Data>& bt) const noexcept {
    return MutableBinaryTree<Data>::operator==(bt);
}
template<typename Data>
bool BinaryTreeLnk<Data>::operator!=(const BinaryTreeLnk<Data>& bt) const noexcept {
    return MutableBinaryTree<Data>::operator!=(bt);
}
template<typename Data>
const typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::Root() const {
    if(root==nullptr)
        throw std::out_of_range("Empty binarytree");
    return *root;
}

template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::Root() {
    return const_cast<NodeLnk&>(const_cast<const BinaryTreeLnk<Data>*>(this)->Root());
}

template<typename Data>
void BinaryTreeLnk<Data>::Clear() {
    if(root!=nullptr)
        deleteTree(root);
}

/* ************************************************************************** */

}

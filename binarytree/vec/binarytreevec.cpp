#pragma once
#include "binarytreevec.hpp"

namespace lasd {

/* ************************************************************************** */

template<typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(const Data& toCopy) {
    element = toCopy;
}
template<typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(Data&& toMove) noexcept {
    std::swap(element, toMove);
}
template<typename Data>
Data& BinaryTreeVec<Data>::NodeVec::Element() {return element;}

template<typename Data>
bool BinaryTreeVec<Data>::NodeVec::IsLeaf() const noexcept {
    return (!HasLeftChild() && !HasRightChild());
}
template<typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasLeftChild() const noexcept {
    return index*2+1 < (*ptr).Size() && (*ptr)[index*2+1] != nullptr;
}
template<typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasRightChild() const noexcept {
    return index*2+2 < (*ptr).Size() && (*ptr)[index*2+2] != nullptr;
}

//Left-RightChild
template<typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::LeftChild() const{
    if (!HasLeftChild())
        throw std::out_of_range("Left child does not exist.");
    return *(*ptr)[index*2+1];
}
template <typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::RightChild() const{
    if (!HasRightChild())
        throw std::out_of_range("Right child does not exist.");
    return *(*ptr)[index*2+2];
}

//MappableContainer
template<typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const MappableContainer<Data>& con) {
    size = con.Size();
    treeVec = new Vector<Data>(con);
}

//MutableMappable
template<typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(MutableMappableContainer<Data>& con) {
    size = con.Size();
    treeVec = new Vector<Data>(con);
}

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const BinaryTreeVec<Data>& bt) {
    pointersVecNodes.Resize(bt.pointersVecNodes.Size());

    for (unsigned long int i = 0; i < pointersVecNodes.Size(); i++) {
        pointersVecNodes[i] = bt.pointersVecNodes[i] ? new NodeVec(bt.pointersVecNodes[i]->Element(), &pointersVecNodes, i) : nullptr;
    }

    nodeXLevel = bt.nodeXLevel;
    size = bt.Size();
}
/* ************************************************************************** */

}

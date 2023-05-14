#pragma once
#include "binarytree.hpp"

namespace lasd {

/* ************************************************************************** */

// BinaryTree::Node - Comparison Operators
template<typename Data>
bool BinaryTree<Data>::Node::operator==(const Node& node) const noexcept {
  return (node.element == element);
}

template<typename Data>
bool BinaryTree<Data>::Node::operator!=(const Node& node) const noexcept {
  return !(*this == node);
}

// BinaryTree Non-Mutable - Comparison Operators
template<typename Data>
bool BinaryTree<Data>::operator==(const BinaryTree& other) const noexcept {
  if(size != other.Size()) {
    return false;
  } if (size == 0 && other.Size() == 0) {
    return true;
  }
  return isEqual(Root(), other.Root());
}
//Definition of the protected support function for == (isEqual) -- GHOST
template<typename Data>
bool BinaryTree<Data>::isEqual(Node& bt1, Node& bt2) const {
  bool value = true;
  if(bt1.Element() != bt2.Element()) {
    value = false;
  } else {
    if (bt1.HasLeftChild() && bt2.HasLeftChild()) {
      value = isEqual(bt1.LeftChild(), bt2.LeftChild());
    } else if (!bt1.HasLeftChild() && !bt2.HasLeftChild()) {
      value = true;
    } else {
      value = false;
    }

    if(value) {
      if(bt1.HasRightChild() && bt2.HasRightChild()) {
        value = isEqual(bt1.RightChild(), bt2.RightChild());
      } else if (!bt1.HasRightChild() && !bt2.HasRightChild()) {
        value = true;
      } else {
        value = false;
      }
    }
  } return value;
}
/* GHOST
  if (bt1.Element() != bt2.Element()) {
    return false;
  }

  bool leftEqual = true;
  if(bt1.HasLeftChild() && bt2.HasLeftChild()) {
    leftEqual = isEqual(bt1.LeftChild(), bt2.LeftChild());
  } else if (bt1.HasLeftChild() || bt2.HasLeftChild()) {
    return false;
  }

  bool rightEqual = true;
  if(bt2.HasRightChild() && bt1.HasRightChild()) {
    rightEqual = isEqual(bt1.RightChild(), bt2.RightChild());
  } else if (bt1.HasRightChild() || bt2.HasRightChild()) {
    return false;
  }

  return leftEqual && rightEqual;
}*/

// "!=" operator
template<typename Data>
bool BinaryTree<Data>::operator!=(const BinaryTree& bt) const noexcept {
  return !(*this == bt);
}

//Fold and Map functions for const BinaryTree
template<typename Data>
void BinaryTree<Data>::Fold(FoldFunctor fun, void* punt) const {
  PreOrderFold(fun, punt);
}

template<typename Data>
void BinaryTree<Data>::Map(MapFunctor fun) {
  PreOrderMap(fun, Root());
}
template<typename Data>
void BinaryTree<Data>::PreOrderMap(MapFunctor fun) {
  PreOrderMap(fun, Root());
}
template<typename Data>
void BinaryTree<Data>::PostOrderMap(MapFunctor fun) {
  PostOrderMap(fun, Root());
}
template<typename Data>
void BinaryTree<Data>::InOrderMap(MapFunctor fun) {
  InOrderMap(fun, Root());
}
template<typename Data>
void BinaryTree<Data>::BreadthMap(MapFunctor fun) {
  BreadthMap(fun, Root());
}

//Aux functions - BinaryTree const
template<typename Data>
void BinaryTree<Data>::PreOrderMap(MapFunctor fun, Node& node) {
    if(&node != nullptr) {
        fun(node.Element());
        if(node.HasLeftChild()) {
            PreOrderMap(fun, node.LeftChild());
        }
        if(node.HasRightChild()) {
            PreOrderMap(fun, node.RightChild());
        }
    }
}

template<typename Data>
void BinaryTree<Data>::PostOrderMap(MapFunctor fun, Node& node) {
    if(&node != nullptr) {
        if(node.HasLeftChild()) {
            PostOrderMap(fun, node.LeftChild());
        }
        if(node.HasRightChild()) {
            PostOrderMap(fun, node.RightChild());
        }
        fun(node.Element());
    }
}

template<typename Data>
void BinaryTree<Data>::InOrderMap(MapFunctor fun, Node& node) {
    if(&node != nullptr) {
        if(node.HasLeftChild()) {
            InOrderMap(fun, node.LeftChild());
        }
        fun(node.Element());
        if(node.HasRightChild()) {
            InOrderMap(fun, node.RightChild());
        }
    }
}

template<typename Data>
void BinaryTree<Data>::BreadthMap(MapFunctor fun, Node& node) {
    lasd::QueueLst<Node*> q;
    if(&node != nullptr) {
        q.Enqueue(&node);
    }

    while(!q.Empty()) {
        fun(q.Head()->Element());

        if(q.Head()->HasLeftChild()) {
            q.Enqueue(&(q.Head()->LeftChild()));
        }
        if(q.Head->HasRightChild()) {
            q.Enqueue(&(q.Head()->RightChild()));
        }
        q.Dequeue();
    }
}

/* ************************************************************************** */

//MutableBinaryTree
template<typename Data>
void MutableBinaryTree<Data>::Map(MutableMapFunctor fun) {
    PreOrderMap(fun, Root());
}
template<typename Data>
void MutableBinaryTree<Data>::PreOrderMap(MutableMapFunctor fun) {
    PreOrderMap(fun, Root());
}
template<typename Data>
void MutableBinaryTree<Data>::PostOrderMap(MutableMapFunctor fun) {
    PostOrderMap(fun, Root());
}
template<typename Data>
void MutableBinaryTree<Data>::InOrderMap(MutableMapFunctor fun) {
    InOrderMap(fun, Root());
}
template<typename Data>
void MutableBinaryTree<Data>::BreadthMap(MutableMapFunctor fun) {
    BreadthMap(fun, Root());
}

//Aux functions - BinaryTree const
template<typename Data>
void MutableBinaryTree<Data>::PreOrderMap(MutableMapFunctor fun, MutableNode& node) {
    if(&node != nullptr) {
        fun(node.Element());
        if(node.HasLeftChild()) {
            PreOrderMap(fun, node.LeftChild());
        }
        if(node.HasRightChild()) {
            PreOrderMap(fun, node.RightChild());
        }
    }
}

template<typename Data>
void MutableBinaryTree<Data>::PostOrderMap(MutableMapFunctor fun, MutableNode& node) {
    if(&node != nullptr) {
        if(node.HasLeftChild()) {
            PostOrderMap(fun, node.LeftChild());
        }
        if(node.HasRightChild()) {
            PostOrderMap(fun, node.RightChild());
        }
        fun(node.Element());
    }
}

template<typename Data>
void MutableBinaryTree<Data>::InOrderMap(MutableMapFunctor fun, MutableNode& node) {
    if(&node != nullptr) {
        if(node.HasLeftChild()) {
            InOrderMap(fun, node.LeftChild());
        }
        fun(node.Element());
        if(node.HasRightChild()) {
            InOrderMap(fun, node.RightChild());
        }
    }
}

template<typename Data>
void MutableBinaryTree<Data>::BreadthMap(MutableMapFunctor fun, MutableNode& node) {
    lasd::QueueLst<MutableNode*> q;
    if(&node != nullptr) {
        q.Enqueue(&node);
    }

    while(!q.Empty()) {
        fun(q.Head()->Element());

        if(q.Head()->HasLeftChild()) {
            q.Enqueue(&(q.Head()->LeftChild()));
        }
        if(q.Head->HasRightChild()) {
            q.Enqueue(&(q.Head()->RightChild()));
        }
        q.Dequeue();
    }
}

/* ************************************************************************** */

//BTPreOrderIterator && BTPreOrderMutableIterator
template<typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BinaryTree<Data>& bt) {
    current = &(bt.Root());
    reset = &(bt.Root());
}

template<typename Data>
BTPreOrderMutableIterator<Data>::BTPreOrderMutableIterator(MutableBinaryTree<Data>& bt) {
    current = &(bt.Root());
    reset = &(bt.Root());
}
//Cpy constructor
template<typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BTPreOrderIterator& it) {
    elements = StackLst<typename BinaryTree<Data>::Node*>(it.elements);
    current = it.current;
    reset = it.reset;
}

template<typename Data>
BTPreOrderMutableIterator<Data>::BTPreOrderMutableIterator(const BTPreOrderMutableIterator& it) {
    elements = StackLst<typename MutableBinaryTree<Data>::Node*>(it.elements);
    current = it.current;
    reset = it.reset;
}

//Mv constructor
template<typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(BTPreOrderIterator&& it) noexcept {
    elements = StackLst<typename BinaryTree<Data>::Node*>(std::move(it.elements));
    std::swap(current, it.current);
    std::swap(reset, it.reset);
}
template<typename Data>
BTPreOrderMutableIterator<Data>::BTPreOrderMutableIterator(BTPreOrderMutableIterator&& it) noexcept {
    elements = StackLst<typename MutableBinaryTree<Data>::Node*>(std::move(it.elements));
    std::swap(current, it.current);
    std::swap(reset, it.reset);
}

//Destructor
template<typename Data>
BTPreOrderIterator<Data>::~BTPreOrderIterator() {
    elements.Clear();
    current = nullptr;
    reset = nullptr;
}
template<typename Data>
BTPreOrderMutableIterator<Data>::~BTPreOrderMutableIterator() {
    elements.Clear();
    current = nullptr;
    reset = nullptr;
}

//Copy assignment
template<typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(const BTPreOrderIterator& it) {
    elements = it.elements;
    current = it.current;
    reset = it.reset;
    return *this;
}
template<typename Data>
BTPreOrderMutableIterator<Data>& BTPreOrderMutableIterator<Data>::operator=(const BTPreOrderMutableIterator& it) {
    elements = it.elements; //Call copy assignment di stackvec
    current = it.current;
    reset = it.reset;
    return *this;
}

//Move assignment
template<typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(BTPreOrderIterator&& it) noexcept {
    std::swap(elements, it.elements);
    std::swap(current, it.current);
    std::swap(reset, it.reset);
    return *this;
}
template<typename Data>
BTPreOrderMutableIterator<Data>& BTPreOrderMutableIterator<Data>::operator=(BTPreOrderMutableIterator&& it) noexcept {
    std::swap(elements, it.elements);
    std::swap(current, it.current);
    std::swap(reset, it.reset);
    return *this;
}

//Comparison operators
template<typename Data>
bool BTPreOrderIterator<Data>::operator==(const BTPreOrderIterator& it) const noexcept {
    return (elements == it.elements && current == it.current);
}
template<typename Data>
bool BTPreOrderMutableIterator<Data>::operator==(const BTPreOrderMutableIterator& it) const noexcept {
    return (elements == it.elements && current == it.current);
}
template<typename Data>
bool BTPreOrderIterator<Data>::operator!=(const BTPreOrderIterator& it) const noexcept {
    return !(*this == it);
}
template<typename Data>
bool BTPreOrderMutableIterator<Data>::operator!=(const BTPreOrderMutableIterator& it) const noexcept {
    return !(*this == it);
}

//Specific member function
template<typename Data>
Data& BTPreOrderIterator<Data>::operator*() const {
    if (Terminated()) {
        throw std::out_of_range("Out of range");
    }
    return current->Element();
}
template<typename Data>
Data& BTPreOrderMutableIterator<Data>::operator*() {
    if (BTPreOrderIterator<Data>::Terminated()) {
        throw std::out_of_range("Out of range");
    }
    return current->Element();
}
//Terminated
template<typename Data>
bool BTPreOrderIterator<Data>::Terminated() const noexcept {
    return (current == nullptr);
}

//Reset
template<typename Data>
void BTPreOrderIterator<Data>::Reset() noexcept {
    current = reset;
}
template<typename Data>
void BTPreOrderMutableIterator<Data>::Reset() noexcept {
    current = reset;
}

//Operator ++ for PreOrder
template<typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator++() {
    if(Terminated()) {
        throw std::out_of_range("Out of range");
    }
    if(current->HasRightChild()) {
        elements.Push(&(current->RightChild()));
    }
    if(current->HasLeftChild()) {
        elements.Push(&(current->LeftChild()));
    }
    if(elements.Empty()) {
        current = nullptr;
    } else {
        current = elements.TopNPop();
    }
    return *this;
}

//PostOrderIterator
template<typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BinaryTree<Data>& bt) {
    startPostOrder(&(bt.Root()));
    current = elements.TopNPop();
    reset = current;
}
template<typename Data>
BTPostOrderMutableIterator<Data>::BTPostOrderMutableIterator(MutableBinaryTree<Data>& bt) {
    startPostOrder(&(bt.Root()));
    current = elements.TopNPop();
    reset = current;
}

//Cpy constructor
template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BTPostOrderIterator& it) {
    elements = StackLst<typename BinaryTree<Data>::Node*>(it.elements);
    current = it.current;
    reset = it.reset;
}
template <typename Data>
BTPostOrderMutableIterator<Data>::BTPostOrderMutableIterator(const BTPostOrderMutableIterator& it) {
    elements = StackLst<typename MutableBinaryTree<Data>::MutableNode*>(it.elements);
    current = it.current;
    reset = it.reset;
}

//Move constructor
template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(BTPostOrderIterator&& it) noexcept {
    elements = StackLst<typename BinaryTree<Data>::Node*>(std::move(it.elements));
    std::swap(current, it.current);
    std::swap(reset, it.reset);
}
template <typename Data>
BTPostOrderMutableIterator<Data>::BTPostOrderMutableIterator(BTPostOrderMutableIterator&& it) noexcept {
    elements = StackLst<typename MutableBinaryTree<Data>::MutableNode*>(std::move(it.elements));
    std::swap(current, it.current);
    std::swap(reset, it.reset);
}

//Destructor
template <typename Data>
BTPostOrderIterator<Data>::~BTPostOrderIterator() {
    elements.Clear();
    current = nullptr;
    reset = nullptr;
}
template <typename Data>
BTPostOrderMutableIterator<Data>::~BTPostOrderMutableIterator() {
    elements.Clear();
    current = nullptr;
    reset = nullptr;
}

//Copy assignment
template<typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=(const BTPostOrderIterator& it) {
    elements = it.elements;
    current = it.current;
    reset = it.reset;
    return *this;
}
template<typename Data>
BTPostOrderMutableIterator<Data>& BTPostOrderMutableIterator<Data>::operator=(const BTPostOrderMutableIterator& it) {
    elements = it.elements;
    current = it.current;
    reset = it.reset;
    return *this;
}

//Move assignment
template<typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=(BTPostOrderIterator&& it) noexcept {
    std::swap(elements, it.elements);
    std::swap(current, it.current);
    std::swap(reset, it.reset);
    return *this;
}
template<typename Data>
BTPostOrderMutableIterator<Data>& BTPostOrderMutableIterator<Data>::operator=(BTPostOrderMutableIterator&& it) noexcept {
    std::swap(elements, it.elements);
    std::swap(current, it.current);
    std::swap(reset, it.reset);
    return *this;
}

//Comparison operators
template<typename Data>
bool BTPostOrderIterator<Data>::operator==(const BTPostOrderIterator& it) const noexcept {
    return (current == it.current && elements == it.elements);
}
template<typename Data>
bool BTPostOrderMutableIterator<Data>::operator==(const BTPostOrderMutableIterator& it) const noexcept {
    return (current == it.current && elements == it.elements);
}
template<typename Data>
bool BTPostOrderIterator<Data>::operator!=(const BTPostOrderIterator& it) const noexcept {
    return !(*this == it);
}
template<typename Data>
bool BTPostOrderMutableIterator<Data>::operator!=(const BTPostOrderMutableIterator& it) const noexcept {
    return !(*this == it);
}

//* operator
template<typename Data>
Data& BTPostOrderIterator<Data>::operator*() const {
    if (Terminated()) {
        throw std::out_of_range("Out of range");
    } return current->Element();
}
template<typename Data>
Data& BTPostOrderMutableIterator<Data>::operator*() {
    if(BTPostOrderIterator<Data>::Terminated()) {
        throw std::out_of_range("Out of range");
    } return current->Element();
}

//Terminated
template<typename Data>
bool BTPostOrderIterator<Data>::Terminated() const noexcept {
    return (current == nullptr);
}
//Reset
template<typename Data>
void BTPostOrderIterator<Data>::Reset() noexcept {
    elements.Clear();
    startPostOrder(&(reset));
    current = elements.TopNPop();
}

//StartPostOrder
template<typename Data>
void BTPostOrderIterator<Data>::startPostOrder(typename BinaryTree<Data>::Node* node) {
    while(node!=nullptr) {
        elements.Push(node);
    } if (node->HasLeftChild()) {
        node = &(node->LeftChild());
    } else if (node->HasRightChild()) {
        node = &(node->RightChild());
    } else { node = nullptr;
    }
}
//++ operator
template<typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator++() {
    if (Terminated()) {
        throw std::out_of_range("Out of range");
    } if (!elements.Empty()) {
        if(elements.Top()->HasLeftChild()) {
            if(current == &(elements.Top()->LeftChild())) {
                if(elements.Top()->HasRightChild()) {
                    startPostOrder(&(elements.Top()->RightChild()));
                }
            }
        }
        current = elements.TopNPop();
    } else {
        current = nullptr;
    }
    return *this;
}
/*GHOST -
 * BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator++() {
    while (!Terminated()) {
        if (!elements.Empty()) {
            auto top = elements.Top();
            if (top->HasLeftChild() && current != &(top->LeftChild())) {
                startPostOrder(&(top->LeftChild()));
            } else if (top->HasRightChild() && current != &(top->RightChild())) {
                startPostOrder(&(top->RightChild()));
            } else {
                current = elements.TopNPop();
                return *this;
            }
        } else {
            current = nullptr;
            return *this;
        }
    }
    throw std::out_of_range("Out of range");
}*/

//BTInOrderIterator
template<typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BinaryTree<Data>& bt) {
    startInOrder(&(bt.Root()));
    current = elements.TopNPop();
}
template<typename Data>
BTInOrderMutableIterator<Data>::BTInOrderMutableIterator(MutableBinaryTree<Data>& bt) {
    startInOrder(&(bt.Root()));
    current = elements.TopNPop();
}

//Copy Constructor
template<typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BTInOrderIterator& it) {
    reset = it.current;
    current = it.current;
    elements = StackLst<typename BinaryTree<Data>::Node*>(it.elements);
}
template<typename Data>
BTInOrderMutableIterator<Data>::BTInOrderMutableIterator(const BTInOrderMutableIterator& it) {
    reset = it.current;
    current = it.current;
    elements = StackLst<typename MutableBinaryTree<Data>::MutableNode*>(it.elements);
}

//Move constructor
template<typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(BTInOrderIterator&& it) noexcept {
    elements = StackLst<typename BinaryTree<Data>::Node*>(std::move(it.elements));
    std::swap(reset,it.reset);
    std::swap(current,it.current);
}
template<typename Data>
BTInOrderMutableIterator<Data>::BTInOrderMutableIterator(BTInOrderMutableIterator&& it) noexcept {
    elements = StackLst<typename MutableBinaryTree<Data>::MutableNode*>(std::move(it.elements));
    std::swap(reset,it.reset);
    std::swap(current,it.current);
}

//Destructor
template<typename Data>
BTInOrderIterator<Data>::~BTInOrderIterator() {
    elements.Clear();
    current = nullptr;
    reset = nullptr;
}
template<typename Data>
BTInOrderMutableIterator<Data>::~BTInOrderMutableIterator() {
    elements.Clear();
    current = nullptr;
    reset = nullptr;
}

//Copy and Move assignment
template<typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator=(const BTInOrderIterator& it) {
    elements = it.elements;
    current = it.current;
    reset = it.reset;
    return *this;
}
template<typename Data>
BTInOrderMutableIterator<Data>& BTInOrderMutableIterator<Data>::operator=(const BTInOrderMutableIterator& it) {
    elements = it.elements;
    current = it.current;
    reset = it.reset;
    return *this;
}
//Mv
template<typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator=(BTInOrderIterator&& it) noexcept {
    std::swap(elements, it.elements);
    std::swap(it.current, current);
    std::swap(reset, it.reset);
    return *this;
}
template<typename Data>
BTInOrderMutableIterator<Data>& BTInOrderMutableIterator<Data>::operator=(BTInOrderMutableIterator&& it) noexcept {
    std::swap(elements, it.elements);
    std::swap(it.current, current);
    std::swap(reset, it.reset);
    return *this;
}

//Comparison Operators
template<typename Data>
bool BTInOrderIterator<Data>::operator==(const BTInOrderIterator& it) const noexcept {
    return (elements == it.elements && current == it.current);
}
template<typename Data>
bool BTInOrderMutableIterator<Data>::operator==(const BTInOrderMutableIterator& it) const noexcept {
    return (elements == it.elements && current == it.current);
}

template<typename Data>
bool BTInOrderIterator<Data>::operator!=(const BTInOrderIterator& it) const noexcept {
    return !(*this == it);
}
template<typename Data>
bool BTInOrderMutableIterator<Data>::operator!=(const BTInOrderMutableIterator& it) const noexcept {
    return !(*this == it);
}

//operator *
template<typename Data>
Data& BTInOrderIterator<Data>::operator*() const {
    if(Terminated()) {
        throw std::out_of_range("Out of range");
    } return current->Element();
}
template<typename Data>
Data& BTInOrderMutableIterator<Data>::operator*() {
    if(BTInOrderIterator<Data>::Terminated()) {
        throw std::out_of_range("Out of range");
    } return current->Element();
}

template <typename Data>
bool BTInOrderIterator<Data>::Terminated() const noexcept {
    return (current == nullptr);
}

//StartInOrder
template<typename Data>
void BTInOrderIterator<Data>::startInOrder(typename BinaryTree<Data>::Node* node) {
    while(node!=nullptr) {
        elements.Push(node);
        if (node->HasLeftChild()) {
            node = &(node->LeftChild());
        } else {
            node = nullptr;
        }
    }
}

//++ operator
template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator++() {
    if (Terminated()) {
        throw std::out_of_range("Out of range exception.");
    }
    if (current->HasRightChild()) {
        FindLastLeftNode(&(current->RightChild()));
    }
    if (elements.Empty()) {
        current = nullptr;
    } else {
        current = elements.TopNPop();
    } return *this;
}

template<typename Data>
void BTInOrderIterator<Data>::Reset() noexcept {
    elements.Clear();
    startInOrder(reset);
    current = elements.TopNPop();
}

//BreadthFirst
template<typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BinaryTree<Data>& bt) {
    current = &(bt.Root());
    reset = current;
}
template<typename Data>
BTBreadthMutableIterator<Data>::BTBreadthMutableIterator(MutableBinaryTree<Data>& bt) {
    current = &(bt.Root());
    reset = current;
}

//Copy constructor
template<typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BTBreadthIterator& brIt) {
    elements = QueueLst<typename BinaryTree<Data>::Node*>(brIt.elements);
    current = brIt.current;
    reset = brIt.reset;
}
template<typename Data>
BTBreadthMutableIterator<Data>::BTBreadthMutableIterator(const BTBreadthMutableIterator& brIt) {
    elements = QueueLst<typename MutableBinaryTree<Data>::MutableNode*>(brIt.elements);
    current = brIt.current;
    reset = brIt.reset;
}

//Move constructor
template<typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(BTBreadthIterator<Data>&& it) noexcept {
    elements = QueueLst<typename BinaryTree<Data>::Node*>(std::move(it.elements));
    std::swap(current, it.current);
    std::swap(reset, it.reset);
}
template<typename Data>
BTBreadthMutableIterator<Data>::BTBreadthMutableIterator(BTBreadthMutableIterator<Data>&& it) noexcept {
    elements = QueueLst<typename MutableBinaryTree<Data>::MutableNode*>(std::move(it.elements));
    std::swap(current, it.current);
    std::swap(reset, it.reset);
}

//Destructor
template<typename Data>
BTBreadthIterator<Data>::~BTBreadthIterator() {
    elements.Clear();
    current = nullptr;
    reset = nullptr;
}
template<typename Data>
BTBreadthMutableIterator<Data>::~BTBreadthMutableIterator() {
    elements.Clear();
    current = nullptr;
    reset = nullptr;
}

//Copy Assignment
template<typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=(const BTBreadthIterator& it) {
    elements = it.elements;
    current = it.current;
    return *this;
}
template<typename Data>
BTBreadthMutableIterator<Data>& BTBreadthMutableIterator<Data>::operator=(const BTBreadthMutableIterator& it) {
    elements = it.elements;
    current = it.current;
    return *this;
}

//Move assignment
template<typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=(BTBreadthIterator&& it) noexcept {
    std::swap(elements, it.elements);
    std::swap(current, it.current);
    std::swap(reset, it.reset);
    return *this;
}
template<typename Data>
BTBreadthMutableIterator<Data>& BTBreadthMutableIterator<Data>::operator=(BTBreadthMutableIterator&& it) noexcept {
    std::swap(elements, it.elements);
    std::swap(current, it.current);
    std::swap(reset, it.reset);
    return *this;
}

//Comparison operators
template<typename Data>
bool BTBreadthIterator<Data>::operator==(const BTBreadthIterator& it) const noexcept {
    return (elements == it.elements && current == it.current);
}
template<typename Data>
bool BTBreadthMutableIterator<Data>::operator==(const BTBreadthMutableIterator& it) const noexcept {
    return (elements == it.elements && current == it.current);
}
template<typename Data>
bool BTBreadthIterator<Data>::operator!=(const BTBreadthIterator& it) const noexcept {
    return !(*this == it);
}
template<typename Data>
bool BTBreadthMutableIterator<Data>::operator!=(const BTBreadthMutableIterator& it) const noexcept {
    return !(*this == it);
}

//operator*
template<typename Data>
Data& BTBreadthIterator<Data>::operator*() const {
    if(Terminated()) {
        throw std::out_of_range("Out of range");
    } return current->Element();
}
template<typename Data>
Data& BTBreadthMutableIterator<Data>::operator*() {
    if(BTBreadthIterator<Data>::Terminated()) {
        throw std::out_of_range("Out of range");
    } return current->Element();
}

//Terminated
template<typename Data>
bool BTBreadthIterator<Data>::Terminated() const noexcept {
    return (current == nullptr);
}

//Reset
template<typename Data>
void BTBreadthIterator<Data>::Reset() const noexcept {
    current = reset;
}

//++
template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator++() {
    if (Terminated()) {
        throw std::out_of_range("Out of range exception.");
    } if (current->HasLeftChild()) {
        elements.Enqueue(&current->LeftChild());
    } if (current->HasRightChild()) {
        elements.Enqueue(&current->RightChild());
    } if (elements.Empty()) {
        current = nullptr;
    } else {
        current = elements.HeadNDequeue();
    } return *this;
}

}
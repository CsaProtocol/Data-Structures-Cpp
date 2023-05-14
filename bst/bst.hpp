
#ifndef BST_HPP
#define BST_HPP

/* ************************************************************************** */

#include "../binarytree/lnk/binarytreelnk.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BST : virtual public ClearableContainer,
            virtual public DictionaryContainer<Data>,
            virtual public BinaryTree<Data>,
            virtual public BinaryTreeLnk<Data> {

private:

protected:

  using Container::size;
  using BinaryTreeLnk<Data>::root;
  using typename BinaryTreeLnk<Data>::NodeLnk;

public:

  //No clue why I need this, but without this the IDE throws errors
  using BinaryTreeLnk<Data>::Size;
  using BinaryTreeLnk<Data>::Root;
  using BinaryTreeLnk<Data>::Empty;
  using BinaryTreeLnk<Data>::Clear;

  using BinaryTreeLnk<Data>::BreadthMap;
  using BinaryTreeLnk<Data>::InOrderMap;
  using BinaryTreeLnk<Data>::PreOrderMap;
  using BinaryTreeLnk<Data>::PostOrderMap;

  using BinaryTreeLnk<Data>::BreadthFold;
  using BinaryTreeLnk<Data>::InOrderFold;
  using BinaryTreeLnk<Data>::PreOrderFold;
  using BinaryTreeLnk<Data>::PostOrderFold;

  // Default constructor
  BST() = default;

  /* ************************************************************************ */

  // Specific constructors
  BST(const MappableContainer<Data>&); // A bst obtained from a MutableContainer
  BST(MutableMappableContainer<Data>&); // A bst obtained from a MappableMutableContainer

  /* ************************************************************************ */

  // Copy constructor
  BST(const BST&);

  // Move constructor
  BST(BST&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~BST() = default;

  /* ************************************************************************ */

  // Copy assignment
  BST& operator=(const BST&);

  // Move assignment
  BST& operator=(BST &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BST&) const noexcept;
  bool operator!=(const BST&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  Data& Min() const; // (concrete function must throw std::length_error when empty)
  Data MinNRemove(); // (concrete function must throw std::length_error when empty)
  void RemoveMin(); // (concrete function must throw std::length_error when empty)

  Data& Max() const; // (concrete function must throw std::length_error when empty)
  Data MaxNRemove(); // (concrete function must throw std::length_error when empty)
  void RemoveMax(); // (concrete function must throw std::length_error when empty)

  const Data& Predecessor(const Data&) const; // (concrete function must throw std::length_error when not found)
  Data PredecessorNRemove(const Data&); // (concrete function must throw std::length_error when not found)
  void RemovePredecessor(const Data&); // (concrete function must throw std::length_error when not found)

  const Data& Successor(const Data&) const; // (concrete function must throw std::length_error when not found)
  Data SuccessorNRemove(const Data&); // (concrete function must throw std::length_error when not found)
  void RemoveSuccessor(const Data&); // (concrete function must throw std::length_error when not found)

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  virtual inline bool Insert(const Data&); // Override DictionaryContainer member (Copy of the value)
  virtual inline bool Insert(Data &&); // Override DictionaryContainer member (Move of the value)
  virtual inline bool Remove(const Data&); // Override DictionaryContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

  bool Exists(const Data&) const noexcept override; // Override TestableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear(argument) specifiers; // Override ClearableContainer member

protected:

  // Auxiliary member functions

  Data DataNDelete(NodeLnk*);

  NodeLnk* Detach(NodeLnk*&) noexcept;

  NodeLnk* DetachMin(NodeLnk*&) noexcept;
  NodeLnk* DetachMax(NodeLnk*&) noexcept;

  NodeLnk* Skip2Left(NodeLnk*&) noexcept;
  NodeLnk* Skip2Right(NodeLnk*&) noexcept;

  NodeLnk*& FindPointerToMin(NodeLnk*&) noexcept; // Both mutable & unmutable versions
  NodeLnk*& FindPointerToMax(NodeLnk*&) noexcept; // Both mutable & unmutable versions

  NodeLnk*& FindPointerTo(NodeLnk*&, Data) noexcept; // Both mutable & unmutable versions

  NodeLnk*& FindPointerToPredecessor(NodeLnk*, Data) noexcept; // Both mutable & unmutable versions
  NodeLnk*& FindPointerToSuccessor(NodeLnk*, Data) noexcept; // Both mutable & unmutable versions

};

/* ************************************************************************** */

}

#include "bst.cpp"

#endif

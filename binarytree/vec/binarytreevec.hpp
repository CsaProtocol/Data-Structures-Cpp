
#ifndef BINARYTREEVEC_HPP
#define BINARYTREEVEC_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeVec : virtual public MutableBinaryTree<Data> {

private:

protected:

  using Container::size;
  void Expand();
  void Reduce();
  void upRef();

  lasd::Vector<unsigned long int> nodeXLevel = lasd::Vector<unsigned long int>(0);

struct NodeVec : virtual public MutableBinaryTree<Data>::MutableNode {

  private:

  protected:

    using MutableBinaryTree<Data>::MutableNode::element;
    unsigned long index = 0;

    lasd::Vector<NodeVec*>* ptr;

    //Specific constructor for index
    NodeVec(const Data&, lasd::Vector<NodeVec*>*, const unsigned long int&);

  public:

    friend class BinaryTreeVec<Data>;
    NodeVec(const Data&);
    NodeVec(Data&&) noexcept;

    virtual Data& Element() override;
    bool IsLeaf() const noexcept override;
    bool HasLeftChild() const noexcept override;
    bool HasRightChild() const noexcept override;

    NodeVec& LeftChild() const override;
    NodeVec& RightChild() const override;

  };

protected:
    lasd::Vector<NodeVec*> pointersVecNodes = lasd::Vector<NodeVec*>(0);
    void treeDeletion(NodeVec*&) noexcept;

public:

  // Default constructor
  BinaryTreeVec() = default;

  /* ************************************************************************ */

  // Specific constructors
  BinaryTreeVec(const MappableContainer<Data>&); // A binary tree obtained from a MappableContainer
  BinaryTreeVec(MutableMappableContainer<Data>&); // A binary tree obtained from a MutableMappableContainer

  /* ************************************************************************ */

  // Copy constructor
  BinaryTreeVec(const BinaryTreeVec<Data>&);

  // Move constructor
  BinaryTreeVec(BinaryTreeVec<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  ~BinaryTreeVec();

  /* ************************************************************************ */

  // Copy assignment
  BinaryTreeVec& operator=(const BinaryTreeVec<Data>&);

  // Move assignment
  BinaryTreeVec& operator=(BinaryTreeVec<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BinaryTreeVec<Data>&) const noexcept;
  bool operator!=(const BinaryTreeVec<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  NodeVec& Root() const override final; // Override BinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from MutableBinaryTree)

  NodeVec& Root() override final; // Override MutableBinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  void Clear() override final; // Override ClearableContainer member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member functions (inherited from BreadthFoldableContainer)
  using typename BreadthFoldableContainer<Data>::FoldFunctor;
  void BreadthFold(FoldFunctor, void*) const override final; // Override BreadthFoldableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from BreadthMappableContainer)
  using typename BreadthMappableContainer<Data>::MapFunctor;
  void BreadthMap(MapFunctor); // Override BreadthMappableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableBreadthMappableContainer)
  using typename MutableBreadthMappableContainer<Data>::MutableMapFunctor;
  void BreadthMap(MutableMapFunctor); // Override MutableBreadthMappableContainer member
};

/* ************************************************************************** */

}

#include "binarytreevec.cpp"

#endif

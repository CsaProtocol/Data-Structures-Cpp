
#ifndef BINARYTREELNK_HPP
#define BINARYTREELNK_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeLnk : public virtual MutableBinaryTree<Data> {

private:

protected:

    using Container::size;
    using Container::Empty;
    using Container::Size;

struct NodeLnk : public virtual MutableBinaryTree<Data>::MutableNode { // Must extend MutableNode

  private:

  protected:

      friend class BinaryTreeLnk<Data>;

  public:

      Data element;
      NodeLnk* left;
      NodeLnk* right;

      NodeLnk(const Data&);
      NodeLnk(Data&&) noexcept;

      using MutableBinaryTree<Data>::MutableNode::Element;
      bool HasLeftChild() override;
      bool HasRightChild() override;

      NodeLnk& LeftChild() const override;
      NodeLnk& RightChild() const override;

  };
protected:
    NodeLnk* root = nullptr;
    void rcCopy(NodeLnk**, const NodeLnk*);
    void deleteTree(NodeLnk*&) noexcept;
    void Insert(typename BinaryTreeLnk<Data>::NodeLnk&, Data&);
    NodeLnk* Copy(const BinaryTreeLnk<Data>&);

public:

  // Default constructor
  BinaryTreeLnk() noexcept = default;

  /* ************************************************************************ */

  // Specific constructors
  BinaryTreeLnk(const MappableContainer<Data>&); // A binary tree obtained from a MappableContainer
  BinaryTreeLnk(MutableMappableContainer<Data>&); // A binary tree obtained from a MutableMappableContainer

  /* ************************************************************************ */

  // Copy constructor
  BinaryTreeLnk(const BinaryTreeLnk&);

  // Move constructor
  BinaryTreeLnk(BinaryTreeLnk&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~BinaryTreeLnk() noexcept;

  /* ************************************************************************ */

  // Copy assignment
  BinaryTreeLnk& operator=(const BinaryTreeLnk&);

  // Move assignment
  BinaryTreeLnk& operator=(BinaryTreeLnk&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BinaryTreeLnk<Data>&) const noexcept;
  bool operator!=(const BinaryTreeLnk<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  virtual const NodeLnk& Root() const override final; // Override BinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from MutableBinaryTree)

  virtual NodeLnk& Root() override final; // Override MutableBinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  virtual void Clear() override final; // Override ClearableContainer member

};

/* ************************************************************************** */

}

#include "binarytreelnk.cpp"

#endif

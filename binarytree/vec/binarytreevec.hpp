
#ifndef BINARYTREEVEC_HPP
#define BINARYTREEVEC_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeVec : virtual public MutableBinaryTree<Data> {

protected:
  using BinaryTree<Data>::size;

  struct NodeVec : virtual public MutableBinaryTree<Data>::MutableNode {
    friend class BinaryTreeVec;

  protected:

    unsigned long index = 0;
    Vector<NodeVec*>* btVec = nullptr;
    Data value;

    NodeVec(const Data&);
    NodeVec(Data&&) noexcept;
    NodeVec(const Data& toInsert, unsigned long i, Vector<NodeVec*>*& btVec);

    bool operator==(const NodeVec&) const noexcept;
    bool operator!=(const NodeVec&) const noexcept;

    bool HasLeftChild() const noexcept override;
    bool HasRightChild() const noexcept override;

    virtual const Data& Element() const noexcept { return value; }
    virtual Data& Element() noexcept { return value; }

    virtual const typename BinaryTree<Data>::Node& LeftChild() const;
    virtual const typename BinaryTree<Data>::Node& RightChild() const;

    virtual typename MutableBinaryTree<Data>::MutableNode& LeftChild();
    virtual typename MutableBinaryTree<Data>::MutableNode& RightChild();

  };

  friend NodeVec;
  Vector<NodeVec*>* tree = nullptr;

public:

  BinaryTreeVec();
  BinaryTreeVec(const TraversableContainer<Data>&);
  BinaryTreeVec(MappableContainer<Data>&&) noexcept;

  BinaryTreeVec(const BinaryTreeVec&);
  BinaryTreeVec(BinaryTreeVec&&) noexcept;

  ~BinaryTreeVec() override;

  BinaryTreeVec& operator=(const BinaryTreeVec&);
  BinaryTreeVec& operator=(BinaryTreeVec&&) noexcept;

  bool operator==(const BinaryTreeVec&) const noexcept;
  bool operator!=(const BinaryTreeVec&) const noexcept;

  const typename BinaryTree<Data>::Node& Root() const override;
  typename MutableBinaryTree<Data>::MutableNode& Root() override;

  void Clear() override;

  using typename TraversableContainer<Data>::TraverseFun;
  void BreadthTraverse(TraverseFun) const override;

  using typename MappableContainer<Data>::MapFun;
  void BreadthMap(MapFun) override;

  bool Empty() const noexcept override;

};

/* ************************************************************************** */

}

#include "binarytreevec.cpp"

#endif

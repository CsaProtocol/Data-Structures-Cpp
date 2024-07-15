
#ifndef BINARYTREELNK_HPP
#define BINARYTREELNK_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeLnk : public virtual MutableBinaryTree<Data> {

protected:

  using BinaryTree<Data>::size;

  struct NodeLnk : public virtual MutableBinaryTree<Data>::MutableNode {
    friend class BinaryTreeLnk;

    NodeLnk(NodeLnk* left, NodeLnk* right)
      : left(left),
        right(right) {
    }

    explicit NodeLnk(const Data &value)
      : value(value) {
    }

    ~NodeLnk() override {
      if(this->left != nullptr) delete left;
      if(this->right != nullptr) delete right;
    }

    Data value;
    NodeLnk* left = nullptr;
    NodeLnk* right = nullptr;

    const Data& Element() const noexcept override { return value; }
    Data& Element() noexcept override { return value; }

    const typename BinaryTree<Data>::Node& LeftChild() const override;
    const typename BinaryTree<Data>::Node& RightChild() const override;

    typename MutableBinaryTree<Data>::MutableNode& LeftChild() override;
    typename MutableBinaryTree<Data>::MutableNode& RightChild() override;

  };

  NodeLnk* root = nullptr;

public:

  BinaryTreeLnk() = default;
  BinaryTreeLnk(const TraversableContainer<Data>&);
  BinaryTreeLnk(MappableContainer<Data>&&) noexcept;

  BinaryTreeLnk(const BinaryTreeLnk&);
  BinaryTreeLnk(BinaryTreeLnk&&) noexcept;

  ~BinaryTreeLnk() override;

  BinaryTreeLnk& operator=(const BinaryTreeLnk&);
  BinaryTreeLnk& operator=(BinaryTreeLnk&&) noexcept;

  bool operator==(const BinaryTreeLnk&) const noexcept;
  bool operator!=(const BinaryTreeLnk&) const noexcept;

  const typename BinaryTree<Data>::Node& Root() const override;
  typename MutableBinaryTree<Data>::MutableNode& Root() override;


  void Clear() override;

protected:
  template<typename GLPRvalue>
  // Accepts both glvalue and prvalue
  void AuxConstructorBreadth(QueueVec<NodeLnk*>&, GLPRvalue&& value);
  void AuxCopy(NodeLnk*, const NodeLnk*);
  bool AuxEqual(const NodeLnk*, const NodeLnk*) const noexcept;
};

/* ************************************************************************** */

}

#include "binarytreelnk.cpp"

#endif

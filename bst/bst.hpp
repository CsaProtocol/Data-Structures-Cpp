
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

protected:

  using Container::size;
  using BinaryTreeLnk<Data>::root;
  using NodeLnk = typename BinaryTreeLnk<Data>::NodeLnk;

public:

  BST() = default;
  BST(const TraversableContainer<Data>&);
  BST(MappableContainer<Data>&&);

  BST(const BST&);
  BST(BST&&) noexcept;

  ~BST() override = default;

  BST& operator=(const BST&);
  BST& operator=(BST&&) noexcept;

  bool operator==(const BST&) const noexcept;
  bool operator!=(const BST&) const noexcept;

  virtual const Data& Min() const;
  virtual Data MinNRemove();
  virtual void RemoveMin();

  virtual const Data& Max() const;
  virtual Data MaxNRemove();
  virtual void RemoveMax();

  virtual const Data& Predecessor(const Data&) const;
  virtual Data PredecessorNRemove(const Data&);
  virtual void RemovePredecessor(const Data&);

  virtual const Data& Successor(const Data&) const;
  virtual Data SuccessorNRemove(const Data&);
  virtual void RemoveSuccessor(const Data&);

  bool Insert(const Data&) noexcept override;
  bool Insert(Data&&) noexcept override;
  bool Remove(const Data&) noexcept override;
  bool Exists(const Data&) const noexcept override;

  void Clear() noexcept override;

protected:

  // type DataNDelete(argument) specifiers;

  virtual NodeLnk* Detach(NodeLnk*&) noexcept;

  // type DetachMin(argument) specifiers;
  // type DetachMax(argument) specifiers;

  // type Skip2Left(argument) specifiers;
  // type Skip2Right(argument) specifiers;

  NodeLnk*& FindPointerToMin(NodeLnk*&);
  const NodeLnk*& FindPointerToMin(const NodeLnk*&) const noexcept;
  NodeLnk*& FindPointerToMax(NodeLnk*&);
  const NodeLnk*& FindPointerToMax(const NodeLnk*&) const noexcept;

  const NodeLnk*& FindPointerTo(const Data&, NodeLnk*&) const;
  NodeLnk*& FindPointerTo(const Data&, NodeLnk*&);

  NodeLnk*& FindPointerToPredecessor(const Data&, NodeLnk*&);
  NodeLnk*& FindPointerToSuccessor(const Data&, NodeLnk*&);

  template<typename GLPRvalue>
  bool AuxInsert(GLPRvalue&&) noexcept;
  void AuxDeletion(NodeLnk* toDelete) noexcept {
    toDelete->left = nullptr;
    toDelete->right = nullptr;
    delete toDelete;
  }
};

/* ************************************************************************** */

}

#include "bst.cpp"

#endif

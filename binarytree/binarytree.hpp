
#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/mappable.hpp"

#include "../iterator/iterator.hpp"

#include "../stack/vec/stackvec.hpp"
#include "../queue/vec/queuevec.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTree : virtual public PreOrderTraversableContainer<Data>,
                   virtual public PostOrderTraversableContainer<Data>,
                   virtual public InOrderTraversableContainer<Data>,
                   virtual public BreadthTraversableContainer<Data> {

protected:
  using Container::size;

public:

  struct Node {
  protected:
    bool operator==(const Node&) const noexcept;
    bool operator!=(const Node&) const noexcept;

  public:
    friend class BinaryTree;

    Node() = default;
    virtual ~Node() = default;

    Node& operator=(const Node&) = delete;
    Node& operator=(Node&&) noexcept = delete;

    virtual const Data& Element() const noexcept = 0;
    virtual bool IsLeaf() const noexcept;
    virtual bool HasLeftChild() const noexcept = 0;
    virtual bool HasRightChild() const noexcept = 0;

    virtual const Node& LeftChild() const = 0;
    virtual const Node& RightChild() const = 0;

  };

  ~BinaryTree() override = default;

  BinaryTree& operator=(const BinaryTree&) = delete;
  BinaryTree& operator=(BinaryTree&&) noexcept = delete;

  bool operator==(const BinaryTree&) const noexcept;
  bool operator!=(const BinaryTree&) const noexcept;

  virtual const Node& Root() const = 0;

  using typename TraversableContainer<Data>::TraverseFun;
  void Traverse(TraverseFun) const override;
  void PreOrderTraverse(TraverseFun) const override;
  void PostOrderTraverse(TraverseFun) const override;
  void InOrderTraverse(TraverseFun) const override;
  void BreadthTraverse(TraverseFun) const override;

  using Container::Size;
  using Container::Empty;

protected:
  virtual void PreOrderTraverseAux(TraverseFun, const Node&) const;
  virtual void PostOrderTraverseAux(TraverseFun, const Node&) const;
  virtual void InOrderTraverseAux(TraverseFun, const Node&) const;
  virtual void BreadthTraverseAux(TraverseFun, const Node&) const;
};

/* ************************************************************************** */

template <typename Data>
class MutableBinaryTree : virtual public ClearableContainer,
                          virtual public BinaryTree<Data>,
                          virtual public PreOrderMappableContainer<Data>,
                          virtual public PostOrderMappableContainer<Data>,
                          virtual public InOrderMappableContainer<Data>,
                          virtual public BreadthMappableContainer<Data> {

public:

  struct MutableNode : virtual BinaryTree<Data>::Node {
    friend class MutableBinaryTree;

    MutableNode() = default;
    ~MutableNode() override = default;

    MutableNode& operator=(const MutableNode&) = delete;
    MutableNode& operator=(MutableNode&&) noexcept = delete;

    virtual Data& Element() noexcept = 0;
    using BinaryTree<Data>::Node::Element;

    virtual MutableNode& LeftChild() = 0;
    using BinaryTree<Data>::Node::LeftChild;

    virtual MutableNode& RightChild() = 0;
    using BinaryTree<Data>::Node::RightChild;

  };

  ~MutableBinaryTree() override = default;

  MutableBinaryTree& operator=(const MutableBinaryTree&) = delete;
  MutableBinaryTree& operator=(MutableBinaryTree&&) noexcept = delete;

  using BinaryTree<Data>::Root;
  virtual MutableNode& Root() = 0;

  using typename MappableContainer<Data>::MapFun;
  void Map(MapFun) override;
  void PreOrderMap(MapFun) override;
  void PostOrderMap(MapFun) override;
  void InOrderMap(MapFun) override;
  void BreadthMap(MapFun) override;

};

/* ************************************************************************** */

template <typename Data>
class BTPreOrderIterator : virtual public ForwardIterator<Data>,
                           virtual public ResettableIterator<Data> {
public:
  BTPreOrderIterator(const BinaryTree<Data>&);
  BTPreOrderIterator(const BTPreOrderIterator&);
  BTPreOrderIterator(BTPreOrderIterator&&) noexcept;

  ~BTPreOrderIterator() override = default;

  BTPreOrderIterator& operator=(const BTPreOrderIterator&);
  BTPreOrderIterator& operator=(BTPreOrderIterator&&) noexcept;

  bool operator==(const BTPreOrderIterator&) const noexcept;
  bool operator!=(const BTPreOrderIterator&) const noexcept;

  const Data& operator*() const override;
  bool Terminated() const noexcept override;

  BTPreOrderIterator& operator++() override;
  void Reset() noexcept override;

protected:
  using Node = typename BinaryTree<Data>::Node;
  Node const* current = nullptr;
  Node const* reset = nullptr;
  StackVec<Node const*> itrStack;

};

/* ************************************************************************** */

template <typename Data>
class BTPreOrderMutableIterator : public virtual MutableIterator<Data>,
                                  public virtual BTPreOrderIterator<Data> {
public:
  BTPreOrderMutableIterator(const MutableBinaryTree<Data>& tree);
  BTPreOrderMutableIterator(const BTPreOrderMutableIterator&);
  BTPreOrderMutableIterator(BTPreOrderMutableIterator&&) noexcept;

  ~BTPreOrderMutableIterator() override = default;

  BTPreOrderMutableIterator& operator=(const BTPreOrderMutableIterator&);
  BTPreOrderMutableIterator& operator=(BTPreOrderMutableIterator&&) noexcept;

  bool operator==(const BTPreOrderMutableIterator&) const noexcept;
  bool operator!=(const BTPreOrderMutableIterator&) const noexcept;

  Data& operator*() override;

protected:
  using MutableNode = typename MutableBinaryTree<Data>::MutableNode;
  using BTPreOrderIterator<Data>::current;
  using BTPreOrderIterator<Data>::itrStack;
  using BTPreOrderIterator<Data>::reset;

};

/* ************************************************************************** */

template <typename Data>
class BTPostOrderIterator : virtual public ForwardIterator<Data>,
                            virtual public ResettableIterator<Data> {
protected:
  using Node = typename BinaryTree<Data>::Node;
  Node const* current = nullptr;
  Node const* reset = nullptr;
  StackVec<Node const*> itrStack;

public:
  BTPostOrderIterator(const BinaryTree<Data>&) noexcept;
  BTPostOrderIterator(const BTPostOrderIterator&);
  BTPostOrderIterator(BTPostOrderIterator&&) noexcept;

  ~BTPostOrderIterator() override = default;

  bool operator==(const BTPostOrderIterator&) const noexcept;
  bool operator!=(const BTPostOrderIterator&) const noexcept;

  BTPostOrderIterator& operator=(const BTPostOrderIterator&);
  BTPostOrderIterator& operator=(BTPostOrderIterator&&) noexcept;
  const Data& operator*() const override;

  bool Terminated() const noexcept override;
  BTPostOrderIterator& operator++() override;

  void Reset() noexcept override;

protected:
  Node const* Explore(Node const* node);
};

/* ************************************************************************** */

template <typename Data>
class BTPostOrderMutableIterator : virtual public MutableIterator<Data>,
                                   virtual public BTPostOrderIterator<Data> {

protected:

  using MutableNode = typename MutableBinaryTree<Data>::MutableNode;
  using BTPostOrderIterator<Data>::current;
  using BTPostOrderIterator<Data>::reset;
  using BTPostOrderIterator<Data>::itrStack;

public:

  BTPostOrderMutableIterator(const MutableBinaryTree<Data>& tree) : BTPostOrderIterator<Data>(tree) {}
  BTPostOrderMutableIterator(const BTPostOrderMutableIterator&) = default;
  BTPostOrderMutableIterator(BTPostOrderMutableIterator&&) noexcept = default;

  ~BTPostOrderMutableIterator() override = default;

  BTPostOrderMutableIterator& operator=(const BTPostOrderMutableIterator&) = default;
  BTPostOrderMutableIterator& operator=(BTPostOrderMutableIterator&&) noexcept = default;

  bool operator==(const BTPostOrderMutableIterator&) const noexcept;
  bool operator!=(const BTPostOrderMutableIterator&) const noexcept;

  using BTPostOrderIterator<Data>::operator==;
  using BTPostOrderIterator<Data>::operator!=;
  using BTPostOrderIterator<Data>::operator++;
  using BTPostOrderIterator<Data>::Reset;
  using BTPostOrderIterator<Data>::Terminated;

  Data& operator*() override;

};

/* ************************************************************************** */

template <typename Data>
class BTInOrderIterator : virtual public ForwardIterator<Data>,
                          virtual public ResettableIterator<Data> {
public:
  BTInOrderIterator(const BinaryTree<Data>&);
  BTInOrderIterator(const BTInOrderIterator&);
  BTInOrderIterator(BTInOrderIterator&&) noexcept;

  ~BTInOrderIterator() override = default;
  bool operator==(const BTInOrderIterator&) const noexcept;
  bool operator!=(const BTInOrderIterator&) const noexcept;

  BTInOrderIterator& operator=(const BTInOrderIterator&);
  BTInOrderIterator& operator=(BTInOrderIterator&&) noexcept;

  BTInOrderIterator& operator++() override;
  void Reset() noexcept override;

  const Data& operator*() const override;
  bool Terminated() const noexcept override;

protected:
  using Node = typename BinaryTree<Data>::Node;
  Node const* current = nullptr;
  Node const* reset = nullptr;
  StackVec<Node const*> itrStack;

  Node const* ExploreInOrder(Node const* node);

};

/* ************************************************************************** */

template <typename Data>
class BTInOrderMutableIterator : virtual public MutableIterator<Data>,
                                 virtual public BTInOrderIterator<Data> {
protected:
  using MutableNode = typename MutableBinaryTree<Data>::MutableNode;
  using BTInOrderIterator<Data>::current;
  using BTInOrderIterator<Data>::reset;
  using BTInOrderIterator<Data>::itrStack;

public:
  BTInOrderMutableIterator(const MutableBinaryTree<Data>& tree) noexcept : BTInOrderIterator<Data>(tree) {};
  BTInOrderMutableIterator(const BTInOrderMutableIterator&) = default;
  BTInOrderMutableIterator(BTInOrderMutableIterator&&) noexcept = default;

  ~BTInOrderMutableIterator() override = default;
  bool operator==(const BTInOrderMutableIterator&) const noexcept;
  bool operator!=(const BTInOrderMutableIterator&) const noexcept;

  BTInOrderMutableIterator& operator=(const BTInOrderMutableIterator&) = default;
  BTInOrderMutableIterator& operator=(BTInOrderMutableIterator&&) noexcept = default;

  Data& operator*() override;

};

/* ************************************************************************** */

template <typename Data>
class BTBreadthIterator : virtual public ForwardIterator<Data>,
                          virtual public ResettableIterator<Data> {
public:
  BTBreadthIterator(const BinaryTree<Data>&) noexcept;
  BTBreadthIterator(const BTBreadthIterator&);
  BTBreadthIterator(BTBreadthIterator&&) noexcept;

  ~BTBreadthIterator() override;

  BTBreadthIterator& operator=(const BTBreadthIterator&);
  BTBreadthIterator& operator=(BTBreadthIterator&&) noexcept;

  bool operator==(const BTBreadthIterator&) const noexcept;
  bool operator!=(const BTBreadthIterator&) const noexcept;

  const Data& operator*() const override;
  bool Terminated() const noexcept override;

  BTBreadthIterator& operator++() override;
  void Reset() noexcept override;

protected:
  using Node = typename BinaryTree<Data>::Node;
  const Node* current = nullptr;
  const Node* reset = nullptr;
  QueueVec<Node const*> itrQueue;

};

/* ************************************************************************** */

template <typename Data>
class BTBreadthMutableIterator : virtual public MutableIterator<Data>,
                                 virtual public BTBreadthIterator<Data> {
public:

  BTBreadthMutableIterator(const MutableBinaryTree<Data>& tree) noexcept;
  BTBreadthMutableIterator(const BTBreadthMutableIterator&);
  BTBreadthMutableIterator(BTBreadthMutableIterator&&) noexcept;

  ~BTBreadthMutableIterator() override = default;

  BTBreadthMutableIterator& operator=(const BTBreadthMutableIterator&);
  BTBreadthMutableIterator& operator=(BTBreadthMutableIterator&&) noexcept;

  bool operator==(const BTBreadthMutableIterator&) const noexcept;
  bool operator!=(const BTBreadthMutableIterator&) const noexcept;

  Data& operator*() override;

protected:
  using Node = typename BinaryTree<Data>::Node;
  using BTBreadthIterator<Data>::current;
  using BTBreadthIterator<Data>::reset;
  using BTBreadthIterator<Data>::itrQueue;
};

/* ************************************************************************** */

}

#include "binarytree.cpp"

#endif

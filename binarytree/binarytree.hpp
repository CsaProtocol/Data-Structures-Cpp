
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
    friend class BinaryTree<Data>;

    Node() = default;
    virtual ~Node() = default;
    Node(const Node&) = delete;
    Node(Node&&) = delete;

    virtual const Data& Element() const noexcept = 0;
    inline bool IsLeaf() const noexcept; // NOLINT(*-use-nodiscard)
    bool HasLeftChild() const noexcept; // NOLINT(*-use-nodiscard)
    bool HasRightChild() const noexcept; // NOLINT(*-use-nodiscard)

    inline virtual Node& LeftChild() const = 0;
    inline virtual Node& RightChild() const = 0;

  };

  virtual ~BinaryTree() override = default;

  BinaryTree& operator=(const BinaryTree&) = delete;
  BinaryTree& operator=(BinaryTree&&) = delete;

  virtual bool operator==(const BinaryTree&) const noexcept;
  virtual bool operator!=(const BinaryTree&) const noexcept;

  virtual const Node& Root() const = 0;

  using typename TraversableContainer<Data>::TraverseFun;
  virtual void Traverse(TraverseFun) const override;
  virtual void PreOrderTraverse(TraverseFun) const override;
  virtual void PostOrderTraverse(TraverseFun) const override;
  virtual void InOrderTraverse(TraverseFun) const override;
  virtual void BreadthTraverse(TraverseFun) const override;

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

  struct MutableNode : virtual public BinaryTree<Data>::Node {

    friend class MutableBinaryTree<Data>;

    virtual ~MutableNode() override = default;

    MutableNode& operator=(const MutableNode&) = delete;
    MutableNode& operator=(MutableNode&&) noexcept = delete;

    virtual Data& Element() noexcept = 0;
    virtual MutableNode& LeftChild() = 0;
    virtual MutableNode& RightChild() = 0;

  };

  virtual ~MutableBinaryTree() override = default;

  MutableBinaryTree& operator=(const MutableBinaryTree&) = delete;
  MutableBinaryTree& operator=(MutableBinaryTree&&) noexcept = delete;

  virtual MutableNode& Root() = 0;

  using typename MappableContainer<Data>::MapFun;
  virtual void Map(MapFun) override;
  virtual void PreOrderMap(MapFun) override;
  virtual void PostOrderMap(MapFun) override;
  virtual void InOrderMap(MapFun) override;
  virtual void BreadthMap(MapFun) override;

};

/* ************************************************************************** */

template <typename Data>
class BTPreOrderIterator : virtual public ForwardIterator<Data>,
                           virtual public ResettableIterator<Data> {
protected:
  using Node = typename BinaryTree<Data>::Node;
  Node const* current = nullptr;
  Node const* reset = nullptr;
  StackVec<Node const*> itrStack;

public:

  BTPreOrderIterator(const BinaryTree<Data>&) noexcept;
  BTPreOrderIterator(const BTPreOrderIterator<Data>&) = default;
  BTPreOrderIterator(BTPreOrderIterator<Data>&&) noexcept = default;

  virtual ~BTPreOrderIterator() override = default;

  BTPreOrderIterator& operator=(const BTPreOrderIterator<Data>&) = default;
  BTPreOrderIterator& operator=(BTPreOrderIterator<Data>&&) noexcept = default;

  virtual bool operator==(const BTPreOrderIterator<Data>&) const noexcept;
  virtual bool operator!=(const BTPreOrderIterator<Data>&) const noexcept;

  virtual const Data& operator*() const override;
  virtual bool Terminated() const noexcept override;

  virtual BTPreOrderIterator& operator++() override;
  virtual void Reset() noexcept override;

};

/* ************************************************************************** */

template <typename Data>
class BTPreOrderMutableIterator : public virtual MutableIterator<Data>,
                                  public virtual BTPreOrderIterator<Data> {
protected:
  using MutableNode = typename MutableBinaryTree<Data>::MutableNode;
  using BTPreOrderIterator<Data>::current;
  using BTPreOrderIterator<Data>::itrStack;
  using BTPreOrderIterator<Data>::reset;

public:
  BTPreOrderMutableIterator(const MutableBinaryTree<Data>& tree) noexcept : BTPreOrderIterator<Data>(tree) {};
  BTPreOrderMutableIterator(const BTPreOrderMutableIterator&) = default;
  BTPreOrderMutableIterator(BTPreOrderMutableIterator&&) = default;
  virtual ~BTPreOrderMutableIterator() override = default;

  BTPreOrderMutableIterator& operator=(const BTPreOrderMutableIterator&) = default;
  BTPreOrderMutableIterator& operator=(BTPreOrderMutableIterator&&) noexcept = default;

  using BTPreOrderIterator<Data>::operator==;
  using BTPreOrderIterator<Data>::operator!=;
  using BTPreOrderIterator<Data>::operator++;
  using BTPreOrderIterator<Data>::Reset;
  using BTPreOrderIterator<Data>::Terminated;

  virtual Data& operator*() override;

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
  BTPostOrderIterator(const BTPostOrderIterator&) = default;
  BTPostOrderIterator(BTPostOrderIterator&&) = default;
  virtual ~BTPostOrderIterator() override = default;

  virtual bool operator==(const BTPostOrderIterator&) const noexcept;
  virtual bool operator!=(const BTPostOrderIterator&) const noexcept;

  BTPostOrderIterator& operator=(const BTPostOrderIterator&) = default;
  BTPostOrderIterator& operator=(BTPostOrderIterator&&) = default;
  virtual const Data& operator*() const override;

  virtual bool Terminated() const noexcept override;
  virtual BTPostOrderIterator& operator++() override;

  virtual void Reset() noexcept override;

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
  BTPostOrderMutableIterator(BTPostOrderMutableIterator&&) = default;

  virtual ~BTPostOrderMutableIterator() override = default;

  BTPostOrderMutableIterator& operator=(const BTPostOrderMutableIterator&) = default;
  BTPostOrderMutableIterator& operator=(BTPostOrderMutableIterator&&) = default;

  bool operator==(const BTPostOrderMutableIterator&) const noexcept;
  bool operator!=(const BTPostOrderMutableIterator&) const noexcept;

  using BTPostOrderIterator<Data>::operator==;
  using BTPostOrderIterator<Data>::operator!=;
  using BTPostOrderIterator<Data>::operator++;
  using BTPostOrderIterator<Data>::Reset;
  using BTPostOrderIterator<Data>::Terminated;

  virtual Data& operator*() override;

};

/* ************************************************************************** */

template <typename Data>
class BTInOrderIterator : virtual public ForwardIterator<Data>,
                          virtual public ResettableIterator<Data> {

protected:
  using Node = typename BinaryTree<Data>::Node;
  Node const* current = nullptr;
  Node const* reset = nullptr;
  StackVec<Node const*> itrStack;

public:
  BTInOrderIterator(const BinaryTree<Data>&) noexcept;
  BTInOrderIterator(const BTInOrderIterator&) = default;
  BTInOrderIterator(BTInOrderIterator&&) = default;

  virtual ~BTInOrderIterator() override = default;
  virtual bool operator==(const BTInOrderIterator&) const noexcept;
  virtual bool operator!=(const BTInOrderIterator&) const noexcept;

  BTInOrderIterator& operator=(const BTInOrderIterator&) = default;
  BTInOrderIterator& operator=(BTInOrderIterator&&) = default;

  virtual BTInOrderIterator& operator++() override;
  virtual void Reset() noexcept override;

  virtual const Data& operator*() const override;
  virtual bool Terminated() const noexcept override;

protected:
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
  BTInOrderMutableIterator(BTInOrderMutableIterator&&) = default;

  virtual ~BTInOrderMutableIterator() override = default;
  virtual bool operator==(const BTInOrderMutableIterator&) const noexcept;
  virtual bool operator!=(const BTInOrderMutableIterator&) const noexcept;

  BTInOrderMutableIterator<Data>& operator=(const BTInOrderMutableIterator&) = default;
  BTInOrderMutableIterator<Data>& operator=(BTInOrderMutableIterator&&) = default;

  Data& operator*() override;

};

/* ************************************************************************** */

template <typename Data>
class BTBreadthIterator : virtual public ForwardIterator<Data>,
                          virtual public ResettableIterator<Data> {

protected:
  using Node = typename BinaryTree<Data>::Node;
  Node const* current = nullptr;
  Node const* reset = nullptr;
  QueueVec<Node const*> itrQueue;

public:
  BTBreadthIterator(const BinaryTree<Data>&) noexcept;
  BTBreadthIterator(const BTBreadthIterator&) = default;
  BTBreadthIterator(BTBreadthIterator&&) = default;

  virtual ~BTBreadthIterator() override = default;

  BTBreadthIterator& operator=(const BTBreadthIterator&) = default;
  BTBreadthIterator& operator=(BTBreadthIterator&&) = default;

  bool operator==(const BTBreadthIterator&) const noexcept;
  bool operator!=(const BTBreadthIterator&) const noexcept;

  virtual const Data& operator*() const override;
  virtual bool Terminated() const noexcept override;

  virtual BTBreadthIterator& operator++() override;
  virtual void Reset() noexcept override;

};

/* ************************************************************************** */

template <typename Data>
class BTBreadthMutableIterator : virtual public MutableIterator<Data>,
                                 virtual public BTBreadthIterator<Data> {

protected:
  using MutableNode = typename MutableBinaryTree<Data>::MutableNode;
  using Node = typename BinaryTree<Data>::Node;
  using BTBreadthIterator<Data>::current;
  using BTBreadthIterator<Data>::reset;
  using BTBreadthIterator<Data>::itrQueue;

public:

  BTBreadthMutableIterator(const MutableBinaryTree<Data>& tree) noexcept : BTBreadthIterator<Data>(tree) {};
  BTBreadthMutableIterator(const BTBreadthMutableIterator&) = default;
  BTBreadthMutableIterator(BTBreadthMutableIterator&&) = default;

  virtual ~BTBreadthMutableIterator() override = default;

  BTBreadthMutableIterator& operator=(const BTBreadthMutableIterator&) = default;
  BTBreadthMutableIterator& operator=(BTBreadthMutableIterator&&) = default;

  bool operator==(const BTBreadthMutableIterator&) const noexcept;
  bool operator!=(const BTBreadthMutableIterator&) const noexcept;

  virtual const Data& operator*() const override;

};

/* ************************************************************************** */

}

#include "binarytree.cpp"

#endif

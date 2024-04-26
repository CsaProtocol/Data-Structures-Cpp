
#ifndef LIST_HPP
#define LIST_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/linear.hpp"
#include "../container/dictionary.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class List : virtual public ClearableContainer,
             virtual public LinearContainer<Data>,
             virtual public DictionaryContainer<Data> {

protected:

  using Container::size;

  struct Node {
    Data value;
    Node* next = nullptr;

    Node(const Data& toInsert) { value = toInsert; }
    Node(Data&& toInsert) { value = std::move(toInsert); }

    Node() = delete;
    Node(const Node&) = delete;
    Node(Node&& node) = delete;
    ~Node() = default;
  };

  Node* head = nullptr;
  Node* tail = nullptr;

public:

  List() = default;
  List(const TraversableContainer<Data>&);
  List(MappableContainer<Data>&&);
  List(const List&) noexcept;
  List(List&&) noexcept;

  virtual ~List() noexcept override;

  List& operator=(const List&) noexcept;
  List& operator=(List&&) noexcept;
  virtual bool operator==(const List&) const noexcept;
  virtual bool operator!=(const List&) const noexcept;
  Data& operator[](unsigned long) override;
  const Data& operator[](unsigned long) const override;

  virtual void InsertAtFront(const Data&);
  virtual void InsertAtFront(Data&&);
  virtual void RemoveFromFront();
  virtual Data FrontNRemove();
  virtual void InsertAtBack(const Data&);
  virtual void InsertAtBack(Data&&);

  void Clear() override;

  virtual bool Insert(const Data&) noexcept override;
  virtual bool Insert(Data&&) noexcept override;
  virtual bool Remove(const Data&) noexcept override;

  virtual const Data& Front() const override;
  virtual Data& Front() override;
  virtual const Data& Back() const override;
  virtual Data& Back() override;

  using typename TraversableContainer<Data>::TraverseFun;
  virtual void Traverse(TraverseFun) const override;
  virtual void PreOrderTraverse(TraverseFun) const override;
  virtual void PostOrderTraverse(TraverseFun) const override;

  using typename MappableContainer<Data>::MapFun;
  virtual void Map(MapFun) override;
  virtual void PreOrderMap(MapFun) override;
  virtual void PostOrderMap(MapFun) override;

protected:
  void PostOrderTraverseAux(Node*, TraverseFun) const;
  void PostOrderMapAux(Node*, MapFun);
};

/* ************************************************************************** */

}

#include "list.cpp"

#endif

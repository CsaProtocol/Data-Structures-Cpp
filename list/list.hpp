
#ifndef LIST_HPP
#define LIST_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/dictionary.hpp"
#include "../container/linear.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class List : virtual public ClearableContainer,
             virtual public DictionaryContainer<Data>,
             virtual public LinearContainer<Data> {

private:

protected:

  using Container::size;

  struct Node {

    // Data
    Data element;
    struct Node* next;

    /* ********************************************************************** */

    // Specific constructors
    // Default
    Node() = default;
    Node(const Data&);
    Node(Data&&) noexcept;

    /* ********************************************************************** */

    // Copy constructor
    Node(const Node&);

    // Move constructor
    Node(Node&&) noexcept;

    /* ********************************************************************** */

    // Destructor
    virtual ~Node() = default;

    /* ********************************************************************** */

    // Comparison operators
    bool operator==(const Node&) const noexcept;
    bool operator!=(const Node&) const noexcept;

    /* ********************************************************************** */

    // Specific member functions

    // ...

  };

  // ...

public:

  // Default constructor
  List();

  /* ************************************************************************ */

  // Specific constructor
  List(const MappableContainer<Data>&); // A list obtained from a MappableContainer
  List(MutableMappableContainer<Data>&&); // A list obtained from a MutableMappableContainer

  /* ************************************************************************ */

  // Copy constructor
  List(const List&);

  // Move constructor
  List(List&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  ~List();

  /* ************************************************************************ */

  // Copy assignment
  List& operator=(const List&);

  // Move assignment
  List& operator=(List &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const List&) const noexcept;
  bool operator!=(const List&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  void InsertAtFront(const Data&); // Copy of the value
  void InsertAtFront(Data&&) noexcept; // Move of the value
  void RemoveFromFront(); // (must throw std::length_error when empty)
  Data& FrontNRemove(); // (must throw std::length_error when empty)

  void InsertAtBack(const Data&); // Copy of the value
  void InsertAtBack(Data&&) noexcept; // Move of the value

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  void Clear() override; // Override ClearableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  bool Insert(const Data &) override; // Copy of the value
  bool Insert(Data &&) override; // Move of the value
  bool Remove(const Data &) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  const Data & operator[](const unsigned long) const override; // Override (NonMutable) LinearContainer member (must throw std::out_of_range when out of range)
  Data & operator[](const unsigned long) override; // Override (Mutable) LinearContainer member (must throw std::out_of_range when out of range)

  const Data& Front() const override; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
  Data& Front() override; // Override (Mutable) LinearContainer member (must throw std::length_error when empty)

  const Data& Back() const override; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
  Data& Back() override; // Override (Mutable) LinearContainer member (must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  bool Exists(const Data&) const noexcept override;

  using typename FoldableContainer<Data>::FoldFunctor;

  //void Fold(FoldFunctor, void*) const override; // Override FoldableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderFoldableContainer)

  //void PreOrderFold(FoldFunctor, void*) const override; // Override PreOrderFoldableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderFoldableContainer)

  //void PostOrderFold(FoldFunctor, void*) const override; // Override PostOrderFoldableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  using typename MappableContainer<Data>::MapFunctor;

  virtual void Map(MapFunctor) const override; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderMappableContainer)

  virtual void PreOrderMap(MapFunctor) const override; // Override PreOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderMappableContainer)

  virtual void PostOrderMap(MapFunctor) const override; // Override PostOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from MutableMappableContainer)

  using typename MutableMappableContainer<Data>::MutableMapFunctor;

  virtual void Map(MutableMapFunctor) override;

  /* ************************************************************************ */

  // Specific member function (inherited from MutablePreOrderMappableContainer)

  virtual void PreOrderMap(MutableMapFunctor) override; // Override MutablePreOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from MutablePostOrderMappableContainer)

  virtual void PostOrderMap(MutableMapFunctor) override; // Override MutablePostOrderMappableContainer member

  

protected:

  // Auxiliary member functions (for PreOrderFoldableContainer & PostOrderFoldableContainer)

  void PreOrderFold(FoldFunctor, void*, Node*); // Accessory function executing from one point of the list onwards
  void PostOrderFold(FoldFunctor, void*, Node*); // Accessory function executing from one point of the list onwards

  /* ************************************************************************ */

  // Auxiliary member functions (for PreOrderMappableContainer & PostOrderMappableContainer)

  virtual void PreOrderMap(MapFunctor, Node*) const; // Accessory function executing from one point of the list onwards
  virtual void PostOrderMap(MapFunctor, Node*) const; // Accessory function executing from one point of the list onward

  /* ************************************************************************ */

  // Auxiliary member functions (for MutablePreOrderMappableContainer & MutablePostOrderMappableContainer)

  virtual void PreOrderMap(MutableMapFunctor, Node*); // Accessory function executing from one point of the list onwards
  virtual void PostOrderMap(MutableMapFunctor, Node*); // Accessory function executing from one point of the list onward

  /* ************************************************************************ */

  struct Node* First;
  struct Node* Last;
};

/* ************************************************************************** */

}

#include "list.cpp"

#endif

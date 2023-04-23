
#ifndef STACKLST_HPP
#define STACKLST_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackLst : public Stack<Data>,
                 public List<Data> {

private:

protected:

  using List<Data>::size;

public:

  // Default constructor
  StackLst();

  /* ************************************************************************ */

  // Specific constructor
  StackLst(const MappableContainer<Data>&); // A stack obtained from a MappableContainer
  StackLst(const MutableMappableContainer<Data>&); // A stack obtained from a MutableMappableContainer

  /* ************************************************************************ */

  // Copy constructor
  StackLst(const StackLst&);

  // Move constructor
  StackLst(StackLst&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  ~StackLst() = default;

  /* ************************************************************************ */

  // Copy assignment
  StackLst& operator=(const StackLst&);

  // Move assignment
  StackLst& operator=(StackLst&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const StackLst&) const noexcept;
  bool operator!=(const StackLst&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Stack)

  const Data& Top() const override; // Override Stack member (non-mutable version; must throw std::length_error when empty)
  Data& Top() override; // Override Stack member (mutable version; must throw std::length_error when empty)
  void Pop() override; // Override Stack member (must throw std::length_error when empty)
  Data TopNPop() override; // Override Stack member (must throw std::length_error when empty)
  void Push(const Data &) override; // Override Stack member (copy of the value)
  void Push(Data&&) override; // Override Stack member (move of the value)

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  using List<Data>::Clear;
  using List<Data>::Size;
  using List<Data>::Empty;

};

/* ************************************************************************** */

}

#include "stacklst.cpp"

#endif

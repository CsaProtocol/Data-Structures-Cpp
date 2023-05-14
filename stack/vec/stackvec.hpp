
#ifndef STACKVEC_HPP
#define STACKVEC_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackVec : virtual public Stack<Data>,
                 virtual public Vector<Data> {

private:

protected:

  using Container::size;
  using Vector<Data>::element;
  unsigned long top = 0;

public:

  // Default constructor
  StackVec();

  /* ************************************************************************ */

  // Specific constructor
  StackVec(const MappableContainer<Data>&); // A stack obtained from a MappableContainer
  StackVec(MutableMappableContainer<Data>&&); // A stack obtained from a MutableMappableContainer

  /* ************************************************************************ */

  // Copy constructor
  StackVec(const StackVec&);

  // Move constructor
  StackVec(StackVec&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  ~StackVec() noexcept = default;

  /* ************************************************************************ */

  // Copy assignment
  StackVec& operator=(const StackVec&);

  // Move assignment
  StackVec& operator=(StackVec&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const StackVec&) const noexcept;
  bool operator!=(const StackVec&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from StackQueue)

  virtual const Data& Top() const override; // Override StackQueue member (non-mutable version; must throw std::length_error when empty)
  virtual Data& Top() override; // Override StackQueue member (non-mutable version; must throw std::length_error when empty)
  virtual void Pop() override; // Override StackQueue member (must throw std::length_error when empty)
  virtual Data TopNPop() override; // Override StackQueue member (must throw std::length_error when empty)
  virtual void Push(const Data&) override; // Override StackQueue member (copy of the value)
  virtual void Push(Data&&) override; // Override StackQueue member (move of the value)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  virtual bool Empty() const noexcept override; // Override Container member

  virtual unsigned long Size() const noexcept override; // Override Container member

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  virtual void Clear() noexcept override; // Override ClearableContainer member

protected:

  // Auxiliary member functions

  void Expand();
  void Reduce();

};

/* ************************************************************************** */

}

#include "stackvec.cpp"

#endif

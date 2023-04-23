
#ifndef QUEUEVEC_HPP
#define QUEUEVEC_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueVec : public virtual Queue<Data>,
                 protected virtual Vector<Data> {

private:

protected:

  using Vector<Data>::element;
  using Container::size;
  unsigned long head = 0;
  unsigned long tail = 0;
  unsigned long length = 0;

public:

  // Default constructor
  QueueVec();

  /* ************************************************************************ */

  // Specific constructor
  QueueVec(const MappableContainer<Data>&); // A queue obtained from a MappableContainer
  QueueVec(MutableMappableContainer<Data>&); // A queue obtained from a MutableMappableContainer

  /* ************************************************************************ */

  // Copy constructor
  QueueVec(const QueueVec&);

  // Move constructor
  QueueVec(QueueVec&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~QueueVec();

  /* ************************************************************************ */

  // Copy assignment
  QueueVec& operator=(const QueueVec&);

  // Move assignment
  QueueVec& operator=(QueueVec&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const QueueVec&) const noexcept;
  bool operator!=(const QueueVec&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Queue)

  const Data& Head() const override; // Override Queue member (non-mutable version; must throw std::length_error when empty)
  Data& Head() override; // Override Queue member (mutable version; must throw std::length_error when empty)
  void Dequeue() override; // Override Queue member (must throw std::length_error when empty)
  Data HeadNDequeue() override; // Override Queue member (must throw std::length_error when empty)
  void Enqueue(const Data&) override; // Override Queue member (copy of the value)
  void Enqueue(Data&&) noexcept override; // Override Queue member (move of the value)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)
  bool Empty() const noexcept override; // Override Container member

  unsigned long Size() const noexcept override; // Override Container member

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  void Clear() override; // Override ClearableContainer member

protected:

  // Auxiliary member functions

  void Expand();
  void Reduce();
  void SwapVectors(unsigned long);

};

/* ************************************************************************** */

}

#include "queuevec.cpp"

#endif

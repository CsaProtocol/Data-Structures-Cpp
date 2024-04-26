
#ifndef STACKLST_HPP
#define STACKLST_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackLst : virtual public Stack<Data>,
                 virtual public List<Data> {

protected:

  using List<Data>::head;
  using List<Data>::tail;
  using List<Data>::size;
  using List<Data>::Node;

public:

  StackLst() = default;
  StackLst(const TraversableContainer<Data>&);
  StackLst(MappableContainer<Data>&&) noexcept;
  StackLst(const StackLst<Data>&);
  StackLst(StackLst<Data>&&) noexcept;

  virtual ~StackLst() override;

  StackLst& operator=(const StackLst<Data>&);
  StackLst& operator=(StackLst<Data>&&) noexcept;

  bool operator==(const StackLst<Data>&) const noexcept;
  bool operator!=(const StackLst<Data>&) const noexcept;

  virtual const Data& Top() const override;
  virtual Data& Top() override;
  virtual void Pop() override;
  virtual Data TopNPop() override;
  virtual void Push(const Data&) override;
  virtual void Push(Data&&) override;

  using List<Data>::Clear;

};

/* ************************************************************************** */

}

#include "stacklst.cpp"

#endif

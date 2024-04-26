
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

protected:
	using Container::size;
  using Vector<Data>::elements;

private:
	unsigned long stackRealSize = 0;

public:

  StackVec();
  StackVec(const TraversableContainer<Data>&);
  StackVec(MappableContainer<Data>&&);
  StackVec(const StackVec<Data>&);
  StackVec(StackVec<Data>&&) noexcept;

  virtual ~StackVec() override; //TODO - da considerare usare default

  StackVec& operator=(const StackVec<Data>&);
  StackVec& operator=(StackVec<Data>&&) noexcept;

  virtual bool operator==(const StackVec<Data>&) const noexcept;
  virtual bool operator!=(const StackVec<Data>&) const noexcept;

  virtual const Data& Top() const override;
  virtual Data& Top() override;
  virtual void Pop() override;
  virtual Data TopNPop() override;
  virtual void Push(const Data&) override;
  virtual void Push(Data&&) override;

  virtual bool Empty() const noexcept override;
  virtual unsigned long Size() const noexcept override;
  virtual void Clear() override;

};

/* ************************************************************************** */

}

#include "stackvec.cpp"

#endif


#ifndef QUEUELST_HPP
#define QUEUELST_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueLst : virtual protected List<Data>,
                 virtual public Queue<Data> {

protected:
  using List<Data>::head;
  using List<Data>::tail;
  using List<Data>::Node;
	using List<Data>::operator[];

public:
  QueueLst() = default;
  QueueLst(const TraversableContainer<Data>&);
  QueueLst(MappableContainer<Data>&&);
  QueueLst(const QueueLst&);
  QueueLst(QueueLst&&) noexcept;

  virtual ~QueueLst() override = default;

  QueueLst& operator=(const QueueLst&);
  QueueLst& operator=(QueueLst&&) noexcept;

  bool operator==(const QueueLst&) const noexcept;
  bool operator!=(const QueueLst&) const noexcept;

  const Data& Head() const override;
  Data& Head() override;
  void Dequeue() override;
  Data HeadNDequeue() override;
  void Enqueue(const Data&) override;
  void Enqueue(Data&&) override;

  bool Empty() const noexcept override;
  unsigned long Size() const noexcept override;

  using List<Data>::Clear;

};

/* ************************************************************************** */

}

#include "queuelst.cpp"

#endif


#ifndef QUEUEVEC_HPP
#define QUEUEVEC_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueVec : virtual public Vector<Data>,
                 virtual public Queue<Data> {

protected:
	using Container::size;
  using Vector<Data>::elements;
	unsigned long queueRealSize = 0;

private:
	unsigned long queueHead = 0;


public:
  QueueVec();
  QueueVec(const TraversableContainer<Data>&);
  QueueVec(MappableContainer<Data>&&);
  QueueVec(const QueueVec&);
  QueueVec(QueueVec&&) noexcept;

  virtual ~QueueVec() override = default;

  QueueVec& operator=(const QueueVec&);
  QueueVec& operator=(QueueVec&&) noexcept;

  bool operator==(const QueueVec&) const noexcept;
  bool operator!=(const QueueVec&) const noexcept;

  const Data& Head() const override;
  Data& Head() override;
  void Dequeue() override;
  Data HeadNDequeue() override;
  void Enqueue(const Data&) override;
  void Enqueue(Data&&) override;

  bool Empty() const noexcept override;
  unsigned long Size() const noexcept override;
  void Clear() override;
};

/* ************************************************************************** */

}

#include "queuevec.cpp"

#endif

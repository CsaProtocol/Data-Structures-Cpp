
#ifndef ITERATOR_HPP
#define ITERATOR_HPP

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Iterator {
public:

  Iterator() = default;
  Iterator(const Iterator&) = delete;
  Iterator(Iterator&&) = delete;
  virtual ~Iterator() = default;

  Iterator& operator=(const Iterator&) = delete;
  Iterator& operator=(Iterator&&) = delete;

  bool operator==(const Iterator&) const noexcept = delete;
  bool operator!=(const Iterator&) const noexcept = delete;

  virtual const Data& operator*() const = 0;
  virtual bool Terminated() const noexcept = 0;

};

/* ************************************************************************** */

template <typename Data>
class MutableIterator : virtual public Iterator<Data> {

public:

  MutableIterator() = default;
  MutableIterator(const MutableIterator&) = default;
  MutableIterator(MutableIterator&&) = default;
  virtual ~MutableIterator() override = default;

  MutableIterator& operator=(const MutableIterator&) = delete;
  MutableIterator& operator=(MutableIterator&&) = delete;

  bool operator==(const MutableIterator&) const noexcept = delete;

  virtual Data& operator*() = 0;

};

/* ************************************************************************** */

template <typename Data>
class ForwardIterator : virtual public Iterator<Data>{

public:

  ForwardIterator() = default;
  ForwardIterator(const ForwardIterator&) = default;
  ForwardIterator(ForwardIterator&&) = default;
  virtual ~ForwardIterator() = default;

  ForwardIterator& operator=(const ForwardIterator&) = delete;
  ForwardIterator& operator=(ForwardIterator&&) = delete;

  bool operator==(const ForwardIterator&) const noexcept = delete;
  bool operator!=(const ForwardIterator&) const noexcept = delete;

  virtual ForwardIterator& operator++() = 0;
};

/* ************************************************************************** */

template <typename Data>
class ResettableIterator : virtual public Iterator<Data> {

public:

  ResettableIterator() = default;
  ResettableIterator(const ResettableIterator&) = default;
  ResettableIterator(ResettableIterator&&) = default;
  virtual ~ResettableIterator() = default;

  ResettableIterator& operator=(const ResettableIterator&) = delete;
  ResettableIterator& operator=(ResettableIterator&&) = delete;

  bool operator==(const ResettableIterator&) const noexcept = delete;
  bool operator!=(const ResettableIterator&) const noexcept = delete;

  virtual void Reset() noexcept = 0;

};

/* ************************************************************************** */

}

#endif

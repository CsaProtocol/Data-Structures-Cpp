
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
  Iterator(Iterator&&) noexcept = delete;
  virtual ~Iterator() = default;

  Iterator& operator=(const Iterator&) = delete;
  Iterator& operator=(Iterator&&) noexcept = delete;

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
  MutableIterator(const MutableIterator&) = delete;
  MutableIterator(MutableIterator&&) noexcept = delete;
  ~MutableIterator() override = default;

  MutableIterator& operator=(const MutableIterator&) = delete;
  MutableIterator& operator=(MutableIterator&&) noexcept = delete;

  bool operator==(const MutableIterator&) const noexcept = delete;
  bool operator!=(const MutableIterator&) const noexcept = delete;

  virtual Data& operator*() = 0;

};

/* ************************************************************************** */

template <typename Data>
class ForwardIterator : virtual public Iterator<Data>{

public:

  ForwardIterator() = default;
  ForwardIterator(const ForwardIterator&) = default;
  ForwardIterator(ForwardIterator&&) noexcept = default;
  virtual ~ForwardIterator() = default;

  ForwardIterator& operator=(const ForwardIterator&) = delete;
  ForwardIterator& operator=(ForwardIterator&&) noexcept = delete;

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
  ResettableIterator(ResettableIterator&&) noexcept = default;
  virtual ~ResettableIterator() = default;

  ResettableIterator& operator=(const ResettableIterator&) = delete;
  ResettableIterator& operator=(ResettableIterator&&) noexcept = delete;

  bool operator==(const ResettableIterator&) const noexcept = delete;
  friend bool operator!=(const ResettableIterator&) noexcept = delete;

  virtual void Reset() noexcept = 0;

};

/* ************************************************************************** */

}

#endif

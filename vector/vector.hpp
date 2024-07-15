
#ifndef VECTOR_HPP
#define VECTOR_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/linear.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Vector : virtual public ResizableContainer,
               virtual public LinearContainer<Data> {

protected:

  using Container::size;
  Data* elements = nullptr;

public:

  Vector() = default;
  Vector(ulong);
  Vector(const TraversableContainer<Data>&);
  Vector(MappableContainer<Data>&&);

  Vector(const Vector&);
  Vector(Vector&&) noexcept;

  ~Vector() override;

  Vector& operator=(const Vector&) noexcept;
  Vector& operator=(Vector&&) noexcept;

  bool operator==(const Vector&) const noexcept;
  bool operator!=(const Vector &) const noexcept;

  void Clear() override;
  void Resize(ulong) override;

  const Data& operator[](ulong) const override;
  Data& operator[](ulong) override;

  const Data& Front() const override;
  Data& Front() override;
  const Data& Back() const override;
  Data& Back() override;

};

/* ************************************************************************** */

template <typename Data>
class SortableVector : virtual public Vector<Data>,
                       virtual public SortableLinearContainer<Data> {

protected:

  using Container::size;

public:

  SortableVector() = default;
  SortableVector(ulong);
  SortableVector(const TraversableContainer<Data>&);
  SortableVector(MappableContainer<Data>&&);

  SortableVector(const SortableVector&);
  SortableVector(SortableVector&&) noexcept;

  ~SortableVector() override;

  SortableVector& operator=(const SortableVector&);
  SortableVector& operator=(SortableVector&&) noexcept;

  bool operator==(const SortableVector&) const noexcept;
  bool operator!=(const SortableVector&) const noexcept;

};

/* ************************************************************************** */

}

#include "vector.cpp"

#endif

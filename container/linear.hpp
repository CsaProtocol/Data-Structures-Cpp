
#ifndef LINEAR_HPP
#define LINEAR_HPP

/* ************************************************************************** */

#include "mappable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class LinearContainer : virtual public MutablePreOrderMappableContainer<Data>,
                        virtual public MutablePostOrderMappableContainer<Data> {

private:

protected:

  using Container::size;

public:

  // Destructor
  virtual ~LinearContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  LinearContainer & operator=(const LinearContainer &) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  LinearContainer & operator=(LinearContainer &&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  virtual bool operator==(const LinearContainer &) const noexcept; // Comparison of abstract types is possible.
  virtual bool operator!=(const LinearContainer &) const noexcept; // Comparison of abstract types is possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual const Data & operator[](unsigned long) const = 0; // (non-mutable version; concrete function must throw std::out_of_range when out of range)
  virtual Data & operator[](unsigned long) = 0; // (mutable version; concrete function must throw std::out_of_range when out of range)

  inline virtual const Data & Front() const = 0; // (non-mutable version; concrete function must throw std::length_error when empty)
  inline virtual Data & Front() = 0; // (mutable version; concrete function must throw std::length_error when empty)

  inline virtual const Data & Back() const = 0; // (non-mutable version; concrete function must throw std::length_error when empty)
  inline virtual Data & Back() = 0; // (mutable version; concrete function must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  using typename FoldableContainer<Data>::FoldFunctor;

  inline void Fold(FoldFunctor, void *) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderFoldableContainer)

  inline void PreOrderFold(FoldFunctor, void *) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderFoldableContainer)

  inline void PostOrderFold(FoldFunctor, void *) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  using typename MappableContainer<Data>::MapFunctor;

  inline void Map(MapFunctor) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderMappableContainer)

  inline void PreOrderMap(MapFunctor) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderMappableContainer)

  inline void PostOrderMap(MapFunctor) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from MutableMappableContainer)

  using typename MutableMappableContainer<Data>::MutableMapFunctor;

  inline void Map(MutableMapFunctor) override;

  /* ************************************************************************ */

  // Specific member function (inherited from MutablePreOrderMappableContainer)

  inline void PreOrderMap(MutableMapFunctor) override;

  /* ************************************************************************ */

  // Specific member function (inherited from MutablePostOrderMappableContainer)

  inline void PostOrderMap(MutableMapFunctor) override; // Override MutablePostOrderMappableContainer member

};

/* ************************************************************************** */

template <typename Data>
class SortableLinearContainer : virtual public LinearContainer<Data> {

private:

protected:

public:

  // Destructor
  virtual ~SortableLinearContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  SortableLinearContainer & operator=(const SortableLinearContainer &) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  SortableLinearContainer & operator=(SortableLinearContainer &&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  using LinearContainer<Data>::operator==;
  using LinearContainer<Data>::operator!=;

  /* ************************************************************************ */

  // Specific member function

  virtual void Sort() noexcept = 0;

};

/* ************************************************************************** */

}

#include "linear.cpp"

#endif

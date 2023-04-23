
#ifndef MAPPABLE_HPP
#define MAPPABLE_HPP

/* ************************************************************************** */

#include <functional>

/* ************************************************************************** */

#include "foldable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class MappableContainer: virtual public FoldableContainer<Data> {

private:

protected:

public:

  // Destructor
  virtual ~MappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  MappableContainer& operator=(const MappableContainer&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  MappableContainer& operator=(MappableContainer&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const MappableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const MappableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function

  using MapFunctor = std::function<void(const Data &)>;

  virtual void Map(MapFunctor) const = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  using typename FoldableContainer<Data>::FoldFunctor;

  virtual void Fold(FoldFunctor, void*) const override = 0;

};

/* ************************************************************************** */

template <typename Data>
class PreOrderMappableContainer : virtual public MappableContainer<Data>,
                                  virtual public PreOrderFoldableContainer<Data> {

private:

protected:

public:

  // Destructor
  virtual ~PreOrderMappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  PreOrderMappableContainer& operator=(const PreOrderMappableContainer&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  PreOrderMappableContainer& operator=(PreOrderMappableContainer &&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const PreOrderMappableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const PreOrderMappableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function
  using typename MappableContainer<Data>::MapFunctor;

  virtual void PreOrderMap(MapFunctor) const = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  virtual void Map(MapFunctor) const override; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  using typename FoldableContainer<Data>::FoldFunctor;

  virtual void Fold(FoldFunctor, void*) const override; // Override FoldableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderFoldableContainer)

  virtual void PreOrderFold(FoldFunctor, void*) const override = 0; // Override PreOrderFoldableContainer member

  virtual bool Exists(const Data&) const noexcept override;
  
};

/* ************************************************************************** */

template <typename Data>
class PostOrderMappableContainer : virtual public MappableContainer<Data>,
                                   virtual public PostOrderFoldableContainer<Data> {

private:

protected:

public:

  // Destructor
  virtual ~PostOrderMappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  PostOrderMappableContainer& operator=(const PostOrderMappableContainer&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  PostOrderMappableContainer& operator=(PostOrderMappableContainer &&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const PostOrderMappableContainer&) const noexcept = delete;  // Comparison of abstract types might not be possible.
  bool operator!=(const PostOrderMappableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function

  using typename MappableContainer<Data>::MapFunctor;

  virtual void PostOrderMap(MapFunctor) const = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  virtual void Map(MapFunctor) const override; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  using typename FoldableContainer<Data>::FoldFunctor;
  
  void Fold(FoldFunctor, void*) const override; // Override FoldableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderFoldableContainer)

  virtual void PostOrderFold(FoldFunctor, void*) const override = 0; // Override PostOrderFoldableContainer member

};

/* ************************************************************************** */

template <typename Data>
class InOrderMappableContainer : virtual public MappableContainer<Data>,
                                 virtual public InOrderFoldableContainer<Data> {

private:

protected:

public:

  // Destructor
  virtual ~InOrderMappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  InOrderMappableContainer& operator=(const InOrderMappableContainer&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  InOrderMappableContainer& operator=(InOrderMappableContainer&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const InOrderMappableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const InOrderMappableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function

  using typename MappableContainer<Data>::MapFunctor;

  virtual void InOrderMap(MapFunctor) const = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  virtual void Map(MapFunctor) const override; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  using typename FoldableContainer<Data>::FoldFunctor;

  virtual void Fold(FoldFunctor, void*) const override; // Override FoldableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from InOrderFoldableContainer)

  using InOrderFoldableContainer<Data>::InOrderFold;

};

/* ************************************************************************** */

template <typename Data>
class BreadthMappableContainer {
                                  // Must extend MappableContainer<Data>,
                                  //             BreadthFoldableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~BreadthMappableContainer() specifiers

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function

  // using typename MappableContainer<Data>::MapFunctor;

  // type BreadthMap(argument) specifiers;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  // type Map(argument) specifiers; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  // using typename FoldableContainer<Data>::FoldFunctor;

  // type Fold(arguments) specifiers; // Override FoldableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from BreadthFoldableContainer)

  // type BreadthFold(arguments) specifiers; // Override BreadthFoldableContainer member

};

/* ************************************************************************** */

template <typename Data>
class MutableMappableContainer : virtual public MappableContainer<Data> {

private:

protected:

public:

  // Destructor
  virtual ~MutableMappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  MutableMappableContainer& operator=(const MutableMappableContainer&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  MutableMappableContainer& operator=(MutableMappableContainer&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const MutableMappableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const MutableMappableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function

  using MutableMapFunctor = std::function<void(Data &)>;

  virtual void Map(MutableMapFunctor) = 0;

};

/* ************************************************************************** */

template <typename Data>
class MutablePreOrderMappableContainer : virtual public MutableMappableContainer<Data>,
                                         virtual public PreOrderMappableContainer<Data> {

private:

protected:

public:

  // Destructor
  virtual ~MutablePreOrderMappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  MutablePreOrderMappableContainer& operator=(const MutablePreOrderMappableContainer&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  MutablePreOrderMappableContainer& operator=(MutablePreOrderMappableContainer&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const MutablePreOrderMappableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const MutablePreOrderMappableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function

  using typename MutableMappableContainer<Data>::MutableMapFunctor;

  virtual void PreOrderMap(MutableMapFunctor) = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MutableMappableContainer)

  virtual void Map(MutableMapFunctor) override; // Override MutableMappableContainer member

};

/* ************************************************************************** */

template <typename Data>
class MutablePostOrderMappableContainer : virtual public MutableMappableContainer<Data>,
                                          virtual public PostOrderMappableContainer<Data> {

private:

protected:

public:

  // Destructor
  virtual ~MutablePostOrderMappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  //MutablePostOrderMappableContainer& operator=(const MutableMappableContainer&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  MutablePostOrderMappableContainer& operator=(MutablePostOrderMappableContainer&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const MutablePostOrderMappableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const MutablePostOrderMappableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function

  using typename MutableMappableContainer<Data>::MutableMapFunctor;

  virtual void PostOrderMap(MutableMapFunctor) = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MutableMappableContainer)

  virtual void Map(MutableMapFunctor) override; // Override MutableMappableContainer member

};

/* ************************************************************************** */

template <typename Data>
class MutableInOrderMappableContainer : virtual public MutableMappableContainer<Data>,
                                        virtual public InOrderMappableContainer<Data> {

private:

protected:

public:

  // Destructor
  virtual ~MutableInOrderMappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  MutableInOrderMappableContainer& operator=(const MutableInOrderMappableContainer&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  MutableInOrderMappableContainer& operator=(MutableInOrderMappableContainer&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const MutableInOrderMappableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const MutableInOrderMappableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function

  using typename MutableMappableContainer<Data>::MutableMapFunctor;

  virtual void InOrderMap(MutableMapFunctor) = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MutableMappableContainer)

  virtual void Map(MutableMapFunctor) override; // Override MutableMappableContainer member

};

/* ************************************************************************** */

template <typename Data>
class MutableBreadthMappableContainer : virtual public MutableMappableContainer<Data>,
                                        virtual public BreadthMappableContainer<Data> {

private:

protected:

public:

  // Destructor
  // ~MutableBreadthMappableContainer() specifiers

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function

  // using typename MutableMappableContainer<Data>::MutableMapFunctor;

  // type BreadthMap(argument) specifiers;

  /* ************************************************************************ */

  // Specific member function (inherited from MutableMappableContainer)

  // type Map(argument) specifiers; // Override MutableMappableContainer member

};

/* ************************************************************************** */

}

#include "mappable.cpp"

#endif

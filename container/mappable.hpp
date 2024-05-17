
#ifndef MAPPABLE_HPP
#define MAPPABLE_HPP

/* ************************************************************************** */

#include <functional>

/* ************************************************************************** */

#include "traversable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class MappableContainer : virtual public TraversableContainer<Data> {

public:

  MappableContainer() = default;
  virtual ~MappableContainer() override = default;

  MappableContainer& operator=(const MappableContainer&) = delete;
  MappableContainer& operator=(MappableContainer&&) = delete;

  bool operator==(const MappableContainer&) const noexcept = delete;
  bool operator!=(const MappableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  using MapFun = std::function<void(Data &)>;
  virtual void Map(MapFun) = 0;

};

/* ************************************************************************** */

template <typename Data>
class PreOrderMappableContainer: virtual public MappableContainer<Data>,
                                 virtual public PreOrderTraversableContainer<Data> {

public:

  PreOrderMappableContainer() = default;
  virtual ~PreOrderMappableContainer() override = default;

  PreOrderMappableContainer& operator=(const PreOrderMappableContainer&) = delete;
  PreOrderMappableContainer& operator=(PreOrderMappableContainer&&) = delete;

  bool operator==(PreOrderMappableContainer const&) const noexcept = delete;
  bool operator!=(PreOrderMappableContainer const&) const noexcept = delete;

  using typename MappableContainer<Data>::MapFun;
  virtual void PreOrderMap(MapFun) = 0;

  inline void Map(MapFun fun) override {
    PreOrderMap(fun);
  }

};

/* ************************************************************************** */

template <typename Data>
class PostOrderMappableContainer : virtual public MappableContainer<Data>,
                                   virtual public PostOrderTraversableContainer<Data> {

public:

  PostOrderMappableContainer() = default;
  virtual ~PostOrderMappableContainer() override = default;

  PostOrderMappableContainer& operator=(const PostOrderMappableContainer&) = delete;
  PostOrderMappableContainer& operator=(PostOrderMappableContainer&&) = delete;

  bool operator==(PostOrderMappableContainer const&) const noexcept = delete;
  bool operator!=(PostOrderMappableContainer const&) const noexcept = delete;

  using typename MappableContainer<Data>::MapFun;
  virtual void PostOrderMap(MapFun) = 0;

  inline void Map(MapFun fun) override {
    PostOrderMap(fun);
  }

};

/* ************************************************************************** */

template <typename Data>
class InOrderMappableContainer : virtual public MappableContainer<Data>,
                                 virtual public InOrderTraversableContainer<Data> {

public:

  InOrderMappableContainer() = default;
  virtual ~InOrderMappableContainer() override = default;

  InOrderMappableContainer& operator=(const InOrderMappableContainer&) = delete;
  InOrderMappableContainer& operator=(InOrderMappableContainer&&) = delete;

  bool operator==(const InOrderMappableContainer&) const noexcept = delete;
  bool operator!=(const InOrderMappableContainer&) const noexcept = delete;

  using typename MappableContainer<Data>::MapFun;
  virtual void InOrderMap(MapFun) = 0;

  inline void Map(MapFun fun) override {
    InOrderMap(fun);
  }

};

/* ************************************************************************** */

template <typename Data>
class BreadthMappableContainer : virtual public MappableContainer<Data>,
                                 virtual public BreadthTraversableContainer<Data> {

public:

  BreadthMappableContainer() = default;
  virtual ~BreadthMappableContainer() override = default;

  BreadthMappableContainer& operator=(const BreadthMappableContainer&) = delete;
  BreadthMappableContainer& operator=(BreadthMappableContainer&&) = delete;

  virtual bool operator==(const BreadthMappableContainer&) const noexcept = delete;
  virtual bool operator!=(const BreadthMappableContainer&) const noexcept = delete;

  using typename MappableContainer<Data>::MapFun;
  virtual void BreadthMap(MapFun) = 0;

  inline void Map(MapFun fun) override {
    BreadthMap(fun);
  }

};

/* ************************************************************************** */

}

#include "mappable.cpp"

#endif

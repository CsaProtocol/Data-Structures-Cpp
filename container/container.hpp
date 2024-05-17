
#ifndef CONTAINER_HPP
#define CONTAINER_HPP
#include <sys/types.h>
#include <iostream>

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

class Container {

protected:
  unsigned long size = 0;

  Container() = default;

public:

  virtual ~Container() = default;

  Container& operator=(const Container&) = delete;
  Container& operator=(Container&&) = delete;

  bool operator==(const Container&) const = delete;
  bool operator!=(const Container&) const = delete;

  virtual bool Empty() const noexcept { return(size == 0); }
  virtual unsigned long Size() const noexcept { return size; }

};

/* ************************************************************************** */

class ClearableContainer : public virtual Container {

public:

  ClearableContainer() = default;
  virtual ~ClearableContainer() override = default;

  ClearableContainer& operator=(const ClearableContainer&) = delete;
  ClearableContainer& operator=(ClearableContainer&&) = delete;

  bool operator==(const ClearableContainer&) const noexcept = delete;
  bool operator!=(const ClearableContainer&) const noexcept = delete;

  virtual void Clear() = 0;

};

/* ************************************************************************** */

class ResizableContainer : public virtual ClearableContainer {

public:

  ResizableContainer() = default;
  virtual ~ResizableContainer() override = default;

  ResizableContainer& operator=(const ResizableContainer&) = delete;
  ResizableContainer& operator=(ResizableContainer&&) = delete;

  bool operator==(const ResizableContainer&) const noexcept = delete;
  bool operator!=(const ResizableContainer&) const noexcept = delete;

  virtual void Resize(ulong updatedSize) = 0;

  virtual void Clear() override { Resize(0); }

};

/* ************************************************************************** */

}

#endif

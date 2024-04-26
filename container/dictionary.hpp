
#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

/* ************************************************************************** */

#include "mappable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class DictionaryContainer : virtual public TestableContainer<Data> {

public:

  DictionaryContainer() = default;
  virtual ~DictionaryContainer() override = default;

	DictionaryContainer& operator=(const DictionaryContainer&) = delete;
	DictionaryContainer& operator=(DictionaryContainer&&) = delete;

	bool operator==(const DictionaryContainer&) const noexcept = delete;
	bool operator!=(const DictionaryContainer&) const noexcept = delete;

	virtual bool Insert(const Data&) noexcept = 0;
	virtual bool Insert(Data&&) noexcept = 0;
	virtual bool Remove(const Data&) noexcept = 0;

	virtual bool InsertAll(const TraversableContainer<Data>&) noexcept;
	virtual bool InsertAll(MappableContainer<Data>&&) noexcept;
	virtual bool RemoveAll(const TraversableContainer<Data>&) noexcept;

	virtual bool InsertSome(const TraversableContainer<Data>&) noexcept;
	virtual bool InsertSome(MappableContainer<Data>&&) noexcept;
	virtual bool RemoveSome(const TraversableContainer<Data>&) noexcept;

};

/* ************************************************************************** */

}

#include "dictionary.cpp"

#endif

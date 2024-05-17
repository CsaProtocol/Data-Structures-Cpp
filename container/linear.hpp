#ifndef LINEAR_HPP
#define LINEAR_HPP

/* ************************************************************************** */

#include "mappable.hpp"
#include <stdexcept>

/* ************************************************************************** */

namespace lasd {
	/* ************************************************************************** */

	template<typename Data>
	class LinearContainer : virtual public PreOrderMappableContainer<Data>,
	                        virtual public PostOrderMappableContainer<Data> {
	public:
		LinearContainer() = default;

		virtual ~LinearContainer() override = default;
		LinearContainer &operator=(const LinearContainer &) = delete;
		LinearContainer &operator=(LinearContainer &&) = delete;
		bool operator==(const LinearContainer &) const noexcept;
		bool operator!=(const LinearContainer &) const noexcept;
		virtual const Data& operator[](unsigned long) const = 0;
		virtual Data& operator[](unsigned long) = 0;
		virtual const Data &Front() const;
		virtual Data &Front();
		virtual const Data &Back() const;
		virtual Data &Back();

		using typename TraversableContainer<Data>::TraverseFun;

		void Traverse(TraverseFun) const override;
		void PreOrderTraverse(TraverseFun) const override;
		void PostOrderTraverse(TraverseFun) const override;

		using typename MappableContainer<Data>::MapFun;

		void Map(MapFun) override;
		void PreOrderMap(MapFun) override;
		void PostOrderMap(MapFun) override;
	};

	/* ************************************************************************** */

	template<typename Data>
	class SortableLinearContainer : virtual public LinearContainer<Data> {
	public:

		SortableLinearContainer() = default;
		virtual ~SortableLinearContainer() override = default;
		SortableLinearContainer &operator=(const SortableLinearContainer &) = delete;
		SortableLinearContainer &operator=(SortableLinearContainer &&) = delete;
		bool operator==(const SortableLinearContainer &) const noexcept;
		bool operator!=(const SortableLinearContainer &) const noexcept;
		void Sort() noexcept;

	protected:
	};

	/* ************************************************************************** */
}

#include "linear.cpp"

#endif

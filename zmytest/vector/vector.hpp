
#ifndef PERSONALVECTORTEST_HPP
#define PERSONALVECTORTEST_HPP

#include "../../vector/vector.hpp"
#include "../../zlasdtest/vector/vector.hpp"
#include "../../zlasdtest/container/linear.hpp"
#include "../../zlasdtest/container/container.hpp"
#include "../../zlasdtest/container/testable.hpp"
#include "../../zlasdtest/container/mappable.hpp"
#include "../../zlasdtest/container/traversable.hpp"


namespace zmytest {
	/* ************************************************************************** */

	// Using functions from zlasdtest:
	// EqualVector(uint & testnum, uint & testerr, const lasd::Vector<Data> & vec1, const lasd::Vector<Data> & vec2, bool chk)
	// NonEqualVector(uint & testnum, uint & testerr, const lasd::Vector<Data> & vec1, const lasd::Vector<Data> & vec2, bool chk)
	// SetAt(uint & testnum, uint & testerr, lasd::LinearContainer<Data> & con, bool chk, const ulong & ind, const Data & val)
	void testVector(unsigned int&, unsigned int&);

	/* ************************************************************************** */
}

#endif

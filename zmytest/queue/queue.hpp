#ifndef PERSONALQUEUETEST_HPP
#define PERSONALQUEUETEST_HPP

#include <iostream>
#include "../../queue/queue.hpp"
#include "../../zlasdtest/queue/queue.hpp"
#include "../../zlasdtest/container/container.hpp"
#include "../../zlasdtest/container/testable.hpp"
#include "../../queue/vec/queuevec.hpp"
#include "../../queue/lst/queuelst.hpp"

namespace zmytest {
	void testQueueVector(unsigned int&, unsigned int&);
	void testQueueList(unsigned int&, unsigned int&);
}

#endif

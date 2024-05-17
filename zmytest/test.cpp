#include "vector/vector.hpp"
#include "list/list.hpp"
#include "queue/queue.hpp"
#include "stack/stack.hpp"

namespace zmytest {

	void mytest() {
		unsigned int testnum = 0;
		unsigned int testerr = 0;
		testVector(testnum, testerr);

		testList(testnum, testerr);
		testDictionaryList(testnum, testerr);

		testStackVector(testnum, testerr);
		testStackList(testnum, testerr);

		testQueueVector(testnum, testerr);
		testQueueList(testnum, testerr);
	}

}

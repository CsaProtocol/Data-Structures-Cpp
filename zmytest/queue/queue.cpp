#include "queue.hpp"

namespace zmytest {
	void QueueVecIntTest(unsigned int& testnum, unsigned int& testerr) {
	}

	void QueueVecDoubleTest(unsigned int& testnum, unsigned int& testerr) {
	}

	void QueueVecStringTest(unsigned int& testnum, unsigned int& testerr) {
	}

	void QueueVecBoolTest(unsigned int& testnum, unsigned int& testerr) {
	}

	void testQueueVector(unsigned int& testnum, unsigned int& testerr) {
		std::cout << "Testing QueueVec<int>" << std::endl;
		QueueVecIntTest(testnum, testerr);

		std::cout << "Testing QueueVec<double>" << std::endl;
		QueueVecDoubleTest(testnum, testerr);

		std::cout << "Testing QueueVec<std::string>" << std::endl;
		QueueVecStringTest(testnum, testerr);

		std::cout << "Testing QueueVec<bool>" << std::endl;
		QueueVecBoolTest(testnum, testerr);
	}


	void QueueLstIntTest(unsigned int& testnum, unsigned int& testerr) {
	}

	void QueueLstDoubleTest(unsigned int& testnum, unsigned int& testerr) {
	}

	void QueueLstStringTest(unsigned int& testnum, unsigned int& testerr) {
	}

	void QueueLstBoolTest(unsigned int& testnum, unsigned int& testerr) {
	}

	void testQueueList(unsigned int& testnum, unsigned int& testerr) {
		std::cout << "Testing QueueLst<int>" << std::endl;
		QueueLstIntTest(testnum, testerr);

		std::cout << "Testing QueueLst<double>" << std::endl;
		QueueLstDoubleTest(testnum, testerr);

		std::cout << "Testing QueueLst<std::string>" << std::endl;
		QueueLstStringTest(testnum, testerr);

		std::cout << "Testing QueueLst<bool>" << std::endl;
		QueueLstBoolTest(testnum, testerr);
	}
}
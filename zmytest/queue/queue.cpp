#include "queue.hpp"

void QueueVecIntTest(unsigned int& testnum, unsigned int& testerr) {
	lasd::QueueVec<int> que;
	lasd::QueueVec<int> equalque;
	Empty(testnum, testerr, que, true);
	EqualQueue(testnum, testerr, que, equalque, true);

	lasd::QueueVec<int> que2;
	for (int i = 0; i < 10; ++i) {
		EnqueueC(testnum, testerr, que2, i);
	}
	Empty(testnum, testerr, que2, false);
	Size(testnum, testerr, que2, true, 10);

	que2.Clear();
	for (int i = 0; i < 3; ++i) {
		EnqueueC(testnum, testerr, que2, i);
	}
	NonEqualQueue(testnum, testerr, que, que2, true);
	EnqueueC(testnum, testerr, que, 3);	EnqueueC(testnum, testerr, que2, 3);
	NonEqualQueue(testnum, testerr, que, que2, true);

	lasd::QueueVec<int> que3(que);
	lasd::QueueVec<int> que4(std::move(que));
	EqualQueue(testnum, testerr, que3, que4, true);
	EqualQueue(testnum, testerr, que, que4, false);
	EnqueueC(testnum, testerr, que4, 150);
	Head(testnum, testerr, que4, true, 3);
	Dequeue(testnum, testerr, que4, true);
	HeadNDequeue(testnum, testerr, que4, true, 150);
	Empty(testnum, testerr, que4, true);

	EnqueueC(testnum, testerr, que4, 1);
	EnqueueC(testnum, testerr, que4, 2);
	Head(testnum, testerr, que4, true, 1);
}

void QueueVecDoubleTest(unsigned int& testnum, unsigned int& testerr) {
	lasd::QueueVec<double> que;
	lasd::QueueVec<double> equalque;
	Empty(testnum, testerr, que, true);
	EqualQueue(testnum, testerr, que, equalque, true);

	lasd::QueueVec<double> que2;
	for (int i = 0; i < 10; ++i) {
		EnqueueC(testnum, testerr, que2, i * 0.1);
	}
	Empty(testnum, testerr, que2, false);
	Size(testnum, testerr, que2, true, 10);

	que2.Clear();
	for (int i = 0; i < 3; ++i) {
		EnqueueC(testnum, testerr, que2, i * 0.1);
	}
	NonEqualQueue(testnum, testerr, que, que2, true);
	EnqueueC(testnum, testerr, que, 0.3);	EnqueueC(testnum, testerr, que2, 0.3);
	NonEqualQueue(testnum, testerr, que, que2, true);

	lasd::QueueVec<double> que3(que);
	lasd::QueueVec<double> que4(std::move(que));
	EqualQueue(testnum, testerr, que3, que4, true);
	EqualQueue(testnum, testerr, que, que4, false);
	EnqueueC(testnum, testerr, que4, 15.0);
	Head(testnum, testerr, que4, true, 0.3);
	Dequeue(testnum, testerr, que4, true);
	HeadNDequeue(testnum, testerr, que4, true, 15.0);
	Empty(testnum, testerr, que4, true);
	EnqueueC(testnum, testerr, que4, 1.0);
	EnqueueC(testnum, testerr, que4, 2.0);
	Head(testnum, testerr, que4, true, 1.0);
}

void QueueVecStringTest(unsigned int& testnum, unsigned int& testerr) {
	lasd::QueueVec<std::string> que;
	lasd::QueueVec<std::string> equalque;
	Empty(testnum, testerr, que, true);
	EqualQueue(testnum, testerr, que, equalque, true);

	lasd::QueueVec<std::string> que2;
	for (int i = 0; i < 10; ++i) {
		EnqueueC(testnum, testerr, que2, std::to_string(i));
	}
	Empty(testnum, testerr, que2, false);
	Size(testnum, testerr, que2, true, 10);

	que2.Clear();
	for (int i = 0; i < 3; ++i) {
		EnqueueC(testnum, testerr, que2, std::to_string(i));
	}
	NonEqualQueue(testnum, testerr, que, que2, true);
	EnqueueC(testnum, testerr, que, std::string("3"));
	EnqueueC(testnum, testerr, que2, std::string("3"));
	NonEqualQueue(testnum, testerr, que, que2, true);

	lasd::QueueVec<std::string> que3(que);
	lasd::QueueVec<std::string> que4(std::move(que));
	EqualQueue(testnum, testerr, que3, que4, true);
	EqualQueue(testnum, testerr, que, que4, false);
	EnqueueC(testnum, testerr, que4, std::string("150"));
	Head(testnum, testerr, que4, true, std::string("3"));
	Dequeue(testnum, testerr, que4, true);
	HeadNDequeue(testnum, testerr, que4, true, std::string("150"));
	Empty(testnum, testerr, que4, true);

	EnqueueC(testnum, testerr, que4, std::string("1"));
	EnqueueC(testnum, testerr, que4, std::string("2"));
	Head(testnum, testerr, que4, true, std::string("1"));
}

void QueueVecBoolTest(unsigned int& testnum, unsigned int& testerr) {
	lasd::QueueVec<bool> que;
	lasd::QueueVec<bool> equalque;
	Empty(testnum, testerr, que, true);
	EqualQueue(testnum, testerr, que, equalque, true);

	lasd::QueueVec<bool> que2;
	for (int i = 0; i < 10; ++i) {
		EnqueueC(testnum, testerr, que2, i % 2 == 0);
	}
	Empty(testnum, testerr, que2, false);
	Size(testnum, testerr, que2, true, 10);

	que2.Clear();
	for (int i = 0; i < 3; ++i) {
		EnqueueC(testnum, testerr, que2, i % 2 == 0);
	}
	NonEqualQueue(testnum, testerr, que, que2, true);
	EnqueueC(testnum, testerr, que, true);	EnqueueC(testnum, testerr, que2, true);
	NonEqualQueue(testnum, testerr, que, que2, true);

	lasd::QueueVec<bool> que3(que);
	lasd::QueueVec<bool> que4(std::move(que));
	EqualQueue(testnum, testerr, que3, que4, true);
	EqualQueue(testnum, testerr, que, que4, false);
	EnqueueC(testnum, testerr, que4, true);
	Head(testnum, testerr, que4, true, true);
	Dequeue(testnum, testerr, que4, true);
	HeadNDequeue(testnum, testerr, que4, true, true);
	Empty(testnum, testerr, que4, true);

	EnqueueC(testnum, testerr, que4, true);
	EnqueueC(testnum, testerr, que4, false);
	Head(testnum, testerr, que4, true, true);
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
	lasd::QueueLst<int> que;
	lasd::QueueLst<int> equalque;
	Empty(testnum, testerr, que, true);
	EqualQueue(testnum, testerr, que, equalque, true);

	lasd::QueueLst<int> que2;
	for (int i = 0; i < 10; ++i) {
		EnqueueC(testnum, testerr, que2, i);
	}
	Empty(testnum, testerr, que2, false);
	Size(testnum, testerr, que2, true, 10);

	que2.Clear();
	for (int i = 0; i < 3; ++i) {
		EnqueueC(testnum, testerr, que2, i);
	}
	NonEqualQueue(testnum, testerr, que, que2, true);
	EnqueueC(testnum, testerr, que, 3);	EnqueueC(testnum, testerr, que2, 3);
	NonEqualQueue(testnum, testerr, que, que2, true);

	lasd::QueueLst<int> que3(que);
	lasd::QueueLst<int> que4(std::move(que));
	EqualQueue(testnum, testerr, que3, que4, true);
	EqualQueue(testnum, testerr, que, que4, false);
	EnqueueC(testnum, testerr, que4, 150);
	Head(testnum, testerr, que4, true, 3);
	Dequeue(testnum, testerr, que4, true);
	HeadNDequeue(testnum, testerr, que4, true, 150);
	Empty(testnum, testerr, que4, true);

	EnqueueC(testnum, testerr, que4, 1);
	EnqueueC(testnum, testerr, que4, 2);
	Head(testnum, testerr, que4, true, 1);
}

void QueueLstDoubleTest(unsigned int& testnum, unsigned int& testerr) {
	lasd::QueueLst<double> que;
	lasd::QueueLst<double> equalque;
	Empty(testnum, testerr, que, true);
	EqualQueue(testnum, testerr, que, equalque, true);

	lasd::QueueLst<double> que2;
	for (int i = 0; i < 10; ++i) {
		EnqueueC(testnum, testerr, que2, i * 0.1);
	}
	Empty(testnum, testerr, que2, false);
	Size(testnum, testerr, que2, true, 10);

	que2.Clear();
	for (int i = 0; i < 3; ++i) {
		EnqueueC(testnum, testerr, que2, i * 0.1);
	}
	NonEqualQueue(testnum, testerr, que, que2, true);
	EnqueueC(testnum, testerr, que, 0.3);	EnqueueC(testnum, testerr, que2, 0.3);
	NonEqualQueue(testnum, testerr, que, que2, true);

	lasd::QueueLst<double> que3(que);
	lasd::QueueLst<double> que4(std::move(que));
	EqualQueue(testnum, testerr, que3, que4, true);
	EqualQueue(testnum, testerr, que, que4, false);
	EnqueueC(testnum, testerr, que4, 15.0);
	Head(testnum, testerr, que4, true, 0.3);
	Dequeue(testnum, testerr, que4, true);
	HeadNDequeue(testnum, testerr, que4, true, 15.0);
	Empty(testnum, testerr, que4, true);
	EnqueueC(testnum, testerr, que4, 1.0);
	EnqueueC(testnum, testerr, que4, 2.0);
	Head(testnum, testerr, que4, true, 1.0);
}

void QueueLstStringTest(unsigned int& testnum, unsigned int& testerr) {
	lasd::QueueLst<std::string> que;
	lasd::QueueLst<std::string> equalque;
	Empty(testnum, testerr, que, true);
	EqualQueue(testnum, testerr, que, equalque, true);

	lasd::QueueLst<std::string> que2;
	for (int i = 0; i < 10; ++i) {
		EnqueueC(testnum, testerr, que2, std::to_string(i));
	}
	Empty(testnum, testerr, que2, false);
	Size(testnum, testerr, que2, true, 10);

	que2.Clear();
	for (int i = 0; i < 3; ++i) {
		EnqueueC(testnum, testerr, que2, std::to_string(i));
	}
	NonEqualQueue(testnum, testerr, que, que2, true);
	EnqueueC(testnum, testerr, que, std::string("3"));
	EnqueueC(testnum, testerr, que2, std::string("3"));
	NonEqualQueue(testnum, testerr, que, que2, true);

	lasd::QueueLst<std::string> que3(que);
	lasd::QueueLst<std::string> que4(std::move(que));
	EqualQueue(testnum, testerr, que3, que4, true);
	EqualQueue(testnum, testerr, que, que4, false);
	EnqueueC(testnum, testerr, que4, std::string("150"));
	Head(testnum, testerr, que4, true, std::string("3"));
	Dequeue(testnum, testerr, que4, true);
	HeadNDequeue(testnum, testerr, que4, true, std::string("150"));
	Empty(testnum, testerr, que4, true);

	EnqueueC(testnum, testerr, que4, std::string("1"));
	EnqueueC(testnum, testerr, que4, std::string("2"));
	Head(testnum, testerr, que4, true, std::string("1"));
}

void QueueLstBoolTest(unsigned int& testnum, unsigned int& testerr) {
	lasd::QueueLst<bool> que;
	lasd::QueueLst<bool> equalque;
	Empty(testnum, testerr, que, true);
	EqualQueue(testnum, testerr, que, equalque, true);

	lasd::QueueLst<bool> que2;
	for (int i = 0; i < 10; ++i) {
		EnqueueC(testnum, testerr, que2, i % 2 == 0);
	}
	Empty(testnum, testerr, que2, false);
	Size(testnum, testerr, que2, true, 10);

	que2.Clear();
	for (int i = 0; i < 3; ++i) {
		EnqueueC(testnum, testerr, que2, i % 2 == 0);
	}
	NonEqualQueue(testnum, testerr, que, que2, true);
	EnqueueC(testnum, testerr, que, true);	EnqueueC(testnum, testerr, que2, true);
	NonEqualQueue(testnum, testerr, que, que2, true);

	lasd::QueueLst<bool> que3(que);
	lasd::QueueLst<bool> que4(std::move(que));
	EqualQueue(testnum, testerr, que3, que4, true);
	EqualQueue(testnum, testerr, que, que4, false);
	EnqueueC(testnum, testerr, que4, true);
	Head(testnum, testerr, que4, true, true);
	Dequeue(testnum, testerr, que4, true);
	HeadNDequeue(testnum, testerr, que4, true, true);
	Empty(testnum, testerr, que4, true);

	EnqueueC(testnum, testerr, que4, true);
	EnqueueC(testnum, testerr, que4, false);
	Head(testnum, testerr, que4, true, true);
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
#include "stack.hpp"

void StackVecIntTest(unsigned int& testnum, unsigned int& testerr) {
	lasd::StackVec<int> stk;
	Empty(testnum, testerr, stk, true);

	lasd::StackVec<int> stk2;
	for (int i = 0; i < 10; ++i) {
		PushC(testnum, testerr, stk2, i);
	}
	Empty(testnum, testerr, stk2, false);
	Size(testnum, testerr, stk2, true, 10);

	stk2.Clear();
	for (int i = 0; i < 3; ++i) {
		PushC(testnum, testerr, stk2, i);
	}
	NonEqualStack(testnum, testerr, stk, stk2, true);
	PushC(testnum, testerr, stk, 3);	PushC(testnum, testerr, stk2, 3);
	NonEqualStack(testnum, testerr, stk, stk2, true);

	lasd::StackVec<int> stk3(stk);
	lasd::StackVec<int> stk4(std::move(stk));
	EqualStack(testnum, testerr, stk3, stk4, true);
	EqualStack(testnum, testerr, stk, stk4, false);
	PushC(testnum, testerr, stk4, 150);
	Top(testnum, testerr, stk4, true, 150);
	Pop(testnum, testerr, stk4, true);
	TopNPop(testnum, testerr, stk4, true, 3);

	stk4.Clear();
	Empty(testnum, testerr, stk4, true);
	PushC(testnum, testerr, stk4, 1);
	PushC(testnum, testerr, stk4, 2);
	Top(testnum, testerr, stk4, true, 2);

}

void StackVecDoubleTest(unsigned int& testnum, unsigned int& testerr) {
	lasd::StackVec<double> stk;
	Empty(testnum, testerr, stk, true);

	lasd::StackVec<double> stk2;
	for (int i = 0; i < 10; ++i) {
		PushC(testnum, testerr, stk2, i * 0.1);
	}
	Empty(testnum, testerr, stk2, false);
	Size(testnum, testerr, stk2, true, 10);

	stk2.Clear();
	for (int i = 0; i < 3; ++i) {
		PushC(testnum, testerr, stk2, i * 0.1);
	}
	NonEqualStack(testnum, testerr, stk, stk2, true);
	PushC(testnum, testerr, stk, 0.3);	PushC(testnum, testerr, stk2, 0.3);
	NonEqualStack(testnum, testerr, stk, stk2, true);

	lasd::StackVec<double> stk3(stk);
	lasd::StackVec<double> stk4(std::move(stk));
	EqualStack(testnum, testerr, stk3, stk4, true);
	EqualStack(testnum, testerr, stk, stk4, false);
	PushC(testnum, testerr, stk4, 15.0);
	Top(testnum, testerr, stk4, true, 15.0);
	Pop(testnum, testerr, stk4, true);
	TopNPop(testnum, testerr, stk4, true, 0.3);

	stk4.Clear();
	Empty(testnum, testerr, stk4, true);
	PushC(testnum, testerr, stk4, 1.0);
	PushC(testnum, testerr, stk4, 2.0);
	Top(testnum, testerr, stk4, true, 2.0);
}

void StackVecStringTest(unsigned int& testnum, unsigned int& testerr) {
	lasd::StackVec<std::string> stk;
	Empty(testnum, testerr, stk, true);

	lasd::StackVec<std::string> stk2;
	for (int i = 0; i < 10; ++i) {
		PushC(testnum, testerr, stk2, std::to_string(i));
	}
	Empty(testnum, testerr, stk2, false);
	Size(testnum, testerr, stk2, true, 10);

	stk2.Clear();
	for (int i = 0; i < 3; ++i) {
		PushC(testnum, testerr, stk2, std::to_string(i));
	}
	NonEqualStack(testnum, testerr, stk, stk2, true);
	PushC(testnum, testerr, stk, std::string("3"));	PushC(testnum, testerr, stk2, std::string("3"));
	NonEqualStack(testnum, testerr, stk, stk2, true);

	lasd::StackVec<std::string> stk3(stk);
	lasd::StackVec<std::string> stk4(std::move(stk));
	EqualStack(testnum, testerr, stk3, stk4, true);
	EqualStack(testnum, testerr, stk, stk4, false);
	PushC(testnum, testerr, stk4, std::string("150"));
	Top(testnum, testerr, stk4, true, std::string("150"));
	Pop(testnum, testerr, stk4, true);
	TopNPop(testnum, testerr, stk4, true, std::string("3"));

	stk4.Clear();
	Empty(testnum, testerr, stk4, true);
	PushC(testnum, testerr, stk4, std::string("1"));
	PushC(testnum, testerr, stk4, std::string("2"));
	Top(testnum, testerr, stk4, true, std::string("2"));
}

void StackVecBoolTest(unsigned int& testnum, unsigned int& testerr) {
	lasd::StackVec<bool> stk;
	Empty(testnum, testerr, stk, true);

	lasd::StackVec<bool> stk2;
	for (int i = 0; i < 10; ++i) {
		PushC(testnum, testerr, stk2, i % 2 == 0);
	}
	Empty(testnum, testerr, stk2, false);
	Size(testnum, testerr, stk2, true, 10);

	stk2.Clear();
	for (int i = 0; i < 3; ++i) {
		PushC(testnum, testerr, stk2, i % 2 == 0);
	}
	NonEqualStack(testnum, testerr, stk, stk2, true);
	PushC(testnum, testerr, stk, true);	PushC(testnum, testerr, stk2, true);
	NonEqualStack(testnum, testerr, stk, stk2, true);

	lasd::StackVec<bool> stk3(stk);
	lasd::StackVec<bool> stk4(std::move(stk));
	EqualStack(testnum, testerr, stk3, stk4, true);
	EqualStack(testnum, testerr, stk, stk4, false);
	PushC(testnum, testerr, stk4, true);
	Top(testnum, testerr, stk4, true, true);
	Pop(testnum, testerr, stk4, true);
	TopNPop(testnum, testerr, stk4, true, true);

	stk4.Clear();
	Empty(testnum, testerr, stk4, true);
	PushC(testnum, testerr, stk4, true);
	PushC(testnum, testerr, stk4, false);
	Top(testnum, testerr, stk4, true, false);
}

void testStackVector(unsigned int& testnum, unsigned int& testerr) {
	std::cout << "Testing StackVec<int>" << std::endl;
	StackVecIntTest(testnum, testerr);

	std::cout << "Testing StackVec<double>" << std::endl;
	StackVecDoubleTest(testnum, testerr);

	std::cout << "Testing StackVec<std::string>" << std::endl;
	StackVecStringTest(testnum, testerr);

	std::cout << "Testing StackVec<bool>" << std::endl;
	StackVecBoolTest(testnum, testerr);
}

void StackLstIntTest(unsigned int& testnum, unsigned int& testerr) {
	lasd::StackLst<int> stk;
	Empty(testnum, testerr, stk, true);

	lasd::StackLst<int> stk2;
	for (int i = 0; i < 10; ++i) {
		PushC(testnum, testerr, stk2, i);
	}
	Empty(testnum, testerr, stk2, false);
	Size(testnum, testerr, stk2, true, 10);

	stk2.Clear();
	for (int i = 0; i < 3; ++i) {
		PushC(testnum, testerr, stk2, i);
	}
	NonEqualStack(testnum, testerr, stk, stk2, true);
	PushC(testnum, testerr, stk, 3);	PushC(testnum, testerr, stk2, 3);
	NonEqualStack(testnum, testerr, stk, stk2, true);

	lasd::StackLst<int> stk3(stk);
	lasd::StackLst<int> stk4(std::move(stk));
	EqualStack(testnum, testerr, stk3, stk4, true);
	EqualStack(testnum, testerr, stk, stk4, false);
	PushC(testnum, testerr, stk4, 150);
	Top(testnum, testerr, stk4, true, 150);
	Pop(testnum, testerr, stk4, true);
	TopNPop(testnum, testerr, stk4, true, 3);

	stk4.Clear();
	Empty(testnum, testerr, stk4, true);
	PushC(testnum, testerr, stk4, 1);
	PushC(testnum, testerr, stk4, 2);
	Top(testnum, testerr, stk4, true, 2);
}

void StackLstDoubleTest(unsigned int& testnum, unsigned int& testerr) {
	lasd::StackLst<double> stk;
	Empty(testnum, testerr, stk, true);

	lasd::StackLst<double> stk2;
	for (int i = 0; i < 10; ++i) {
		PushC(testnum, testerr, stk2, i * 0.1);
	}
	Empty(testnum, testerr, stk2, false);
	Size(testnum, testerr, stk2, true, 10);

	stk2.Clear();
	for (int i = 0; i < 3; ++i) {
		PushC(testnum, testerr, stk2, i * 0.1);
	}
	NonEqualStack(testnum, testerr, stk, stk2, true);
	PushC(testnum, testerr, stk, 0.3);	PushC(testnum, testerr, stk2, 0.3);
	NonEqualStack(testnum, testerr, stk, stk2, true);

	lasd::StackLst<double> stk3(stk);
	lasd::StackLst<double> stk4(std::move(stk));
	EqualStack(testnum, testerr, stk3, stk4, true);
	EqualStack(testnum, testerr, stk, stk4, false);
	PushC(testnum, testerr, stk4, 15.0);
	Top(testnum, testerr, stk4, true, 15.0);
	Pop(testnum, testerr, stk4, true);
	TopNPop(testnum, testerr, stk4, true, 0.3);

	stk4.Clear();
	Empty(testnum, testerr, stk4, true);
	PushC(testnum, testerr, stk4, 1.0);
	PushC(testnum, testerr, stk4, 2.0);
	Top(testnum, testerr, stk4, true, 2.0);
}

void StackLstStringTest(unsigned int& testnum, unsigned int& testerr) {
	lasd::StackLst<std::string> stk;
	Empty(testnum, testerr, stk, true);

	lasd::StackLst<std::string> stk2;
	for (int i = 0; i < 10; ++i) {
		PushC(testnum, testerr, stk2, std::to_string(i));
	}
	Empty(testnum, testerr, stk2, false);
	Size(testnum, testerr, stk2, true, 10);

	stk2.Clear();
	for (int i = 0; i < 3; ++i) {
		PushC(testnum, testerr, stk2, std::to_string(i));
	}
	NonEqualStack(testnum, testerr, stk, stk2, true);
	PushC(testnum, testerr, stk, std::string("3"));
	PushC(testnum, testerr, stk2, std::string("3"));
	NonEqualStack(testnum, testerr, stk, stk2, true);

	lasd::StackLst<std::string> stk3(stk);
	lasd::StackLst<std::string> stk4(std::move(stk));
	EqualStack(testnum, testerr, stk3, stk4, true);
	EqualStack(testnum, testerr, stk, stk4, false);
	PushC(testnum, testerr, stk4, std::string("150"));
	Top(testnum, testerr, stk4, true, std::string("150"));
	Pop(testnum, testerr, stk4, true);
	TopNPop(testnum, testerr, stk4, true, std::string("3"));

	stk4.Clear();
	Empty(testnum, testerr, stk4, true);
	PushC(testnum, testerr, stk4, std::string("1"));
	PushC(testnum, testerr, stk4, std::string("2"));
	Top(testnum, testerr, stk4, true, std::string("2"));
}

void StackLstBoolTest(unsigned int& testnum, unsigned int& testerr) {
	lasd::StackLst<bool> stk;
	Empty(testnum, testerr, stk, true);

	lasd::StackLst<bool> stk2;
	for (int i = 0; i < 10; ++i) {
		PushC(testnum, testerr, stk2, i % 2 == 0);
	}
	Empty(testnum, testerr, stk2, false);
	Size(testnum, testerr, stk2, true, 10);

	stk2.Clear();
	for (int i = 0; i < 3; ++i) {
		PushC(testnum, testerr, stk2, i % 2 == 0);
	}
	NonEqualStack(testnum, testerr, stk, stk2, true);
	PushC(testnum, testerr, stk, true);	PushC(testnum, testerr, stk2, true);
	NonEqualStack(testnum, testerr, stk, stk2, true);

	lasd::StackLst<bool> stk3(stk);
	lasd::StackLst<bool> stk4(std::move(stk));
	EqualStack(testnum, testerr, stk3, stk4, true);
	EqualStack(testnum, testerr, stk, stk4, false);
	PushC(testnum, testerr, stk4, true);
	Top(testnum, testerr, stk4, true, true);
	Pop(testnum, testerr, stk4, true);
	TopNPop(testnum, testerr, stk4, true, true);

	stk4.Clear();
	Empty(testnum, testerr, stk4, true);
	PushC(testnum, testerr, stk4, true);
	PushC(testnum, testerr, stk4, false);
	Top(testnum, testerr, stk4, true, false);
}

void testStackList(unsigned int& testnum, unsigned int& testerr) {
	std::cout << "Testing StackLst<int>" << std::endl;
	StackLstIntTest(testnum, testerr);

	std::cout << "Testing StackLst<double>" << std::endl;
	StackLstDoubleTest(testnum, testerr);

	std::cout << "Testing StackLst<std::string>" << std::endl;
	StackLstStringTest(testnum, testerr);

	std::cout << "Testing StackLst<bool>" << std::endl;
	StackLstBoolTest(testnum, testerr);
}
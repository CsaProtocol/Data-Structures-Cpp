#include <cassert>

#include "../vector/vector.hpp"
#define DOCTEST_CONFIG_IMPLEMENT

using namespace lasd;

/* ************************************************************************** */

#include <cassert>

void testVector() {
	lasd::Vector<int> vec1(5);
	assert(vec1.Size() == 5);

	lasd::Vector<int> vec2(vec1);
	assert(vec2.Size() == 5);

	lasd::Vector<int> vec(5);
	for (int i = 0; i < 5; ++i) {
		vec[i] = i;
	}
	assert(vec[2] == 2);

	lasd::Vector<int> vec3(5);
	for (int i = 0; i < 5; ++i) {
		vec3[i] = i;
	}
	assert(vec3.Front() == 0);
	assert(vec3.Back() == 4);

	lasd::Vector<int> vec4(5);
	vec4.Clear();
	assert(vec4.Size() == 0);

	lasd::Vector<int> vec5(5);
	vec5.Resize(10);
	assert(vec5.Size() == 10);
}

int mytest() {
	testVector();
	return 0;
}
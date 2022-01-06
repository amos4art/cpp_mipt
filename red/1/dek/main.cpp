
#ifdef TEST_BUILD
#include "test_runner.h"
#endif

#include <vector>
#include <stdexcept>

using namespace std;

template <typename T>
class Deque {
public:
	Deque() {
	}
	
	bool Empty() const {
		return (m_front.empty() && m_back.empty());
	}

	size_t Size() const {
		return m_front.size() + m_back.size();
	}
	
	T& operator[](size_t index) {
		return this->At(index);
	}
		
	const T& operator[](size_t index) const {
		return this->At(index);
	}

	T& At(size_t index) {
		if (index < m_front.size()) {
			return m_front[m_front.size() - 1 - index];
		}
		else if (index < m_front.size() + m_back.size()) {
			return m_back[index - m_front.size()];
		}
		else {
			throw out_of_range ("index is out of range");
		}
	}
	
	const T& At(size_t index) const {
		if (index < m_front.size()) {
			return m_front[m_front.size() - 1 - index];
		}
		else if (index < m_front.size() + m_back.size()) {
			return m_back[index - m_front.size()];
		}
		else {
			throw out_of_range ("index is out of range");
		}
	}
	
	T& Front() {
		if (m_front.size() > 0) {
			return m_front.back();
		}
		else if (!this->Empty()) {
			return m_back.front();
		}
		else {
			throw out_of_range("deque is empty");
		}
	}

	const T& Front() const {
		if (m_front.size() > 0) {
			return m_front.back();
		}
		else if (!this->Empty()) {
			return m_back.front();
		}
		else {
			throw out_of_range("deque is empty");
		}
	}

	T& Back() {
		if (m_back.size() > 0) {
			return m_back.back();
		}
		else if (!this->Empty()) {
			return m_front.front();
		}
		else {
			throw out_of_range("deque is empty");
		}
	}

	const T& Back() const {
		if (m_back.size() > 0) {
			return m_back.back();
		}
		else if (!this->Empty()) {
			return m_front.front();
		}
		else {
			throw out_of_range("deque is empty");
		}
	}
	

	void PushFront(const T& val) {
		m_front.push_back(val);
	}
	
	void PushBack(const T& val) {
		m_back.push_back(val);
	}

private:
	vector<T> m_front, m_back;
};

#ifdef TEST_BUILD
void TestDeque() {
	Deque<int> d;	
	d.PushFront(5);
	d.PushFront(9);
	ASSERT_EQUAL(d[0], 9);
	ASSERT_EQUAL(d.At(0), 9);
	d[0] = 42; 
	ASSERT_EQUAL(d.Front(), 42);
	ASSERT_EQUAL(d.Back(), 5);
	d.At(1) = 33;
	d.PushBack(10);
	ASSERT_EQUAL(d[1], 33);
	ASSERT_EQUAL(d.Back(), 10);

	Deque<int> d2;
	ASSERT_EQUAL(d2.Empty(), true);
	d2.PushBack(12);
	ASSERT_EQUAL(d2.Empty(), false);
	ASSERT_EQUAL(d2.Front(), 12);
	ASSERT_EQUAL(d2.Back(), 12);
	d2.PushBack(13);
	d2.PushBack(14);
	d2.PushFront(11);
	ASSERT_EQUAL(d2[1], 12);
	ASSERT_EQUAL(d2[3], 14);
}


int main() {
	TestRunner tr;
	RUN_TEST(tr, TestDeque);
	return 0;
}
#else

int main() {
	return 0;
}
#endif
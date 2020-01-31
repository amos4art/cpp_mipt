#include "test_runner.h"

using namespace std;

// Реализуйте здесь шаблонный класс Table

template <typename T>
class Table{
public:
	Table(const size_t& h, const size_t& w) : m_h(h), m_w(w) {
		m_table = vector<vector<T>>(m_h);
		for (auto& row : m_table) {
			row = vector<T>(m_w);
		}
	}

	vector<T>& operator[](size_t ind) {
		return m_table[ind];
	}

	const Table& operator[](size_t v) const {
		return m_table[v];
	}

	void Resize(const size_t& new_h, const size_t& new_w){
		m_h = new_h;
		m_w = new_w;		
		m_table.resize(m_h);
		for (auto& row : m_table) {
			row.resize(m_w);
		}		
	}

	pair<size_t, size_t> Size() const {
		return { m_h, m_w };
	}

private:
	vector<vector<T>> m_table;
	size_t m_h, m_w;

};





void TestTable() {
  Table<int> t(1, 1);
  ASSERT_EQUAL(t.Size().first, 1u);
  ASSERT_EQUAL(t.Size().second, 1u);
  t[0][0] = 42;
  ASSERT_EQUAL(t[0][0], 42);
  t.Resize(3, 4);
  ASSERT_EQUAL(t.Size().first, 3u);
  ASSERT_EQUAL(t.Size().second, 4u);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestTable);
  return 0;
}

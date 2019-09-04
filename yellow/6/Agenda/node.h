#pragma once

#include "date.h"
#include <memory>

using namespace std;

enum class Comparison {
	Less,
	LessOrEqual,
	Greater,
	GreaterOrEqual,
	Equal,
	NotEqual,
};

enum class LogicalOperation {
	Or,
	And,
};


class Node {
public:
	virtual bool Evaluate(const Date& date, const string& event) const = 0;
};


class EmptyNode : public Node {
	bool Evaluate(const Date& date, const string& event) const override;
};
	

class DateComparisonNode : public Node {
public:	
	DateComparisonNode(const Comparison& cmp, const Date& date) : _cmp(cmp), _date(date) {};
	bool Evaluate(const Date& date, const string& event) const override;
private:
	Date _date;
	Comparison _cmp;
};
	

class EventComparisonNode : public Node {
public:
	EventComparisonNode(const Comparison& cmp, const string& event) : _cmp(cmp), _event(event) {};
	bool Evaluate(const Date& date, const string& event) const override;
private:
	string _event;
	Comparison _cmp;
};


class LogicalOperationNode : public Node {
public:
	LogicalOperationNode(const LogicalOperation& lo, shared_ptr<Node> left, shared_ptr<Node> right);
	bool Evaluate(const Date& date, const string& event) const override;
private:	
	shared_ptr<Node> _left;
	shared_ptr<Node> _right;
	LogicalOperation _lo;
};


/*
class DateComparisonNode : public Node {
public:
	DateComparisonNode(bool(*cmp)(const Date&, const Date&), Date& date) : _cmp(cmp), _date(date) {};
	bool Evaluate(const Date& date, const string& event) const override;
	const Date _date;
private:
	bool(*_cmp)(const Date&, const Date&);
};


class EventComparisonNode : public Node {
public:
	EventComparisonNode(bool(*cmp)(const string&, const string&), const string& event) : _cmp(cmp), _event(event) {};
	bool Evaluate(const Date& date, const string& event) const override;
	const string _event;
private:
	bool(*_cmp)(const string&, const string&);
};


class LogicalOperationNode : public Node {
	LogicalOperationNode(bool(*lo)(const bool&, const bool&), shared_ptr<Node> left, shared_ptr<Node> right) : _lo(lo), _left(left), _right(right) {};
	bool Evaluate(const Date& date, const string& event) const override;
	bool(*_lo)(const bool&, const bool&);
	shared_ptr<Node> _left;
	shared_ptr<Node> _right;
};

*/



template <typename It>
bool ComparisonTemplate(const Comparison& cmp, const It& lhs, const It& rhs) {
	switch (cmp) {
		case Comparison::Less:
			return lhs < rhs;
		case Comparison::LessOrEqual:
			return lhs <= rhs;
		case Comparison::Greater:
			return lhs > rhs;
		case Comparison::GreaterOrEqual:
			return lhs >= rhs;
		case Comparison::Equal:
			return lhs == rhs;
		case Comparison::NotEqual:
			return lhs != rhs;
		default:
			throw logic_error("Unknown comparison");
	}
};

template <typename It>
bool LogicalOperationTemplate(const LogicalOperation& lo, const It& lhs, const It& rhs) {
	switch (lo) {
		case LogicalOperation::And:
			return lhs & rhs;
		case LogicalOperation::Or:
			return lhs | rhs;
		default:
			throw logic_error("Unknown logical operation");
	}
}


/*
struct LogicalOperation {
	
	bool Or(const bool& left, const bool& right) {
		return left || right;
	}
	bool And(const bool& left, const bool& right) {
		return left && right;
	}
};
*/
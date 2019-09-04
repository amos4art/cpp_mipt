#include "node.h"

using namespace std;

bool EmptyNode::Evaluate(const Date& date, const string& event) const {
	return true;
}

bool DateComparisonNode::Evaluate(const Date& date, const string& event) const {
	return ComparisonTemplate <Date> (_cmp, date, _date);
	//return _cmp(date, _date);
}

bool EventComparisonNode::Evaluate(const Date& date, const string& event) const {
	return ComparisonTemplate <string> (_cmp, event, _event);
	//return _cmp(event, _event);
}


LogicalOperationNode::LogicalOperationNode(const LogicalOperation& lo, shared_ptr<Node> left, shared_ptr<Node> right) : _lo(lo) {
	_left = left;
	_right = right;
}

bool LogicalOperationNode::Evaluate(const Date& date, const string& event) const {
	return LogicalOperationTemplate <bool> (_lo, _left->Evaluate(date, event), _right->Evaluate(date, event));
	//return _lo(_left->Evaluate(date, event), _right->Evaluate(date, event));
}
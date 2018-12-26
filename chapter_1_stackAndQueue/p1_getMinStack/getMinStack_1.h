#pragma once
/*!
 * \file getMinStack_1.h
 * \date 2018/12/25 21:04
 *
 * \author wangjinju
 * Contact: user@company.com
 *
 * \brief 在原有栈的基础上，实现特殊的栈，返回栈中最小的元素
 *
 * TODO: long description
 *
 * \note
*/
#include <stack>
#include <iostream>
using namespace std;

template <typename T>
class GetMinStack_1 {
private:
	stack<T> m_stackData;
	stack<T> m_stackMin;
public:
	T GetMin()
	{
		if (m_stackMin.empty())
		{
			cout << "Your stack is empty" << endl;
			return -99999999;
		}
		else
			return m_stackMin.top();
	}
	void pop()
	{
		if (m_stackData.empty())
		{
			cout << "Your stack is empty, pop error" << endl;
			return;
		}
		int value = m_stackData.top();
		if (value == m_stackMin.top())
			m_stackMin.pop();
		m_stackData.pop();
	}
	void push(const T& item)
	{
		m_stackData.push(item);
		if (m_stackMin.empty())
			m_stackMin.push(item);
		else if (item <= m_stackMin.top())
			m_stackMin.push(item);
	}
};

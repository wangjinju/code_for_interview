/*!
 * \file getMinStack_2.h
 * \date 2018/12/26 9:33
 *
 * \author wangjinju
 * Contact: user@company.com
 *
 * \brief 
 *
 * TODO: long description
 *
 * \note
*/
#pragma once
#include <stack>
#include <iostream>
using namespace std;

template <typename T>
class GetMinStack_2
{
private:
	stack<T> m_stackData;
	stack<T> m_stackMin;
public:
	T GetMin()
	{
		if (m_stackData.empty())
		{
			cout << "Your stack is empty" << endl;
			return -999999;
		}
		else
			return m_stackMin.top();
	}
	void push(const T& item)
	{
		m_stackData.push(item);
		if (m_stackMin.empty())
			m_stackMin.push(item);
		else if (item <= m_stackMin.top())
		{
			m_stackMin.push(item);
		}
		else
			m_stackMin.push(m_stackMin.top());
	}
	void pop()
	{
		m_stackData.pop();
		m_stackMin.pop();
	}
};

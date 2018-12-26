#include <stack>
#include <vector>
#include <iostream>
using namespace std;
/*!
 * \file main.cpp
 * \date 2018/12/26 20:16
 *
 * \author wangjinju
 * Contact: user@company.com
 *
 * \brief
用两个栈实现队列，支持队列的基本操作（add,poll,peek）
 *
 * TODO: 
 add()向队列中添加元素
 poll()从队列中删除第一个元素
 peek()返回队列第一个元素
 *
 * \note
*/
template <typename T>
class MyQueue
{
private:
	stack<T> m_stackPush;
	stack<T> m_stackPop;
public:
	void poll()
	{
		if (m_stackPop.empty())
		{
			for (; !m_stackPush.empty();)
			{
				m_stackPop.push(m_stackPush.top());
				m_stackPush.pop();
			}
		}
		m_stackPop.pop();
	}
	void add(const T& item)
	{
		m_stackPush.push(item);
	}
	T peek()
	{
		if (m_stackPop.empty())
		{
			for (; !m_stackPush.empty();)
			{
				m_stackPop.push(m_stackPush.top());
				m_stackPush.pop();
			}
		}
		return m_stackPop.top();
	}
};

int main()
{
	vector<int> v = { 1,2,3,4,5,6,7 };
	MyQueue<int> myQueue;
	for (auto item : v)
	{
		myQueue.add(item);
	}

	cout << myQueue.peek() << endl; // 1
	myQueue.poll();

	cout << myQueue.peek() << endl; // 2 
	myQueue.poll();

	cout << myQueue.peek() << endl; // 3
	myQueue.poll();

	cout << myQueue.peek() << endl; // 4
	myQueue.poll();

	cout << myQueue.peek() << endl; // 5
	myQueue.poll();

	return 0;
}

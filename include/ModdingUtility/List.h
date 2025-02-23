#ifndef _MODDINGUTILITY_LIST_H_
#define _MODDINGUTILITY_LIST_H_

#include "types.h"
#include "Dolphin/os.h"

#define LIST_SAFE_MODE (true)

namespace ModdingUtility {

template <typename T>
class ListIterator;
template <typename T>
class ReversedListIterator;

template <typename T>
class List {
	friend class ListIterator<T>;
	friend class ReversedListIterator<T>;

private:
	struct Node {
		friend class ListIterator<T>;
		friend class ReversedListIterator<T>;

		Node(const T& obj)
		    : mObject(obj)
		{
			mNext = nullptr;
			mPrev = nullptr;
		}

		void setNext(Node* node)
		{
			mNext = node;
			if (node) {
				node->mPrev = this;
			}
		}

		void setPrev(Node* node)
		{
			mPrev = node;
			if (node) {
				node->mNext = this;
			}
		}

		Node* mNext;
		Node* mPrev;
		T mObject;
	};

	inline void _clear()
	{
		while (mFirst) {
			Node* node = mFirst;
			mFirst     = node->mNext;
			delete node;
		}
		mFirst = mLast = nullptr;
		mSize          = 0;
	}

	inline void _insert_at_node(Node* node, const T& value)
	{
		Node* n = new Node(value);
		if (node->mNext) {
			node->mNext->setPrev(n);
		} else {
			mLast = n;
		}
		node->setNext(n);
		mSize++;
	}

	inline void _insert_many_at_node(Node* node, size_t n, const T& value)
	{
		for (size_t i = 0; i < n; i++) {
			Node* v = new Node(value);
			if (node->mNext) {
				node->mNext->setPrev(v);
			}
			node->setNext(v);

			node = v;
		}
		mSize += n;
	}

	inline void _insert_from_back(size_t invpos, const T& value)
	{
		Node* node = _find_node_from_back(invpos);
		_insert_at_node(node, value);
	}

	inline void _insert_from_front(size_t pos, const T& value)
	{
		Node* node = _find_node_from_front(pos - 1);
		_insert_at_node(node, value);
	}

	inline void _insert_many_from_back(size_t invpos, size_t n, const T& value)
	{
		Node* node = _find_node_from_back(invpos);
		_insert_many_at_node(node, n, value);
	}

	inline void _insert_many_from_front(size_t pos, size_t n, const T& value)
	{
		Node* node = _find_node_from_front(pos - 1);
		_insert_many_at_node(node, n, value);
	}

	// doesn't work
	inline void _erase_from_back(size_t first, size_t last)
	{
		Node* node = _find_node_from_back(last);

		Node* next = node->mNext;
		for (size_t i = 0; i < last - first; i++) {
			Node* kill = node;
			node       = node->mPrev;
			delete kill;
		}
		node->setNext(next);
		mSize -= last - first;
	}

	inline void _erase_from_front(size_t first, size_t last)
	{
		Node* node = _find_node_from_front(first);

		Node* prev = node->mPrev;
		for (size_t i = 0; i < last - first; i++) {
			Node* kill = node;
			node       = node->mNext;
			delete kill;
		}
		if (node) {
			node->mPrev = prev;
			if (prev) {
				prev->mNext = node;
			}
			else {
				mFirst = node;
			}
		} else {
			prev->mNext = nullptr;
			mLast       = prev;
		}
		mSize -= last - first;
	}

	inline Node* _find_node_from_back(size_t invpos)
	{
		Node* node = mLast;
		for (size_t i = 0; i < invpos; i++) {
			node = node->mPrev;
		}
		return node;
	}

	inline Node* _find_node_from_front(size_t pos)
	{
		Node* node = mFirst;
		for (size_t i = 0; i < pos; i++) {
			node = node->mNext;
		}
		return node;
	}

	inline Node* _find_node(size_t pos)
	{
		if (pos > mSize / 2) {
			return _find_node_from_back(mSize - pos);
		}
		return _find_node_from_front(pos);
	}

	inline void _remove(Node* node)
	{
		if (node == mLast) {
			mLast = node->mPrev;
			if (mLast) {
				mLast->mNext = nullptr;
			} else {
				mFirst = nullptr;
			}
		} else if (node == mFirst) {
			mFirst = node->mNext;
			if (mFirst) {
				mFirst->mPrev = nullptr;
			} else {
				mLast = nullptr;
			}
		} else {
			node->mPrev->setNext(node->mNext);
		}
		delete node;
	}

public:
	List()
	    : mFirst(nullptr)
	    , mLast(nullptr)
		, mSize(0)
	{
	}
	// fill constructor
	List(size_t n, const T& obj)
	    : mFirst(nullptr)
	    , mLast(nullptr)
		, mSize(0)
	{
		for (size_t i = 0; i < n; i++) {
			push_back(obj);
		}
	}

	List(size_t n, const T* arr)
	    : mFirst(nullptr)
	    , mLast(nullptr)
		, mSize(0)
	{
		for (size_t i = 0; i < n; i++) {
			push_back(arr[i]);
		}
	}

	List(const List& other)
	    : mFirst(nullptr)
	    , mLast(nullptr)
		, mSize(0)
	{
		Node* node = other.mFirst;
		while (node) {
			push_back(node->mObject);
			node = node->mNext;
		}
	}

	void assign(size_t n, const T& obj)
	{
		_clear();
		for (size_t i = 0; i < n; i++) {
			push_back(obj);
		}
	}

	void assign(size_t n, const T* arr)
	{
		_clear();
		for (size_t i = 0; i < n; i++) {
			push_back(arr[i]);
		}
	}

	List& operator=(const List& other)
	{
		const Node* node = other.mFirst;
		while (node) {
			push_back(node->mObject);
			node = node->mNext;
		}
		return *this;
	}

	void push_back(const T& obj)
	{
		if (mLast) {
			Node* newLast = new Node(obj);
			mLast->setNext(newLast);
			mLast = newLast;
		} else {
			mFirst = mLast = new Node(obj);
		}
		mSize++;
	}

	void push_front(const T& obj)
	{
		if (mFirst) {
			Node* newFirst = new Node(obj);
			mFirst->setPrev(newFirst);
			mFirst = newFirst;
		} else {
			mLast = mFirst = new Node(obj);
		}
		mSize++;
	}

	void pop_back()
	{
#if LIST_SAFE_MODE
		JUT_ASSERT(mLast, "pop_back on empty list!");
#endif
		Node* delNode = mLast;
		mLast         = mLast->mPrev;
		delete delNode;

		if (mLast) {
			mLast->mNext = nullptr;
		}

		mSize--;
	}

	void pop_front()
	{
#if LIST_SAFE_MODE
		JUT_ASSERT(mFirst, "pop_back on empty list!");
#endif
		Node* delNode = mFirst;
		mFirst        = mFirst->mNext;
		delete delNode;

		if (mFirst) {
			mFirst->mPrev = nullptr;
		}

		mSize--;
	}

	void insert(size_t pos, const T& value)
	{
#if LIST_SAFE_MODE
		JUT_ASSERT(pos <= mSize, "insert out of bounds");
#endif
		if (pos == 0) {
			push_front(value);
		} else if (pos > mSize / 2) {
			_insert_from_back(mSize - pos, value);
		} else {
			_insert_from_front(pos, value);
		}
	}

	void insert(size_t pos, size_t n, const T& value)
	{
#if LIST_SAFE_MODE
		JUT_ASSERT(pos <= mSize, "fill insert out of bounds");
#endif
		if (pos == 0) {
			for (size_t i = 0; i < n; i++) {
				push_front(value);
			}
		} else if (pos < mSize / 2) {
			_insert_many_from_back(mSize - pos, n, value);
		} else {
			_insert_many_from_front(pos, value);
		}
	}

	// first inclusive last exclusive
	void erase(size_t first, size_t last)
	{
#if LIST_SAFE_MODE
		JUT_ASSERT(last <= mSize && first <= last, "erase parameters malformed");
#endif

		if (first == 0 && last == mSize) {
			_clear();
		} else {
			_erase_from_front(first, last);
		}
	}

	T pop_value(size_t idx) {
		Node* node = _find_node(idx);

		T value = node->mObject;

		_remove(node);

		return value;
	}


	void erase(size_t idx)
	{
#if LIST_SAFE_MODE
		JUT_ASSERT(idx <= mSize, "erase parameters malformed");
#endif

		
		_erase_from_front(idx, idx);
	}

	void swap(List& other)
	{
		Node* tempFirst = other.mFirst;
		Node* tempLast  = other.mLast;

		other.mFirst = mFirst;
		other.mLast  = mLast;

		mFirst = tempFirst;
		mLast  = tempLast;
	}

	void resize(size_t n, T v = T())
	{
		if (n == 0) {
			_clear();
		} else if (n > mSize) {
			size_t size = mSize;
			for (size_t i = 0; i < n - size; i++) {
				push_back(v);
			}
		} else {
			Node* newLast = _find_node(n - 1);

			mLast = newLast;

			Node* node = mLast;
			while (node) {
				Node* kill = node;
				node       = node->mNext;
				delete kill;
			}
			mLast->mNext = nullptr;

			mSize = n;
		}
	}

	template <typename Y>
	void remove(const Y& value)
	{
		Node* node = mFirst;
		while (node) {
			Node* kill = node;
			node       = node->mNext;
			if (kill->mObject == value) {
				_remove(kill);
			}
		}
	}

	void clear() { _clear(); }

	~List()
	{
		while (mFirst) {
			Node* node = mFirst;
			mFirst     = node->mNext;
			delete node;
		}
	}

	T& front()
	{
#if LIST_SAFE_MODE
		JUT_ASSERT(mFirst, "front on empty list!");
#endif
		return mFirst->mObject;
	}

	const T& front() const
	{
#if LIST_SAFE_MODE
		JUT_ASSERT(mFirst, "front on empty list!");
#endif
		return mFirst->mObject;
	}

	T& back()
	{
#if LIST_SAFE_MODE
		JUT_ASSERT(mLast, "back on empty list!");
#endif
		return mLast->mObject;
	}

	const T& back() const
	{
#if LIST_SAFE_MODE
		JUT_ASSERT(mLast, "back on empty list!");
#endif
		return mLast->mObject;
	}

	bool empty() const { return mSize == 0; }

	size_t size() const { return mSize; }

private:
	size_t mSize;
	Node* mFirst;
	Node* mLast;
};

template <typename T>
class ListIterator {
public:
	ListIterator(List<T>* stack)
	    : mList(stack)
	{
		mNode = nullptr;
	}

	ListIterator& operator++()
	{
		next();
		return *this;
	}

	inline void first() { mNode = mList->mFirst; }
	inline bool isDone() { return !mNode; }
	inline void next() { mNode = mNode->mNext; }

	inline T& getObject() { return mNode->mObject; }
	inline T& operator*() { return mNode->mObject; }

	inline T* operator->() { return &mNode->mObject; }

private:
	List<T>* mList;
	typename List<T>::Node* mNode;
};

template <typename T>
class ReversedListIterator {
public:
	ReversedListIterator(List<T>* stack)
	    : mList(stack)
	{
		mNode = nullptr;
	}

	ReversedListIterator& operator++()
	{
		next();
		return *this;
	}

	inline void first() { mNode = mList->mLast; }
	inline bool isDone() { return !mNode; }
	inline void next() { mNode = mNode->mPrev; }

	inline T& getObject() { return mNode->mObject; }
	inline T& operator*() { return mNode->mObject; }

	inline T* operator->() { return &mNode->mObject; }

private:
	List<T>* mList;
	typename List<T>::Node* mNode;
};

} // namespace ModdingUtility

#endif

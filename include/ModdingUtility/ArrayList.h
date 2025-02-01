#ifndef _MODDINGUTILITY_ARRAYLIST_H_
#define _MODDINGUTILITY_ARRAYLIST_H_

#include "types.h"
#include "JSystem/JUtility/JUTException.h"

namespace ModdingUtility {

#define ARRAY_LIST_SAFE_MDOE (false)

// actually equivilent to std::vector, java name used to avoid confusion with vector3
template <typename T>
class ArrayList {
	inline void _cleanup() { delete[] mArray; }

	inline void _alloc(size_t size)
	{
		mCapacity = size;
		mArray    = new T[size];
	}

	inline void _copy(T* arr, size_t size)
	{
		mSize = size;
		for (size_t i = 0; i < size; i++) {
			mArray[i] = arr[i];
		}
	}

	inline void _set_all(const T& val)
	{
		for (size_t i = 0; i < mSize; i++) {
			mArray[i] = val;
		}
	}

	inline void _copy_to(T* arr)
	{
		for (size_t i = 0; i < mSize; i++) {
			arr[i] = mArray[i];
		}
	}

	inline void _realloc_if_oversize()
	{
		if (mSize >= mCapacity) {
			size_t new_capacity = (mCapacity == 0) ? 1 : 2 * mCapacity;
			T* data             = new T[new_capacity];

			// Copy old data
			for (size_t i = 0; i < mCapacity; ++i) {
				data[i] = mArray[i];
			}

			delete[] mArray; // Free old array
			mArray    = data;
			mCapacity = new_capacity;
		}
	}

	inline void _realloc_if_oversize(size_t newsize)
	{
		if (newsize >= mCapacity) {
			size_t new_capacity = (mCapacity == 0) ? 1 : 2 * mCapacity;

			while (new_capacity < newsize)
				new_capacity *= 2;

			T* data = new T[new_capacity];

			// Copy old data
			for (size_t i = 0; i < mSize; ++i) {
				data[i] = mArray[i];
			}

			delete[] mArray; // Free old array
			mArray    = data;
			mCapacity = new_capacity;
		}
		mSize = newsize;
	}

	size_t mSize;
	size_t mCapacity;
	T* mArray;

public:
	// default constructor
	ArrayList()
	    : mArray(nullptr)
	    , mSize(0)
	    , mCapacity(0)
	{
	}
	// size constructor
	ArrayList(size_t size)
	    : mArray(new T[size])
	    , mSize(size)
	    , mCapacity(size)
	{
	}
	// fill constructor
	ArrayList(size_t size, const T& val)
	    : mArray(new T[size])
	    , mSize(size)
	    , mCapacity(size)
	{
		_set_all(val);
	}
	// copy list constructor
	ArrayList(size_t size, const T* arr)
	    : mArray(new T[size])
	    , mSize(size)
	    , mCapacity(size)
	{
		for (size_t i = 0; i < size; i++) {
			mArray[i] = arr[i];
		}
	}
	// copy constructor
	ArrayList(const ArrayList& other)
	{
		_alloc(other.mCapacity);
		_copy(other.mArray, other.mSize);
	}

	ArrayList& operator=(const ArrayList& other)
	{
		_cleanup();
		_alloc(other.mSize);
		_copy(other.mArray, other.mSize);
	}

	// clears object and fills with value
	void assign(size_t count, T& value)
	{
		_realloc_if_oversize(count);
		_set_all(value);
	}

	// clears object and copies from array
	void assign(size_t count, const T* arr)
	{
		_realloc_if_oversize(count);
		for (size_t i = 0; i < count; i++) {
			mArray[i] = arr[i];
		}
	}

	// asserts if OoBs
	T& at(size_t idx)
	{
		if (idx < 0 || idx >= mSize) {
			JUT_PANIC("at(%i) out of range (mSize == %i)", idx, mSize);
		}
		return mArray[idx];
	}

	// asserts if OoBs
	const T& at(size_t idx) const
	{
		if (idx < 0 || idx >= mSize) {
			JUT_PANIC("at(%i) out of range (mSize == %i)", idx, mSize);
		}
		return mArray[idx];
	}

	T& operator[](size_t idx)
	{
#if ARRAY_LIST_SAFE_MDOE
		return at(idx);
#else
		return mArray[idx];
#endif
	}
	const T& operator[](size_t idx) const
	{
#if ARRAY_LIST_SAFE_MDOE
		return at(idx);
#else
		return mArray[idx];
#endif
	}

	// gets the first element
	T& front() { return mArray[0]; }
	// gets the first element
	const T& front() const { return mArray[0]; }

	// gets the last element
	T& back() { return mArray[mSize - 1]; }
	// gets the last element
	const T& back() const { return mArray[mSize - 1]; }

	T* data() { return mArray; }
	const T* data() const { return mArray; }

	bool empty() const { return mSize == 0; }

	size_t size() const { return mSize; }

	size_t capacity() const { return mCapacity; }

	// resizes the array
	void resize(size_t size)
	{
		if (size < mSize) {
			mSize = size;
		} else {
			size_t oldsize = mSize;
			_realloc_if_oversize(size);
			for (size_t i = oldsize; i < mSize; i++) {
				mArray[i] = T();
			}
		}
	}

	// resizes the array, fills blank spaces with value
	void resize(size_t size, const T& value)
	{
		if (mSize >= size) {
			mSize = size;
		} else {
			size_t oldsize = mSize;
			_realloc_if_oversize(size);
			for (size_t i = oldsize; i < mSize; i++) {
				mArray[i] = value;
			}
		}
	}

	// allocates capacity, does not alter mSize
	void reserve(size_t capacity)
	{
		if (capacity < mCapacity) {
			return;
		}
		T* old = new T[capacity];
		_copy_to(old);
		_cleanup();
		mCapacity = mCapacity;
		mArray    = old;
	}

	// sets mCapacity to mSize
	void shrink_to_fit()
	{
		mCapacity = mSize;
		T* old    = new T[mCapacity];
		_copy_to(old);
		_cleanup();
		mArray = old;
	}

	void clear() { mSize = 0; }

	// inserts a value at pos
	void insert(size_t pos, const T& value)
	{
#if ARRAY_LIST_SAFE_MDOE
		JUT_ASSERT(pos <= mSize, "insert out of bounds");
#endif
		mSize++;
		_realloc_if_oversize();
		for (size_t i = mSize - 1; i > pos; i--) {
			mArray[i] = mArray[i - 1];
		}
		mArray[pos] = value;
	}

	// inserts arr of size arrSize at pos
	void insert(size_t pos, size_t arrSize, const T* arr)
	{
#if ARRAY_LIST_SAFE_MDOE
		JUT_ASSERT(pos <= mSize, "insert out of bounds");
#endif
		_realloc_if_oversize(mSize + arrSize);
		for (size_t i = mSize - 1; i >= pos + arrSize; i--) {
			mArray[i] = mArray[i - arrSize];
		}

		for (size_t i = 0; i < arrSize; i++) {
			mArray[i + pos] = arr[i];
		}
	}

	// inserts n copies of value at pos
	void insert(size_t pos, size_t n, const T& value)
	{
#if ARRAY_LIST_SAFE_MDOE
		JUT_ASSERT(pos <= mSize, "insert out of bounds");
#endif
		_realloc_if_oversize(mSize + n);
		for (size_t i = mSize - 1; i >= pos + n; i--) {
			mArray[i] = mArray[i - n];
		}

		for (size_t i = 0; i < n; i++) {
			mArray[i + pos] = value;
		}
	}

	void erase(size_t pos)
	{
#if ARRAY_LIST_SAFE_MDOE
		JUT_ASSERT(pos <= mSize, "erase out of bounds");
#endif
		mSize--;
		for (size_t i = pos; i < mSize; i++) {
			mArray[pos] = mArray[pos + 1];
		}
	}

	// start inclusive end exclusive
	void erase(size_t start, size_t end)
	{
		size_t dsize = end - start;
#if ARRAY_LIST_SAFE_MDOE
		JUT_ASSERT(start <= end, "start and end disagree");
		JUT_ASSERT(start <= mSize, "start erase out of bounds");
		JUT_ASSERT(end <= mSize, "end erase out of bounds");
#endif
		mSize -= dsize;
		for (size_t i = 0; i < dsize; i++) {
			mArray[start + i] = mArray[end + i + 1];
		}
	}

	// pushes value to the back of the list
	void push_back(const T& value)
	{
		mSize++;
		_realloc_if_oversize();
		mArray[mSize - 1] = value;
	}

	// pushes arr of size arrSize to the back of the list
	void push_back(size_t arrSize, const T* arr)
	{
		size_t oldsize = mSize;
		_realloc_if_oversize(mSize + arrSize);
		for (size_t i = 0; i < arrSize; i++) {
			mArray[i + oldsize] = arr[i];
		}
	}

	// pushes all contents of other to the back of the list
	void push_back(const ArrayList& other)
	{
		size_t oldsize = mSize;
		_realloc_if_oversize(mSize + other.size());
		for (size_t i = 0; i < other.size(); i++) {
			mArray[i + oldsize] = other[i];
		}
	}

	// removes the last element
	void pop_back()
	{
#if ARRAY_LIST_SAFE_MDOE
		JUT_ASSERT(mSize > 0, "pop on zero length list");
#endif
		mSize--;
	}

	// swaps data with another ArrayList
	void swap(ArrayList& other)
	{
		T* tempArr          = mArray;
		size_t tempSize     = mSize;
		size_t tempCapacity = mCapacity;

		mArray    = other.mArray;
		mSize     = other.mSize;
		mCapacity = other.mCapacity;

		other.mArray    = mArray;
		other.mSize     = mSize;
		other.mCapacity = mCapacity;
	}

	~ArrayList() { _cleanup(); }
};

// please do not alter the array list while its being iterated I SWEAR TO GOD

template <typename T>
struct ArrayListIterator {
	ArrayListIterator(ArrayList<T>* arr)
	    : mArrayList(arr)
	{
	}

	const ArrayList<T>* mArrayList;
	size_t mIdx;

	inline void first() { mIdx = 0; }
	inline bool isDone() { mIdx >= mArrayList->size(); }
	inline void next() { mIdx++; }

	inline T* getObject() { return &mArrayList[mIdx]; }

	inline T* operator*() { return getObject(); }
};

template <typename T>
struct ReversedArrayListIterator {
	ReversedArrayListIterator(ArrayList<T>* arr)
	    : mArrayList(arr)
	{
	}

	const ArrayList<T>* mArrayList;
	size_t mIdx;

	inline void first() { mIdx = mArrayList->size() - 1; }
	inline bool isDone() { mIdx == (size_t)(-1); }
	inline void next() { mIdx--; }

	inline T* getObject() { return &mArrayList[mIdx]; }

	inline T* operator*() { return getObject(); }
};

} // namespace ModdingUtility

#endif
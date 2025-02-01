#ifndef _MODDINGUTILITY_STRING_H_
#define _MODDINGUTILITY_STRING_H_

#include "ModdingUtility/ArrayList.h"
#include "Dolphin/string.h"
#include "stream.h"
#include "types.h"

// untested

#define STRING_SAFE_MDOE (true)

namespace ModdingUtility {

class String {

private:
	static const size_t npos = -1;

	inline void _null_terminate() { mCharArr.back() = '\0'; }

	static String _format(const char* formatStr, va_list args)
	{
		// try to use the format function until it works
		size_t buff_size = 256;
		size_t check     = 0;

		char* buffer = nullptr;

		while (true) {
			buffer = new char[buff_size];
			check  = vsnprintf(buffer, buff_size, formatStr, args);
			if (check != buff_size) {
				break;
			}
			delete[] buffer;
		};

		String outStr(buffer);
		outStr.shrink_to_fit();
		
		delete[] buffer;

		return outStr;
	}

public:
	// default constructor
	String()
	    : mCharArr(1, '\0')
	{
	}

	String(char c)
	    : mCharArr(2)
	{
		mCharArr[0] = c;
		mCharArr[1] = '\0';
	}

	// c-string constructor
	String(const char* c)
	    : mCharArr(strlen(c) + 1, c)
	{
	}

	// buffer constructor
	String(const char* c, size_t n)
	    : mCharArr(n + 1, c)
	{
		mCharArr[n] = '\0';
	}

	// copy constructor
	String(const String& other)
	    : mCharArr(other.mCharArr)
	{
	}

	// substring constructor
	String(const String& other, size_t pos, size_t len = npos)
	{
#if STRING_SAFE_MDOE
		if (pos > other.length() || pos + len > other.length()) {
			JUT_PANIC("String %s constructed with pos %i and length %i", other, pos, len);
		}
#endif
		if (len == npos) {
			len = other.length() - pos;
		}

		mCharArr.assign(len + 1, &other.c_str()[pos]);
		mCharArr[len] = '\0';
	}

	// fill constructor
	String(size_t n, char c)
	    : mCharArr(n + 1, c)
	{
		mCharArr[n] = '\0';
	}

	// excludes null-terminator
	inline size_t size() const { return mCharArr.size() - 1; }
	// excludes null-terminator
	inline size_t length() const { return mCharArr.size() - 1; }

	// excludes null-terminator
	inline size_t capacity() const { return mCharArr.capacity() - 1; }

	// unsafe, please don't use
	inline char* data() { return mCharArr.data(); }
	inline const char* data() const { return mCharArr.data(); }

	inline const char* c_str() const { return mCharArr.data(); }

	inline bool empty() const { return mCharArr.size() == 1; }

	inline char& operator[](size_t idx)
	{
#if STRING_SAFE_MDOE
		return at(idx);
#else
		return mCharArr[idx];
#endif
	}
	inline const char& operator[](size_t idx) const
	{
#if STRING_SAFE_MDOE
		return at(idx);
#else
		return mCharArr[idx];
#endif
	}

	inline char& at(size_t idx) { return at(idx); }
	inline const char& at(size_t idx) const { return at(idx); }

	inline const char& front() const
	{
#if STRING_SAFE_MDOE
		JUT_ASSERT(empty(), "front() used on empty string\n");
#endif
		return mCharArr[0];
	}

	inline char& front()
	{
#if STRING_SAFE_MDOE
		JUT_ASSERT(empty(), "front() used on empty string\n");
#endif
		return mCharArr[0];
	}

	inline const char& back() const
	{
#if STRING_SAFE_MDOE
		JUT_ASSERT(empty(), "back() used on empty string\n");
#endif
		return mCharArr[mCharArr.size() - 2];
	}

	inline char& back()
	{
#if STRING_SAFE_MDOE
		JUT_ASSERT(empty(), "back() used on empty string\n");
#endif
		return mCharArr[mCharArr.size() - 2];
	}

	// resizes the string
	void resize(size_t n)
	{
		mCharArr.resize(n + 1);
		mCharArr[n] = '\0';
	}

	// changes the string's capacity
	void reserve(size_t n) { mCharArr.reserve(n + 1); }

	void clear() { mCharArr.assign(1, '\0'); }

	void shrink_to_fit() { mCharArr.shrink_to_fit(); }

	void operator+=(const String& str) { append(str); }

	void operator+=(const char* s) { append(s); }

	void operator+=(char c) { push_back(c); }

	String& append(const String& other)
	{
		mCharArr.resize(mCharArr.size() - 1);
		mCharArr.push_back(other.mCharArr);
		return *this;
	}

	String& append(const String& other, size_t subpos, size_t sublen)
	{
#if STRING_SAFE_MDOE
		if (subpos > other.length() || subpos + sublen > other.length()) {
			JUT_PANIC("String %s appended %s with pos %i and length %i", c_str(), other, subpos, sublen);
		}
#endif
		if (sublen == npos) {
			sublen = other.length() - subpos;
		}

		mCharArr.resize(mCharArr.size() - 1);
		mCharArr.push_back(sublen + 1, &other.c_str()[subpos]);
		_null_terminate();
		return *this;
	}

	String& append(const char* s)
	{
		mCharArr.resize(mCharArr.size() - 1);
		mCharArr.push_back(strlen(s) + 1, s);
		return *this;
	}

	String& append(const char* s, size_t n)
	{
		mCharArr.push_back(n + 1, s);
		_null_terminate();
		return *this;
	}

	// fill new space
	String& append(size_t n, char c)
	{
		size_t oldsize = mCharArr.size();
		mCharArr.resize(oldsize - 1); // yes this has to be here
		mCharArr.resize(oldsize + n, c);

		_null_terminate();
		return *this;
	}

	String& assign(const String& other)
	{
		mCharArr = other.mCharArr;
		return *this;
	}

	String& assign(const String& other, size_t subpos, size_t sublen)
	{
#if STRING_SAFE_MDOE
		if (subpos > other.length() || subpos + sublen > other.length()) {
			JUT_PANIC("String %s assigned %s with pos %i and length %i", c_str(), other, subpos, sublen);
		}
#endif
		if (sublen == npos) {
			sublen = other.length() - subpos;
		}

		mCharArr.assign(sublen, &other.c_str()[subpos]);
		mCharArr.push_back('\0');
		return *this;
	}

	String& assign(const char* s)
	{
		mCharArr.assign(strlen(s) + 1, s);
		return *this;
	}

	String& assign(const char* s, size_t n)
	{
		mCharArr.assign(n + 1, s);
		mCharArr[n] = '\0';
		return *this;
	}

	// fill
	String& assign(size_t n, char c)
	{
		mCharArr.assign(n + 1, c);
		mCharArr[n] = '\0';
		return *this;
	}

	void push_back(char c)
	{
		mCharArr.back() = c;
		mCharArr.push_back('\0');
	}

	String& insert(size_t pos, const String& other)
	{
#if STRING_SAFE_MDOE
		JUT_ASSERT(pos <= size(), "insert out of bounds");
#endif
		mCharArr.insert(pos, other.size(), other.data());
		return *this;
	}

	String& insert(size_t pos, const String& other, size_t subpos, size_t sublen)
	{
#if STRING_SAFE_MDOE
		JUT_ASSERT(pos <= size(), "insert out of bounds");
#endif

#if STRING_SAFE_MDOE
		if (subpos > other.length() || subpos + sublen > other.length()) {
			JUT_PANIC("String %s appended %s with pos %i and length %i", c_str(), other, subpos, sublen);
		}
#endif
		if (sublen == npos) {
			sublen = other.length() - subpos;
		}

		mCharArr.insert(pos, sublen, &other.c_str()[subpos]);
		return *this;
	}

	String& insert(size_t pos, const char* s)
	{
#if STRING_SAFE_MDOE
		JUT_ASSERT(pos <= size(), "insert out of bounds");
#endif
		mCharArr.insert(pos, strlen(s) + 1, s);
		return *this;
	}

	String& insert(size_t pos, const char* s, size_t n) { return insert(pos, String(s, n)); }

	// fill new space
	String& insert(size_t pos, size_t n, char c)
	{
		mCharArr.insert(pos, n, c);
		return *this;
	}

	String& erase(size_t pos = 0, size_t len = npos)
	{
#if STRING_SAFE_MDOE
		JUT_ASSERT(pos <= size(), "erase out of bounds");
#endif

#if STRING_SAFE_MDOE
		if (len > length()) {
			JUT_PANIC("String %s erase at pos %i length %i", c_str(), pos, len);
		}
#endif
		if (len == npos) {
			mCharArr.erase(pos, length());
			return *this;
		}

		mCharArr.erase(pos, pos + len);
	}

	// string
	String& replace(size_t pos, size_t len, const String& str)
	{
		erase(pos, len);
		return insert(pos, str);
	}

	// substring
	String& replace(size_t pos, size_t len, const String& str, size_t subpos, size_t sublen)
	{
		erase(pos, len);
		return insert(pos, str, subpos, sublen);
	}

	// c-string
	String& replace(size_t pos, size_t len, const char* cstr)
	{
		erase(pos, len);
		return insert(pos, cstr);
	}

	// buffer
	String& replace(size_t pos, size_t len, const char* cstr, size_t n)
	{
		erase(pos, len);
		return insert(pos, cstr, n);
	}

	// fill
	String& replace(size_t pos, size_t len, size_t n, char c)
	{
		erase(pos, len);
		return insert(pos, n, c);
	}

	void swap(String& other) { mCharArr.swap(other.mCharArr); }

	void pop_back()
	{
		mCharArr.pop_back();
		_null_terminate();
	}

	// does not append a null character at the end of the copied content
	size_t copy(char* s, size_t len = npos, size_t pos = 0) const
	{
#if STRING_SAFE_MDOE
		JUT_ASSERT(pos <= size(), "copy out of bounds");
#endif
		size_t maxlength = length() - pos;
		if (len > maxlength) {
			len = maxlength;
		}

		for (int i = 0; i < len; i++) {
			s[i] = mCharArr[pos + i];
		}
		return len;
	}

	char* copy() const
	{
		char* buffer = new char[mCharArr.size()];
		copy(buffer);
		buffer[mCharArr.size() - 1] = '\0';
		return buffer;
	}

	size_t find(const String& str, size_t pos = 0) const
	{
#if STRING_SAFE_MDOE
		JUT_ASSERT(pos <= size(), "find out of bounds");
#endif
		size_t count    = 0;
		size_t required = str.size();

		for (size_t i = pos; i < size(); i++) {
			if (mCharArr[i] == str[count]) {
				count++;
				if (count == required) {
					return i - count;
				}
			} else if (mCharArr[i] == str.front()) {
				count = 1;
			} else {
				count = 0;
			}
		}
		return npos;
	}

	size_t find(const char* s, size_t pos = 0) const
	{
#if STRING_SAFE_MDOE
		JUT_ASSERT(pos <= size(), "find out of bounds");
#endif
		size_t count    = 0;
		size_t required = strlen(s);

		for (size_t i = pos; i < size(); i++) {
			if (mCharArr[i] == s[count]) {
				count++;
				if (count == required) {
					return i - count;
				}
			} else if (mCharArr[i] == s[0]) {
				count = 1;
			} else {
				count = 0;
			}
		}
		return npos;
	}

	size_t find(const char* s, size_t pos, size_t n) const
	{
#if STRING_SAFE_MDOE
		JUT_ASSERT(pos <= size(), "find out of bounds");
#endif
		size_t count    = 0;
		size_t required = n;

		for (size_t i = pos; i < size(); i++) {
			if (mCharArr[i] == s[count]) {
				count++;
				if (count == required) {
					return i - count;
				}
			} else if (mCharArr[i] == s[0]) {
				count = 1;
			} else {
				count = 0;
			}
		}
		return npos;
	}

	size_t find(char c, size_t pos = 0) const
	{
#if STRING_SAFE_MDOE
		JUT_ASSERT(pos <= size(), "find out of bounds");
#endif

		for (size_t i = pos; i < size(); i++) {
			if (mCharArr[i] == c) {
				return i;
			}
		}
		return npos;
	}

	size_t rfind(const String& str, size_t pos = npos) const
	{
#if STRING_SAFE_MDOE
		JUT_ASSERT(pos <= size() - str.length(), "rfind out of bounds");
#endif
		if (pos == npos) {
			pos = length() - 1;
		} else {
			pos += str.length();
		}

		size_t count = str.length();

		for (size_t i = pos; i >= 0; i--) {
			if (mCharArr[i] == str[count - 1]) {
				count--;
				if (count == 0) {
					return i;
				}
			} else if (mCharArr[i] == str.back()) {
				count = str.length() - 1;
			} else {
				count = str.length();
			}
		}
		return npos;
	}

	size_t rfind(const char* s, size_t pos = npos) const
	{
		size_t len = strlen(s);
#if STRING_SAFE_MDOE
		JUT_ASSERT(pos <= size() - len, "rfind out of bounds");
#endif
		if (pos == npos) {
			pos = length() - 1;
		} else {
			pos += len;
		}

		size_t count = len;

		for (size_t i = pos; i >= 0; i--) {
			if (mCharArr[i] == s[count - 1]) {
				count--;
				if (count == 0) {
					return i;
				}
			} else if (mCharArr[i] == s[len - 1]) {
				count = len - 1;
			} else {
				count = len;
			}
		}
		return npos;
	}

	size_t rfind(const char* s, size_t pos, size_t n) const
	{
		size_t len = n;
#if STRING_SAFE_MDOE
		JUT_ASSERT(pos <= size() - len, "rfind out of bounds");
#endif
		if (pos == npos) {
			pos = length() - 1;
		} else {
			pos += len;
		}

		size_t count = len;

		for (size_t i = pos; i >= 0; i--) {
			if (mCharArr[i] == s[count - 1]) {
				count--;
				if (count == 0) {
					return i;
				}
			} else if (mCharArr[i] == s[len - 1]) {
				count = len - 1;
			} else {
				count = len;
			}
		}
		return npos;
	}

	size_t rfind(char c, size_t pos = npos) const
	{
#if STRING_SAFE_MDOE
		JUT_ASSERT(pos <= size(), "find out of bounds");
#endif
		if (pos == npos)
			pos = length() - 1;

		for (size_t i = pos; i >= 0; i--) {
			if (mCharArr[i] == c) {
				return i;
			}
		}
		return npos;
	}

	size_t find_first_of(const String& str, size_t pos = 0) const
	{
#if STRING_SAFE_MDOE
		JUT_ASSERT(pos <= size(), "find_first_of out of bounds");
#endif

		for (size_t i = 0; i < str.length(); i++) {
			size_t out = find(str[i], pos);
			if (out != npos) {
				return out;
			}
		}
		return npos;
	}

	size_t find_first_of(const char* s, size_t pos = 0) const
	{
#if STRING_SAFE_MDOE
		JUT_ASSERT(pos <= size(), "find_first_of out of bounds");
#endif

		for (size_t i = 0; i < strlen(s); i++) {
			size_t out = find(s[i], pos);
			if (out != npos) {
				return out;
			}
		}
		return npos;
	}

	size_t find_first_of(const char* s, size_t pos, size_t n) const
	{
#if STRING_SAFE_MDOE
		JUT_ASSERT(pos <= size(), "find_first_of out of bounds");
#endif

		for (size_t i = 0; i < n; i++) {
			size_t out = find(s[i], pos);
			if (out != npos) {
				return out;
			}
		}
		return npos;
	}

	size_t find_first_of(char c, size_t pos = 0) const
	{
#if STRING_SAFE_MDOE
		JUT_ASSERT(pos <= size(), "find_first_of out of bounds");
#endif

		return find(c, pos);
	}

	size_t find_last_of(const String& str, size_t pos = 0) const
	{
#if STRING_SAFE_MDOE
		JUT_ASSERT(pos <= size(), "find_last_of out of bounds");
#endif

		for (size_t i = 0; i < str.length(); i++) {
			size_t out = rfind(str[i], pos);
			if (out != npos) {
				return out;
			}
		}
		return npos;
	}

	size_t find_last_of(const char* s, size_t pos = 0) const
	{
#if STRING_SAFE_MDOE
		JUT_ASSERT(pos <= size(), "find_last_of out of bounds");
#endif

		for (size_t i = 0; i < strlen(s); i++) {
			size_t out = rfind(s[i], pos);
			if (out != npos) {
				return out;
			}
		}
		return npos;
	}

	size_t find_last_of(const char* s, size_t pos, size_t n) const
	{
#if STRING_SAFE_MDOE
		JUT_ASSERT(pos <= size(), "find_last_of out of bounds");
#endif

		for (size_t i = 0; i < n; i++) {
			size_t out = rfind(s[i], pos);
			if (out != npos) {
				return out;
			}
		}
		return npos;
	}

	size_t find_last_of(char c, size_t pos = 0) const
	{
#if STRING_SAFE_MDOE
		JUT_ASSERT(pos <= size(), "find_last_of out of bounds");
#endif

		return rfind(c, pos);
	}

	size_t find_first_not_of(const String& str, size_t pos = 0) const
	{
#if STRING_SAFE_MDOE
		JUT_ASSERT(pos <= size(), "find_first_not_of out of bounds");
#endif

		for (size_t i = 0; i < str.length(); i++) {
			size_t out = find_first_not_of(str[i], pos);
			if (out != npos) {
				return out;
			}
		}
		return npos;
	}

	size_t find_first_not_of(const char* s, size_t pos = 0) const
	{
#if STRING_SAFE_MDOE
		JUT_ASSERT(pos <= size(), "find_first_not_of out of bounds");
#endif

		for (size_t i = 0; i < strlen(s); i++) {
			size_t out = find_first_not_of(s[i], pos);
			if (out != npos) {
				return out;
			}
		}
		return npos;
	}

	size_t find_first_not_of(const char* s, size_t pos, size_t n) const
	{
#if STRING_SAFE_MDOE
		JUT_ASSERT(pos <= size(), "find_first_not_of out of bounds");
#endif

		for (size_t i = 0; i < n; i++) {
			size_t out = find_first_not_of(s[i], pos);
			if (out != npos) {
				return out;
			}
		}
		return npos;
	}

	size_t find_first_not_of(char c, size_t pos = 0) const
	{
#if STRING_SAFE_MDOE
		JUT_ASSERT(pos <= size(), "find_first_not_of out of bounds");
#endif

		for (size_t i = pos; i < size(); i++) {
			if (mCharArr[i] != c) {
				return i;
			}
		}
		return npos;
	}

	size_t find_last_not_of(const String& str, size_t pos = 0) const
	{
#if STRING_SAFE_MDOE
		JUT_ASSERT(pos <= size(), "find_last_not_of out of bounds");
#endif

		for (size_t i = 0; i < str.length(); i++) {
			size_t out = find_last_not_of(str[i], pos);
			if (out != npos) {
				return out;
			}
		}
		return npos;
	}

	size_t find_last_not_of(const char* s, size_t pos = 0) const
	{
#if STRING_SAFE_MDOE
		JUT_ASSERT(pos <= size(), "find_last_not_of out of bounds");
#endif

		for (size_t i = 0; i < strlen(s); i++) {
			size_t out = find_last_not_of(s[i], pos);
			if (out != npos) {
				return out;
			}
		}
		return npos;
	}

	size_t find_last_not_of(const char* s, size_t pos, size_t n) const
	{
#if STRING_SAFE_MDOE
		JUT_ASSERT(pos <= size(), "find_last_not_of out of bounds");
#endif

		for (size_t i = 0; i < n; i++) {
			size_t out = find_last_not_of(s[i], pos);
			if (out != npos) {
				return out;
			}
		}
		return npos;
	}

	size_t find_last_not_of(char c, size_t pos = npos) const
	{
#if STRING_SAFE_MDOE
		JUT_ASSERT(pos <= size(), "find_last_not_of out of bounds");
#endif
		if (pos == npos)
			pos = length() - 1;

		for (size_t i = pos; i >= 0; i--) {
			if (mCharArr[i] != c) {
				return i;
			}
		}
		return npos;
	}

	String substr(size_t pos = 0, size_t len = npos) const
	{
		size_t maxsize = size() - pos;
		if (len > maxsize) {
			len = maxsize;
		}
		return String(&c_str()[pos], len);
	}

	int compare(const String& str) const { return strcmp(c_str(), str.c_str()); }

	int compare(size_t pos, size_t len, const String& str) const
	{
		if (len == npos)
			len = size() - pos;
		return strncmp(&c_str()[pos], str.c_str(), len);
	}

	int compare(size_t pos, size_t len, const String& str, size_t subpos, size_t sublen) const
	{
		if (len == npos)
			len = size() - pos;
		if (sublen == npos)
			sublen = str.size() - subpos;

		return strncmp(&c_str()[pos], &str.c_str()[subpos], MIN(len, sublen));
	}

	int compare(size_t pos, size_t len, const char* s, size_t n) const
	{
		if (len == npos)
			len = size() - pos;
		return strncmp(&c_str()[pos], s, MIN(len, n));
	}

	void write(Stream& stream) { stream.writeString(data()); }

	void read(Stream& stream)
	{
		char* buff = stream.readString(nullptr, 0);
		assign(buff);
		delete[] buff;
	}

	static String format(const char* formatStr, ...)
	{
		va_list args;
		va_start(args, formatStr);
		String outStr = _format(formatStr, args);
		va_end(args);

		return outStr;
	}

	static String format(const String& formatStr, ...)
	{
		va_list args;
		va_start(args, formatStr);
		String outStr = _format(formatStr.c_str(), args);
		va_end(args);

		return outStr;
	}

	bool ends_with(const String& suffix) const
	{
		return size() >= suffix.size() && compare(size()-suffix.size(), suffix.size(), suffix) == 0;
	}

	bool starts_with(const String& prefix) const
	{
		return size() >= prefix.size() && compare(0, prefix.size(), prefix) == 0;
	}

	// some extra helper overloads:

	bool ends_with(const char* suffix, size_t suffixLen) const
	{
		return size() >= suffixLen && compare((size_t)size()-suffixLen, (size_t)suffixLen, suffix, (size_t)suffixLen) == 0;
	}

	bool ends_with(const char* suffix) const
	{
		return ends_with(suffix, strlen(suffix));
	}

	bool starts_with(const char* prefix, size_t prefixLen) const
	{
		return size() >= prefixLen && compare(0, prefixLen, prefix, prefixLen) == 0;
	}

	bool starts_with(const char* prefix) const
	{
		return starts_with(prefix, strlen(prefix));
	}

private:
	ArrayList<char> mCharArr;
};

String operator+(const String& lhs, const String& rhs)
{
	String start = lhs;
	start += rhs;
	return start;
}

String operator+(const String& lhs, const char* rhs)
{
	String start = lhs;
	start += rhs;
	return start;
}

String operator+(const char* lhs, const String& rhs)
{
	String start = lhs;
	start += rhs;
	return start;
}

String operator+(const String& lhs, char rhs)
{
	String start = lhs;
	start += rhs;
	return start;
}

String operator+(char lhs, const String& rhs)
{
	String start = lhs;
	start += rhs;
	return start;
}

bool operator==(const String& lhs, const String& rhs) { return lhs.compare(rhs) == 0; }
bool operator==(const String& lhs, const char* rhs) { return lhs.compare(rhs) == 0; }
bool operator==(const char* lhs, const String& rhs) { return rhs.compare(lhs) == 0; }

bool operator!=(const String& lhs, const String& rhs) { return lhs.compare(rhs) != 0; }
bool operator!=(const String& lhs, const char* rhs) { return lhs.compare(rhs) != 0; }
bool operator!=(const char* lhs, const String& rhs) { return rhs.compare(lhs) != 0; }

bool operator<(const String& lhs, const String& rhs) { return lhs.compare(rhs) < 0; }
bool operator<(const String& lhs, const char* rhs) { return lhs.compare(rhs) < 0; }
bool operator<(const char* lhs, const String& rhs) { return rhs.compare(lhs) > 0; }

bool operator<=(const String& lhs, const String& rhs) { return lhs.compare(rhs) <= 0; }
bool operator<=(const String& lhs, const char* rhs) { return lhs.compare(rhs) <= 0; }
bool operator<=(const char* lhs, const String& rhs) { return rhs.compare(lhs) >= 0; }

bool operator>(const String& lhs, const String& rhs) { return lhs.compare(rhs) > 0; }
bool operator>(const String& lhs, const char* rhs) { return lhs.compare(rhs) > 0; }
bool operator>(const char* lhs, const String& rhs) { return rhs.compare(lhs) < 0; }

bool operator>=(const String& lhs, const String& rhs) { return lhs.compare(rhs) >= 0; }
bool operator>=(const String& lhs, const char* rhs) { return lhs.compare(rhs) >= 0; }
bool operator>=(const char* lhs, const String& rhs) { return rhs.compare(lhs) <= 0; }



namespace FilePath {

// excludes trailing '/'
static String GetParentDirectory(const String& str) { return str.substr(0, str.find_last_of('/', str.size())); }

static String TruncateFileExtension(const String& str) { return str.substr(0, str.find_last_of('.', str.size())); }

} // namespace FilePath

} // namespace ModdingUtility

typedef ModdingUtility::String string;

#endif
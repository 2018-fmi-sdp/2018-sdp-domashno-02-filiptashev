#include "String.h"

#include <cassert>

void String::copyFrom(const String& other) {
  using std::strcpy;

  assert(_data == NULL && _size == 0);
  if (other._size == 0)
    return;

  _size = other._size;
  _data = new char[_size + 1];
  strcpy(_data, other._data);
}

void String::deleteThis() {
  delete [] _data;
  _data = NULL;
  _size = 0;
}

String::String() : _data(NULL), _size(0) {}

String::~String() {
  deleteThis();
}

String::String(const String& other)  : _data(NULL), _size(0) { // : String() in c++ >11
  copyFrom(other);
}

String& String::operator=(const String& other) {
  if (this == &other)
    return *this;

  deleteThis();
  copyFrom(other);
}

String::String(unsigned int size) : _data(NULL), _size(0) {
  _data = new char[size + 1];
  _size = size;
  memset(_data, '\0', _size + 1);
}

void String::resize(unsigned int newSize) {
  using std::strncpy;

  if (newSize == 0) {
    deleteThis();
    return;
  }

  char* tmp = new char[newSize + 1];
  unsigned int copySize = newSize < _size ? newSize : _size; // min
  strncpy(tmp, _data, copySize);
  tmp[newSize] = '\0';

  deleteThis();
  _data = tmp;
  _size = newSize;
}

std::ostream& operator<<(std::ostream& out, const String& s) {
  if (s._size != 0)
    out << s._data;
  return out;
}

std::istream& operator>>(std::istream& in, String& s) {
  const unsigned int BUFFER_SIZE = 16;
  String bufferedInput(BUFFER_SIZE);
  in.getline(bufferedInput._data, BUFFER_SIZE + 1);
  unsigned int offset = BUFFER_SIZE;
  while (in.fail()) {
    in.clear(std::ios::goodbit);

    bufferedInput.resize(bufferedInput._size + BUFFER_SIZE);
    in.getline(bufferedInput._data + offset, BUFFER_SIZE + 1);
    offset += BUFFER_SIZE;
  }
  s = bufferedInput;

  return in;
}

/*static*/ String String::reverse(const String& s) {
  if (s.len() < 2)
    return s;

  String result(s.len());
  for (unsigned int i=0; i < s.len(); i++) {
    result[i] = s[s.len() - i - 1];
  }

  return result;
}

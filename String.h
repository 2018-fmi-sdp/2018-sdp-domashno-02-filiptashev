#pragma once

/**
 * @file Този файл декларира класът String, който използваме
 *  за представяне на низове в динамичната памет.
 */

#include <iostream>
#include <cstring>

class String {
private:
  char* _data;
  unsigned int _size;

  void copyFrom(const String& other);
  void deleteThis();

public:
  String();
  ~String();
  String(const String& other);
  String& operator=(const String& other);

  String(unsigned int size);
  String(const char* s) : _data(NULL), _size(0) { _size = strlen(s); _data = new char[_size + 1]; strcpy(_data, s); }

  bool operator==(const char* s) const { return strcmp(_data, s) == 0; }
  bool startsWith(const char* s) const { return len() >= strlen(s) && strncmp(_data, s, strlen(s)) == 0; }

  unsigned int size() const { return _size; }
  unsigned int len() const { return _data ? std::strlen(_data) : 0; }
  bool empty() const { return len() == 0; }

  const char* data() const { return _data; }
  char* data() { return _data; }

  char& operator[](unsigned int i) { return _data[i]; }
  const char& operator[](unsigned int i) const { return _data[i]; }

  void resize(unsigned int newSize);

  friend std::ostream& operator<<(std::ostream& o, const String& s);
  friend std::istream& operator>>(std::istream& o, String& s);

  static String reverse(const String& s);
};



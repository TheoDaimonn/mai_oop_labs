#pragma once
#include <initializer_list>
#include <string>

void isValid(unsigned char digit);

class Twelve {
public:
//inits
    Twelve();
    Twelve(const size_t & n, unsigned char t = 0);
    Twelve(const std::initializer_list< unsigned char> &t);
    Twelve(const std::string &t);
    Twelve(const Twelve& other);
    Twelve(Twelve&& other) noexcept;
    virtual ~Twelve() noexcept;

//arythmetics overload
  Twelve& operator=(const Twelve& other);
  Twelve& operator+=(const Twelve& other);
  Twelve& operator-=(const Twelve& other);
  bool operator==(const Twelve& other) const;
  bool operator>(const Twelve& other) const;
  bool operator<(const Twelve& other) const;
  bool operator!= (const Twelve &other) const;
//attr getters
  size_t getSize() const;
  unsigned char* getData() const;
  void repr() const;
private:
  unsigned char* data;
  size_t size; 

};
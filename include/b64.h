#ifndef _B64_H
#define _B64_H

#include <iostream>
#include <string>
#define byte unsigned char

class Base64 {
public:
  Base64(){}
  Base64(const std::string& msg): msg(msg) {}
  void setEncode(const std::string& encoded){ this->encoded = encoded;}

  void encode();
  void decode();


  std::string getMsg() const { return this->msg; }
  std::string getEncode() const { return this->encoded; }
  std::string getDecode() const { return this->decoded; }

private:
  std::string encoded;
  std::string decoded;
  std::string msg;
  const char* table64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
};


#endif

// Copyright 2023 Prokofev Denis


#ifndef  MODULES_REV_POL_NOT_INCLUDE_POL_NOT_H_
#define  MODULES_REV_POL_NOT_INCLUDE_POL_NOT_H_

#include <string>
#include "include/lex.h"
#include "include/stack.h"

class PolNot {
 public:
    bool number(char c);
    int prior(Lex tmp);
    TQueue<Lex*>* sEOL(std::string _s);
    std::string revPolNot(TQueue<Lex*>* q);
};
#endif  //  MODULES_REV_POL_NOT_INCLUDE_POL_NOT_H_

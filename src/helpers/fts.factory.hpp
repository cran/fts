// -*- mode: C++; c-indent-level: 2; c-basic-offset: 2; tab-width: 8 -*-
#ifndef FTS_FACTORY_HPP
#define FTS_FACTORY_HPP

#include <stdexcept>
#include <cstring>
#include <Rinternals.h>

enum DatePolicyT { dateT, posixT, unknownDateTypeT };

class TsTypeTuple {
public:
  static DatePolicyT getIndexPolicyType(SEXP x) {
    SEXP klass = getAttrib(x,R_ClassSymbol);
    if(klass==R_NilValue) return unknownDateTypeT;
    if(strcmp(CHAR(STRING_ELT(klass,0)),"Date")==0) return dateT;
    if(strcmp(CHAR(STRING_ELT(klass,0)),"POSIXct")==0) return posixT;
    if(length(klass)>1 && strcmp(CHAR(STRING_ELT(klass,1)),"POSIXct")==0) return posixT;
    return unknownDateTypeT;
  }
  SEXPTYPE dateSEXPTYPE;
  SEXPTYPE dataSEXPTYPE;
  DatePolicyT datePolicy;
  TsTypeTuple(SEXP x):
  dateSEXPTYPE(TYPEOF(getAttrib(x,install("index")))),
  dataSEXPTYPE(TYPEOF(x)),
  datePolicy(getIndexPolicyType(getAttrib(x,install("index"))))
  {
    if(getAttrib(x,install("index"))==R_NilValue) {
      REprintf("Object has no index.");
    }
  }

  bool operator==(const TsTypeTuple& other) const {
    if(dateSEXPTYPE == other.dateSEXPTYPE &&
       dataSEXPTYPE == other.dataSEXPTYPE &&
       datePolicy == other.datePolicy) {
      return true;
    } else {
      return false;
    }
  }
  bool operator!=(const TsTypeTuple& other) const {
    return !(*this == other);
  }
};

#endif // FTS_FACTORY_HPP

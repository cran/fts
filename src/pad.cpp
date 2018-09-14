#define R_NO_REMAP
#include <Rinternals.h>
#include <tslib/tseries.hpp>
#include <R.tseries.data.backend.hpp>
#include <Rsexp.allocator.templates.hpp>
#include <Rtype.hpp>
#include <fts.factory.hpp>

using namespace tslib;


template<typename TDATE, typename TDATA,
         typename TSDIM,
         template<typename,typename,typename> class TSDATABACKEND,
         template<typename> class DatePolicy>
SEXP padFun(SEXP x, SEXP dates) {
  // build tseries from SEXP x
  TSDATABACKEND<TDATE,TDATA,TSDIM> tsData(x);
  TSeries<TDATE,TDATA,TSDIM,TSDATABACKEND,DatePolicy> ts(tsData);
  TSeries<TDATE,TDATA,TSDIM,TSDATABACKEND,DatePolicy> ans = ts.pad(Rallocator<TDATE>::RdataPtr(dates),Rallocator<TDATE>::RdataPtr(dates) + Rf_length(dates));
  return ans.getIMPL()->Robject;
}

SEXP padSpecializer(SEXP x, SEXP dates) {
  const TsTypeTuple tsTypeInfo(x);
  if(TYPEOF(dates) != tsTypeInfo.dateSEXPTYPE) {
    REprintf("padSpecializer: pad dates must be same storage.mode as index.");
    return R_NilValue;
  }

  if(TsTypeTuple::getIndexPolicyType(dates) != tsTypeInfo.datePolicy) {
    REprintf("padSpecializer: pad dates must be the same class as index.");
    return R_NilValue;
  }

  if(tsTypeInfo.dateSEXPTYPE==REALSXP && tsTypeInfo.dataSEXPTYPE==REALSXP && tsTypeInfo.datePolicy==dateT) {
    return padFun<double,double,R_len_t,JulianBackend,JulianDate>(x,dates);
  } else if(tsTypeInfo.dateSEXPTYPE==REALSXP && tsTypeInfo.dataSEXPTYPE==INTSXP && tsTypeInfo.datePolicy==dateT) {
    return padFun<double,int,R_len_t,JulianBackend,JulianDate>(x,dates);
  } else if(tsTypeInfo.dateSEXPTYPE==REALSXP && tsTypeInfo.dataSEXPTYPE==LGLSXP && tsTypeInfo.datePolicy==dateT) {
    return padFun<double,int,R_len_t,JulianBackend,JulianDate>(x,dates);
  } else if(tsTypeInfo.dateSEXPTYPE==INTSXP && tsTypeInfo.dataSEXPTYPE==REALSXP && tsTypeInfo.datePolicy==dateT) {
    return padFun<int,double,R_len_t,JulianBackend,JulianDate>(x,dates);
  } else if(tsTypeInfo.dateSEXPTYPE==INTSXP && tsTypeInfo.dataSEXPTYPE==INTSXP && tsTypeInfo.datePolicy==dateT) {
    return padFun<int,int,R_len_t,JulianBackend,JulianDate>(x,dates);
  } else if(tsTypeInfo.dateSEXPTYPE==INTSXP && tsTypeInfo.dataSEXPTYPE==LGLSXP && tsTypeInfo.datePolicy==dateT) {
    return padFun<int,int,R_len_t,JulianBackend,JulianDate>(x,dates);
  } else if(tsTypeInfo.dateSEXPTYPE==REALSXP && tsTypeInfo.dataSEXPTYPE==REALSXP && tsTypeInfo.datePolicy==posixT) {
    return padFun<double,double,R_len_t,PosixBackend,PosixDate>(x,dates);
  } else if(tsTypeInfo.dateSEXPTYPE==REALSXP && tsTypeInfo.dataSEXPTYPE==INTSXP && tsTypeInfo.datePolicy==posixT) {
    return padFun<double,int,R_len_t,PosixBackend,PosixDate>(x,dates);
  } else if(tsTypeInfo.dateSEXPTYPE==REALSXP && tsTypeInfo.dataSEXPTYPE==LGLSXP && tsTypeInfo.datePolicy==posixT) {
    return padFun<double,int,R_len_t,PosixBackend,PosixDate>(x,dates);
  } else if(tsTypeInfo.dateSEXPTYPE==INTSXP && tsTypeInfo.dataSEXPTYPE==REALSXP && tsTypeInfo.datePolicy==posixT) {
    return padFun<int,double,R_len_t,PosixBackend,PosixDate>(x,dates);
  } else if(tsTypeInfo.dateSEXPTYPE==INTSXP && tsTypeInfo.dataSEXPTYPE==INTSXP && tsTypeInfo.datePolicy==posixT) {
    return padFun<int,int,R_len_t,PosixBackend,PosixDate>(x,dates);
  } else if(tsTypeInfo.dateSEXPTYPE==INTSXP && tsTypeInfo.dataSEXPTYPE==LGLSXP && tsTypeInfo.datePolicy==posixT) {
    return padFun<int,int,R_len_t,PosixBackend,PosixDate>(x,dates);
  } else {
    //throw std::logic_error("unable to classify time series.");
    REprintf("diffSpecializer: unable to classify time series.");
    return R_NilValue;
  }
}

extern "C" SEXP pad(SEXP x, SEXP dates) {
  return padSpecializer(x,dates);
}


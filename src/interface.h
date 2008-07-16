#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <iostream> // to prevent length macro conflict
#include <Rinternals.h>

extern "C" {
  SEXP movingMean(SEXP x, SEXP periods);
  SEXP movingSum(SEXP x, SEXP periods);
  SEXP movingProduct(SEXP x, SEXP periods);
  SEXP movingMax(SEXP x, SEXP periods);
  SEXP movingMin(SEXP x, SEXP periods);
  SEXP movingStdev(SEXP x, SEXP periods);
  SEXP movingRank(SEXP x, SEXP periods);

  SEXP movingCov(SEXP x, SEXP y, SEXP periods);
  SEXP movingCor(SEXP x, SEXP y, SEXP periods);

  SEXP expandingMax(SEXP x);
  SEXP expandingMin(SEXP x);

  SEXP sinceNA(SEXP x);
  SEXP fillForward(SEXP x);
  SEXP fillBackward(SEXP x);
  SEXP fillValue(SEXP x,SEXP value);

  SEXP lag(SEXP x, SEXP periods);
  SEXP lead(SEXP x, SEXP periods);

  SEXP toQuarterly(SEXP x);
  SEXP toMonthly(SEXP x);
  SEXP toWeekly(SEXP x);
}

#endif // INTERFACE_HPP

// -*- mode: C++; c-indent-level: 2; c-basic-offset: 2; tab-width: 8 -*-

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
  SEXP analog(SEXP x, SEXP y, SEXP periods);

  SEXP expandingMax(SEXP x);
  SEXP expandingMin(SEXP x);

  SEXP sinceNA(SEXP x);
  SEXP fillForward(SEXP x);
  SEXP fillBackward(SEXP x);
  SEXP fillValue(SEXP x,SEXP value);

  SEXP pad(SEXP x, SEXP padDates);
  SEXP lag(SEXP x, SEXP periods);
  SEXP lead(SEXP x, SEXP periods);
  SEXP diff(SEXP x, SEXP periods);

  SEXP dailySum(SEXP x);
  SEXP monthlySum(SEXP x);

  SEXP toYearly(SEXP x);
  SEXP toQuarterly(SEXP x);
  SEXP toMonthly(SEXP x);
  SEXP toWeekly(SEXP x);
  SEXP toDaily(SEXP x);
  SEXP toHourly(SEXP x);
  SEXP toMinute(SEXP x);
  SEXP toSecond(SEXP x);

  SEXP rsi(SEXP x, SEXP periods);
  SEXP ema(SEXP x, SEXP periods);
}

#endif // INTERFACE_HPP

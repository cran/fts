///////////////////////////////////////////////////////////////////////////
// (C) Copyright David Vandevoorde and Nicolai M. Josuttis 2002.         //
//                                                                       //
// This program is free software: you can redistribute it and/or modify  //
// it under the terms of the GNU General Public License as published by  //
// the Free Software Foundation, either version 3 of the License, or     //
// (at your option) any later version.                                   //
//                                                                       //
// This program is distributed in the hope that it will be useful,       //
// but WITHOUT ANY WARRANTY; without even the implied warranty of        //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         //
// GNU General Public License for more details.                          //
//                                                                       //
// You should have received a copy of the GNU General Public License     //
// along with this program.  If not, see <http://www.gnu.org/licenses/>. //
///////////////////////////////////////////////////////////////////////////

/* The following code example is taken from the book
 * "C++ Templates - The Complete Guide"
 * by David Vandevoorde and Nicolai M. Josuttis, Addison-Wesley, 2002
 *
 * (C) Copyright David Vandevoorde and Nicolai M. Josuttis 2002.
 * Permission to copy, use, modify, sell and distribute this software
 * is granted provided this copyright notice appears in all copies.
 * This software is provided "as is" without express or implied
 * warranty, and with no claim as to its suitability for any purpose.
 */

#ifndef TS_PROMOTION_HPP
#define TS_PROMOTION_HPP

#include <tslib/ts.opps/ifthenelse.hpp>

namespace tslib {

  // primary template for type promotion
  template<typename T1, typename T2>
  class Promotion {
  public:
    typedef typename 
    IfThenElse<(sizeof(T1)>sizeof(T2)),
      T1,
      typename IfThenElse<(sizeof(T1)<sizeof(T2)),
      T2,
      void
      >::ResultT
    >::ResultT ResultT;
  };

  // partial specialization for two identical types
  template<typename T>
  class Promotion<T,T> {
  public:
    typedef T ResultT;
  };
} //namespace tslib

#endif // TS_PROMOTION_HPP

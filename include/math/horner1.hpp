/*
  Les Piegl, Wayne Tiller The Nurbs Book p.

*/


/*

    Permission is  hereby granted,  free of charge,  to any  person obtaining
   a  copy  of  this  software   and  associated  documentation  files  (the
   "Software"),  to  deal in  the  Software  without restriction,  including
   without  limitation the  rights  to use,  copy,  modify, merge,  publish,
   distribute, sublicense, and/or sell copies of the Software, and to permit
   persons  to whom  the Software  is  furnished to  do so,  subject to  the
   following conditions:
   The above copyright  notice and this permission notice  shall be included
   in all copies or substantial portions of the Software.
   THE  SOFTWARE  IS  PROVIDED  "AS  IS",  WITHOUT  WARRANTY  OF  ANY  KIND,
   EXPRESS  OR IMPLIED,  INCLUDING  BUT  NOT LIMITED  TO  THE WARRANTIES  OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN
   NO EVENT SHALL THE AUTHORS OR  COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
   DAMAGES OR  OTHER LIABILITY, WHETHER  IN AN  ACTION OF CONTRACT,  TORT OR
   OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
   USE OR OTHER DEALINGS IN THE SOFTWARE.


*/



#pragma once

//#ifndef MATH_HORNER1_HPP
//#define MATH_HORNER1_HPP

#include <cstddef>
template <typename T1, typename T2>
T1 horner1(T1 *a, const size_t n, const T2 u)
{

  T1 C = a[n - 1];

  for (size_t i = n - 2; i > 0; i--)
  {
    C = C * u + a[i];
  }

  C = C * u + a[0];

  return C;
}

template <class T, typename S, size_t o>
T horner(const T a[o], const S u)
{
  T C = a[o - 1];
  for (size_t i = o - 2; i > 0; i--)
  {
    C = C * u + a[i];
  }

  C = C * u + a[0];

  return C;
}

template <class T, typename S, size_t O_m, size_t O_n>
T horner(const T a[O_m * O_n], const S u, const S v)
{
  T b[O_n];

  for (size_t i = 0; i < O_n; i++)
  {
    b[i] = horner<T, S, O_m>(&a[i * O_m], u);
  }

  return horner<T, S, O_n>(b, v);
}

//#endif


/*
Licensed under the MIT license:

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



#ifndef MATH_CONSTANT_HPP
#define MATH_CONSTANT_HPP

#include <cmath>


/*
template <typename T>
constexpr T
*/


template <typename T>
constexpr T ZERO = T(0.0L);

template <typename T>
constexpr T HALF = T(0.5L);
template <typename T>
constexpr T ONE = T(1.0L);
template <typename T>
constexpr T TWO = T(2.0L);
template <typename T>
constexpr T THREE = T(3.0L);
template <typename T>
constexpr T FOUR = T(4.0L);
template <typename T>
constexpr T SIX = T(6.0L);
template <typename T>
constexpr T EIGHT = T(8.0L);

template <typename T>
constexpr T TEN = T(10.0L);

template <typename T>
constexpr T FIFTEEN = T(15.0L);

template <typename T>
constexpr T SEVENTY = T(70.0L);

template <typename T>
constexpr T MILLI = T(0.001L);

template <typename T>
const T PI = FOUR<T> * std::atan(T(1.0L));

template <typename T>
T pi(const T val) { return PI<T> * val; }

template <typename T>
constexpr T biasExponent(const T val){return ONE<T>/std::log(val);}

template <typename T>
constexpr T BIAS_GAMMA(0.73L); //  logmap.pdf

template <typename T>
constexpr T LOGMAP_BIAS(0.85L);

template <typename T>
constexpr T SCALED_LUMINANCE_FACTOR(0.18L);

#endif

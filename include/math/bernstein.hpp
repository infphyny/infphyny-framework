//Les Piegl,Wayne Tiller The Nurbs Book 2nd edition


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
#include <cstddef>
#include <array>
#include <vector>
#include "math/constant.hpp"

//A1.2 p.20 Compute bernstein polynomial B_i_n(u)

template <typename T, size_t o>
T bernstein(const size_t i, T u)
{

    if (i >= o)
    {
        return ZERO<T>;
    }

    std::array<T, o> temp;

    for (auto &t : temp)
    {
        t = ZERO<T>;
    }

    temp[o - 1 - i] = ONE<T>;
    const T u1 = ONE<T> - u;

    for (size_t k = 1; k < o; k++)
    {
        for (size_t j = o - 1; j >= k; j--)
        {
            temp[j] = u1 * temp[j] + u * temp[j - 1];
        }
    }

    return temp[o - 1];
}

//template <size_t n>
//using bernstein<> = TBernstein<float, size_t>;
//A1.3
template <typename T, size_t o>
void allBernstein(const T u, T b[o])
{
    b[0] = ONE<T>;
    const T u1 = ONE<T> - u;

    for (size_t j = 1; j < o; j++)
    {
        T saved = ZERO<T>;
        for (size_t k = 0; k < j; k++)
        {
            T temp = b[k];
            b[k] = saved + u1 * temp;
            saved = u * temp;
        }
        b[j] = saved;
    }
}

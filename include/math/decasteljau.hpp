//Les Piegl, Wayne Tiller The nurbs book 2nd edition


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



#pragma once

#include "math/constant.hpp"
#include <array>
#include <cstddef>


//A1.5
template <class T, typename S, size_t O_u>
T deCasteljau(const T p[O_u], const S u)
{
    std::array<T, O_u> q;

    std::copy(p, p + O_u, q);

    for (size_t k = 1; k < O_u; k++)
    {

        for (size_t i = 0; i < O_u - k; i++)
        {
            q[i] = q[i] * (ONE<S> - u) + q[i + 1] * u;
        }
    }

    return q[0];
}

/*
 * A1.7
This function is more efficient if O_m < O_n
*/
template <class T, typename S, size_t O_m, size_t O_n>
T deCasteljau(const T p[O_m * O_n], const S u, const S v)
{
 T C;
    /*

    std::array<T, O_n> q;
    for (size_t j = 0; j < O_n; j++)
    {
        q[j] = deCasteljau<T, S, O_m>(p[j * O_m], u);
    }

    C = deCasteljau<T, S, O_n>(q, v);
    */


    if (O_m <= O_n)
    {
        std::array<T, O_n> q;
        for (size_t j = 0; j < O_n; j++)
        {
            q[j] = deCasteljau<T, S, O_m>(p[j * O_m], u);
        }

        C = deCasteljau<T, S, O_n>(q, v);
    }

    else
    {
        std::array<T, O_m> q;

        //transpose the array

        for (size_t j = 0; j < O_m; j++)
        {
            q[j] = deCasteljau<T, S, O_n>(p[j * O_n], v);
        }
        C = deCasteljau<T, S, O_m>(q, u);
    }


    return C;
}

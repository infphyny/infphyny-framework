

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


#ifndef BSPLINE_HPP
#define BSPLINE_HPP

#include <cstddef>
#include "math/constant.hpp"

//n=m-p-1
//p degre of basis function
//U knot vector


//Algorithm A2.1
//M = m+1
//n = m - p - 1  = M - p
template <typename S, size_t M>
size_t findSpan(size_t p,S u, S U[M])
{

   const size_t n = M - p;

    if( u == U[n+1])
    {
        return n;
    }

    size_t low = p;
    size_t high = n+1;

    size_t mid = (low + high)>>1;
    //binary search
    while(u < U[mid] || u >= U[mid+1])
    {
        if(u < U[mid])
        {
            high = mid;
        }
        else
        {
            low = mid;
        }

        mid = (low + high)>>1;
    }

    return mid;

}


//Algorithm 2.2
// i = findSpan(...)
//Compute nonzero basis function see example 2.3
//Compute N_i-p,p N_i,p
//M = m+1 : number of elements in the knot vector
template<typename S,size_t O_p,size_t M>
void basisFunctions(const size_t i,const S u,const size_t p,const S U[M], S N[O_p])
{
    N[0] = ONE<S>;
    S left[O_p];
    S right[O_p];

    for(size_t j = 1; j <= p ; j++ )
    {
        left[j] = u - U[i+1-j];
        right[j] = U[i+j]-u;

        S saved  = ZERO<S>;

        for(size_t r = 0 ; r < j ; r++)
        {
          S  temp = N[r]/(right[r+1]+left[j-r]);
          N[r] = saved + right[r+1]*temp;
          saved = left[j-r]*temp;
        }
        N[j] = saved;

    }

}

//A2.3
//Compute nth derivative of basis function
/*
template<typename S, size_t O_p,size_t R>
basisFunctionDerivatives(const size_t i,const S u,const size_t p,const size_t n,const S U[o_p+R],const S ders[o_p+R])
{

}
*/
#endif // BSPLINE_HPP

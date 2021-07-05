
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

#include "math/constant.hpp"
#include <cstddef>
#include <sstream>

constexpr size_t cm_mat2(const size_t row,const size_t column){return 2*column + row;}

template<typename T>
TMat2<T> invert(const TMat2<T>& m); 


template<typename T>
class TMat2;

template<typename T> 
class TVec2;


template<typename T>
class TMat2
{
public:
TMat2(const T val);
friend TMat2<T> invert<>(const TMat2<T>& mat);

private:
T m_data[4];
};

using mat2 = TMat2<float>;
using dmat2 = TMat2<double>;



template<typename T>
TMat2<T>::TMat2(const T val)
{
    m_data[0] = val;
    m_data[1] = ZERO<T>;
    m_data[2] = ZERO<T>;
    m_data[3] = val;
}

template <typename T>
TMat2<T> invert(const TMat2<T>& mat)
{
return mat2(ONE<T>);
}

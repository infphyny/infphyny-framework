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


#ifndef AABOX_HPP
#define AABOX_HPP

#include "math/vec3.hpp"


template <typename T>
class TAABox
{
public:
    TAABox(){}
    TAABox(const TVec3<T>& min,const TVec3<T>& max):m_min(min),m_max(max){}


    void setMinMax(const TVec3<T>& min,const TVec3<T>& max){m_min = min;
                                                   m_max = max;}

      const TVec3<T>& getMax(void)const{return m_max;}
      const TVec3<T>& getMin(void)const{return m_min;}



protected:

    TVec3<T> m_min;
    TVec3<T> m_max;

};

using AABox = TAABox<float>;


#endif // AABOX_HPP


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




#ifndef MATH_VEC2_HPP
#define MATH_VEC2_HPP

#include <limits>
#include <sstream>
#include <cstddef>
#include <cstdint>

template<typename T>
class TVec2;

namespace std
{


template< typename T > class numeric_limits< TVec2<T> > {
    public:
       static TVec2<T> lowest() {return TVec2<T>(std::numeric_limits<T>::lowest());}
       static TVec2<T> min() {return TVec2<T>(std::numeric_limits<T>::min());}
       static TVec2<T> max() {return TVec2<T>(std::numeric_limits<T>::max());}
};

}


template <typename T>
std::string to_string(const TVec2<T> &v);

//template<typename T>
//TVec2<T> std::numeric_limits< TVec2<T> >::max();



template<typename T> 
class TVec2 final
{
 public:

 TVec2(void){}
 TVec2(const T v0,const T v1){m_data[0] = v0; m_data[1] = v1;}
 TVec2(const T s){m_data[0] = s;m_data[1] = s;}


 const T* data()const{return &m_data[0];}
  

 T& operator[](const size_t i){return m_data[i];}
 const T& operator[](const size_t i )const{return m_data[i];}

 TVec2<T> operator*(const T s)
 {
     TVec2<T> result;
     result.m_data[0] = m_data[0]*s;
     result.m_data[1] = m_data[1]*s;

     return result;

 }

const TVec2<T>& operator=(const T s)
{
    m_data[0] = s;
    m_data[1] = s;

}
const TVec2<T>& operator=(const TVec2<T>& v)
{
    m_data[0] = v.m_data[0];
    m_data[1] = v.m_data[1];

    return *this;
}

TVec2<T> operator+(const TVec2<T>& v)const{  
TVec2<T> result;

  result.m_data[0] = m_data[0] + v.m_data[0];
  result.m_data[1] = m_data[1] + v.m_data[1]; 
  return result; 
}
  
  //template<typename T> 
  friend T dot(const TVec2<T>& v0,const TVec2<T>& v1)
  {
      return v0.m_data[0] * v1.m_data[0] + v0.m_data[1] * v1.m_data[1];
  } 
 

 private:
 friend std::string to_string<>(const TVec2 &v);
 T m_data[2];

};


using vec2  = TVec2<float>;
using dvec2 = TVec2<double>;
using ivec2 = TVec2<int32_t>;
using u8vec2 = TVec2<uint8_t>;


template <typename T>
std::string to_string(const TVec2<T> &v)
{
    std::ostringstream ss;

    ss << "vec2: " << "\t[" << v.m_data[0] << ";" << v.m_data[1]  << "]\n";

    std::string result(ss.str());

    return result;
}




#endif

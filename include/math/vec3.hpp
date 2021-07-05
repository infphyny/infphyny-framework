
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




//#pragma once

#ifndef MATH_VEC3_HPP
#define MATH_VEC3_HPP

#include <sstream>
#include <vector>

#include "math/constant.hpp"
#include "std/limits.hpp"

template <typename T>
class TMat4;

template<typename T>
class TVec4;

template <typename T>
class TVec3;

namespace std
{


template< typename T > class numeric_limits< TVec3<T> > {
    public:
        static TVec3<T> lowest() {return TVec3<T>(std::numeric_limits<T>::lowest());}
       static TVec3<T> min() {return TVec3<T>(std::numeric_limits<T>::min());}
       static TVec3<T> max() {return TVec3<T>(std::numeric_limits<T>::max());}
};

}





template<typename T>
class TQuaternion;


template <typename T>
T dot(const TVec3<T> &v0, const TVec3<T> &v1);

template <typename T>
TVec3<T> cross(const TVec3<T> &v0, const TVec3<T> &v1);

template<typename T>
T length(const TVec3<T>& v);

template<typename T>
T length2(const TVec3<T>& v);

template <typename T>
TVec3<T> max(const TVec3<T> &val, const T max);

template<typename T>
TVec3<T> max(const TVec3<T>& v0,const TVec3<T>& v1);

template<typename T>
TVec3<T> min(const TVec3<T>& val0,const TVec3<T>& val1);

template <typename T>
TVec3<T> normalize(const TVec3<T> &val);

template <typename T>
std::string to_string(const TVec3<T> &v);

template <typename T>
class TVec3
{

public:
    friend class TMat4<T>;
    friend class TQuaternion<T>;
    TVec3() {}
    TVec3(const T s) : m_data{s, s, s} {}
    TVec3(const T v0, const T v1, const T v2) : m_data{v0, v1, v2} {}

    // TVec3(TVec3 &&v) = default;

    const T &operator[](const size_t i) const
    {
        return m_data[i];
    }

    T &operator[](const size_t i)
    {
        return const_cast<T &>(const_cast<const TVec3<T> *>(this)->operator[](i));
    }


    TVec3<T> operator/(const T s)const
    {
        TVec3<T> result;

        result.m_data[0] = m_data[0]/s;
        result.m_data[1] = m_data[1]/s;
        result.m_data[2] = m_data[2]/s;
        return result;
    }


    const TVec3<T> &operator=(const TVec3<T> &v)
    {
        m_data[0] = v.m_data[0];
        m_data[1] = v.m_data[1];
        m_data[2] = v.m_data[2];
        return *this;
    }

    const TVec3<T>& operator=(const std::vector<T>& v)
    {

        size_t max_index = std::min(3lu,v.size());

        for(size_t i = 0 ; i < max_index ; i++)
        {
            m_data[i] = v[i];
        }
        return *this;
    }

   const TVec3<T>& operator=(const TVec4<T>& v)
   {
      float w_inv = ONE<T>/v.m_data[3];
       m_data[0] = v.m_data[0]*w_inv;
       m_data[1] = v.m_data[1]*w_inv;
       m_data[2] = v.m_data[2]*w_inv;

       return *this;
   }


    TVec3<T> operator*(const T v) const
    {
        TVec3<T> result;

        result.m_data[0] = m_data[0] * v;
        result.m_data[1] = m_data[1] * v;
        result.m_data[2] = m_data[2] * v;
        return result;
    }

    TQuaternion<T> operator*(const TQuaternion<T>& q)const
    {
        TQuaternion<T> result;

        result.m_s = -dot(*this,q.m_v);
        result.m_v = (*this)*q.m_s + cross(*this,q.m_v);

        return result;

    }

    const TVec3<T> &operator+=(const TVec3<T> &v)
    {

        m_data[0] += v.m_data[0];
        m_data[1] += v.m_data[1];
        m_data[2] += v.m_data[2];

        return *this;
    }


    const TVec3<T>& operator*=(const T s)
    {
        m_data[0]*=s;
        m_data[1]*=s;
        m_data[2]*=s;
        return *this;
    }

    TVec3<T> operator-(void)const
    {
        TVec3<T> result;
        result.m_data[0] = -m_data[0];
        result.m_data[1] = -m_data[1];
        result.m_data[2] = -m_data[2];
        return result;
    }

    TVec3<T> operator-(const TVec3<T> &v) const
    {
        TVec3<T> result;

        result.m_data[0] = m_data[0] - v.m_data[0];
        result.m_data[1] = m_data[1] - v.m_data[1];
        result.m_data[2] = m_data[2] - v.m_data[2];
        return result;
    }

    TVec3<T> operator+(const TVec3<T> &v) const
    {
        TVec3<T> result;

        result.m_data[0] = m_data[0] + v.m_data[0];
        result.m_data[1] = m_data[1] + v.m_data[1];
        result.m_data[2] = m_data[2] + v.m_data[2];

        return result;
    }

    TVec3<T> operator+(const T v) const
    {
        TVec3<T> result;

        result.m_data[0] = m_data[0] + v;
        result.m_data[1] = m_data[1] + v;
        result.m_data[2] = m_data[2] + v;
        return result;
    }

    friend TVec3<T> operator*(const float s,const TVec3<T>&v)
    {
        TVec3<T> result;

        result.m_data[0] = s*v.m_data[0];
        result.m_data[1] = s*v.m_data[1];
        result.m_data[2] = s*v.m_data[2];
        return result;
    }

    const T& x(void)const{return m_data[0];}
    const T& y(void)const{return m_data[1];}
    const T& z(void)const{return m_data[2];}
    T& x(void){return m_data[0];}
    T& y(void){return m_data[1];}
    T& z(void){return m_data[2];}


    friend TVec3<T> normalize<>(const TVec3<T> &v);

private:
    friend class TVec4<T>;
    friend T dot<>(const TVec3 &v0, const TVec3 &v1);
    friend TVec3 cross<>(const TVec3 &v0, const TVec3 &v1);
    friend T length<>(const TVec3 &v);
    friend T length2<>(const TVec3 &v);
    friend TVec3 max<>(const TVec3 &v, const T max);
    friend TVec3 max<>(const TVec3 &v0,const TVec3& v1);
    friend TVec3 min<>(const TVec3 & v0,const TVec3& v1);
    friend std::string to_string<>(const TVec3 &v);
    T m_data[3];
};

template <typename T>
TVec3<T> cross(const TVec3<T> &v0, const TVec3<T> &v1)
{
    TVec3<T> result;

    result.m_data[0] = v0.m_data[1] * v1.m_data[2] - v0.m_data[2] * v1.m_data[1];
    result.m_data[1] = v0.m_data[2] * v1.m_data[0] - v0.m_data[0] * v1.m_data[2];
    result.m_data[2] = v0.m_data[0] * v1.m_data[1] - v0.m_data[1] * v1.m_data[0];

    return result;
}

template <typename T>
T dot(const TVec3<T> &v0, const TVec3<T> &v1)
{
    return v0.m_data[0] * v1.m_data[0] + v0.m_data[1] * v1.m_data[1] + v0.m_data[2] * v1.m_data[2];
}

template<typename T>
T length(const TVec3<T> &v)
{
   return std::sqrt(dot(v, v));
}

template<typename T>
T length2(const TVec3<T>& v)
{
    return dot(v,v);
}


template <typename T>
TVec3<T> max(const TVec3<T> &v, const T max)
{

    TVec3<T> result;

    result.m_data[0] = (v.m_data[0] < max) ? v.m_data[0] : max;
    result.m_data[1] = (v.m_data[1] < max) ? v.m_data[1] : max;
    result.m_data[2] = (v.m_data[2] < max) ? v.m_data[2] : max;

    return result;
}

template<typename T>
TVec3<T> max(const TVec3<T>& v0,const TVec3<T>& v1)
{
    TVec3<T> result;

    result.m_data[0] = std::max(v0.m_data[0],v1.m_data[0]);
    result.m_data[1] = std::max(v0.m_data[1],v1.m_data[1]);
    result.m_data[2] = std::max(v0.m_data[2],v1.m_data[2]);

    return result;
}


template<typename T>
TVec3<T> min(const TVec3<T>& v0,const TVec3<T>& v1)
{
    TVec3<T> result;

    result.m_data[0] = std::min(v0.m_data[0],v1.m_data[0]);
    result.m_data[1] = std::min(v0.m_data[1],v1.m_data[1]);
    result.m_data[2] = std::min(v0.m_data[2],v1.m_data[2]);

    return result;

}


template <typename T>
TVec3<T> normalize(const TVec3<T> &v)
{
    TVec3<T> result;
    T l = ONE<T> / length(v);
    result.m_data[0] = v.m_data[0] * l;
    result.m_data[1] = v.m_data[1] * l;
    result.m_data[2] = v.m_data[2] * l;
    return result;
}

template <typename T>
std::string to_string(const TVec3<T> &v)
{
    std::ostringstream ss;

    ss << "vec3: "
       << "\n"
       << "\t[" << v.m_data[0] << ";" << v.m_data[1] << ";" << v.m_data[2] << "]\n";

    std::string result(ss.str());

    return result;
}

using vec3 = TVec3<float>;
using dvec3 = TVec3<double>;
using ivec3 = TVec3<int>;

#endif

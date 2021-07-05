
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





#ifndef MATH_VEC4_HPP
#define MATH_VEC4_HPP

#include <vector>
#include <sstream>
#include <cstdint>

template <typename T>
class TMat4;

template <typename T>
class TVec3;

template <typename T>
class TVec4;

template <typename T>
TVec4<T> max(const TVec4<T> &v, const T s);

template <typename T>
std::string to_string(const TVec4<T> &v);

template <typename T>
class TVec4
{

public:
    TVec4<T>() {}

    TVec4<T>(const T s) : m_data{s, s, s, s} {}
    TVec4<T>(const T s, const TVec3<T> &v) : m_data{s, v[0], v[1], v[2]}
    {
    }
    TVec4<T>(const TVec3<T>&v,const T s):m_data{v[0],v[1],v[2],s}{}

    TVec4<T>(const T v0, const T v1, const T v2, const T v3) : m_data{v0, v1, v2, v3}
    {
    }
    T &operator[](const size_t i) { return m_data[i]; }
    const T &operator[](const size_t i) const { return m_data[i]; }
    const TVec4<T> &operator=(const TVec4<T> &v)
    {
        m_data[0] = v.m_data[0];
        m_data[1] = v.m_data[1];
        m_data[2] = v.m_data[2];
        m_data[3] = v.m_data[3];

        return *this;
    }
    const TVec4<T> & operator=(const std::vector<T>& v)
    {
        size_t max = std::min(4lu,v.size());
       for(size_t i = 0 ; i < max ; i++)
        {
            m_data[i] = v[i];
        }

        return *this;

    }

    TVec4<T> operator+(const T s) const
    {
        TVec4<T> result;
        result.m_data[0] = m_data[0] + s;
        result.m_data[1] = m_data[1] + s;
        result.m_data[2] = m_data[2] + s;
        result.m_data[3] = m_data[3] + s;
        return result;
    }

    TVec4<T> operator*(const T s) const
    {
        TVec4<T> result;
        result.m_data[0] = m_data[0] * s;
        result.m_data[1] = m_data[1] * s;
        result.m_data[2] = m_data[2] * s;
        result.m_data[3] = m_data[3] * s;

        return result;
    }

    TVec3<T> xyz(void)const
    {
        TVec3<T> result;
        result.m_data[0] = m_data[0];
        result.m_data[1] = m_data[1];
        result.m_data[2] = m_data[2];
        return result;
    }


private:
    friend class TMat4<T>;
    friend class TVec3<T>;
    friend TVec4<T> max<>(const TVec4<T> &v, const T s);
    friend std::string to_string<>(const TVec4<T> &v);

private:
    T m_data[4];
};

using vec4 = TVec4<float>;
using dvec4 = TVec4<double>;
using ivec4 = TVec4<int>;
using u8vec4 = TVec4<uint8_t>;

template <typename T>
TVec4<T> max(const TVec4<T> &v, const T s)
{
    TVec4<T> result;
    result.m_data[0] = (v.m_data[0] < s) ? v.m_data[0] : s;
    result.m_data[1] = (v.m_data[1] < s) ? v.m_data[1] : s;
    result.m_data[2] = (v.m_data[2] < s) ? v.m_data[2] : s;
    result.m_data[3] = (v.m_data[3] < s) ? v.m_data[3] : s;

    return result;
}

template <typename T>
std::string to_string(const TVec4<T> &v)
{
    std::ostringstream ss;

    ss << "vec4: "
       << "\n"
       << "\t[" << v.m_data[0] << ";" << v.m_data[1] << ";" << v.m_data[2] << ";" << v.m_data[3] << "]\n";

    std::string result(ss.str());

    return result;
}

#endif


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
#include <sstream>
#include "math/constant.hpp"
//#include "math/mat3.hpp"
constexpr size_t cm_mat3(const size_t row, const size_t column) { return 3 * column + row; }

template <typename T>
class TMat3;

template <typename T>
class TVec3;

template <typename T>
TMat3<T> generate_mat3(const TVec3<T> &v0, const TVec3<T> &v1); //outer product ?

template <typename T>
std::string to_string(const TMat3<T> &m);

template <typename T>
class TMat3
{
public:
    TMat3<T>() {}
    TMat3<T>(const T m00, const T m10, const T m20, const T m01, const T m11, const T m21, const T m02, const T m12, const T m22)
    {
        m_data[0] = m00;
        m_data[1] = m10;
        m_data[2] = m20;
        m_data[3] = m01;
        m_data[4] = m11;
        m_data[5] = m21;
        m_data[6] = m02;
        m_data[7] = m12;
        m_data[8] = m22;
    }
    TMat3<T>(const T v)
    {
        m_data[0] = v;
        m_data[1] = ZERO<T>;
        m_data[2] = ZERO<T>;
        m_data[3] = ZERO<T>;
        m_data[4] = v;
        m_data[5] = ZERO<T>;
        m_data[6] = ZERO<T>;
        m_data[7] = ZERO<T>;
        m_data[8] = v;
    }

    T &operator[](const size_t i) { return m_data[i]; }
    const T &operator[](const size_t i) const { return m_data[i]; }


    const T& operator()(const size_t row,const size_t column)const
    {
        return m_data[cm_mat3(row,column)];
    }


    const TMat3<T> &operator=(const TMat3<T> &m)
    {
        for (size_t i = 0; i < 9; i++)
        {
            m_data[i] = m.m_data[i];
        }
        return *this;
    }

    TMat3<T> operator-(const TMat3<T> &m) const
    {
        TMat3<T> result;

        for (size_t i = 0; i < 9; i++)
        {
            result.m_data[i] = m_data[i] - m.m_data[i];
        }

        return result;
    }

    TMat3<T> operator+(const TMat3<T> &m) const
    {
        TMat3<T> result;

        for (size_t i = 0; i < 9; i++)
        {
            result.m_data[i] = m_data[i] + m.m_data[i];
        }

        return result;
    }

    TMat3<T> operator*(const TMat3<T> &m) const
    {
        TMat3<T> result;

        for (size_t i = 0; i < 3; i++) //Row
        {
            for (size_t j = 0; j < 3; j++) //Column
            {
                result.m_data[i + j * 3] = ZERO<T>;
                for (size_t k = 0; k < 4; k++)
                {
                    result.m_data[i + j * 3] += m_data[i + k * 3] * m.m_data[k + j * 3];
                }
            }
        }

        return result;
    }

    TMat3<T> operator*(const T v) const
    {
        TMat3<T> result;

        for (size_t i = 0; i < 9; i++)
        {
            result.m_data[i] = m_data[i] * v;
        }

        return result;
    }

private:
    friend TMat3<T> generate_mat3<>(const TVec3<T> &v0, const TVec3<T> &v1);
    friend std::string to_string<>(const TMat3<T> &m);

private:
    T m_data[9];
};

using mat3 = TMat3<float>;
using dmat3 = TMat3<double>;

template <typename T>
TMat3<T> generate_mat3(const TVec3<T> &v0, const TVec3<T> &v1)
{

    TMat3<T> result;

    for (size_t j = 0; j < 3; j++)
    {
        for (size_t i = 0; i < 3; i++)
        {
            result.m_data[i + j * 3] = v0[i] * v1[j];
        }
    }

    return result;
}

template <typename T>
std::string to_string(const TMat3<T> &m)
{
    std::ostringstream ss;

    ss << "Matrix3: "
       << "\n"
       << "\t[" << m.m_data[0] << ";" << m.m_data[3] << ";" << m.m_data[6] << "]\n"
       << "\t[" << m.m_data[1] << ";" << m.m_data[4] << ";" << m.m_data[7] << "]\n"
       << "\t[" << m.m_data[2] << ";" << m.m_data[5] << ";" << m.m_data[8] << "]\n";

    std::string result(ss.str());

    return result;
}

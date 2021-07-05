
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




#ifndef MATH_MAT4_HPP
#define MATH_MAT4_HPP

#include "math/constant.hpp"
#include <string>
#include <sstream>

constexpr size_t cm_mat4(const size_t row, const size_t column) { return 4 * column + row; }

template <typename T>
class TVec3;

template <typename T>
class TVec4;

template <typename T>
class TMat3;

template <typename T>
class TMat4;

template <typename T>
TMat4<T> lookAt(const TVec3<T> &eye, const TVec3<T> &center, const TVec3<T> &up);




template <typename T>
TMat4<T> rotate(const T angle, const TVec3<T> &axis);

template <typename T>
TMat4<T> translate(const TVec3<T> &t);





template <typename T>
std::string to_string(const TMat4<T> &m);

template <typename T>
TMat4<T> vk_ortho(const T left, const T right, const T bottom, const T top, const T near, const T far);

template <typename T>
TMat4<T> vk_projection(const T fovy, const T aspect, const T near, const T far);

template <typename T>
//Column major matrix
class TMat4
{

public:
    TMat4<T>() {}

    TMat4<T>(const float m[16])
    {

       for(size_t i = 0 ; i < 16 ; i++)
       {
           m_data[i] = m[i];
       }

    }


    TMat4<T>(const T v)
    {

        m_data[0] = v;
        m_data[1] = ZERO<T>;
        m_data[2] = ZERO<T>;
        m_data[3] = ZERO<T>;

        m_data[4] = ZERO<T>;
        m_data[5] = v;
        m_data[6] = ZERO<T>;
        m_data[7] = ZERO<T>;

        m_data[8] = ZERO<T>;
        m_data[9] = ZERO<T>;
        m_data[10] = v;
        m_data[11] = ZERO<T>;

        m_data[12] = ZERO<T>;
        m_data[13] = ZERO<T>;
        m_data[14] = ZERO<T>;
        m_data[15] = ONE<T>;
    }
    TMat4<T>(const TMat3<T> &m)
    {
        m_data[0] = m[0];
        m_data[1] = m[1];
        m_data[2] = m[2];
        m_data[3] = ZERO<T>;

        m_data[4] = m[3];
        m_data[5] = m[4];
        m_data[6] = m[5];
        m_data[7] = ZERO<T>;

        m_data[8] = m[6];
        m_data[9] = m[7];
        m_data[10] = m[8];
        m_data[11] = ZERO<T>;

        m_data[12] = ZERO<T>;
        m_data[13] = ZERO<T>;
        m_data[14] = ZERO<T>;
        m_data[15] = ONE<T>;
    }

    T& operator()(const size_t row,const size_t column){return m_data[cm_mat4(row,column)];}
    const T &operator[](const size_t i) const { return m_data[i]; }
    T &operator[](const size_t i) { return m_data[i]; }
    TMat4<T> operator*(const TMat4<T> &m) const
    {

        TMat4<T> result;

        for (size_t i = 0; i < 4; i++) //Row
        {
            for (size_t j = 0; j < 4; j++) //Column
            {
                result.m_data[i + j * 4] = ZERO<T>;
                for (size_t k = 0; k < 4; k++)
                {
                    result.m_data[i + j * 4] += m_data[i + k * 4] * m.m_data[k + j * 4];
                }
            }
        }

        return result;
    }

    TVec4<T> operator*(const TVec4<T> &v)const
    {
        TVec4<T> result;

        for (size_t j = 0; j < 4; j++)
        {
            T temp = ZERO<T>;
            for (size_t i = 0; i < 4; i++)
            {
                temp += m_data[cm_mat4(j, i)] * v[i];
            }
            result.m_data[j] = temp;
        }

        return result;
    }

    void setIdentity(void)
    {

        m_data[0] = ONE<T>;
        m_data[1] = ZERO<T>;
        m_data[2] = ZERO<T>;
        m_data[3] = ZERO<T>;

        m_data[4] = ZERO<T>;
        m_data[5] = ONE<T>;
        m_data[6] = ZERO<T>;
        m_data[7] = ZERO<T>;

        m_data[8] = ZERO<T>;
        m_data[9] = ZERO<T>;
        m_data[10] = ONE<T>;
        m_data[11] = ZERO<T>;

        m_data[12] = ZERO<T>;
        m_data[13] = ZERO<T>;
        m_data[14] = ZERO<T>;
        m_data[15] = ONE<T>;
    }

private:
    friend class TVec4<T>;

    friend TMat4<T> lookAt<>(const TVec3<T> &eye, const TVec3<T> &center, const TVec3<T> &up);
    friend TMat4<T> rotate<>(const T angle, const TVec3<T> &axis);
    friend std::string to_string<>(const TMat4<T> &m);
    friend TMat4<T> translate<>(const TVec3<T> &t);
    friend TMat4<T> vk_ortho<>(const T left, const T right, const T bottom, const T top, const T near, const T far);
    friend TMat4<T> vk_projection<>(const T fovy, const T aspect, const T near, const T far);
    //void setLookAt()

private:
    T m_data[16];
};

using mat4 = TMat4<float>;
using dmat4 = TMat4<double>;

//https://slideplayer.com/slide/8731554/
template <typename T>
TMat4<T> lookAt(const TVec3<T> &eye, const TVec3<T> &center, const TVec3<T> &up)
{
    TMat4<T> result;

    TVec3<T> n_right, n_view_dir, n_up;

    n_up = up;

    n_view_dir = normalize(eye-center);

    n_right = normalize(cross(n_up, n_view_dir));

   // n_right = normalize(n_right);

    n_up = -normalize(cross(n_right, n_view_dir));
  //  n_up = normalize(n_up);
  //  n_view_dir = normalize(n_view_dir);

    result.m_data[cm_mat4(0, 0)] = n_right[0];
    result.m_data[cm_mat4(0, 1)] = n_right[1];
    result.m_data[cm_mat4(0, 2)] = n_right[2];
    result.m_data[cm_mat4(0, 3)] = -dot(n_right,eye);

    result.m_data[cm_mat4(1, 0)] = n_up[0];
    result.m_data[cm_mat4(1, 1)] = n_up[1];
    result.m_data[cm_mat4(1, 2)] = n_up[2];
    result.m_data[cm_mat4(1, 3)] = -dot(n_up,eye);

    result.m_data[cm_mat4(2, 0)] = n_view_dir[0];
    result.m_data[cm_mat4(2, 1)] = n_view_dir[1];
    result.m_data[cm_mat4(2, 2)] = n_view_dir[2];
    result.m_data[cm_mat4(2, 3)] = -dot(n_view_dir,eye);

    result.m_data[cm_mat4(3, 0)] = ZERO<T>;
    result.m_data[cm_mat4(3, 1)] = ZERO<T>;
    result.m_data[cm_mat4(3, 2)] = ZERO<T>;
    result.m_data[cm_mat4(3, 3)] = ONE<T>;

    return result;
}

/*
  P.754 OpenGL programming guide V5.0
*/
template <typename T>
TMat4<T> rotate(const T angle, const TVec3<T> &axis)
{

    TVec3<T>
        n_axis = normalize(axis);
    TMat3<T> S(ZERO<T>, n_axis[2], -n_axis[1],
               -n_axis[2], ZERO<T>, n_axis[0],
               n_axis[1], -n_axis[0], ZERO<T>);

    TMat3<T> uu = generate_mat3(n_axis, n_axis);
    TMat3<T> M = uu + (TMat3<T>(ONE<T>) - uu) * std::cos(angle) + S * std::sin(angle);
    TMat4<T> result(M);
    return result;
}

template <typename T>
std::string to_string(const TMat4<T> &m)
{
    std::ostringstream ss;

    ss << "Matrix4: "
       << "\n"
       << "\t[" << m.m_data[0] << ";" << m.m_data[4] << ";" << m.m_data[8] << ";" << m.m_data[12] << "]\n"
       << "\t[" << m.m_data[1] << ";" << m.m_data[5] << ";" << m.m_data[9] << ";" << m.m_data[13] << "]\n"
       << "\t[" << m.m_data[2] << ";" << m.m_data[6] << ";" << m.m_data[10] << ";" << m.m_data[14] << "]\n"
       << "\t[" << m.m_data[3] << ";" << m.m_data[7] << ";" << m.m_data[11] << ";" << m.m_data[15] << "]";

    std::string result(ss.str());

    return result;
}

template <typename T>
TMat4<T> translate(const TVec3<T> &t)
{

    TMat4<T> result;

    result.m_data[0] = ONE<T>;
    result.m_data[1] = ZERO<T>;
    result.m_data[2] = ZERO<T>;
    result.m_data[3] = ZERO<T>;

    result.m_data[4] = ZERO<T>;
    result.m_data[5] = ONE<T>;
    result.m_data[6] = ZERO<T>;
    result.m_data[7] = ZERO<T>;

    result.m_data[8] = ZERO<T>;
    result.m_data[9] = ZERO<T>;
    result.m_data[10] = ONE<T>;
    result.m_data[11] = ZERO<T>;

    result.m_data[12] = t[0];
    result.m_data[13] = t[1];
    result.m_data[14] = t[2];
    result.m_data[15] = ONE<T>;

    return result;
}

template <typename T>
TMat4<T> vk_ortho(const T left, const T right, const T bottom, const T top, const T near, const T far)
{
    TMat4<T> result;

    //first column
    result.m_data[cm_mat4(0, 0)] = TWO<T> / (right - left);
    result.m_data[cm_mat4(1, 0)] = ZERO<T>;
    result.m_data[cm_mat4(2, 0)] = ZERO<T>;
    result.m_data[cm_mat4(3, 0)] = ZERO<T>;

    //second column
    result.m_data[cm_mat4(0, 1)] = ZERO<T>;
    result.m_data[cm_mat4(1, 1)] = TWO<T> / (bottom - top);
    result.m_data[cm_mat4(2, 1)] = ZERO<T>;
    result.m_data[cm_mat4(3, 1)] = ZERO<T>;

    //third
    result.m_data[cm_mat4(0, 2)] = ZERO<T>;
    result.m_data[cm_mat4(1, 2)] = ZERO<T>;
    result.m_data[cm_mat4(2, 2)] = ONE<T> / (near - far);
    result.m_data[cm_mat4(3, 2)] = ZERO<T>;

    //fourth
    result.m_data[cm_mat4(0, 3)] = (right + left) / (left - right);
    result.m_data[cm_mat4(1, 3)] = (bottom + top) / (top - bottom);
    result.m_data[cm_mat4(2, 3)] = near / (near - far);
    result.m_data[cm_mat4(3, 3)] = ONE<T>;
    return result;
}

template <typename T>
TMat4<T> vk_projection(const T fovy, const T aspect, const T near, const T far)
{
    TMat4<T> result;
    const T f = ONE<T> / std::tan(HALF<T> * fovy);
    result.m_data[0] = f / aspect;
    result.m_data[1] = ZERO<T>;
    result.m_data[2] = ZERO<T>;
    result.m_data[3] = ZERO<T>;
    result.m_data[4] = ZERO<T>;
    result.m_data[5] = -f;
    result.m_data[6] = ZERO<T>;
    result.m_data[7] = ZERO<T>;
    result.m_data[8] = ZERO<T>;
    result.m_data[9] = ZERO<T>;
    result.m_data[10] = far / (near - far);
    result.m_data[11] = -ONE<T>;
    result.m_data[12] = ZERO<T>;
    result.m_data[13] = ZERO<T>;
    result.m_data[14] = (near * far) / (near - far);
    result.m_data[15] = ZERO<T>;

    return result;
}

#endif

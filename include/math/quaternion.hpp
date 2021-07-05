/*
 * Description (scalar,bivector) pair
 *
 *
 *  web.mit.edu/QuaternionReport1.pdf
 *
 *
 * */


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

#include <cmath>
#include "math/constant.hpp"
#include <string>


//#define MATH_QUATERNION_DEBUG 1

#ifdef MATH_QUATERNION_DEBUG
#include <iostream>
#define MATH_QUATERNION_NORMALIZE_DEBUG 1
//#define MATH_QUATERNION_SQRT_DEBUG 1
//#define MATH_QUATERNION_TRANSFORM_DEBUG 1
#endif


template <typename T>
class TQuaternion;

template <typename T>
class TVec3;

template <typename T>
class TVec4;

template <typename T>
class TMat3;

template<typename T>
class TMat4;

template<typename T>
TQuaternion<T> conjugate(const TQuaternion<T>& q);


template<typename T>
void identity(TQuaternion<T>& q);

template<typename T>
TQuaternion<T> inverse(const TQuaternion<T>& q);

template<typename T>
T length(const TQuaternion<T>& q);

template<typename T>
T length2(const TQuaternion<T>& q);




template<typename T>
TQuaternion<T> matrixToQuaternion(TMat3<T>& m);

template <typename T>
TQuaternion<T> normalize(const TQuaternion<T> &q);


template <typename T>
TMat4<T> positionAttitude(const TVec3<T>& position,const TVec3<T>& axis,const T angle);


template<typename T>
TMat3<T> quaternionToMatrix(const TQuaternion<T> &q){return /*TMat3<T>(ONE<T>)*/q.asMat3();}

template<typename T>
TQuaternion<T> sqrt(const TQuaternion<T> &q);

template<typename T>
std::string to_string(const TQuaternion<T>& q);

template<typename T>
TVec3<T> transform(const TQuaternion<T>& from,const TQuaternion<T>& to,const TVec3<T>& v );


template <typename T>
class TQuaternion final
{
public:
    TQuaternion<T>() {}

    TQuaternion<T>(const TVec3<T>& axis)
    {
        m_s = ZERO<T>;
        m_v = axis;
    }

    TQuaternion<T>(const T theta,const TVec3<T> &axis)
    {

        m_s = std::cos(theta);

        m_v = axis * std::sin(theta);
    }

    TMat3<T> asMat3(void) const
    {
        TMat3<T> result;

        const T v_x_2 = m_v[0] * m_v[0];
        const T v_y_2 = m_v[1] * m_v[1];
        const T v_z_2 = m_v[2] * m_v[2];
        const T v_xy = m_v[0] * m_v[1];
        const T v_xz = m_v[0] * m_v[2];
        const T v_yz = m_v[1] * m_v[2];

        const T sv_x = m_s * m_v[0];
        const T sv_y = m_s * m_v[1];
        const T sv_z = m_s * m_v[2];

        result[0] = ONE<T> - TWO<T> * (v_y_2 - v_z_2);
        result[1] = TWO<T> * (v_xy + sv_z);
        result[2] = TWO<T> * (v_xz - sv_y);

        result[3] = TWO<T> * (v_xy - sv_z);
        result[4] = ONE<T> - TWO<T> * (v_x_2 - v_z_2);
        result[5] = TWO<T> * (v_yz + sv_x);

        result[6] = TWO<T> * (v_xz + sv_y);
        result[7] = TWO<T> * (v_yz - sv_x);
        result[8] = ONE<T> - TWO<T> * (v_x_2 - v_y_2);

        return result;
    }


    const TVec3<T>& getAxis(void)const{return m_v;}
    const TVec3<T>& getBiVector(void)const{return m_v;}


    TQuaternion<T> operator-(void)const
    {
        TQuaternion<T> result;

        result.m_s = -m_s;
        result.m_v = -m_v;

        return result;

    }


    TQuaternion<T> operator/(const T s)const
    {
        TQuaternion<T> result;

        result.m_s = m_s/s;
        result.m_v = m_v/s;

        return result;
    }


    TQuaternion<T> operator-(const TQuaternion<T>& q)const
    {
        TQuaternion<T> result;

        result.m_s = m_s - q.m_s;
        result.m_v = m_v - q.m_v;
        return result;
    }


    //Take the definition of multiplication of quaternion*quaternion  difference is a bivector = (0,bivector) in quaternion notation
    TQuaternion<T> operator*(const TVec3<T> &bivector)const
    {
        TQuaternion<T> result;

        result.m_s = -dot(m_v,bivector);
        result.m_v = bivector * m_s + cross(m_v,bivector);

        return result;

    }

   //Bivector basis  e1e2 e2e3 e3e1
    TQuaternion<T> operator*(const TQuaternion<T> &q) const
    {
        TQuaternion<T> result;

        result.m_s = m_s * q.m_s - dot(m_v, q.m_v);
        result.m_v = q.m_v * m_s + m_v * q.m_s + cross(m_v, q.m_v);

        return result;
    }

    TQuaternion<T> operator+(const TQuaternion<T> &q)const
    {
      TQuaternion<T> result;

      result.m_s = m_s + q.m_s;
      result.m_v = m_v + q.m_v;
      return result;
    }
/*
 * Same as bullet physics quaternion class
 *
*/
  /*
  void setRotation(const TVec3<T>& axis,const T angle)
  {

  }
*/
void setScalar(const T s)
{
    m_s = s;
}




void setVector(const TVec3<T>& v)
{
    m_v = v;
}


private:
    friend class TVec3<T>;
    friend TQuaternion<T> conjugate<>(const TQuaternion<T> &q);
    friend void identity<>(TQuaternion<T>& q);
    friend TQuaternion<T> inverse<>(const TQuaternion<T>& q);
    friend T length<>(const TQuaternion<T>& q);
    friend T length2<>(const TQuaternion<T>& q);
    friend TQuaternion<T> normalize<>(const TQuaternion<T> &q);
    friend TQuaternion<T> sqrt<>(const TQuaternion<T>& q);
    friend std::string to_string<>(const TQuaternion<T>& q);

private:
    T m_s;
    TVec3<T> m_v;
};

using quaternion = TQuaternion<float>;
using dquaternion = TQuaternion<double>;


template<typename T>
TQuaternion<T> conjugate(const TQuaternion<T>& q)
{
    TQuaternion<T> result;

    result.m_s  = q.m_s;
    result.m_v = -q.m_v;
    return result;
}


template<typename T>
void identity(TQuaternion<T>& q)
{


            q.m_s = ONE<T>;
            q.m_v[0] = 0.0f;
            q.m_v[1] = 0.0f;
            q.m_v[2] = 0.0f;


}

template<typename T>
TQuaternion<T> inverse(const TQuaternion<T>& q)
{
    TQuaternion<T> result  = conjugate(q)/length2(q);
    return result;

}

template<typename T>
T length(const TQuaternion<T>& q)
{
    return std::sqrt(length2(q));
}

template<typename T>
T length2(const TQuaternion<T>& q)
{
    return (q.m_s * q.m_s + dot(q.m_v,q.m_v));
}


//David Baraff Andrew Witkin Physically based modeling
template<typename T>
TQuaternion<T> matrixToQuaternion(const TMat3<T>& m)
{
    TQuaternion<T> result;

    T s;
  T trace = m(0,0) + m(1,1) + m(2,2);
 TVec3<T> v;
 if(trace > ZERO<T>)
 {
     s = std::sqrt(trace+ONE<T>);

     result.setScalar(s*HALF<T>);

     s = HALF<T>/s;



     v[0] = (m(2,1) - m(1,2) ) * s;
     v[1] = (m(0,2)-m(2,0)) * s;
     v[2] = (m(1,0)-m(0,1)) * s;
    result.setVector(v);

 }else
 {
uint i = 0;

if(m(1,1) > m(0,0))
{
    i = 1;
}
if(m(2,2) > m(i,i))
{
    i =2;
}


switch(i)
{
  case 0:
{
    s = std::sqrt((m(0,0) - m(1,1) -m(2,2)) + ONE<T> );
    v[0] = HALF<T> * s;
    s = HALF<T>/s;

    v[1] = (m(0,1) + m(1,0))*s;
    v[2] = (m(2,0) + m(0,2))*s;

    result.setScalar( (m(2,1) - m(1,2))*s );

    result.setVector(v);

}
    break;

case 1:
{
s = std::sqrt(m(1,1) - m(0,0) - m(2,2) + ONE<T>);

v[1] = HALF<T> * s;
s = HALF<T>/s;
v[2] = (m(1,2) + m(2,1))*s;
v[0] = (m(0,1) + m(0,1))*s;

result.setScalar((m(0,2)-m(2,0))*s);
result.setVector(v);
}
    break;

case 2:
{
s = std::sqrt(m(2,2) - m(0,0) - m(1,1) + ONE<T>);

v[2] = HALF<T> * s;
s = HALF<T>/s;
v[0] = (m(2,0) + m(0,2))*s;
v[1] = (m(1,2) + m(2,1))*s;
result.setScalar((m(1,0)-m(0,1))*s);
result.setVector(v);

}
    break;

default:
    v[0] = v[1] = v[2] = ZERO<T>;
    result.setScalar(ONE<T>);
    result.setVector(v);
    break;

}


 }


return result;

}


template <typename T>
TQuaternion<T> normalize(const TQuaternion<T> &q)
{
    TQuaternion<T> result = q;

   T inv_length = ONE<T>/length(q);

    result.m_s *= inv_length;
    result.m_v *= inv_length;

#ifdef MATH_QUATERNION_NORMALIZE_DEBUG
    std::cout<<"inv_length: "<<inv_length<<std::endl;
    std::cout<<"Result.m_s: "<<result.m_s<<std::endl;

#endif

    return result;
}

template <typename T>
TMat4<T> positionAttitude(const TVec3<T>& position,const TVec3<T>& axis,const T angle)
{
  TMat4<T> result;

  result[3] = ZERO<T>;
  result[7] = ZERO<T>;
  result[11] = ZERO<T>;
  result[12] = position.x();
  result[13] = position.y();
  result[14] = position.z();
  result[15] = ONE<T>;

  TQuaternion<T> q(angle*HALF<T>,axis);

  TMat3<T> rot = q.asMat3();

  result[0] = rot[0];
  result[1] = rot[1];
  result[2] = rot[2];

  result[4] = rot[3];
  result[5] = rot[4];
  result[6] = rot[5];

  result[8] = rot[6];
  result[9] = rot[7];
  result[10] = rot[8];

    return result;
}



template<typename T>
TQuaternion<T> sqrt(const TQuaternion<T>& q)
{
  TQuaternion<T> result = q;

  if(q.m_s > ONE<T>)
  {
      //result = normalize(result);
    result.m_s = ONE<T>;
#ifdef MATH_QUATERNION_SQRT_DEBUG

      std::cout<<"Error q.m_s > 1 acos cannot be calculated:  "<<to_string(q)<<std::endl;
      #endif
  }



   T theta = std::acos(result.m_s);

   T sin_theta = std::sin(theta*HALF<T>);

   result.m_s = std::cos(theta*HALF<T>);

   result.m_v =  normalize(result.m_v)*sin_theta; //If length of q.m_v == 0 => big trouble
   return result;

}


template<typename T>
TMat4<T> positionAttitude(const TVec3<T> &position,const TQuaternion<T>& attitude)
{



    TMat4<T> result(quaternionToMatrix(attitude));

    result[3] = position.x();
    result[7] = position.y();
    result[11] = position.z();
    result[15] = ONE<T>;


    return result;


}


template<typename T>
std::string to_string(const TQuaternion<T>& q)
{

  return std::string(std::to_string(q.m_s) + " " + to_string(q.m_v));

}


/*
 *
 *
 * */

template<typename T>
TVec3<T> transform(const TQuaternion<T>& from,const TQuaternion<T>& to,const TVec3<T>& v)
{

    TQuaternion<T> result;


    result = (sqrt(-to*from)) * v * inverse(sqrt(-to*from));


#ifdef MATH_QUATERNION_TRANSFORM_DEBUG
std::cout<<"Quaternion transform result:b "<< to_string(result)<<std::endl;
#endif

return result.getAxis();

}




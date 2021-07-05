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


#include <iostream>
#include <cstdlib>


#include "math/quaternion.hpp"
#include "math/mat3.hpp"
#include "math/mat4.hpp"
#include "math/vec3.hpp"


void positionAttitudeTest(void);

int main(void)
{

    positionAttitudeTest();

    vec3 axis0(0.0f,0.0f,1.0f);
    quaternion q0(axis0);
    vec3 axis1(0.0f,1.0f,0.0f);
    quaternion q1(axis1);

    vec3 x(1.0f,0.0f,0.0f);
    vec3 y(0.0f,1.0f,0.0f);
    vec3 z(0.0f,0.0f,1.0f);
    //quaternion v(0.0f,pos);


  // std::cout<< to_string(q0*q1)<<std::endl;
  // std::cout<<to_string(inverse(q0*q1))<<std::endl;

  // quaternion result = (sqrt(-q1*q0)) * axis0 * sqrt(inverse(-q1*q0));

  // std::cout<< to_string(result.getAxis())<<std::endl;

   std::cout<< to_string(transform(q0,q1,x)/*(sqrt(-q1*q0)) * x * sqrt(inverse(-q1*q0))*/)<<std::endl;
   std::cout<< to_string(transform(q0,q1,y)/*(sqrt(-q1*q0)) * y * sqrt(inverse(-q1*q0))*/)<<std::endl;
   std::cout<< to_string(transform(q0,q1,z)/*(sqrt(-q1*q0)) * z * sqrt(inverse(-q1*q0))*/)<<std::endl;


    axis0 = vec3(0.0f,1.0f,0.0f);
    quaternion q_from(axis0);

    axis1 = normalize(vec3(std::sin(pi(1.0f/20.0f)),std::cos(pi(1.0f/20.0f)),0.0f));
    std::cout<<"Axis1: "<<to_string(axis1)<<std::endl;
    quaternion q_to(axis1);
    quaternion pos(x);
    quaternion total_transform;
    identity(total_transform);
   //Test accumulative transform
    std::cout<<"-q_to*q_from: "<<to_string(-q_to*q_from)<<std::endl;
    std::cout<<"sqrt(-q_to*q_from):"<<to_string(sqrt(-q_to*q_from))<<std::endl;
    std::cout<<"inverse(sqrt(-q_to*q_from)):"<<to_string(inverse(sqrt(-q_to*q_from)))<<std::endl;
    std::cout<<"X axis rotation:"<<to_string(sqrt(-q_to*q_from)*pos*inverse(sqrt(-q_to*q_from)))<<std::endl;

 for(size_t i = 0 ; i < 10 ; i++)
 {

  //std::cout<<"length: "<<length(sqrt(-q_to*q_from) * total_transform)<<std::endl;
  total_transform  = normalize(sqrt(-q_to*q_from)*total_transform);

  y  =  transform(q_from,q_to,y);

 }

std::cout<<"Total transform: "<<to_string(total_transform)<<std::endl;

std::cout<<to_string(y)<<std::endl;
std::cout<<to_string( total_transform * axis0 * inverse(total_transform) )<<std::endl;
    return EXIT_SUCCESS;
}



void positionAttitudeTest(void)
{
    mat4 result = positionAttitude(vec3(0.0f,0.0f,0.0f),vec3(0.0f,1.0f,0.0f),pi(0.25f));

    std::cout<<to_string(result)<<std::endl;





}




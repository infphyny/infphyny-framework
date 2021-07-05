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

#include <array>
#include "math/vec2.hpp"
#include "math/vec3.hpp"
#include "math/horner.hpp"

void test_surface(void);

int main(void)
{

  std::array<vec2, 2> ctrl_points;

  ctrl_points[0] = vec2(1.0f, 0.0f);
  ctrl_points[1] = vec2(1.0f, 1.0f);

  vec2 point = horner<vec2, float, 2>(ctrl_points.data(), 0.5f);
  //vec2 v(0.0f,0.0f);

  std::cout << "(" << point[0] << ";" << point[1] << ")" << std::endl;

  test_surface();
  return EXIT_SUCCESS;
}

void test_surface(void)
{
  const size_t v_step = 2;
  const size_t u_step = 2;

  std::array<vec3, 4> ctrl_points;

  ctrl_points[0] = vec3(0.0f, 0.0f, 0.0f);
  ctrl_points[1] = vec3(1.0f, 0.0f, 0.0f);
  ctrl_points[2] = vec3(0.0f, 1.0f, 0.0f);
  ctrl_points[3] = vec3(1.0f, 1.0f, 0.0f);

  const float stride_u = 1.0f / static_cast<float>(u_step);
  const float stride_v = 1.0f / static_cast<float>(v_step);

  for (size_t j = 0; j <= v_step; j++)
  {
    const float v = j * stride_v;
    for (size_t i = 0; i <= u_step; i++)
    {
      const float u = i * stride_u;
      vec3 p = horner<vec3, float, 2, 2>(ctrl_points.data(), u, v);
      std::cout << "(" << p[0] << ";" << p[1] << ";" << p[2] << ")" << std::endl;
    }
  }
}
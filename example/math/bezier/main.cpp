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



#include <array>
#include <cstdlib>
#include <fstream>

#include "math/vec3.hpp"
#include "math/bezier.hpp"

void bezier_curve_test(void);

int main(void)
{

    bezier_curve_test();

    return EXIT_SUCCESS;
}

void bezier_curve_test(void)
{

    std::fstream write_bezier_curve;

    write_bezier_curve.open("bezier_curve.txt", std::fstream::out);
    std::array<vec3, 4> ctrl_points;

    ctrl_points[0] = vec3(0.0f, 0.0f, 0.0f);
    ctrl_points[1] = vec3(1.0f, 1.0f, 0.0f);
    ctrl_points[2] = vec3(2.0f, 1.0f, 0.0f);
    ctrl_points[3] = vec3(3.0f, 0.0f, 0.0f);

    vec3 p;
    const size_t step = 1000;

    const float stride = 1.0f / static_cast<float>(step);

    float t;
    for (size_t i = 0; i <= step; i++)
    {
        t = i * stride;

        p = bezier<vec3, float, 4>(ctrl_points.data(), t);

        write_bezier_curve << p[0] << " " << p[1] << std::endl;
    }

    write_bezier_curve.close();
}
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


#include <cstdlib>

#include <array>
#include "math/vec2.hpp"
#include "math/decasteljau.hpp"

int main(void)
{

    const size_t step = 2;

    std::array<vec2, 4> ctrl_points;

    ctrl_points[0] = vec2(0.0f, 0.0f);
    ctrl_points[1] = vec2(1.0f, 0.0f);
    ctrl_points[2] = vec2(0.0f, 1.0f);
    ctrl_points[3] = vec2(1.0f, 1.0f);

    const float stride = 1.0f / static_cast<float>(step);

    for (size_t j = 0; j <= step; j++)
    {
        for (size_t i = 0; i <= step; i++)
        {
        }
    }

    return EXIT_SUCCESS;
}
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
#include <functional>
#include <fstream>

#include "math/constant.hpp"
#include "math/vec3.hpp"
#include "math/mat3.hpp"
#include "math/mat4.hpp"

#include <random>

int main(void)
{
    std::mt19937_64 engine;
    std::uniform_real_distribution<float> distribution(0.0f, 1.0f);
    auto random = std::bind(distribution, engine);
    // s_bias.open("bias.txt", std::fstream::out);
    std::fstream write;

    write.open("mat4.txt", std::fstream::out);

    float angle1 = random();
    float angle2 = random();

    mat4 m0 = rotate(pi(1.0f) * angle1, vec3(0.0f, 1.0f, 0.0f));
    mat4 m1 = rotate(pi(0.5f) * angle2, vec3(0.0f, 1.0f, 0.0f));

    mat4 m2 = m0 * m1;

    for (size_t i = 0; i < 16; i++)
    {
        write << m2[i] << std::endl;
    }

    write.close();
}

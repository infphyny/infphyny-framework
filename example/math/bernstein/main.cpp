
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
#include <fstream>
#include "math/bernstein.hpp"

int main(void)
{
    std::fstream write;
    std::fstream ab_write;
    write.open("bernstein.txt", std::fstream::out);
    ab_write.open("allbernstein.txt", std::fstream::out);
    const size_t step = 1000;

    const float stride = 1.0f / static_cast<float>(step);
    std::array<float, 4> all_bernstein;
    for (size_t i = 0; i <= step; i++)
    {
        const float u = i * stride;

        const float b = bernstein<float, 2>(0, u);
        write << u << " " << b << std::endl;

        allBernstein<float, 4>(u, all_bernstein.data());

        ab_write << u << " " << all_bernstein[0] << " " << all_bernstein[1] << " " << all_bernstein[2] << " " << all_bernstein[3] << std::endl;
    }

    write.close();
    ab_write.close();
    return EXIT_SUCCESS;
}
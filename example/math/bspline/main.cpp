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
#include <fstream>

#include "math/bspline.hpp"

int main(void)
{
    size_t count = 100;
    const float delta = 1/static_cast<float>(count);

    //knot size numberof basis function + order of the basis function
    float knots[8] = {0.0f,0.0f,0.0f,0.0f,1.0f,1.0f,1.0f,1.0f};
    float knots2[] = {0.0f,0.0f,0.0f,1.0f,2.0f,3.0f,4.0f,4.0f,5.0f,5.0f,5.0f};
    std::fstream write_bezier3_basis;
    write_bezier3_basis.open("bezier3_basis.txt", std::fstream::out);

   // std::fstream write_basis;
    //write_basis.open("basis.txt",std::fstream::out);

    for(size_t i = 0 ; i <= count ; i++)
    {
        float N[4];
       // float N2[8];
        basisFunctions<float,4,8>(3,i*delta,3,knots,N);
       // basisFunctions<float,3,8>(7,i*delta*5,7,knots2,N2);



        write_bezier3_basis<<i*delta<<" "<<N[0]<<" "<<N[1]<<" "<<N[2]<<" "<<N[3]<<std::endl;

       // write_basis<<i*delta*5<<" "<<N2[0]<<" "<<N2[1]<<" "<<N2[2]<<" "<<N2[3]<<" "<<N2[4]<<" "<<N2[5]<<" "<<N2[6]<<" "<<N2[7]<<std::endl;

/*
        for(size_t j = 0 ; j < 4; j++)
        {
            std::cout<<N[j]<<std::endl;
        }
        std::cout<<std::endl;
*/


    }

    write_bezier3_basis.close();
   // write_basis.close();

  float N2[3];


  basisFunctions<float,3,11>(findSpan<float,11>(2,2.5f,knots2),2.5f,2,knots2,N2);

  for(size_t i = 0 ; i < 3 ; i++)
  {
  std::cout<<N2[i]<<std::endl;
  }


    return EXIT_SUCCESS;

}


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

#include "math/constant.hpp"

/*

*/

template <typename S>
S elinas(const S I_t, const S T_1, const S T_2, const S D, const S g)
{
  S alpha = ((I_t - T_1) - (T_2 * (ONE<S> - g))) * D;
}

/*
  Gardner transparency function for clouds of elipsoid shape 
  @param I_t texture value at pixel
  @param T_1 threshold at center of the elipse
  @param T_2 threshold at the boundary of the elipse
  @param D inverse range of texture function value whis transluce varie from 0 to 1 (normalization factor)
  @param g value from a 2D function, vertical and horizontal image coordinate

  @return    0 <= alpha <= 1
*/

template <typename S>
S gardner(const S I_t, const S T_1, const S T_2, const S D, const S g)
{
  S alpha = ONE<S> - (I_t - T_1 - (T_2 - T_1) * (ONE<S> - g)) * D;

  return alpha;
}

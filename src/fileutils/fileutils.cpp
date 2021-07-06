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


#include "fileutils/fileutils.hpp"


int readbyteinfile(const std::string& filename, std::vector<std::byte>& data)
{

  std::fstream read_file;


  read_file.open(filename,std::ios_base::in);

read_file.seekg(0,std::ios_base::end);
  const int size = read_file.tellg();
  read_file.seekg(0,std::ios_base::beg);



  if(size > 0)
    {
  data.resize(size);
   read_file.read(reinterpret_cast<char*>(data.data()),size);
   }

return size;

}





int readstringinfile(const std::string& filename,std::string &stringinfile)
{

    std::fstream read_file;


    read_file.open(filename,std::ios_base::in);

read_file.seekg(0,std::ios_base::end);
    const int size = read_file.tellg();
    read_file.seekg(0,std::ios_base::beg);

   // std::string stringinfile;

    if(size > 0)
      {
    stringinfile.resize(size);

   read_file.read(&stringinfile[0],size);
}


   return size;


}

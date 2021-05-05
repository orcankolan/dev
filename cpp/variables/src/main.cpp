#include <iostream>

int main()
{
  int variable = 8;
  /* Signed integer of 4 bytes of data
     from -2^31 to +2^31 (2.1 billion)
     (not 32bits bec. 1 bit is for the sign)
  */

  unsigned int var2 = 31;
  /* up tp 2^32
     other variables:
     char -> 1byte, chort -> 2bytes, long -> 4bytes, long long -> 8bytes
     unsigned can be added to any of these by using 1 bit
 */

  char a = 'A'; //use single quotes
  unsigned char b = 65;
  /*  You can put characters or 1 byte of integer (one bit for sign) 
      b will be written as character (A)
   */

  float dec = 5.5;
  float dec2 = 5.5f; // Now it is float 
  /*  float -> 4bytes of data (actually double) 
      double -> 8bytes
   */

  bool mybool = true; // will print 1 (1 byte using 1 bit)
  bool mybool2 = false; // will print 0
  /*  Why 1 byte is necessary
      Cause 1 bit can nor be addressed
      Only bytes can be addressed or accessed by the computer
   */

  std::cout << variable << "," << var2 << std::endl;
  std::cout << a << "," << b << std::endl;
  std::cout << dec << "," << dec2 << std::endl;
  std::cout << mybool << "," << mybool2 << "\n" << std::endl;
  std::cout << "To find size use sizeof: (bool) " << sizeof(bool) << std::endl;
  std::cout << "To find size use sizeof: (double) " << sizeof(double) << std::endl;
}

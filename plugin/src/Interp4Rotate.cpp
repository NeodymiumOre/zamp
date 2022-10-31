#include <iostream>
#include "Interp4Rotate.hpp"
#include "MobileObj.hpp"

using std::cout;
using std::endl;


extern "C" {
 Interp4Command* create_cmd(void);
  const char* get_cmd_name() { return "Rotate"; }
}




/*!
 * \brief
 *
 *
 */
Interp4Command* create_cmd(void)
{
  return Interp4Rotate::create_cmd();
}


/*!
 *
 */
Interp4Rotate::Interp4Rotate(): _Speed_mmS(0)
{}


/*!
 *
 */
void Interp4Rotate::PrintCmd() const
{
  /*
   *  Tu trzeba napisać odpowiednio zmodyfikować kod poniżej.
   */
  cout << get_cmd_name() << " " << _Speed_mmS  << " 10  2" << endl;
}


/*!
 *
 */
const char* Interp4Rotate::get_cmd_name() const
{
  return ::get_cmd_name();
}


/*!
 *
 */
bool Interp4Rotate::ExecCmd( MobileObj  *pMobObj,  int  Socket) const
{
  /*
   *  Tu trzeba napisać odpowiedni kod.
   */
  return true;
}


/*!
 *
 */
bool Interp4Rotate::ReadParams(std::istream& Strm_CmdsList)
{
  /*
   *  Tu trzeba napisać odpowiedni kod.
   */
  return true;
}


/*!
 *
 */
Interp4Command* Interp4Rotate::create_cmd()
{
  return new Interp4Rotate();
}


/*!
 *
 */
void Interp4Rotate::PrintSyntax() const
{
  cout << "   Move  NazwaObiektu  Szybkosc[m/s]  DlugoscDrogi[m]" << endl;
}

#include <iostream>
#include "Interp4Set.hpp"
#include "MobileObj.hpp"

using std::cout;
using std::endl;


extern "C" {
 Interp4Command* create_cmd(void);
  const char* get_cmd_name() { return "Set"; }
}


/*!
 * \brief
 *
 *
 */
Interp4Command* create_cmd(void)
{
  return Interp4Set::create_cmd();
}


/*!
 *
 */
Interp4Set::Interp4Set(): _Speed_mmS(0)
{}


/*!
 *
 */
void Interp4Set::PrintCmd() const
{
  /*
   *  Tu trzeba napisać odpowiednio zmodyfikować kod poniżej.
   */
  cout << get_cmd_name() << " " << _Speed_mmS  << " 10  2" << endl;
}


/*!
 *
 */
const char* Interp4Set::get_cmd_name() const
{
  return ::get_cmd_name();
}


/*!
 *
 */
bool Interp4Set::ExecCmd( MobileObj  *pMobObj,  int  Socket) const
{
  /*
   *  Tu trzeba napisać odpowiedni kod.
   */
  return true;
}


/*!
 *
 */
bool Interp4Set::ReadParams(std::istream& Strm_CmdsList)
{
  /*
   *  Tu trzeba napisać odpowiedni kod.
   */
  return true;
}


/*!
 *
 */
Interp4Command* Interp4Set::create_cmd()
{
  return new Interp4Set();
}


/*!
 *
 */
void Interp4Set::PrintSyntax() const
{
  cout << "   Move  NazwaObiektu  Szybkosc[m/s]  DlugoscDrogi[m]" << endl;
}

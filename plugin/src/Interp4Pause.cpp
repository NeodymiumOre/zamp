#include <iostream>
#include "Interp4Pause.hpp"
#include "MobileObj.hpp"

using std::cout;
using std::endl;


extern "C" {
 Interp4Command* create_cmd(void);
  const char* get_cmd_name() { return "Pause"; }
}




/*!
 * \brief
 *
 *
 */
Interp4Command* create_cmd(void)
{
  return Interp4Pause::create_cmd();
}


/*!
 *
 */
Interp4Pause::Interp4Pause(): _Speed_mmS(0)
{}


/*!
 *
 */
void Interp4Pause::PrintCmd() const
{
  /*
   *  Tu trzeba napisać odpowiednio zmodyfikować kod poniżej.
   */
  cout << get_cmd_name() << " " << _Speed_mmS  << " 10  2" << endl;
}


/*!
 *
 */
const char* Interp4Pause::get_cmd_name() const
{
  return ::get_cmd_name();
}


/*!
 *
 */
bool Interp4Pause::ExecCmd( MobileObj  *pMobObj,  int  Socket) const
{
  /*
   *  Tu trzeba napisać odpowiedni kod.
   */
  return true;
}


/*!
 *
 */
bool Interp4Pause::ReadParams(std::istream& Strm_CmdsList)
{
  /*
   *  Tu trzeba napisać odpowiedni kod.
   */
  return true;
}


/*!
 *
 */
Interp4Command* Interp4Pause::create_cmd()
{
  return new Interp4Pause();
}


/*!
 *
 */
void Interp4Pause::PrintSyntax() const
{
  cout << "   Move  NazwaObiektu  Szybkosc[m/s]  DlugoscDrogi[m]" << endl;
}

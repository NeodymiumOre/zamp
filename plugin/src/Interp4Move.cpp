#include <iostream>
#include <sstream>

#include "Interp4Move.hpp"
#include "MobileObj.hpp"
#include "Handlers.hpp"

using std::cout;
using std::endl;


extern "C" {
 Interp4Command* create_cmd(std::string cmd);
  const char* get_cmd_name() { return "Move"; }
}

Interp4Move::Interp4Move(std::string cmd)
{
  std::istringstream ss(cmd);
  std::string word;
  while(ss >> word)
    nprint(word);
}


/*!
 * \brief
 *
 *
 */
Interp4Command* create_cmd(std::string cmd)
{
  // std::istringstream ss(cmd);
  // std::string word;
  // while(ss >> word)
  //   nprint(word);
  // nprint("xd");

  // return Interp4Move::create_cmd();
  return Interp4Move::create_cmd(cmd);
}


/*!
 *
 */
Interp4Move::Interp4Move(): _Speed_mmS(0)
{}


/*!
 *
 */
void Interp4Move::PrintCmd() const
{
  /*
   *  Tu trzeba napisać odpowiednio zmodyfikować kod poniżej.
   */
  cout << get_cmd_name() << " " << _Speed_mmS  << " 10  2" << endl;
}


/*!
 *
 */
const char* Interp4Move::get_cmd_name() const
{
  return ::get_cmd_name();
}


/*!
 *
 */
bool Interp4Move::ExecCmd( MobileObj  *pMobObj,  int  Socket) const
{
  /*
   *  Tu trzeba napisać odpowiedni kod.
   */
  return true;
}


/*!
 *
 */
bool Interp4Move::ReadParams(std::istream& Strm_CmdsList)
{
  /*
   *  Tu trzeba napisać odpowiedni kod.
   */
  return true;
}


/*!
 *
 */
Interp4Command* Interp4Move::create_cmd(std::string cmd)
{
  std::cout << "xd" << std::endl;
  return new Interp4Move();
}


/*!
 *
 */
void Interp4Move::PrintSyntax() const
{
  cout << "   Move  NazwaObiektu  Szybkosc[m/s]  DlugoscDrogi[m]" << endl;
}

#ifndef  COMMAND4MOVE_HH
#define  COMMAND4MOVE_HH

#ifndef __GNUG__
#endif

#include "Interp4Command.hpp"

/*!
 * \file
 * \brief Definicja klasy Interp4Move
 *
 * Plik zawiera definicję klasy Interp4Move ...
 */

struct MoveCmd {
  std::string cmd_name;
  std::string obj_name;
  int speed;
  int dist;
};

/*!
 * \brief Modeluje polecenie dla robota mobilnego, które wymusza jego ruch do przodu
 *
 *  Klasa modeluje ...
 */
class Interp4Move: public Interp4Command {
  /*
   *  Tu należy zdefiniować pola, które są niezbędne
   *  do przechowywania wartości parametrów danego polecenia.
   *  Ponieżej zdefiniowane jest tylko jedno pole jako przykład.
   */
  
  private:

    double _Speed_mmS;
    MoveCmd *_cmd;

  public:

    Interp4Move();  
    /*!
    * \brief Wyświetla postać bieżącego polecenia (nazwę oraz wartości parametrów)
    */

    /*!
    * \brief Inicjalizuje _cmd
    */
    Interp4Move(std::string cmd);

    virtual void PrintCmd() const;
    /*!
    * \brief Wyświetla składnię polecenia
    */
    virtual void PrintSyntax() const;
    /*!
    * \brief Wyświetla nazwę polecenia
    */
    virtual const char* get_cmd_name() const;
    /*!
    * \brief Wykonuje polecenie oraz wizualizuje jego realizację
    */
    virtual bool ExecCmd( MobileObj  *pMobObj, int Socket) const;
    /*!
    * \brief Czyta wartości parametrów danego polecenia
    */
    virtual bool ReadParams(std::istream& Strm_CmdsList);
    /*!
    * \brief Wyświetla wartości wczytanych parametrów
    */
    virtual void PrintParams() {}
    /*!
    * \brief
    *
    *  Ta metoda nie musi być zdefiniowna w klasie bazowej.
    */
    static Interp4Command* create_cmd(std::string cmd);
 };

#endif

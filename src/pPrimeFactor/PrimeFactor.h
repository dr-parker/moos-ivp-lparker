/************************************************************/
/*    NAME: Lonnie Parker                                   */
/*    ORGN: MIT                                             */
/*    FILE: PrimeFactor.h                                   */
/*    DATE: Created 10/13/16                                */
/************************************************************/

#ifndef PRIMEFACTOR_HEADER
#define PRIMEFACTOR_HEADER

#include "MOOS/libMOOS/MOOSLib.h"
#include <iterator>
#include <cstdlib> // Used for string parsing and manipulation
#include "MBUtils.h"
#include "PrimeEntry.h"

//Included to handle 64-bit sized values as opposed to unsigned long int types
#include <stdint.h>

using namespace std;

class PrimeFactor : public CMOOSApp
{
 public:
   PrimeFactor();
   ~PrimeFactor();

 protected:
   bool OnNewMail(MOOSMSG_LIST &NewMail);
   bool Iterate();
   bool OnConnectToServer();
   bool OnStartUp();
   void RegisterVariables();

 private: // Configuration variables
   unsigned long int m_input_value; //Temporary value to test early stage of pPrimeFactor app
   PrimeEntry* m_prime_entry;
   
 private: // State variables
   unsigned int m_iterations;
   double       m_timewarp;
};

#endif 

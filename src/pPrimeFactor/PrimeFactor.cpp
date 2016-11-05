/************************************************************/
/*    NAME: Lonnie Parker                                   */
/*    ORGN: MIT                                             */
/*    FILE: PrimeFactor.cpp                                 */
/*    DATE: Created 10/27/16                                */
/************************************************************/

/*This is the main class in the pPrimeFactor application
that is derived from CMOOSApp. It is used to calculate the
prime actorization of 64-bit integers. Incoming values are 
accepted as strings in the variable NUM_VALUE. A detailed
factorization result is posted to PRIME_RESULT each time a
number is factored.
 */

#include "PrimeFactor.h"


using namespace std;

//---------------------------------------------------------
// Constructor

PrimeFactor::PrimeFactor()
{
  m_iterations = 0;
  m_timewarp   = 1;
  m_input_value = 0;
  m_prime_entry = new PrimeEntry(0);
}

//---------------------------------------------------------
// Destructor

PrimeFactor::~PrimeFactor()
{
}

//---------------------------------------------------------
// Procedure: OnNewMail

bool PrimeFactor::OnNewMail(MOOSMSG_LIST &NewMail)
{
  MOOSMSG_LIST::iterator p;
   
  for(p=NewMail.begin(); p!=NewMail.end(); p++) {
    CMOOSMsg &msg = *p;
    string key = msg.GetKey(); //DEFAULT FUNCTION
    //    string key   = toupper(stripBlankEnds(msg.GetKey()));
    /*
#if 0 // Keep these around just for template
    string key   = msg.GetKey();
    string comm  = msg.GetCommunity();
    double dval  = msg.GetDouble();
    string sval  = msg.GetString(); 
    string msrc  = msg.GetSource();
    double mtime = msg.GetTime();
    bool   mdbl  = msg.IsDouble();
    bool   mstr  = msg.IsString();
#endif
*/
    if(key == "NUM_VALUE"){
      string num = msg.GetString(); //DEFAULT FUNCTION
      unsigned long int j = strtoul(num.c_str(), NULL, 0);

      //Generate a pointer
      m_prime_entry->setOriginalValue(j);

      //      MOOSDebugWrite(MOOSFormat("Input Prime       =   %.3f", m_input_value));
      //      MOOSDebugWrite(MOOSFormat("MADE IT TO OnNewMail"));
      //      m_prime_entry->setInitialTime(msg.GetTime());

      //SAVE FOR LATER IMPLEMENTATION
      //      newPrime->setInitialTime(msg.GetTime());
      //      newPrime->setInitialTime(msg.GetTime());      

      //Stop here and practice converting the value in x before
      //moving on to establishing a queue of input values.
      //unsigned long int x = strtoul(num.c_str(), NULL, 0);
    }

  }
	
   return(true);
}

//---------------------------------------------------------
// Procedure: OnConnectToServer

bool PrimeFactor::OnConnectToServer()
{
   // register for variables here
   // possibly look at the mission file?
   // m_MissionReader.GetConfigurationParam("Name", <string>);
   // m_Comms.Register("VARNAME", 0);
	
   RegisterVariables();
   return(true);
}

//---------------------------------------------------------
// Procedure: Iterate()
//            happens AppTick times per second

bool PrimeFactor::Iterate()
{
  
  //  unsigned int maxiter = 100; //Dummy variable (not used)
  m_prime_entry->findPrimes();
  //MOOSDebugWrite(MOOSFormat("MADE IT TO ITERATE LOOP"));

  //MOOSDebugWrite(MOOSFormat("PRIME_RESULT       =   %s",result));
  string result = m_prime_entry->getReport();

  Notify("PRIME_RESULT", result);

  m_iterations++;
  return(true);
}

//---------------------------------------------------------
// Procedure: OnStartUp()
//            happens before connection is open

bool PrimeFactor::OnStartUp()
{
  list<string> sParams;
  m_MissionReader.EnableVerbatimQuoting(false);
  if(m_MissionReader.GetConfiguration(GetAppName(), sParams)) {
    list<string>::iterator p;
    for(p=sParams.begin(); p!=sParams.end(); p++) {
      string original_line = *p;
      string param = stripBlankEnds(toupper(biteString(*p, '=')));
      string value = stripBlankEnds(*p);
      
      if(param == "FOO") {
        //handled
      }
      else if(param == "BAR") {
        //handled
      }
    }
  }
  
  m_timewarp = GetMOOSTimeWarp();

  RegisterVariables();	
  return(true);
}

//---------------------------------------------------------
// Procedure: RegisterVariables

void PrimeFactor::RegisterVariables()
{
  Register("NUM_VALUE", 0);
}


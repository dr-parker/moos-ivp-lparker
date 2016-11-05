/************************************************************/
/*    NAME: Lonnie Parker                                   */
/*    ORGN: MIT                                             */
/*    FILE: Odometry.h                                      */
/*    DATE: 06-17-16                                        */
/************************************************************/

#ifndef Odometry_HEADER
#define Odometry_HEADER

#include <string>
//#include "MOOS/libMOOS/MOOSLib.h"
#include "MOOS/libMOOS/Thirdparty/AppCasting/AppCastingMOOSApp.h"

//class Odometry : public CMOOSApp
class Odometry : public AppCastingMOOSApp
{
 public:
   Odometry();
   ~Odometry();

 protected:
   bool OnNewMail(MOOSMSG_LIST &NewMail);
   bool Iterate();
   bool OnConnectToServer();
   bool OnStartUp();
   void RegisterVariables();

   //Standard AppCastingMOOSApp function to overload
   bool buildReport();

 private: // Configuration variables
   bool   m_first_reading;
   double m_current_x;
   double m_current_y;
   double m_previous_x;
   double m_previous_y;
   double m_total_distance;

 private: // State variables
   unsigned int m_iterations;
   double       m_timewarp;
};

#endif 

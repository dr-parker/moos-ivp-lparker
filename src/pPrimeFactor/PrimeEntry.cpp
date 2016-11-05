/* 
 * File:   PrimeEntry.cpp
 * Author: L. Parker
 *
 * Created on October 27, 2016, 12:00 PM
 */

#include "PrimeEntry.h"

using namespace std;

/*
The PrimeEntry class is used to calculate the prime factorization of a number. Numbers are received as 64-bit integers with a maximum value of 18,446,744,073,709,551,615. Results an be stored in a string an displayed.
*/

//Class constructor
PrimeEntry::PrimeEntry(unsigned long int entry){
    m_orig = entry; // Assign original prime value to be factored
}

//Class destructor
PrimeEntry::~PrimeEntry() {
}

//void PrimeEntry::setoriginalVal(unassigned long int v){
//}

/***********************************************************************************/
//Functions defined directly in PrimeEntry.h
//  void PrimeEntry::setReceivedIndex(unsigned int v)       {m_received_index=v;};
//  void PrimeEntry::setCalculatedIndex(unsigned int v)     {m_calculated_index=v;};
//  void setDone(bool v)                        {m_done=v;};
//  bool done() {return}
/***********************************************************************************/

void PrimeEntry::findPrimes(){

  unsigned long int inVal = m_orig; //Preserve original prime value
  m_out_string.str(""); //Reset the contents of PrimeEntry class member m_out_string

  //Print the number of 2s that divide n (NOTE: (0%number) = 0)
  while ((inVal%2 == 0) && (inVal != 0)){
    inVal = inVal/2;
    m_out_string << "2:";
  }
  
  // n must be odd at this point. So we can skip one element (Note i = i + 2)
  for (int i = 3; i <= sqrt(inVal); i = i+2){
    // While i divides n, print i and divide n
    while ( inVal%i == 0){
      m_out_string << i << ":";
      inVal = inVal/i;
    }
  }
  
  /* This condition is to handle the case when v is a prime number
     greater than 2 */
  if (inVal > 2)
    m_out_string << inVal;

  /*  if(m_orig == 0){
    out_string << m_orig << ": Boo ";
  }else{
    out_string << m_orig << ": Boo908";
    }

  //  m_out_string << "1:2:3:4:5:6";
  //  m_out_string << m_orig;
  out_string << 754;
  out_string << " : " << m_string;
  */
  
  return;
}

/*bool PrimeEntry::factor(unsigned long int max_steps); //A function for finding the next prime, given a maximum number of steps to search
 */

string PrimeEntry::getReport(){
//A function for generating a string report of the results

  return m_out_string.str();

}

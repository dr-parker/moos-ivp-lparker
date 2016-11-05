/* 
 * File:   PrimeEntry.h
 * Author: L. Parker
 *
 * Created on October 28, 2016, 12:00 PM
 */

#ifndef PRIMEENTRY_H
#define	PRIMEENTRY_H

#include "MOOS/libMOOS/MOOSLib.h"
//#include "PrimeQueue.h"
#include <vector>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <sstream>

using namespace std;

class PrimeEntry{

 public:
   PrimeEntry(unsigned long int);   
  ~PrimeEntry();

  void setOriginalValue(unsigned long int v) {m_orig = v;};
  //  void setOriginalString(string inString) {m_string = inString;};
  //void setReceivedIndex(unsigned int v) {m_received_index=v;};
  //void setCalculatedIndex(unsigned int v) {m_calculated_index=v;};
  //void setDone(bool v) {m_done=v;};
  void findPrimes(); //Temporary function to implement portion of pPrimeFactor app
  //  bool done() {return;};

  //  bool factor(unsigned long int max_steps); //A function for finding the next prime, given a maximum number of steps to search

  string getReport(); //A function for generating a string report of the results

 protected:
  //unsigned long int m_start_index; //The index in the for-loop to start searching for prime
  unsigned long int m_orig; //A holder of the original prime number
  //vector<unsigned long int>* m_primes; //Vector containing the list of prime factors of m_orig
  //bool              m_done; 
  //unsigned int      m_received_index; //The index at which it was received (i.e., the time)
  //unsigned int      m_calculated_index; //The index at which is was solved
  stringstream      m_out_string; //Temporary variable to collect the prime values found during findPrimes
  //std::vector<unsigned long int> m_factors; //A holder of prime factors found so far
};

#endif

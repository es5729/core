// StubStubInst.cpp
// Implements the StubStubInst class
#include <iostream>
#include "Logger.h"

#include "StubInst.h"




/* --------------------
 * all MODEL classes have these members
 * --------------------
 */
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
StubInst::StubInst() {};

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
StubInst::~StubInst() {};
    
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void StubInst::init(xmlNodePtr cur) { 
  InstModel::init(cur); 
};
  
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void StubInst::copy(StubInst* src) { 
  InstModel::copy(src); 
};


//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void StubInst::copyFreshModel(Model* src) { 
  copy(dynamic_cast<StubInst*>(src)); 
};

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void StubInst::print() { 
  InstModel::print(); 
};

/* --------------------
 * all COMMUNICATOR classes have these members
 * --------------------
 */

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void StubInst::receiveMessage(msg_ptr msg) {};


/* --------------------
 * all INSTMODEL classes have these members
 * --------------------
 */


/* --------------------
   output database info
 * --------------------
 */
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
std::string StubInst::outputDir_ = "/stub";


/* --------------------
 * all MODEL classes have these members
 * --------------------
 */

extern "C" Model* constructStubInst() {
  return new StubInst();
}

extern "C" void destructStubInst(Model* p) {
  delete p;
}

/* ------------------- */ 




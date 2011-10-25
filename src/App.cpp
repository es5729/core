#include <iostream>
#include <cstdlib>
#include <cstring>

#include "Model.h"
#include "Logician.h"
#include "BookKeeper.h"
#include "Timer.h"
#include "InputXML.h"
#include "CycException.h"
#include "Env.h"

using namespace std;

//-----------------------------------------------------------------------------
// Main entry point for the test application...
//-----------------------------------------------------------------------------
int main(int argc, char* argv[]) {
  // tell ENV the path between the cwd and the cyclus executable
  string path = ENV->pathBase(argv[0]);
  ENV->setCyclusPath(path);

  // announce yourself
  cout << "|--------------------------------------------|" << endl;
  cout << "|                  Cyclus                    |" << endl;
  cout << "|       a nuclear fuel cycle simulator       |" << endl;
  cout << "|  from the University of Wisconsin-Madison  |" << endl;
  cout << "|--------------------------------------------|" << endl;

  if(argc<2) {
    string err_msg = "Cyclus usage requires an input file.\n";
    err_msg += "Usage:   ./cyclus [path/to/input/filename]\n";
    throw CycException(err_msg);
  }

  // parse arguments
  try {
    // read input file
    XMLinput->load_file(argv[1]); 


    // setup simulation
    // =====================

    // load markets
    // create_market_method
    //  * get market model name
    //  * search cache for market methods
    //     * if not found load market
    
    cout << "Here is a list of " << LI->getNumModels(CONVERTER) << " converters:" << endl;
    LI->printModelList(CONVERTER);
    cout << "Here is a list of " << LI->getNumModels(MARKET) << " markets:" << endl;
    LI->printModelList(MARKET);
    cout << "Here is a list of " << LI->getNumModels(FACILITY) << " facilities:" << endl;
    LI->printModelList(FACILITY);
    cout << "Here is a list of " << LI->getNumModels(REGION) << " regions:" << endl;
    LI->printModelList(REGION);
    cout << "Here is a list of " << LI->getNumRecipes() << " recipes:" << endl;
    LI->printRecipes();
    
    // Run the simulation 
    TI->runSim();

    // Create the output file
    BI->createDB();

    BI->writeModelList(INST);
    BI->writeModelList(REGION);
    BI->writeModelList(FACILITY);
    BI->writeModelList(MARKET);
    BI->writeTransList();
    BI->writeMatHist();

    BI->closeDB();
  } catch (CycException ge) {
    cout << ge.what() << endl;
  };

  return 0;
}

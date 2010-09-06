// ConverterModel.h
#if !defined(_CONVERTERMODEL_H)
#define _CONVERTERMODEL_H
#include <string>
#include <list>

#include "Model.h"
#include "Message.h"

using namespace std;

/// forward declaration to resolve recursion
class Commodity;
// forward declare Material class to avoid full inclusion and dependency
class Material;

//-----------------------------------------------------------------------------
/**
 * The ConverterModel class is the abstract class/interconve used by all
 * converter models
 * 
 * This is all that is known externally about converters
*/
//-----------------------------------------------------------------------------
class ConverterModel : public Model
{
/* --------------------
 * all MODEL classes have these members
 * --------------------
 */

public:
  /// Default constructor for ConverterModel Class
  ConverterModel() { ID = nextID++; model_type="Converter"; };

  /// every model should be destructable
  virtual ~ConverterModel() {};
  
  // every model needs a method to initialize from XML
  virtual void init(xmlNodePtr cur);

  // every model needs a method to copy one object to another
  virtual void copy(ConverterModel* src);

  // every model should be able to print a verbose description
  virtual void print()              { Model::print(); };

protected: 
  /// Stores the next available converter ID
  static int nextID;
/* ------------------- */ 


/* --------------------
 * all CONVERTERMODEL classes have these members
 * --------------------
 */
protected:
  /// each instance of a converter needs a name
  string conv_name;

  /// each converter needs a list of equivalent commodities it converts
  list<Commodity*> commodities; 

public:

  /**
   * Sets the converter's name 
   *
   * @param convName is the new name of the converter
   */
  void setConvName(string convName) { conv_name = convName; };

  /// Returns the converter's name
  string getConvName() { return conv_name; };

  /**
   * Converts between amounts of two commodities
   *
   * @param convMsg is a message concerning one convertible commodity to convert
   * @param refMsg is a message concerning the commodity to convert it to
   * 
   * @return the converted message
   */
  virtual Message* convert(Message* convMsg, Message* refMsg); 

/* ------------------- */ 
  
};

#endif



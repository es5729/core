// RegionModelTests.h
#include <gtest/gtest.h>

#include "RegionModel.h"
#include "suffix.h"
#include "TestRegion.h"

#if GTEST_HAS_PARAM_TEST

using ::testing::TestWithParam;
using ::testing::Values;

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Inside the test body, fixture constructor, SetUp(), and TearDown() we
// can refer to the test parameter by GetParam().  In this case, the test
// parameter is a pointer to a concrete RegionModel instance 
typedef RegionModel* RegionModelConstructor();

class RegionModelTests : public TestWithParam<RegionModelConstructor*> {
  public:
    virtual void SetUp() { 
      region_model_ = (*GetParam())();
    }
    virtual void TearDown(){ 
      delete region_model_;
    }

  protected:
    RegionModel* region_model_;

};

#else

// Google Test may not support value-parameterized tests with some
// compilers. If we use conditional compilation to compile out all
// code referring to the gtest_main library, MSVC linker will not link
// that library at all and consequently complain about missing entry
// point defined in that library (fatal error LNK1561: entry point
// must be defined). This dummy test keeps gtest_main linked in.
TEST(DummyTest, ValueParameterizedTestsAreNotSupportedOnThisPlatform) {}

#endif  // GTEST_HAS_PARAM_TEST



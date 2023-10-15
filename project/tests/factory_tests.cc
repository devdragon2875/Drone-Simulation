#include "project/src/composite_entity_factory.h"
#include "gtest/gtest.h"

class FactoryTest : public ::testing::Test {
public:
  void SetUp( ) { 
  }
protected:
};

//REGRESSION TEST:
//What this test does: First we create a composite factory and a robot factory called RobotFactoryTest. Then, I add the factory to the composite's map of factories.
//Finally, to check if the factory was successfully added to the mapping, I call the function checkFactory, which indexes into the map with the provided input, and calls
//the factories getName function. Since we gave the name RobotFactoryTest to the factory, thats why we expect it as the output.
TEST_F(FactoryTest, AddFactoryTest) {
  CompositeEntityFactory* fac=new CompositeEntityFactory();
  RobotFactory* r=new RobotFactory("RobotFactoryTest");
  fac->AddFactory(r);
  EXPECT_EQ(fac->checkFactory("RobotFactoryTest"), "RobotFactoryTest");
}

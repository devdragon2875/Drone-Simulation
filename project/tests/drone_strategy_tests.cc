#include "gtest/gtest.h"
#include "project/src/drone.h"
#include "project/src/Idle.h"
#include "project/src/Vantage.h"
#include "project/src/electrical_entity.h"
#include <fstream>

class DroneStrategyTest : public ::testing::Test {
public:
  void SetUp( ) {
  }
protected:
};

//REGRESSION TEST - testing if Idle works
TEST_F(DroneStrategyTest, Idle){
    Idle* i = new Idle();
    Vector output = i->Execute(1, new Point(0, 0, 0), new Vector(1, 1, 1), 2);
    std::string result;
    if(output.x == 0 && output.y == 0 && output.z == 0){
          result="Pass";
    }
    else{
          result="Fail";
    }
        EXPECT_EQ(result, "Pass");

}
//REGRESSION TEST - testing if Vantage works
TEST_F(DroneStrategyTest, Vantage){
    Vantage* v = new Vantage();
    Vector output = v->Execute(1, new Point(0, 0, 0), new Vector(-1, 0, -1), 2);
    std::string result;
    if(output.x == -1 && output.y == 1 && output.z == -1){
          result="Pass";
    }
    else{
          result="Fail";
    }
        EXPECT_EQ(result, "Pass");

}
//REGRESSION TEST - testing if Hospital strategy would have worked
TEST_F(DroneStrategyTest, Hospital){
	
	Drone* drone = new Drone();
	ElectricalEntity* e = new ElectricalEntity(drone);
	drone->ChangeStrategy("hospital");
	drone->Update(1);
    std::string result;
    if(drone->getXDir() != 0 ||  drone->getYDir() != 0 ||  drone->getZDir() != 0){
          result="Pass";
    }
    else{
          result="Fail";
    }
        EXPECT_EQ(result, "Pass");

}

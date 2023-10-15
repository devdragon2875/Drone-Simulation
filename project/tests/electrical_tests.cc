#include "gtest/gtest.h"
#include "project/src/electrical_entity.h"
#include "drone.h"
#include <fstream>

class ElectricalTest : public ::testing::Test {
public:
  void SetUp( ) {
  }
protected:
};


//INTEGRATION TEST - testing if drone works with decorator
TEST_F(ElectricalTest, OneDecoratorTest){
	Drone* drone = new Drone();
	ElectricalEntity* e = new ElectricalEntity(drone, 100);
	
    std::string result;
    if((e->getEntity())->getEnergy() == 100 && (e->getEntity())->getEnergyCapacity() == 100){
          result="Pass";
    }
    else{
          result="Fail";
    }
        EXPECT_EQ(result, "Pass");

}

//COMPONENT TEST - testing if two decorators work
TEST_F(ElectricalTest, TwoDecoratorTest){
        Drone* drone = new Drone();
        ElectricalEntity* e = new ElectricalEntity(drone, 100);
	ElectricalEntity* e2 = new ElectricalEntity(drone, 100);

    std::string result;
    if((e2->getEntity())->getEnergy() == 200 && (e->getEntity())->getEnergyCapacity() == 200){
          result="Pass";
    }
    else{
          result="Fail";
    }
        EXPECT_EQ(result, "Pass");

}

//COMPONENT TEST - testing if add energy works
TEST_F(ElectricalTest, AddEnergy){
        Drone* drone = new Drone();
        drone->addEnergy(100);
    std::string result;
    if(drone->getEnergy() == 100 && drone->getEnergyCapacity() == 100){
          result="Pass";
    }
    else{
          result="Fail";
    }
        EXPECT_EQ(result, "Pass");

}

//COMPONENT TEST - testing if reduce energy works
TEST_F(ElectricalTest, ReduceEnergy){
        Drone* drone = new Drone();
	drone->addEnergy(200);
        drone->reduceEnergy(100);
    std::string result;
    if(drone->getEnergy() == 100 && drone->getEnergyCapacity() == 200){
          result="Pass";
    }
    else{
          result="Fail";
    }
        EXPECT_EQ(result, "Pass");

}

//COMPONENT TEST - testing if electrical entity works with a negative value
TEST_F(ElectricalTest, negativeEnergy){
        Drone* drone = new Drone();
        drone->addEnergy(200);
        drone->reduceEnergy(300);
	drone->Update(1);
    std::string result;
    if(drone->getEnergy() == 0){
          result="Pass";
    }
    else{
          result="Fail";
    }
        EXPECT_EQ(result, "Pass");

}

//INTEGRATION TEST - testing if the decorator works with a generic entity
TEST_F(ElectricalTest, GenericTest){
        Entity* entity = new Entity();
        ElectricalEntity* e = new ElectricalEntity(entity, 100);

    std::string result;
    if((e->getEntity())->getEnergy() == 100 && (e->getEntity())->getEnergyCapacity() == 100){
          result="Pass";
    }
    else{
          result="Fail";
    }
        EXPECT_EQ(result, "Pass");

}



#include "project/src/drone.h"
#include "gtest/gtest.h"

class DroneMovementTest : public ::testing::Test {
	public:
		void SetUp() {
			
		}
	protected:
		Drone* droneA = new Drone();
		Drone* droneB = new Drone(0, new Point(0, 20, 0), new Vector(0, 0, 1), 3.0);	
};

//UNIT TEST 1: ChangeStrategy()
TEST_F(DroneMovementTest, ChangeStrategyTest) {
	EXPECT_EQ(droneA->getStrategy(), "patrol");
	droneA->ChangeStrategy("beeline");
	EXPECT_EQ(droneA->getStrategy(), "beeline");
}

//UNIT TEST 2: SetJoystick()
TEST_F(DroneMovementTest, SetJoystickTest) {
	droneA->SetJoystick(1, 2, 3, 4);
	EXPECT_EQ(droneA->getXDir(), 1.0);
	EXPECT_EQ(droneA->getYDir(), 2.0);
	EXPECT_EQ(droneA->getZDir(), 3.0);
	EXPECT_EQ(droneA->getSpeed(), 4.0);
}

//UNIT TEST 3: Patrol
TEST_F(DroneMovementTest, Patrol) {
	droneA->Update(0.1);
	EXPECT_EQ(droneA->getZDir(), 0);
}

//UNIT TEST 4: Para
TEST_F(DroneMovementTest, Para) {
	droneB->ChangeStrategy("para");
	droneB->Update(2.0);
	bool test = false;
	if(droneB->getYDir() == 0) {
		test = true;
	}
	EXPECT_EQ(test, true);
}

//UNIT TEST 5: Drone() Constructor
TEST_F(DroneMovementTest, DroneConstructorATest) { 
	bool pass = false;
	if(droneA->getX() == 0 && droneA->getY() == 10 && droneA->getZ() == 0) {
		pass = true;
	}
	EXPECT_EQ(pass, true);
	
	pass = false;
	if(droneA->getXDir() == 0 && droneA->getYDir() == 0 && droneA->getZDir() == 0) {
		pass = true;
	}
	EXPECT_EQ(pass, true);
	
	EXPECT_EQ(droneA->getStrategy(), "patrol");
}

//UNIT TEST 6: Drone(...) Constructor
TEST_F(DroneMovementTest, DroneConstructorBTest) { 
	bool pass = false;
	if(droneB->getX() == 0 && droneB->getY() == 20 && droneB->getZ() == 0) {
		pass = true;
	}
	EXPECT_EQ(pass, true);
	
	pass = false;
	if(droneB->getXDir() == 0 && droneB->getYDir() == 0 && droneB->getZDir() == 1) {
		pass = true;
	}
	EXPECT_EQ(pass, true);
	
	EXPECT_EQ(droneB->getStrategy(), "patrol");
}

//UNIT TEST 8: set?Dir()
TEST_F(DroneMovementTest, DirSettersTest) { 
	droneA->setXDir(3.0);
	EXPECT_EQ(droneA->getXDir(), 3.0);
	droneA->setYDir(2.0);
	EXPECT_EQ(droneA->getYDir(), 2.0);
	droneA->setZDir(2.5);
	EXPECT_EQ(droneA->getZDir(), 2.5);
}

//UNIT TEST 9: getDir()
TEST_F(DroneMovementTest, DirGetTest) { 
	bool pass = false;
	if(droneA->getXDir() == 0 && droneA->getYDir() == 0 && droneA->getZDir() == 0) {
		pass = true;
	}
	EXPECT_EQ(pass, true);
	
	pass = false;
	if(droneB->getXDir() == 0 && droneB->getYDir() == 0 && droneB->getZDir() == 1) {
		pass = true;
	}
	EXPECT_EQ(pass, true);
}

//UNIT TEST 10: getPos()
TEST_F(DroneMovementTest, PosGetTest) { 
	bool pass = false;
	if(droneA->getX() == 0 && droneA->getY() == 10 && droneA->getZ() == 0) {
		pass = true;
	}
	EXPECT_EQ(pass, true);
	
	pass = false;
	if(droneB->getX() == 0 && droneB->getY() == 20 && droneB->getZ() == 0) {
		pass = true;
	}
	EXPECT_EQ(pass, true);
}





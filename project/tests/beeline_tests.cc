#include "gtest/gtest.h"
#include "project/src/Beeline.h"
#include <fstream>

class BeelineTest : public ::testing::Test {
public:
  void SetUp( ) {
  }
protected:
};

//INTEGRATION TEST - tests beeline with an arbitrary point
TEST_F(BeelineTest, PointTarget){
    Beeline* b = new Beeline(new Point(0, 0, 0));
    Point* destination = new Point(1,1,1);
    Vector output = b->Execute(1, destination, new Vector(0, 0, 0), 1);
    std::string result;
    if(output.x == -1 && output.y == -1 && output.z == -1){
          result="Pass";
    }
    else{
          result="Fail";
    }
        EXPECT_EQ(result, "Pass");
    
}
//INTEGRATION TEST - testing beeline with the same position as the target
TEST_F(BeelineTest, SamePosTarget){
    Beeline* b = new Beeline(new Point(0, 0, 0));
    Point* destination = new Point(0,0,0);
    Vector output = b->Execute(1, destination, new Vector(0, 0, 0), 1);
    std::string result;
    if(output.x == 0 && output.y == 0 && output.z == 0){
          result="Pass";
    }
    else{
          result="Fail";
    }
        EXPECT_EQ(result, "Pass");

}

//INTEGRATION TEST - testing if beeline can account for rounding error and not get DivideByZero
TEST_F(BeelineTest, RoundingErrorTarget){
    Beeline* b = new Beeline(new Point(0, 0, 0));
    Point* destination = new Point(0.0000002,0.0000002,0.0000002);
    Vector output = b->Execute(1, destination, new Vector(0, 0, 0), 1);
    std::string result;
    if(output.x == 0 && output.y == 0 && output.z == 0){
          result="Pass";
    }
    else{
          result="Fail";
    }
        EXPECT_EQ(result, "Pass");

}
//INTEGRATION TEST - testing if beeline can handle negative target
TEST_F(BeelineTest, NegativeTarget){
    Beeline* b = new Beeline(new Point(0, 0, 0));
    Point* destination = new Point(-1,-1,-1);
    Vector output = b->Execute(1, destination, new Vector(0, 0, 0), 1);
    std::string result;
    if(output.x == 1 && output.y == 1 && output.z == 1){
          result="Pass";
    }
    else{
          result="Fail";
    }
        EXPECT_EQ(result, "Pass");

}


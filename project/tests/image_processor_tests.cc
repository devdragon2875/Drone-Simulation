#include "gtest/gtest.h"
#include "project/src/imageProcessor.h"
#include <fstream>
#include "invert.h"
class ImageProcessorTest : public ::testing::Test {
public:
  void SetUp( ) { 
  }
protected:
};


//COMPONENT TEST: 
//What this test does: First we create an image processor. Then we take in an image, then apply the canny-edge-detect filter, 
//which applies multiple different filters/classes to produce an output image. We then ensure the file was produced and thus if 
//the filter was successfully applied. There is a bit of visual verification after this as well.
TEST_F(ImageProcessorTest,FacadeTest){
    ImageProcessor* i=new ImageProcessor();
    std::string inputFile="statue.jpg";
    ifstream input(inputFile.c_str()); //Check to make sure our input image exists, so as not to segfault
    if(input.good()){
        Image input(inputFile.c_str());
        Image output;
          
        std::vector<Image*> inputs;
        std::vector<Image*> outputs;
        inputs.push_back(&input);
        outputs.push_back(&output);
        i->Apply("canny-edge-detect",inputs,outputs);
      
        // Save output image

        std::string outputFile="canny.jpg";
        output.SaveAs(outputFile.c_str());
        ifstream f(outputFile.c_str());
        std::string result;
        if(f.good()){
          result="Pass";
        }
        else{
          result="Fail";
        }
        EXPECT_EQ(result, "Pass");
    }
    else{
        EXPECT_EQ(1, 2);
    }

}


//REGRESSION TEST:
//What this test does: Here, we add a new filter to the image processor facade class. Then, verify the test input file exists, then apply the filter and ensure an output file exists.
//This is a regression test because it tests to see if the existing image processor facade can accept a new filter, and use it without error.
TEST_F(ImageProcessorTest, AddFilter){
    ImageProcessor* i=new ImageProcessor();
    Invert* inv=new Invert();
    std::string filterType="Invert";
    i->AddFilter(inv,filterType);
    std::string inputFile="statue.jpg";
    ifstream input(inputFile.c_str()); //Check to make sure our input image exists, so as not to segfault
    if(input.good()){
        Image input(inputFile.c_str());
        Image output;
          
        std::vector<Image*> inputs;
        std::vector<Image*> outputs;
        inputs.push_back(&input);
        outputs.push_back(&output);
        i->Apply(filterType,inputs,outputs);
      
        // Save output image

        std::string outputFile="invert.jpg";
        output.SaveAs(outputFile.c_str());
        ifstream f(outputFile.c_str());
        std::string result;
        if(f.good()){
          result="Pass";
        }
        else{
          result="Fail";
        }
        EXPECT_EQ(result, "Pass");
    }
    else{
        EXPECT_EQ(1, 2);
    }
  
}

#include "pch.h"
#include "C:\Users\onner\source\repos\DaikinTest\DaikinTest\control.cpp"


//Function Test for the function in control.cpp Verfify that we get the right output depending of the case.
TEST(Test_control_loop, All_value) {
  EXPECT_EQ(control_loop(1,15,20), 1);
  EXPECT_EQ(control_loop(35, 15, 20), 2);
  EXPECT_EQ(control_loop(25, 20, 30), 3);
}
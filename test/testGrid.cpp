#ifndef TESTGRID_CPP
#define TESTGRID_CPP

#include "../src/grid.cpp"
#include "gtest/gtest.h"

TEST(GridTest, GridDefaultContrustor){
   Grid g = Grid();
   EXPECT_EQ(g.getValue(0,0), 0);
}

TEST(GridTest, GridAdd){
   Grid g = Grid();
   g.add(0,0,1);
   g.add(8,8,9);

   EXPECT_EQ(g.getValue(0,0), 1);
   EXPECT_EQ(g.getValue(8,8), 9);
}

TEST(GridTest, GridCheckColRow){
   Grid g = Grid();
   for (int i = 0; i < 9; i++){
      g.add(0, i, i+1); //row 0 filled with 1-9
      g.add(1, i, 1); //row 1 filled with 1's
      g.add(i, 0, i+1); //col 0 filled with 1-9
      g.add(i, 4, 5); //col 4 filled with 5's
   }

   ASSERT_EQ(g.getValue(0,0), 1);
   ASSERT_EQ(g.getValue(1,8), 1);
   ASSERT_EQ(g.getValue(8,0), 9);
   ASSERT_EQ(g.getValue(7,4), 5);
   
   EXPECT_TRUE(g.checkRow(0));
   EXPECT_FALSE(g.checkRow(1));
   EXPECT_TRUE(g.checkCol(0));
   EXPECT_FALSE(g.checkCol(4));  
}

TEST(GridTest, GridCheckBox){
   Grid g = Grid();

   EXPECT_FALSE(g.checkBox(1));
   g.add(0,0,1);
   g.add(0,1,2);
   g.add(0,2,3);
   g.add(1,0,4);
   g.add(1,1,5);
   g.add(1,2,6);
   g.add(2,0,7);
   g.add(2,1,8);
   g.add(2,2,9);
   EXPECT_TRUE(g.checkBox(1));
}
#endif

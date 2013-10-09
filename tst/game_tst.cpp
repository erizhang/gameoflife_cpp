
#include "Game.h"
#include "gtest/gtest.h"


using namespace std;

namespace {
    class GameTest : public ::testing::Test {
    protected:
        GameTest(){

        }
        virtual ~GameTest(){

        }
       
        virtual void SetUp(){
            cout<<"Game Test Suite SetUp"<<endl;
        }

        virtual void TearDown(){
            cout<<"Game Test Suite TearDown"<<endl;
        }
    };

    TEST_F(GameTest, NoneAliveCells){
        Game g(3, 3, "000000000");
        EXPECT_EQ("000000000", g.nextGeneration());
    }

    TEST_F(GameTest, AloneToDieOne){
        Game g(3, 3, "000010000");
        EXPECT_EQ("000000000", g.nextGeneration());
    }

    TEST_F(GameTest, AloneToDieTwo){
        Game g(3, 3, "000110000");
        EXPECT_EQ("000000000", g.nextGeneration());
    }

    TEST_F(GameTest, SurvieUnderTwoNeighbors){
        Game g(3, 3, "010101010");
        EXPECT_EQ("010101010", g.nextGeneration());
    }

}//namespace


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

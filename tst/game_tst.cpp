
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
        }

        virtual void TearDown(){
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

    TEST_F(GameTest, SurvieUnderBlockStyle){
        Game g(4, 4, "0000011001100000");
        EXPECT_EQ("0000011001100000", g.nextGeneration());
    }

    TEST_F(GameTest, SurvieUnderLoafStyle){
        Game g(6, 6, "000000001100010010001010000100000000");
        EXPECT_EQ("000000001100010010001010000100000000", g.nextGeneration());
    }

    TEST_F(GameTest, ChangeInToadStyle){
        Game g(6, 6, "000000000000001110011100000000000000");
        EXPECT_EQ("000000000100010010010010001000000000", g.nextGeneration());
    }

}//namespace


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


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
        Game g;
        EXPECT_EQ("000000000", g.nextGeneration());
    }


}//namespace


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

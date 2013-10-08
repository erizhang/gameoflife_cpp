
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

    TEST_F(GameTest, ConfirmUTSetUp){
        Game g;//(0, 0, "test");
        EXPECT_EQ(3, g.verify_ut(1, 2));
    }
}//namespace


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

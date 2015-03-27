#include <ExceptionModel.h>
#include <gtest.h>

class ExceptionModelTest : public ::testing::Test
{
public:
    ExceptionModelTest() :
        exceptionalObject("An Object"),
        exceptionalFile("filename.cc")
    {
    }

protected:
    void validateOutput(std::string& filename)
    {
        std::string msg = "A message";
        int line = 42;
        std::string expectedOutput = msg + "; location: " + exceptionalFile + "@" + std::to_string(line);
        ExceptionModel::exception<std::string> e = ExceptionModel::create(msg, filename, line, exceptionalObject);
        EXPECT_EQ(exceptionalObject, e.object);
        EXPECT_STREQ(expectedOutput.c_str(), e.what());
    }

    std::string exceptionalObject;
    std::string exceptionalFile;
};

TEST_F(ExceptionModelTest, ExceptionFormatSimple)
{
    std::string filename = exceptionalFile;
    validateOutput(filename);
}

TEST_F(ExceptionModelTest, ExceptionFormatAbsolutePath)
{
    std::string filename = "/home/username/cc_project/" + exceptionalFile;
    validateOutput(filename);
}

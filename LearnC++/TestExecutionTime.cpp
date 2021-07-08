#include "TestExecutionTime.h"
#include <assert.h>

clock_t TestExecutionTime::start_time = 0;
clock_t TestExecutionTime::end_time = 0;
bool TestExecutionTime::start_init = false;

void TestExecutionTime::start()
{
    start_time = clock();
    start_init = true;
}

void TestExecutionTime::end()
{
    end_time = clock();
    assert(start_init);
    std::cout << std::endl << std::endl << "程序运行时间："<<static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000 << "ms" << std::endl;
    start_init = false;
}

TestExecutionTime::TestExecutionTime()
{
}


TestExecutionTime::~TestExecutionTime()
{
}

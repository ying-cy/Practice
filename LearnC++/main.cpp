#include "TestExecutionTime.h"
#include "Base.h"
#include "Head.h"

#include <iostream>
using namespace std;

int main()
{
    TestExecutionTime::start();
    BASE *ch = new _148_sortList_h();
    ch->main();
    TestExecutionTime::end();

    cout << "\n程序停止...\n";

    return 0;
}

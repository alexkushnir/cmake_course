#include "Control/Control.h"
#include "Data/Data.h"

int main()
{
    Control ctrl;
    Data data;

    ctrl.SetControlParameters(5, 4);

    auto d = data.GetData();

    return 0;
}
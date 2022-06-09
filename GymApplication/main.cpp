//
// Created by migue on 09/06/2022.
//
#include "gym.h"
#include "mockdata.h"
#include "controllers.h"
using namespace std;

int main() {
    Gym gym("Ginásio");
    mockdata mock;
    mock.gData(gym);
    Controller controller(gym);
    controller.run();
    return 0;
}


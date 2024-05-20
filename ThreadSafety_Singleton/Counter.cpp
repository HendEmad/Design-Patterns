#include "Counter.h"
#include <mutex>
using namespace std;

Counter* Counter::instance = nullptr;
mutex Counter::lockObj;
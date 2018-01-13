#include "math\Vector2.h"
#include <iostream>

using namespace engine;
using namespace engine::math;

void main() {
	Vector2 v1 = Vector2(1, 1);
	Vector2 v2 = Vector2(2, 2);
	Vector2 v3 = v1 + v2;
	std::cout << v3 << std::endl;

	system("pause");
}
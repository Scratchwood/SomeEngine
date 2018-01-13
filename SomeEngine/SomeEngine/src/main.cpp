#include "math\Vector2.h"
#include "window\Window.h"
#include <iostream>
#include <string>


using namespace engine;
using namespace engine::math;
using namespace engine::window;

void main() 
{
	Vector2 v1 = Vector2(1, 1);
	Vector2 v2 = Vector2(2, 2);
	Vector2 v3 = v1 + v2;
	std::cout << v3 << std::endl;

	std::string name = "SomeEngine";
	Window w = Window(name, 800, 600);

	while (!w.isClosed())
	{
		w.clear();
		w.update();
	}
}
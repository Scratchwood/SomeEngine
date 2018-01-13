#include "CppUnitTest.h"
#include <math\Vector2.cpp>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace SomeEngineTests
{
	TEST_CLASS(Vector2)
	{
	public:

		TEST_METHOD(Vector2_ctor)
		{
			engine::math::Vector2 vector;
			Assert::AreEqual(0.f, vector.x);
			Assert::AreEqual(0.f, vector.y);
		}
		TEST_METHOD(Vector2_ctor_params)
		{
			engine::math::Vector2 vector( 1.f, 2.f );
			Assert::AreEqual(1.f, vector.x);
			Assert::AreEqual(2.f, vector.y);
		}
		TEST_METHOD(Vector2_operator_add)
		{
			engine::math::Vector2 vectorA(1.0f, 2.0f);
			engine::math::Vector2 vectorB(3.0f, 4.0f);
			engine::math::Vector2 actualVector = vectorA + vectorB;

			Assert::AreEqual(4.f, actualVector.x);
			Assert::AreEqual(6.f, actualVector.y);

		}

	};
}
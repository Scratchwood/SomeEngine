#include "CppUnitTest.h"
#include <graphics\Color.cpp>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace SomeEngineTests
{
	TEST_CLASS(Color_test)
	{
	public:

		TEST_METHOD(Color_ctor)
		{
			engine::graphics::Color color;
			Assert::AreEqual(1.f, color.r);
			Assert::AreEqual(1.f, color.g);
			Assert::AreEqual(1.f, color.b);
			Assert::AreEqual(1.f, color.a);
		}

		TEST_METHOD(Color_ctor_hex)
		{
			engine::graphics::Color color(0xff00ff, 0.5f);
			Assert::AreEqual(1.f, color.r);
			Assert::AreEqual(0.f, color.g);
			Assert::AreEqual(1.f, color.b);
			Assert::AreEqual(0.5f, color.a);
		}

		TEST_METHOD(Color_ctor_rgba)
		{
			engine::graphics::Color color(.1f, .2f, .3f, .4f);
			Assert::AreEqual(.1f, color.r);
			Assert::AreEqual(.2f, color.g);
			Assert::AreEqual(.3f, color.b);
			Assert::AreEqual(.4f, color.a);
		}

		TEST_METHOD(Color_setHex)
		{
			engine::graphics::Color color;
			color.setHex(0x000000);
			Assert::AreEqual(0.f, color.r);
			Assert::AreEqual(0.f, color.g);
			Assert::AreEqual(0.f, color.b);
			Assert::AreEqual(1.f, color.a);
		}

		TEST_METHOD(Color_setRGB)
		{
			engine::graphics::Color color(0x000000, 0.5f);
			color.setRGB(1.0f, 1.0f, 1.0f);
			Assert::AreEqual(1.f, color.r);
			Assert::AreEqual(1.f, color.g);
			Assert::AreEqual(1.0f, color.b);
			Assert::AreEqual(0.5f, color.a);
		}

		TEST_METHOD(Color_setRGBA)
		{
			engine::graphics::Color color;
			color.setRGBA(1.0f, 0.5f, 0.25f, 0.0);
			Assert::AreEqual(1.f, color.r);
			Assert::AreEqual(0.5f, color.g);
			Assert::AreEqual(0.25f, color.b);
			Assert::AreEqual(0.0f, color.a);
		}

	};
}
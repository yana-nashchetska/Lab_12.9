#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_12.9/Lab_12.9.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTest)
    {
    public:

		TEST_METHOD(InfixOrderTest)
		{
			Node* tree = CreateTree(0);
			Node* maxNode = NULL;
			tree = CreateTree(1);
			tree->info_num = 10;
			tree->info_word = "A";
			maxNode = NULL;
			InfixOrder(tree, &maxNode);
			Assert::AreEqual(string("A"), maxNode->info_word);

		}
    };
}

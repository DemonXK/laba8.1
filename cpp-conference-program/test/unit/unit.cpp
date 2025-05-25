#include "pch.h"
#include "CppUnitTest.h"
#include "C:\git\laba8.1\cpp-conference-program\main-project/processing.h"
#include "C:\git\laba8.1\cpp-conference-program\main-project/conference_talk.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittestproject
{
    TEST_CLASS(unittestproject)
    {
    public:

        TEST_METHOD(OneTalk)
        {
            std::vector<ConferenceTalk> talks = {
                {"Доклад 1", 70}
            };
            int result = findLongestTalkDuration(talks);
            Assert::AreEqual(70, result);
        }

        TEST_METHOD(MultipleTalks)
        {
            std::vector<ConferenceTalk> talks = {
                {"Доклад 1", 45},
                {"Доклад 2", 110},
                {"Доклад 3", 85}
            };
            int result = findLongestTalkDuration(talks);
            Assert::AreEqual(110, result);
        }

        TEST_METHOD(EmptyList)
        {
            std::vector<ConferenceTalk> talks = {};
            int result = findLongestTalkDuration(talks);
            Assert::AreEqual(0, result);
        }
        TEST_METHOD(TestMethod1) {
            std::vector<ConferenceTalk> talks = {};
            int result = findLongestTalkDuration(talks);
            Assert::AreNotEqual(result, 5); // Пример теста, который ожидает ненулевой результат
        }

        TEST_METHOD(FormattedTime)
        {
            int minutes = 135;
            std::string result = formatDuration(minutes);
            Assert::AreEqual(std::string("02:15"), result);
        }
    };
}

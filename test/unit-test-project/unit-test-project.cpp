#include "pch.h"
#include "CppUnitTest.h"

#include "C:\git\laba8.1\test\unit/processing.h"
#include "C:\git\laba8.1\test\unit/conference_talk.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittestproject
{
    TEST_CLASS(unittestproject)
    {
    public:

        TEST_METHOD(SingleTalk_ReturnsItsDuration)
        {
            std::vector<ConferenceTalk> talks = {
                {"Открытие", 45}
            };
            int result = findLongestTalkDuration(talks);
            Assert::AreEqual(45, result);
        }

        TEST_METHOD(MultipleTalks_ReturnsMaxDuration)
        {
            std::vector<ConferenceTalk> talks = {
                {"Доклад 1", 20},
                {"Доклад 2", 90},
                {"Доклад 3", 60}
            };
            int result = findLongestTalkDuration(talks);
            Assert::AreEqual(90, result);
        }

        TEST_METHOD(EmptyList_ReturnsZero)
        {
            std::vector<ConferenceTalk> talks = {};
            int result = findLongestTalkDuration(talks);
            Assert::AreEqual(0, result);
        }
    };
}

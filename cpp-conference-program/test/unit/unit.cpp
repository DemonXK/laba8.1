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
            std::vector<ConferenceEntry> talks = {
                {10, 0, 11, 10, "Иванов", "Иван", "Иванович", "Доклад 1", "10:00", "11:10"}
            };
            int result = findLongestTalkDuration(talks);
            Assert::AreEqual(70, result);
        }

        TEST_METHOD(MultipleTalks)
        {
            std::vector<ConferenceEntry> talks = {
                {10, 0, 10, 45, "Смирнов", "Олег", "Петрович", "Доклад 1", "10:00", "10:45"},  
                {11, 0, 12, 50, "Сидоров", "Антон", "Игоревич", "Доклад 2", "11:00", "12:50"}, 
                {13, 0, 14, 25, "Петров", "Алексей", "Дмитриевич", "Доклад 3", "13:00", "14:25"} 
            };
            int result = findLongestTalkDuration(talks);
            Assert::AreEqual(110, result);
        }

        TEST_METHOD(EmptyList)
        {
            std::vector<ConferenceEntry> talks = {};
            int result = findLongestTalkDuration(talks);
            Assert::AreEqual(0, result);
        }
        TEST_METHOD(TestMethod1) {
            std::vector<ConferenceEntry> talks = {};
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

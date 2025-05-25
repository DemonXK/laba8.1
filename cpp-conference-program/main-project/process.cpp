#include "processing.h"
#include <sstream>
#include <iomanip>

// ���������� ������������ �����������������
int findLongestTalkDuration(const std::vector<ConferenceTalk>& talks) {
    int maxDuration = 0;
    for (const auto& talk : talks) {
        if (talk.durationMinutes > maxDuration) {
            maxDuration = talk.durationMinutes;
        }
    }
    return maxDuration;
}

// ����������� ������ � ������ ��:��
std::string formatDuration(int minutes) {
    int hours = minutes / 60;
    int mins = minutes % 60;
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << hours
        << ":" << std::setw(2) << std::setfill('0') << mins;
    return oss.str();
}

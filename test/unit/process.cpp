#include "processing.h"

int findLongestTalkDuration(const std::vector<ConferenceTalk>& talks) {
    int maxDuration = 0;
    for (const auto& talk : talks) {
        if (talk.durationMinutes > maxDuration) {
            maxDuration = talk.durationMinutes;
        }
    }
    return maxDuration;
}

#ifndef LAB3_GAMEVIEW_H
#define LAB3_GAMEVIEW_H

#include <string>

class GameView {
public:
    virtual void sendMessage(const std::string &message) const = 0;
    virtual void sendMessage(unsigned int message) const = 0;
    virtual ~GameView() = default;
};

#endif //LAB3_GAMEVIEW_H

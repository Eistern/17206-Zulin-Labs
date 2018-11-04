#ifndef LAB3_CONSOLEVIEW_H
#define LAB3_CONSOLEVIEW_H

#include "../GameView.h"

class ConsoleView : public GameView {
public:
    void sendMessage(const std::string &message) const override;
    void sendMessage(unsigned int message) const override;
};


#endif //LAB3_CONSOLEVIEW_H

#ifndef LAB3_CONSOLEVIEW_H
#define LAB3_CONSOLEVIEW_H

#include "../GameView.h"

class ConsoleView : public GameView {
public:
    void sendMessage(const std::string &message) const override;
    void printBoard() const override;
};


#endif //LAB3_CONSOLEVIEW_H

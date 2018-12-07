#ifndef LAB3_CONSOLEVIEW_H
#define LAB3_CONSOLEVIEW_H

#include "../GameView.h"

class ConsoleView : public GameView {
public:
    void sendMessage(const std::string &) const override;
    void printBoard(const Board&) const override;
};


#endif //LAB3_CONSOLEVIEW_H

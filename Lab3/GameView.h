#ifndef LAB3_GAMEVIEW_H
#define LAB3_GAMEVIEW_H

class GameView {
public:
    virtual void updateFrame() = 0;
    virtual ~GameView() = default;
};

#endif //LAB3_GAMEVIEW_H

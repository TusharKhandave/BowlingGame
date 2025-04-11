#ifndef BOWLINGGAME_H
#define BOWLINGGAME_H

#include <vector>

class BowlingGame {
private:
    std::vector<int> rolls;

    // Helper function to check if it's a strike
    bool isStrike(int frameStart) const;

    // Helper function to check if it's a spare
    bool isSpare(int frameStart) const;

    // Helper function to get the score for a strike
    int strikeScore(int frameStart) const;

    // Helper function to get the score for a spare
    int spareScore(int frameStart) const;

    // Helper function to get the score for a normal frame
    int normalFrameScore(int frameStart) const;

public:
    BowlingGame();
    void roll(int pins);
    int score() const;
    void play();
};

#endif // BOWLINGGAME_H
#include "bowlinggame.h"
#include <iostream>
#include <numeric> // For std::accumulate

using namespace std;

// Helper function to check if it's a strike
bool BowlingGame::isStrike(int frameStart) const {
    return rolls[frameStart] == 10;
}

// Helper function to check if it's a spare
bool BowlingGame::isSpare(int frameStart) const {
    return !isStrike(frameStart) && rolls[frameStart] + rolls[frameStart + 1] == 10;
}

// Helper function to get the score for a strike
int BowlingGame::strikeScore(int frameStart) const {
    return 10 + rolls[frameStart + 1] + rolls[frameStart + 2];
}

// Helper function to get the score for a spare
int BowlingGame::spareScore(int frameStart) const {
    return 10 + rolls[frameStart + 2];
}

// Helper function to get the score for a normal frame
int BowlingGame::normalFrameScore(int frameStart) const {
    return rolls[frameStart] + rolls[frameStart + 1];
}

BowlingGame::BowlingGame() : rolls() {}

void BowlingGame::roll(int pins) {
    rolls.push_back(pins);
}

int BowlingGame::score() const {
    int totalScore = 0;
    int rollIndex = 0;

    for (int frame = 0; frame < 10; ++frame) {
        if (rollIndex >= rolls.size()) {
            break; // Should not happen in a valid game
        }

        if (isStrike(rollIndex)) {
            totalScore += strikeScore(rollIndex);
            rollIndex++;
        } else if (rollIndex + 1 < rolls.size() && isSpare(rollIndex)) {
            totalScore += spareScore(rollIndex);
            rollIndex += 2;
        } else {
            if (rollIndex + 1 < rolls.size()) {
                totalScore += normalFrameScore(rollIndex);
                rollIndex += 2;
            } else {
                break; // Should not happen in a valid game
            }
        }
    }
    return totalScore;
}

void BowlingGame::play() {
    cout << "Starting a bowling game..." << endl;

    for (int frame = 0; frame < 10; ++frame) {
        cout << "Frame " << frame + 1 << " Enter Roll 1 value: ";
        int roll1;
        cin >> roll1;

        if (roll1 < 0 || roll1 > 10) {
            cout << "Invalid roll value. Please enter a value between 0 and 10." << endl;
            frame--;
            continue;
        }
        roll(roll1);

        if (roll1 == 10) {
            cout << "Strike!" << endl;
            if (frame == 9) { // Last frame bonus rolls
                cout << "Enter bonus Roll 2 value: ";
                int roll2;
                cin >> roll2;
                if (roll2 < 0 || roll2 > 10) {
                    cout << "Invalid roll value." << endl;
                    break;
                }
                roll(roll2);
                cout << "Enter bonus Roll 3 value: ";
                int roll3;
                cin >> roll3;
                if (roll3 < 0 || roll3 > 10) {
                    cout << "Invalid roll value." << endl;
                    break;
                }
                roll(roll3);
            }
        } else {
            cout << "Frame " << frame + 1 << " Enter Roll 2 value: ";
            int roll2;
            cin >> roll2;
            if (roll2 < 0 || roll1 + roll2 > 10) {
                cout << "Invalid roll value. Sum cannot exceed 10." << endl;
                rolls.pop_back(); // Remove the first invalid roll
                frame--;
                continue;
            }
            roll(roll2);
            if (frame == 9 && roll1 + roll2 == 10) { // Last frame bonus roll for spare
                cout << "Spare! Enter bonus Roll 3 value: ";
                int roll3;
                cin >> roll3;
                if (roll3 < 0 || roll3 > 10) {
                    cout << "Invalid roll value." << endl;
                    break;
                }
                roll(roll3);
            }
        }
        cout << "Your current total score (after frame " << frame + 1 << "): " << score() << endl;
    }
    cout << "Your final score is: " << score() << endl;
}
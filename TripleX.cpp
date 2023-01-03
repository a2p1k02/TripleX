#include <iostream>
#include <ctime>


bool Game(int difficulty)
{
    std::cout << "You're a secret agent breaking into a LEVEL " << difficulty << " server room\n";
    std::cout << "Your SuperHacker 3000 tells you the following information...\n";

    srand(time(NULL));
    const int a = rand() % difficulty + difficulty;
    const int b = rand() % difficulty + difficulty;
    const int c = rand() % difficulty + difficulty;

    const int sum = a + b + c;
    const int product = a * b * c;

    std::cout << std::endl;
    std::cout << "+ There are three numbers in the code\n";
    std::cout << "+ The codes multiply to give " << product << std::endl;
    std::cout << "+ The codes add-up to " << sum << std::endl;

    std::cout << std::endl;
    std::cout << "Enter the three code numbers followed by x" << std::endl;
    std::cout << std::endl;

    int answerA, answerB, answerC;

    std::cin >> answerA >> answerB >> answerC;

    int tmpSum = answerA + answerB + answerC;
    int tmpProduct = answerA * answerB * answerC;

    std::cout << std::endl;
    if (tmpSum == sum && tmpProduct == product) {
        std::cout << "Congratulations! You're IN. Now hurry before anyone finds you.\n";
        std::cout << "==============================================================\n";
        return true;
    }
    else {
        std::cout << "BOOM :-( You failed mission!\n";
        return false;
    }
}

int main()
{
    int levelDifficulty = 1;
    const int maxDifficulty = 3;

    while (levelDifficulty <= maxDifficulty) {
        bool levelComplete = Game(levelDifficulty);

        std::cin.clear();
        std::cin.ignore();

        if (levelComplete) {
            ++levelDifficulty;
        }

    }

    return 0;
}

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;


// Abstract Oyuncu
class Player {
    protected:
        string name;
        string choice;
        int score;
    public: 
        Player(string name){
            this->name = name;
            this->score = 0;
        }
        string getName(){
            return this->name;
        }
        string getChoice(){
            return this->choice;
        }
        int getScore(){
            return this->score;
        }
        void increaseScore(){
            this->score++;
        }
    
        virtual void makeChoice() = 0; // Abstract method

};

class HumanPlayer : public Player {

    public:
        HumanPlayer(string name) : Player(name){} // Çok biçimlilik
    
        void makeChoice() override {

            int choiceNum;

            cout << "\n1 - Tas" << endl;
            cout << "2 - Kagit" << endl;
            cout << "3 - Makas" << endl;

            cout << name << " secimin: ";
            cin >> choiceNum;

            if(choiceNum == 1){
                choice = "Tas";
            } else if(choiceNum == 2){
                choice = "Kagit";
            } else if(choiceNum == 3){
                choice = "Makas";
            } else {
                cout << "Gecersiz secim!" << endl;
                makeChoice(); 
            }
        }
};

class RandomComputerPlayer : public Player {
public:

    RandomComputerPlayer()
        : Player("Bilgisayar") {
    }

    void makeChoice() override {

        int randomMove = rand() % 3 + 1;

        if (randomMove == 1)
            choice = "Tas";
        else if (randomMove == 2)
            choice = "Kagit";
        else
            choice = "Makas";
    }
};

int main() {

    srand(time(0));

    string name;
    char devam;

    vector<string> history;

    cout << "Oyuncu adini gir: ";
    cin >> name;

    HumanPlayer human(name);
    RandomComputerPlayer computer;

    do {

        human.makeChoice();
        computer.makeChoice();

        cout << "\n-------------------" << endl;

        cout << human.getName()
             << ": "
             << human.getChoice() << endl;

        cout << computer.getName()
             << ": "
             << computer.getChoice() << endl;


        string result;

        if (human.getChoice() == computer.getChoice()) {

            result = "Berabere!";

        } else if (
            (human.getChoice() == "Tas" && computer.getChoice() == "Makas") ||
            (human.getChoice() == "Kagit" && computer.getChoice() == "Tas") ||
            (human.getChoice() == "Makas" && computer.getChoice() == "Kagit")
        ) {

            result = human.getName() + " kazandi!";
            human.increaseScore();

        } else {

            result = computer.getName() + " kazandi!";
            computer.increaseScore();
        }


        cout << "\nSonuc: " << result << endl;


        history.push_back(
            human.getChoice() + " - " +
            computer.getChoice() + " -> " +
            result
        );


        cout << "\nPuanlar" << endl;

        cout << human.getName()
             << ": "
             << human.getScore() << endl;

        cout << computer.getName()
             << ": "
             << computer.getScore() << endl;


        cout << "\nDevam etmek ister misin? (e/h): ";
        cin >> devam;

    } while (devam == 'e' || devam == 'E');


    cout << "\n===== OYUN SONU =====" << endl;

    cout << human.getName()
         << ": "
         << human.getScore() << endl;

    cout << computer.getName()
         << ": "
         << computer.getScore() << endl;


    cout << "\n===== GECMIS =====" << endl;

    for (int i = 0; i < history.size(); i++) {
        cout << i + 1
             << ". Tur: "
             << history[i] << endl;
    }


    return 0;
}
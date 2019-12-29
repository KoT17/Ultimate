#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream folder;
    string opponent, tournament, scoreLimit;

    cout << "Who was UCF playing?" << endl;
    cin >> opponent;

    cout << "Which Tournament?" << endl;
    cin >> tournament;

    folder.open("Games/"+opponent+tournament+"/info.txt");

    if (folder.fail()) {
        cerr << "Failed to load game information" << endl;
    }

    folder >> scoreLimit;
    folder.close();
    scoreLimit = scoreLimit.substr(11,13);

    std::string::size_type size_t;
    int limit = stoi(scoreLimit, &size_t);
    int half = limit / 2  + 1;
    int point = 1;

    int opponentScore, ucfScore;
    while (opponentScore < limit && ucfScore < limit) {
      folder.open("Games/"+opponent+tournament+"/UCFvs"+opponent+"\ -\ Point_"+to_string(point)+".csv");
      if(folder.fail()) {
        std::cerr << "Point CSVs has finished" << endl;
        break;
      }

      cout << "Point " << to_string(point) << " has been processed" << endl;
      point++;
      folder.close();
    }
    return 0;
}

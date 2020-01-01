#include <iostream>
#include <fstream>
#include <string>
#include<vector>

using namespace std;

bool teamScores(int players[][16]);
string* prompt();
void process_game(int scoreCap, string input[2]);
vector<vector<int>> convert_player_data(string playerRawInfo[][16]); // May need to convert to vector

void process_game(int scoreCap, string input[2]) {
  ifstream pointFile;

  int opponentScore, homeScore, count = 1;

  string titles[16];
  string playerRawInfo[7][16];

  vector<vector<int>> playerConverted;

  while (opponentScore < scoreCap && homeScore < scoreCap) {
    pointFile.open("Games/"+input[0]+input[1]+"/UCFvs"+input[0]+"\ -\ Point_"+to_string(count)+".csv");
    if (pointFile.fail()) {
      std::cerr << "Point CSVs has finished" << endl;
      break;
    }

    playerConverted = convert_player_data(playerRawInfo);

    cout << "Point " << to_string(count) << " has been processed" << endl;
    count++;
    /*if(teamScores(playerConverted))
      homeScore++;
    else
      opponentScore++;*/


    pointFile.close();
  }
}

// May tranverse the player array to determine scores instead of (n^2) apporach

bool teamScores(int players[][16]) {

}

vector<vector<int>> convert_player_data(string playerRawInfo[][16]) {
  vector<vector<int>> result;

  return result;
}

string* prompt() {
  string* input = new string[2];
  cout << "Who was UCF playing?" << endl;
  cin >> input[0];

  cout << "Which Tournament?" << endl;
  cin >> input[1];

  return input;
}

int main() {
    ifstream folder;
    string opponent, tournament, scoreLimit;
    string* input;

    input = prompt();//Opponent = [0] Tournament = [1]

    folder.open("Games/"+input[0]+input[1]+"/info.txt");

    if (folder.fail()) {
        cerr << "Failed to load game information" << endl;
    }

    folder >> scoreLimit;
    folder.close();
    scoreLimit = scoreLimit.substr(11,13);

    std::string::size_type size_t;
    int limit = stoi(scoreLimit, &size_t);
    process_game(limit, input);

}

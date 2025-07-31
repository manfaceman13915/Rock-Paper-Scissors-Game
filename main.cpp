#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

string getMoveName(int move) {
    if (move == 0) return "ค้อน";
    else if (move == 1) return "กระดาษ";
    else return "กรรไกร";
}

string getWinner(int player, int cpu) {
    if (player == cpu) return "Draw";
    if ((player == 0 && cpu == 2) ||
        (player == 1 && cpu == 0) ||
        (player == 2 && cpu == 1)) {
        return "Win!";
    }
    return "Lose";
}

int main() {
    int playerScore = 0;
    int cpuScore = 0;
    int drawCount = 0;

    char again = 'y';
    srand(time(0)); // ตั้งค่าสุ่มเพียงครั้งเดียว

    while (again == 'y' || again == 'Y') {
        int player;
        cout << "\nเลือกทำ: 0 = ค้อน, 1 = กระดาษ, 2 = กรรไกร >> ";
        cin >> player;

        while (player < 0 || player > 2) {
            cout << "เลือกไม่ถูกต้อง กรุณาเลือก 0, 1 หรือ 2 >> ";
            cin >> player;
        }

        int cpu = rand() % 3;

        cout << "คุณเลือก: " << getMoveName(player) << endl;
        cout << "คอมเลือก: " << getMoveName(cpu) << endl;

        string result = getWinner(player, cpu);

        if (result == "Win!") {
            cout << "คุณชนะ!" << endl;
            playerScore++;
        }
        else if (result == "Lose") {
            cout << "คุณแพ้!" << endl;
            cpuScore++;
        }
        else {
            cout << "เสมอกัน!" << endl;
            drawCount++;
        }

        cout << "คะแนนปัจจุบัน - คุณ: " << playerScore
             << " | คอม: " << cpuScore
             << " | เสมอ: " << drawCount << endl;

        cout << "เล่นอีกไหม (y/n)? ";
        cin >> again;
    }

    // แสดงผลรวมหลังจบเกม
    cout << "\n=== สรุปผลการเล่น ===" << endl;
    cout << "คุณชนะ: " << playerScore << " ครั้ง" << endl;
    cout << "คอมชนะ: " << cpuScore << " ครั้ง" << endl;
    cout << "เสมอ: " << drawCount << " ครั้ง" << endl;
    cout << "ขอบคุณที่เล่น!" << endl;

    return 0;
}

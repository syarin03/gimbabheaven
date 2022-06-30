#include <iostream>
#include "menu.h"
using namespace std;

int selOpt();
int printMenu1();
int printMenu2(int n);
int buyMenu();

Menu menu[8][11] = {{{"김밥", 2500}, {"참치김밥", 3000}, {"돈가스김밥", 3500}, {"고추참치김밥", 3500},
                     {"소고기김밥", 4500}, {"치즈김밥", 3000}, {"샐러드김밥", 2500}, {"꼬마김밥", 1200},
                     {"충무김밥", 20000}, {"꽈리김밥", 3500}, {"진미김밥", 3700}},
                    {{"라면",
                      4000}, {"치즈라면", 4500}, {"된장라면", 4700}, {"떡라면", 4800}, {"만두라면", 4500},
                     {"떡만두라면", 5000}, {"카레라면", 4500}, {"해물라면", 5500}, {"짜장라면", 4200}, {"비빔라면", 4200}, {"", 0}},
                    {{"돈가스", 8000}, {"치즈돈가스", 9000}, {"고구마치즈돈가스", 10000}, {"등심돈가스", 7500},
                     {"안심돈가스", 7500}, {"피카츄돈가스", 500}, {"새우돈가스", 7500}, {"대왕돈가스", 12000},
                     {"치킨돈가스", 6000}, {"함박스테이크", 9500}, {"", 0}},
                    {{"제육덮밥", 7000}, {"오므라이스", 7000}, {"하이라이스", 7000}, {"오징어덮밥", 7500},
                     {"짜장덮밥", 6500}, {"소고기덮밥", 8000}, {"카레덮밥", 6500}, {"돌솥비빔밥", 7000}, {"김치덮밥", 6500}, {"", 0}, {"", 0}},
                    {{"김치찌개", 6500}, {"된장찌개", 6500}, {"순두부찌개", 6500}, {"내장찌개", 6500},
                     {"해물된장찌개", 8000}, {"부대찌개", 7800}, {"", 0}, {"", 0}, {"", 0}, {"", 0}, {"", 0}},
                    {{"떡볶이", 3000}, {"치즈떡볶이", 4500}, {"라볶이", 5000}, {"마약떡볶이", 99900}, {"컵떡볶이", 500}, {"", 0}, {"", 0}, {"", 0}, {"", 0}, {"", 0}, {"", 0}},
                    {{"우동", 3000}, {"튀김우동", 4500}, {"김치우동", 4500}, {"유부우동", 4500}, {"", 0}, {"", 0}, {"", 0}, {"", 0}, {"", 0}, {"", 0}, {"", 0}},
                    {{"육개장", 6000}, {"알탕", 7500}, {"갈비탕", 8000}, {"황태해장국", 7000},
                     {"순대국밥", 5500}, {"명태국밥", 7000}, {"공기밥", 1000}, {"", 0}, {"", 0}, {"", 0}, {"", 0}}
};

int main() {
    bool loop = true;
    int sel, n1, n2, money, total = 0, cnt = 0;
    Menu selmenu[100];

    cout << "현재 내 지갑\n>>> ";
    cin >> money;
    cout << endl;

    while (loop) {
        switch (selOpt()) {
            case 1:
                n1 = printMenu1();
                n2 = printMenu2(n1);
                selmenu[cnt] = menu[n1][n2];
                cout << selmenu[cnt].getName() << endl;
                cnt++;
                break;
            case 2:
                cout << money << "원" << endl;
                break;
            case 3:
                cout << "선택한 메뉴: ";
                for (auto i : selmenu) {
                    if (strcmp(i.getName(), " ") != 0)
                        cout << i.getName() << " ";
                    total += i.getPrice();
                }
                cout << endl;
                cout << "계산할 금액: " << total << "원" << endl;
                cout << "(1) 계산\t(2) 취소\n>>> ";
                cin >> sel;
                if (sel == 1) {
                    if (total > money) {
                        cout << "금액이 모자랍니다" << endl << endl;
                        // 금액 충전 or 종료 or 메뉴 선택 해제
                    }
                    money -= total;
                    cout << total << "원 계산되었습니다" << endl << "현재 내 지갑: " << money << "원" << endl << endl;
                }
                break;
            case 4:
                cout << "종료" << endl;
                loop = false;
            default:
                break;
        }
    }
    return 0;
}

int selOpt() {
    cout << "(1) 메뉴 선택\n(2) 잔액 확인\n(3) 계산\n(4) 종료\n>>> ";
    int sel;
    cin >> sel;
    cout << endl;

    return sel;
}

int printMenu1() {
    cout << "(1) 김밥\n(2) 라면\n(3) 돈가스\n(4) 덮밥류\n(5) 찌개류\n(6) 떡볶이\n(7) 우동\n(8) 국밥류\n>>> ";
    int sel;
    cin >> sel;
    cout << endl;

    return sel-1;
}

int printMenu2(int n) {
    for (int i = 0; i < 11; i++) {
        if (menu[n][i].getPrice() != 0)
            cout << "(" << i+1 << ") " << menu[n][i].getName() << " " << menu[n][i].getPrice() << endl;
    }
    cout << ">>> ";
    int sel;
    cin >> sel;
    cout << endl;

    return sel-1;
}

#include <iostream> 
#include <string> 
#include <sqlite_modern_cpp.h> 
#include<vector> 
using namespace sqlite;
using namespace std;
struct User
{

    std::string login_user;
    std::string password_user;
    void end() {
        login_user = nullptr;
        password_user = nullptr;
    }
};
class Gallow {
    int count_2;
    int right;
    int wrong;
    std::vector<std::string> words = {
       "�����", "�����", "�����", "�����", "�����",
       "�����", "�����", "�����", "�����", "�����",
       "����", "�����", "����", "����", "������",
       "����", "�����", "������", "�����", "������",
       "�����", "�����", "�����", "�����", "������",
       "������", "�����", "�����", "����", "�����",
       "�����", "�����", "�����", "����", "�������",
       "�����", "����", "�����", "�����", "�����",
       "�����", "����", "�����", "����", "������",
       "�����", "�����", "�����", "������", "�����"
    };
    string rword;
    int life;
    void rand_word() {
        int x = rand() % (50 - 1 + 1) + 1;
        rword = words[x];
    }

    char* using_word = new char{};
    void push_back_word() {
        for (int i = 0; i < 5; i++) {
            using_word[i] = rword[i];
        }

    }




    bool access(char user_words) {


        bool flage = false;
        for (int i = 0; i < 5 + 1; i++) {
            if (user_words == rword[i]) {
                flage == true;
                right++;
            }
            else {

                life--;
                flage == false;
                wrong++;
            }
        }

        return flage;
    }


public:


    void run() {
        while (true)
        {
            string  user_string;
            char user_char;
            int user_nember;
            cout << "�������� �������  ��������� �� 1 �� 5" << "\n" << "��� ����" << endl;
            cin >> user_nember;
            switch (user_nember)
            {
            case 1:
                life = 7;
                cout << " � ��� 7 ������" << endl;
                rand_word();
                push_back_word();
                while (true)
                {
                    if (life == 0) {
                        break;
                    }
                    else if (right == 5) {
                        count();
                        break;
                    }
                    else {
                        user_char = user_string[0];
                        cout << "������ ������� �����";
                        cin >> user_string;
                        if (access(user_char) == true) {
                            cout << " �� ��������  ���������" << endl;

                        }
                        else {
                            cout << " �� ��������  �� ���������" << "\n ��������  ������:" + life << endl;
                        }
                    }
                }

                break;
            case 2:
                life = 6;
                cout << " � ��� 6 ������" << endl;
                rand_word();
                push_back_word();

                while (true)
                {
                    if (life == 0) {
                        break;
                    }
                    else if (right == 5) {
                        count();
                        break;
                    }
                    else {
                        user_char = user_string[0];
                        cout << "������ ������� �����";
                        cin >> user_string;
                        if (access(user_char) == true) {
                            cout << " �� ��������  ���������" << endl;

                        }
                        else {
                            cout << " �� ��������  �� ���������" << "\n ��������  ������:" + life << endl;
                        }
                    }
                }
                break;
            
            case 3:
                life = 5;
                cout << " � ��� 5 ������" << endl;
                rand_word();
                push_back_word();

                while (true)
                {
                    if (life == 0) {
                        break;
                    }
                    else if (right == 5) {
                        count();
                        break;
                    }
                    else {
                        user_char = user_string[0];
                        cout << "������ ������� �����";
                        cin >> user_string;
                        if (access(user_char) == true) {
                            cout << " �� ��������  ���������" << endl;

                        }
                        else {
                            cout << " �� ��������  �� ���������" << "\n ��������  ������:" + life << endl;
                        }
                    }
                }
                break;
            case 4:
                life = 4;
                cout << " � ��� 4 ������" << endl;
                rand_word();
                push_back_word();


                while (true)
                {
                    if (life == 0) {
                        break;
                    }
                    else if (right == 5) {
                        count();
                        break;
                    }
                    else {
                        user_char = user_string[0];
                        cout << "������ ������� �����";
                        cin >> user_string;
                        if (access(user_char) == true) {
                            cout << " �� ��������  ���������" << endl;

                        }
                        else {
                            cout << " �� ��������  �� ���������" << "\n ��������  ������:" + life << endl;
                        }
                    }
                }
                break;
        
            case 5:
                life = 3;
                cout << " � ��� 3 ������" << endl;
                rand_word();
                push_back_word();
                while (true)
                {
                    if (life == 0) {
                        break;
                    }
                    else if (right == 5) {
                        count();
                        break;
                    }
                    else {

                        cout << "������ ������� �����";
                        cin >> user_string;
                        user_char = user_string[0];
                        if (access(user_char) == true) {
                            cout << " �� ��������  ���������" << endl;

                        }
                        else {
                            cout << " �� ��������  �� ���������" << "\n ��������  ������:" + life << endl;
                        }
                    }
                }
                break;

            default:
                break;
    }
} 
}
int count(){
        return right - wrong;
     }
};
class AccountManager {
public:
    AccountManager() {
        db << "CREATE TABLE IF NOT EXISTS users ("
            "id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"
            "login TEXT UNIQUE,"
            "password TEXT,"
            "point INT"
            ");";
    }

    bool access(const string& login, const string& password) {
        int count = 0;

        db << "SELECT COUNT(*) FROM users WHERE login = ?;"
            << login
            >> count;

        if (count > 0) {
            std::cout << "������! ������������ � ����� ������� ��� ����������. ���������� �����.\n";
            return false;
        }
        else {
            db << "INSERT INTO users (login, password) VALUES (?, ?);"
                << login
                << password;
                
            std::cout << "������������ ������� ���������������!\n";
            return true;
        }
    }

    bool add(const string& login, const string& password) {
        User u;

        u.login_user = login;
        u.password_user = password;
        return access(login, password);
    }

    bool login(const string& login, const string& password) {
        int count = 0;

        db << "SELECT COUNT(*) FROM users WHERE login = ? AND password = ?;"
            << login
            << password
            >> count;

        if (count > 0) {
            std::cout << "����������� �������! ����� ����������, " << login << "!\n";
            return true;
        }
        else {
            std::cout << "������! �������� ����� ��� ������.\n";
            return false;
        }
    }
    bool and_point(int point) {
        db << "INSERT INTO users (point) VALUES (?);"
             << point;
    }
private:
    database db{ "database.db" };
};

class CLTMaseng {
public:
    static void run() {
        cout << "1 - ����������� \n" << "2 - ����������� \n" << "3 - ����� �� �������\n" << "4 - �����\n";
        while (true) {
            int number;
            cin >> number;

            int point=0;
            AccountManager a;
            string login;
            string password;
            Gallow g;
            User u;
            switch (number) {
            case 1:
                cout << "����������� (login, password): ";
                cin >> login >> password;
                a.add(login, password);
                break;
            case 2:
                cout << "����������� (login, password): ";
                cin >> login >> password;
                a.login(login, password);
                g.run();
                point =+ g.count();
                cout << " � ��� " + point<< "�������" << endl;
                break;
            case 3:
                cout << "����� �� �������: " << "\n";
                u.end();
                break;
            case 4:
                cout << "����� " << "\n";
                u.end();
                return;
            default:
                cout << "�������� �����, ���������� �����.\n";
                break;
            }
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    CLTMaseng c;
    c.run();

}
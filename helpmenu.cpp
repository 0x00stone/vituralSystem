#include <iostream>
#include <string>
using namespace std;

class helpmenu {
public:
    static void menu() {
        printf("\n************************************************************************\n");
        printf("************* �й�ĳ���������ϸ��Ϣ������� help ������ ***************\n");
        printf("************* quit               �˳�                    ***************\n");
        printf("************* create             �����ļ�                ***************\n");
        printf("************* delete             ɾ���ļ�                ***************\n");
        printf("************* open               ���ļ�                ***************\n");
        printf("************* close              �ر��ļ�                ***************\n");
        printf("************* read               ���ļ�                  ***************\n");
        printf("************* write              д�ļ�                  ***************\n");
        printf("************* ls                 �鿴UFD                 ***************\n");
        printf("************* logout             �˳���ǰ�û�            ***************\n");
        printf("************* help               �鿴�û�ѡ��            ***************\n");
        printf("************************************************************************\n\n");
    }

    static void help(string command) {
        cout <<endl << "help command" << endl;
        if (command == "quit") {
            cout << "���� : �˳�����" << endl;
            cout << "�÷� : quit" << endl << endl;
        }
        else if (command == "create") {
            cout << "���� : �����ļ�" << endl;
            cout << "�÷� : create <�ļ���> [�ļ�Ȩ��]" << endl;
            cout << "       �ļ�Ȩ��(1ִֻ�� 2ֻ�� 3��д,4�ɶ�д)" << endl << endl;
        }
        else if (command == "delete") {
            cout << "���� : ɾ���ļ�" << endl;
            cout << "�÷� : delete <�ļ���>" << endl << endl;
        }
        else if (command == "open") {
            cout << "���� : ���ļ�" << endl;
            cout << "�÷� : open <�ļ���>" << endl << endl;
        }
        else if (command == "close") {
            cout << "���� : �ر��ļ�" << endl;
            cout << "�÷� : close <�ļ���>" << endl << endl;
        }
        else if (command == "read") {
            cout << "���� : ��ȡ�ļ�" << endl;
            cout << "�÷� : read <�ļ���>" << endl << endl;
        }
        else if (command == "write") {
            cout << "���� : д�ļ�" << endl;
            cout << "�÷� : write <�ļ���>" << endl << endl;
        }
        else if (command == "ls") {
            cout << "���� : �鿴�ļ�����" << endl;
            cout << "�÷� : ls" << endl << endl;
        }
        else if (command == "logout") {
            cout << "���� : �ǳ���ǰ�˻�" << endl;
            cout << "�÷� : logout" << endl << endl;
        }
        else if (command == "help") {
            cout << "���� : ��ѯ�����ļ�" << endl;
            cout << "�÷� : help" << endl<<endl;
        }
        else {}
    }
};
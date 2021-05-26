#include <iostream>
#include <string>
using namespace std;

class helpmenu {
public:
    static void menu() {
        printf("\n************************************************************************\n");
        printf("************* 有关某个命令的详细信息，请键入 help 命令名 ***************\n");
        printf("************* quit               退出                    ***************\n");
        printf("************* create             创建文件                ***************\n");
        printf("************* delete             删除文件                ***************\n");
        printf("************* open               打开文件                ***************\n");
        printf("************* close              关闭文件                ***************\n");
        printf("************* read               读文件                  ***************\n");
        printf("************* write              写文件                  ***************\n");
        printf("************* ls                 查看UFD                 ***************\n");
        printf("************* logout             退出当前用户            ***************\n");
        printf("************* help               查看用户选项            ***************\n");
        printf("************************************************************************\n\n");
    }

    static void help(string command) {
        cout <<endl << "help command" << endl;
        if (command == "quit") {
            cout << "描述 : 退出程序" << endl;
            cout << "用法 : quit" << endl << endl;
        }
        else if (command == "create") {
            cout << "描述 : 创建文件" << endl;
            cout << "用法 : create <文件名> [文件权限]" << endl;
            cout << "       文件权限(1只执行 2只读 3可写,4可读写)" << endl << endl;
        }
        else if (command == "delete") {
            cout << "描述 : 删除文件" << endl;
            cout << "用法 : delete <文件名>" << endl << endl;
        }
        else if (command == "open") {
            cout << "描述 : 打开文件" << endl;
            cout << "用法 : open <文件名>" << endl << endl;
        }
        else if (command == "close") {
            cout << "描述 : 关闭文件" << endl;
            cout << "用法 : close <文件名>" << endl << endl;
        }
        else if (command == "read") {
            cout << "描述 : 读取文件" << endl;
            cout << "用法 : read <文件名>" << endl << endl;
        }
        else if (command == "write") {
            cout << "描述 : 写文件" << endl;
            cout << "用法 : write <文件名>" << endl << endl;
        }
        else if (command == "ls") {
            cout << "描述 : 查看文件属性" << endl;
            cout << "用法 : ls" << endl << endl;
        }
        else if (command == "logout") {
            cout << "描述 : 登出当前账户" << endl;
            cout << "用法 : logout" << endl << endl;
        }
        else if (command == "help") {
            cout << "描述 : 查询帮助文件" << endl;
            cout << "用法 : help" << endl<<endl;
        }
        else {}
    }
};
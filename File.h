
struct File {
    string name; // 文件名
    bool exist; // 0表示文件已经删除，1表示文件存在
    bool state; // 0表示文件处于关闭状态，1表示打开状态
    int protect; // 1表示只执行，2表示只读，3表示只写，4表示可读可写
    string content; // 文件内容

    void create(string,string);
    void del();
    bool open();
    bool close();
    void read();
    void write();
};
void File::create(string n,string p) {
    name = n;
    protect = atoi(&p[0]);
    cout << "请输入文件内容: "; 
    cin >> content;
    exist = 1;
    state = 0;
    cout << "文件创建成功" << endl << endl;
}
void File::del() {
    exist = 0;
}
bool File::open() {
    if (protect == 1) { 
        cout << "打开失败，该文件为只执行文件！" << endl; 
        return 0; 
    }
    else if (state == 1) {
        cout << "该文件已处于打开状态" << endl;
        return 0; 
    }
    else { 
        state = 1; 
        cout << "打开成功" << endl; 
        return 1; 
    }
}
bool File::close() {
    if (state == 0) { 
        cout << "该文件已处于关闭状态" << endl; 
        return 0; 
    }
    else { 
        state = 0; 
        cout << "关闭成功" << endl;
        return 1; 
    }
}
void File::read() {
    if (protect == 1) { 
        cout << "读文件失败，该文件为只执行文件！" << endl; 
    }
    else { 
        cout << content << endl; 
    }
}
void File::write() {
    if (protect == 1 || protect == 2) { 
        cout << "写文件失败，该文件不可写" << endl; 
    }
    else {
        string cont;
        cout << "请输入写入内容: "<<content; 
        cin >> cont;
        content = content + cont;
        cout << "写入成功！" << endl;
    }
}

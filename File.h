
struct File {
    string name; // �ļ���
    bool exist; // 0��ʾ�ļ��Ѿ�ɾ����1��ʾ�ļ�����
    bool state; // 0��ʾ�ļ����ڹر�״̬��1��ʾ��״̬
    int protect; // 1��ʾִֻ�У�2��ʾֻ����3��ʾֻд��4��ʾ�ɶ���д
    string content; // �ļ�����

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
    cout << "�������ļ�����: "; 
    cin >> content;
    exist = 1;
    state = 0;
    cout << "�ļ������ɹ�" << endl << endl;
}
void File::del() {
    exist = 0;
}
bool File::open() {
    if (protect == 1) { 
        cout << "��ʧ�ܣ����ļ�Ϊִֻ���ļ���" << endl; 
        return 0; 
    }
    else if (state == 1) {
        cout << "���ļ��Ѵ��ڴ�״̬" << endl;
        return 0; 
    }
    else { 
        state = 1; 
        cout << "�򿪳ɹ�" << endl; 
        return 1; 
    }
}
bool File::close() {
    if (state == 0) { 
        cout << "���ļ��Ѵ��ڹر�״̬" << endl; 
        return 0; 
    }
    else { 
        state = 0; 
        cout << "�رճɹ�" << endl;
        return 1; 
    }
}
void File::read() {
    if (protect == 1) { 
        cout << "���ļ�ʧ�ܣ����ļ�Ϊִֻ���ļ���" << endl; 
    }
    else { 
        cout << content << endl; 
    }
}
void File::write() {
    if (protect == 1 || protect == 2) { 
        cout << "д�ļ�ʧ�ܣ����ļ�����д" << endl; 
    }
    else {
        string cont;
        cout << "������д������: "<<content; 
        cin >> cont;
        content = content + cont;
        cout << "д��ɹ���" << endl;
    }
}

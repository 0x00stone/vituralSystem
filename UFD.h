
int k = 5; // ÿ���û����򿪵��ļ���

struct UFD { // �û��ļ�Ŀ¼

    File file[1000];
    string u_name; // �û���
    int id; // �ļ�������
    int cnt; // �û��ļ����ڵĸ���
    int open_cnt; // �û����ļ����������Ϊk

    void init() {
        cnt = 0; 
        open_cnt = 0; 
        id = 0;
    }
    void create(string n, string p) {
        file[id].create(n,p); 
        cnt++; 
        id++; 
    }
    void create(string n) {
        file[id].create(n, "4");
        cnt++;
        id++;
    }
    void del(int pos) {
        file[pos].del(); cnt--;
    }

    void open(int pos) {
        if (open_cnt == k) cout << "���Ѿ�����" << k << "���ļ��������ٴ���" << endl;
        else {
            if (file[pos].open() == 1) open_cnt++;
        }
    }
    void close(int pos) {
        if (file[pos].close() == 1) open_cnt--;
    }

    void read(int pos) {
        file[pos].read();
    }

    void write(int pos) {
        file[pos].write();
    }

    int Find(string name) {
        int pos = -1;  // ��Ҫ�����ļ���λ��
        for (int i = 0; i < id; i++)
            if (file[i].exist == 1 && file[i].name == name) return pos = i;
        cout << "�Ҳ������ļ��������ļ���\n";
        return pos;
    }
}ufd[10];

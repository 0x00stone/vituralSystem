
int k = 5; // 每个用户最多打开的文件数

struct UFD { // 用户文件目录

    File file[1000];
    string u_name; // 用户名
    int id; // 文件的总数
    int cnt; // 用户文件存在的个数
    int open_cnt; // 用户打开文件个数，最大为k

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
        if (open_cnt == k) cout << "您已经打开了" << k << "个文件，不能再打开了" << endl;
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
        int pos = -1;  // 需要操作文件的位置
        for (int i = 0; i < id; i++)
            if (file[i].exist == 1 && file[i].name == name) return pos = i;
        cout << "找不到该文件，请检查文件名\n";
        return pos;
    }
}ufd[10];

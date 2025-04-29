class ND
{
    private:
    int n;
    int d;

    public:

    ND();
    void setN(int i);
    void setD(int i);

    int getN();
    int getD();

    //操作
    void mul(int i,int j);
    void div(int i,int j);
    void add(int i,int j);
    void sub(int i,int j);
    void reduced();
};
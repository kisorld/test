

class Complex
{
    private:
    double r;
    double v;

    public:
    Complex();
    void setR(double _r);
    void setV(double _v);
    double getR();
    double getV();

    //操作
    void Mul(double i,double j);
    void Div(double i,double j);
    void Add(double i,double j);
    void Sub(double i,double j);
    
};
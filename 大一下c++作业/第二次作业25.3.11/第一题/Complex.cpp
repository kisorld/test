



Complex::Complex():r(0),v(0)
{

}

void  Complex::setV(double _v)
{
    v=_v;
}

void Complex:: setR(double _r)
{
    r=_r;
}

double Complex:: getR()
{
    return r;
}
double Complex:: getV()
{
    return v;
}


//操作
void  Complex::Mul(double i,double j)
{
    double n_r,n_v;
    n_r=r*i-v*j;
    n_v=r*j+v*i;
    r=n_r;
    v=n_v;
}
void  Complex::Div(double i,double j)
{
    double n_r,n_v;
    double k=(i*i+j*j);
    n_r=(r*i+v*j)/k;
    n_v=(v*i-r*j)/k;
    r=n_r;
    v=n_v;
}
void  Complex::Add(double i,double j)
{
    r=r+i;
    v=v+j;
}
void  Complex::Sub(double i,double j)
{
    r=r-i;
    v=v-j;
}
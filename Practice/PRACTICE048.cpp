#include<iostream>
#include<cmath>

//this vector is created for practice
class vector
{
private:
    double x,y;
    double angle,distance;
    bool mode;
    void setx(){ x=distance*cos(angle);}
    void sety(){ y=distance*sin(angle);}
    void setangle(){ if(x&&y) angle=atan2(y,x); else angle=0;}
    void setdistance(){ distance=sqrt(x*x+y*y);}
public:
    double getx(){return x;}
    double gety(){return y;}
    double getangle(){return angle;}
    double getdistance(){return distance;}

    // vector()=default;
    vector(double n1=0,double n2=0,bool Mode=false);
    void reset(double n1=0,double n2=0,bool Mode=false);

    void mode_0(){mode=false;}
    void mode_1(){mode=true;}

    vector operator-(const vector&) const;
    vector operator-();
    vector operator+(const vector&) const;
    double operator*(const vector&) const;
    vector operator*(const double) const;
    friend vector operator*(const double n1,const vector& n2){return n2*n1;}
    friend std::ostream& operator<<(std::ostream &os,const vector &v1);
};
    vector::vector(double n1,double n2,bool Mode/*=false*/)
    {
        mode=Mode;
        if(Mode)
        {
            x=n1;
            y=n2;
            setangle();
            setdistance();
        }
        else
        {
            angle=n1;
            distance=n2;
            setx();
            sety();
        }
    }
    void vector::reset(double n1/*=0*/,double n2/*=0*/,bool Mode/*=false*/)
    {
        x=n1;
        y=n2;
        mode=Mode;
        setangle();
        setdistance();
    }
    vector vector::operator-(const vector& v) const
    {
        return vector(x-v.x,y-v.y,mode);
    }
    vector vector::operator-()
    {
        return vector(-x,-y,mode);
    }
    vector vector::operator+(const vector& v) const
    {
        return vector(x+v.x,y+v.y,mode);
    }
    vector vector::operator*(const double v) const
    {
        return vector(v*x,v*y,mode);
    }
    double vector::operator*(const vector& v) const
    {
        return sqrt(x*v.x+y*v.y);
    }
    std::ostream& operator<<(std::ostream &os,const vector &v1)
    {
        os<<v1.x<<' '<<v1.y<<std::endl
        <<v1.angle<<' '<<v1.distance<<std::endl;

        return os;
    }


int main()
{
    vector t1;
    std::cout<<t1;

    vector t2(3,4,1);

    std::cout<<t2;
    std::cout<<t2*2;
    std::cout<<2*t2;
    t2.reset();
    std::cout<<t2;

    return 0;
}
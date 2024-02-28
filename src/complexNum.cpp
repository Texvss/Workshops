class Complex {
public:
    Complex(double r = 0, double i = 0):re(r), im(i){}
//    Complex():re(0), im(0){}
    Complex operator + (const Complex& c) const{
        return Complex{ re + c.re, im + c.im };
    }
    double getRe() const {
        return re;
    }
//    double getIm() const {
//        return im;
//    }
    friend std::ostream& operator << (std::ostream& stream, const Complex& complex);
private:
    double re, im;
};

std::ostream& operator << (std::ostream& stream, const Complex& complex){
    stream << complex.getRe() << ',' << complex.im;
    return stream;
}
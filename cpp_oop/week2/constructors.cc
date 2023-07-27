 #include <iostream>


 class Rectangle{

    private:
        double h, l;
    public:
        Rectangle() = default;
        Rectangle(double h1, double l1)
            : h(h1*2.0), l(l1*3.0)
            {}
        Rectangle(Rectangle const& autre)
            : h(autre.h/2.0), l(autre.l/3.0)
            {}

        void display(){
            std::cout << h << ", " << l << std::endl;
        }


 };


 class Number {
private:
    int n;
public:
    Number() 
      : n(0) 
    { std::cout << n; }
    Number( int nn )
      : n(nn)
    { std::cout << n; }
    Number(Number const& otherNum)
      : n(otherNum.n+1)
    { std::cout << n; }
    void display() { std::cout << n; }
    void increase() { n += 1; }
    
    
    }; 

 int main()
 {

    Rectangle r1(2.0, 4.0), r2(r1); r1.display();
    r2.display();

    Number a, b(1), c(b);
    b.increase();
    c.display();
    b.display();







    return 0;
 }
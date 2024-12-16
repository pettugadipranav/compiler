#include <bits/stdc++.h>
using namespace std;
/* teja */
// #include <utility>
/*for printing*/
template<typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}



/* For addition */
pair <double, double> operator+(pair <double, double> a, pair <double, double> b){
    return make_pair(a.first+b.first, a.second+b.second);
}
pair <double, double> operator+(double a, pair <double, double> b){
    b.first+=a;
    return b;
}
pair <double, double> operator+(pair <double, double> b,double a){
    b.first+=a;
    return b;
}
pair <double, double> operator+(pair<double, double> a){
    return a;
}

/* for subtraction */
pair <double, double> operator-(pair <double, double> a, pair <double, double> b){
    return make_pair(a.first-b.first, a.second-b.second);
}
pair <double, double> operator-(double a, pair <double, double> b){
     return make_pair(a-b.first, -b.second);
}
pair <double, double> operator-(pair <double, double> b,double a){
    b.first-=a;
    return b;
}
pair<double,double> operator-(pair<double,double> a){
    return make_pair(-a.first,-a.second);
}

/* for multiplication */
pair <double, double> operator*(pair <double, double> a, pair <double, double> b){
    return make_pair(a.first*b.first - a.second*b.second, a.first*b.second + a.second*b.first);
}
pair <double, double> operator*(double a, pair <double, double> b){
    return make_pair(b.first*a, b.second*a);
}
pair <double, double> operator*(pair <double, double> b,double a){
    return make_pair(b.first*a, b.second*a);
}

/* for divison */

pair <double, double> operator/(pair <double, double> a, pair <double, double> b){
    double t = (a.first*b.first+a.second*b.second) / (pow(b.first, 2) + pow(b.second, 2) );
    double u = (-a.first*b.second+a.second*b.first) / (pow(b.first, 2) + pow(b.second, 2) );
    return make_pair(t, u);
}
pair <double, double> operator/(double a, pair <double, double> b){
    double t = (a*b.first) / (pow(b.first, 2) + pow(b.second, 2) );
    double u = (-a*b.second) / (pow(b.first, 2) + pow(b.second, 2) );
    return make_pair(t, u);
}
pair <double, double> operator/(pair <double, double> b,double a){
    b.first/=a;
    b.second /= a;
    return b;
}

double real(pair<double, double> p){
    return p.first;
}

double img(pair<double, double> p){
    return p.second;
}

void polar(pair<double, double> p){
    double a1 = p.first;
    double a2 = p.second;    
    double ang = atan(abs(a2/a1));
    if(a1 < 0 && a2 < 0){
        ang = -(M_PI - ang);
    }
    else if(a1 < 0 && a2 > 0){
        ang = M_PI - ang;
    }
    else if(a1 > 0 && a2 < 0){
        ang = -ang;
    }
    cout << "r = " << sqrt(p.first*p.first + p.second*p.second) << "exp{ i" << ang << "}" << endl;
}

pair<double, double> conjugate(pair<double, double> p){
    return make_pair(p.first, -p.second);
}

double mod(pair<double, double> p){
    return sqrt(p.first*p.first + p.second*p.second);
}

double arg(pair<double, double> p){
    double a1 = p.first;
    double a2 = p.second;
    double ang = atan(abs(a2/a1));
    if(a1 < 0 && a2 < 0){
        ang = -(M_PI - ang);
    }
    else if(a1 < 0 && a2 > 0){
        ang = M_PI - ang;
    }
    else if(a1 > 0 && a2 < 0){
        ang = -ang;
    }
    return ang;
}

double angle(pair<double, double> p1, pair<double, double> p2){
    double a1 = p1.first;
    double a2 = p1.second;
    double b1 = p2.first;
    double b2 = p2.second;
    double dot = a1*b1 + a2*b2;
    double mod1 = sqrt(a1*a1 + a2*a2);
    double mod2 = sqrt(b1*b1 + b2*b2);
    double angle = acos(dot/(mod1*mod2));
    return angle;
}

double dist(pair<double, double> p1, pair<double, double> p2){
    double a1 = p1.first;
    double a2 = p1.second;
    double b1 = p2.first;
    double b2 = p2.second;
    double dist = sqrt((a1-b1)*(a1-b1) + (a2-b2)*(a2-b2));
    return dist;
}

void cprint(pair<double, double> p){
    if(p.second < 0){
        cout << p.first << " - " << -p.second << "i" << endl;
    }
    else
    cout << p.first << " + " << p.second << "i" << endl;
}

pair<double, double>  complex_pow(pair<double, double> p, double x){
    // write the power function of complex number
    double a1 = p.first;
    double a2 = p.second;
    double ang = atan(abs(a2/a1));
    if(a1 < 0 && a2 < 0){
        ang = -(M_PI - ang);
    }
    else if(a1 < 0 && a2 > 0){
        ang = M_PI - ang;
    }
    else if(a1 > 0 && a2 < 0){
        ang = -ang;
    }
    double mod = sqrt(a1*a1 + a2*a2);
    double real = pow(mod, x)*cos(x*ang);
    double img = pow(mod, x)*sin(x*ang);
    return make_pair(real, img);
}

double real_pow(double a, double b){
    return pow(a, b);
}

pair<double, double> rotate(pair<double, double> p1, pair<double, double> origin, double angle){
    angle = angle*M_PI/180;
    double a1 = p1.first;
    double a2 = p1.second;
    double b1 = origin.first;
    double b2 = origin.second;
    double ang = atan(abs((a2-b2)/(a1-b1)));
    if(a1 < 0 && a2 < 0){
        ang = -(M_PI - ang);
    }
    else if(a1 < 0 && a2 > 0){
        ang = M_PI - ang;
    }
    else if(a1 > 0 && a2 < 0){
        ang = -ang;
    }
    double modulas = mod(p1);
    double fin_angle = angle + ang;
    double x = modulas*cos(fin_angle), y = modulas*sin(fin_angle);
    return make_pair(x, y);
}

void get_line(pair<double, double> p1, pair<double, double> p2){
    double a1 = p1.first;
    double a2 = p1.second;
    double b1 = p2.first;
    double b2 = p2.second;
    double slope = (b2-a2)/(b1-a1);
    double intercept = a2 - slope*a1;
    cout << "line Equation:"<<endl;
    if(intercept < 0){
        cout << "y = " << slope << "x - " << -intercept << endl;
    }
    else
    cout << "y = " << slope << "x + " << intercept << endl;
}

bool is_triangle(pair<double, double> p1, pair<double, double> p2, pair<double, double> p3){
    double a1 = p1.first;
    double a2 = p1.second;
    double b1 = p2.first;
    double b2 = p2.second;
    double c1 = p3.first;
    double c2 = p3.second;
    double side_a = sqrt((b1-c1)*(b1-c1) + (b2-c2)*(b2-c2));
    double side_b = sqrt((a1-c1)*(a1-c1) + (a2-c2)*(a2-c2));
    double side_c = sqrt((a1-b1)*(a1-b1) + (a2-b2)*(a2-b2));
    if(side_a + side_b > side_c && side_b + side_c > side_a && side_a + side_c > side_b){
        return true;
    }
    else{
        return false;
    }
}

pair<double, double> get_centroid(pair<double, double> p1, pair<double, double> p2, pair<double, double> p3){
    double a1 = p1.first;
    double a2 = p1.second;
    double b1 = p2.first;
    double b2 = p2.second;
    double c1 = p3.first;
    double c2 = p3.second;
    double x = (a1+b1+c1)/3;
    double y = (a2+b2+c2)/3;
    return make_pair(x, y);
}

pair<double, double> get_circumcenter(pair<double, double> p1, pair<double, double> p2, pair<double, double> p3){
    double x1 = p1.first;
    double y1 = p1.second;
    double x2 = p2.first;
    double y2 = p2.second;
    double x3 = p3.first;
    double y3 = p3.second;
    double A = x2 - x1;
    double B = y2 - y1;
    double C = x3 - x1;
    double D = y3 - y1;
    double E = A*(x1 + x2) + B*(y1 + y2);
    double F = C*(x1 + x3) + D*(y1 + y3);
    double G = 2*(A*(y3 - y2) - B*(x3 - x2));
    double x = (D*E - B*F) / G;
    double y = (A*F - C*E) / G;
    return make_pair(x, y);
}

pair<double, double> get_orthocenter(pair<double, double> p1, pair<double, double> p2, pair<double, double> p3){
    double x1 = p1.first;
    double y1 = p1.second;
    double x2 = p2.first;
    double y2 = p2.second;
    double x3 = p3.first;
    double y3 = p3.second;
    double m1 = (y2-y3)/(x2-x3);
    double m2 = (y3-y1)/(x3-x1);
    double x = (m1*m2*(y2-y1) + m1*x2 - m2*x1)/(m1-m2);
    double y = (x1-x2+m1*y1-m2*y2)/(m1-m2);
    return make_pair(x, y);
}

/* TO BE CHANGED(wrt A) */
pair<double, double> get_excenter(pair<double, double> p1, pair<double, double> p2, pair<double, double> p3){
    double a1 = p1.first;
    double a2 = p1.second;
    double b1 = p2.first;
    double b2 = p2.second;
    double c1 = p3.first;
    double c2 = p3.second;
    double side_a = sqrt((b1-c1)*(b1-c1) + (b2-c2)*(b2-c2));
    double side_b = sqrt((a1-c1)*(a1-c1) + (a2-c2)*(a2-c2));
    double side_c = sqrt((a1-b1)*(a1-b1) + (a2-b2)*(a2-b2));
    double x = (-side_a*a1 + side_b*b1 + side_c*c1)/(-side_a + side_b + side_c);
    double y = (-side_a*a2 + side_b*b2 + side_c*c2)/(-side_a + side_b + side_c); 
    return make_pair(x, y);     
}

pair<double, double> get_incenter(pair<double, double> p1, pair<double, double> p2, pair<double, double> p3){
    double a1 = p1.first;
    double a2 = p1.second;
    double b1 = p2.first;
    double b2 = p2.second;
    double c1 = p3.first;
    double c2 = p3.second;
    double side_a = sqrt((b1-c1)*(b1-c1) + (b2-c2)*(b2-c2));
    double side_b = sqrt((a1-c1)*(a1-c1) + (a2-c2)*(a2-c2));
    double side_c = sqrt((a1-b1)*(a1-b1) + (a2-b2)*(a2-b2));
    double x = (side_a*a1 + side_b*b1 + side_c*c1)/(side_a + side_b + side_c);
    double y = (side_a*a2 + side_b*b2 + side_c*c2)/(side_a + side_b + side_c); 
    return make_pair(x, y);     
}

double get_area(pair<double, double> p1, pair<double, double> p2, pair<double, double> p3){
    double x1 = p1.first;
    double y1 = p1.second;
    double x2 = p2.first;
    double y2 = p2.second;
    double x3 = p3.first;
    double y3 = p3.second;
    double area = abs((x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2))/2);
    return area;
}

double get_perimeter(pair<double, double> p1, pair<double, double> p2, pair<double, double> p3){
    double x1 = p1.first;
    double y1 = p1.second;
    double x2 = p2.first;
    double y2 = p2.second;
    double x3 = p3.first;
    double y3 = p3.second;
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)) + sqrt((x1-x3)*(x1-x3) + (y1-y3)*(y1-y3)) + sqrt((x3-x2)*(x3-x2) + (y3-y2)*(y3-y2));    
}

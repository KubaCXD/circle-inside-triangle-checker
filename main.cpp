//#include <simple2d.h>
#include <iostream>
#include <math.h>

using namespace std;

struct Punkt
{
    float x;
    float y;
};

int punktTrojkat(Punkt A, Punkt B, Punkt C,Punkt P);
float poleTrojkata(Punkt A, Punkt B, Punkt C);

int main() 
{
	cout << "Hello World!" << endl;
	
	Punkt A, B, C, P;
	
	A.x = 3; A.y = 4;
	B.x = 5; B.y = 1;
	C.x = 1; C.y = 1;
	P.x = 1; P.y = 3;
	
	punktTrojkat(A, B, C, P);
	
	return 0;
}

int punktTrojkat(Punkt A, Punkt B, Punkt C,Punkt P)
{
    float ABC = poleTrojkata(A,B,C);
    cout << "\tABC:" << ABC << endl;
    float ABP = poleTrojkata(A,B,P);
    cout << "\tABP:" << ABC << endl;
    float APC = poleTrojkata(A,P,C);
    cout << "\tAPC:" << ABC << endl;
    float PBC = poleTrojkata(P,B,C);
    cout << "\tPBC:" << ABC << endl;

    cout << " Pole ABC = " << ABC << endl;
    cout << " SUMA ABP + APC + PBC = " << ABP+APC+PBC << endl;
    if(fabs(ABC - (ABP+APC+PBC)) < 0.00001)
    {
    	cout << "\n Punkt P znajduje sie poza trojkatem ABC\n";
        return 1;
    }
    else
    {
    	cout << "\n Punkt P znajduje sie WEWNATRZ trojkata ABC\n";
        return 0;
    }
}

float poleTrojkata(Punkt A, Punkt B, Punkt C)
{
    return 0.5*fabs((B.x-A.x)*(C.y-A.y) - (B.y-A.y)*(C.x-A.x));
}


#include <iostream>
#include <math.h>
#include <simple2d.h>

#define PI 3.14159265

using namespace std;

struct Punkt
{
    float x;
    float y;
};
float poleTrojkata(Punkt A, Punkt B, Punkt C);
bool punktTrojkat(Punkt A, Punkt B, Punkt C,Punkt P);
float calculatedDiffrence(int angle, float cLength, bool mode);

bool fullyInside = true;

//S2D STUFF

void S2D_DrawSolidLine(float x1, float y1, float x2, float y2, float width, float r, float g, float b, float a) //for S2D Library
{
	S2D_DrawLine(x1, y1, x2, y2, width, r, g, b, a, r, g, b, a, r, g, b, a, r, g, b, a);
	return;
}

int windowW, windowH, winWCenter, winHCenter;

Punkt circleData[360]; //for S2D Library, saving radius end position
Punkt triangleData[3];

void render() //for S2D Library
{
    int GUI_Scaling = 25;
    winWCenter = windowW/2;
    winHCenter = windowH/2;

    S2D_DrawSolidLine(0, winHCenter, windowW, winHCenter, 1, 0.30, 0.30, 0.30, 1);
    S2D_DrawSolidLine(winWCenter, 0, winWCenter, windowH, 1, 0.30, 0.30, 0.30, 1);

    for(int i = 0; i < winWCenter/GUI_Scaling; i++)//horizontal
    {
        S2D_DrawSolidLine(winWCenter+(GUI_Scaling *(i+1)), winHCenter-5, winWCenter+(GUI_Scaling *(i+1)), winHCenter+5, 1, 0.31, 0.31, 0.31, 1); // RIGHT
        S2D_DrawSolidLine(winWCenter-(GUI_Scaling *(i+1)), winHCenter-5, winWCenter-(GUI_Scaling *(i+1)), winHCenter+5, 1, 0.31, 0.31, 0.31, 1); //LEFT
    }
    for(int i = 0; i < winHCenter/GUI_Scaling; i++)//vertical
    {
        S2D_DrawSolidLine(winWCenter-5, winHCenter+(GUI_Scaling *(i+1)), winWCenter+5, winHCenter+(GUI_Scaling *(i+1)), 1, 0.31, 0.31, 0.31, 1); // DOWN
        S2D_DrawSolidLine(winWCenter-5, winHCenter-(GUI_Scaling *(i+1)),  winWCenter+5, winHCenter-(GUI_Scaling *(i+1)), 1, 0.31, 0.31, 0.31, 1); //UP
    }

    S2D_DrawSolidLine(winWCenter + (triangleData[0].x * GUI_Scaling), winHCenter - (triangleData[0].y * GUI_Scaling),winWCenter + (triangleData[1].x * GUI_Scaling), winHCenter - (triangleData[1].y * GUI_Scaling),1, 0, 1, 0, 1);
    S2D_DrawSolidLine(winWCenter + (triangleData[1].x * GUI_Scaling), winHCenter - (triangleData[1].y * GUI_Scaling),winWCenter + (triangleData[2].x * GUI_Scaling), winHCenter - (triangleData[2].y * GUI_Scaling),1, 0, 1, 0, 1);
    S2D_DrawSolidLine(winWCenter + (triangleData[2].x * GUI_Scaling), winHCenter - (triangleData[2].y * GUI_Scaling),winWCenter + (triangleData[0].x * GUI_Scaling), winHCenter - (triangleData[0].y * GUI_Scaling),1, 0, 1, 0, 1);
    
    for(int i = 0; i < 359; i++)
    {
        S2D_DrawSolidLine(winWCenter + (circleData[i].x * GUI_Scaling), winHCenter - (circleData[i].y * GUI_Scaling), winWCenter + (circleData[i+1].x * GUI_Scaling), winHCenter - (circleData[i+1].y * GUI_Scaling), 2, 
        1, 0, 0, 1);
    }
    S2D_DrawSolidLine(winWCenter + (circleData[359].x * GUI_Scaling), winHCenter - (circleData[359].y * GUI_Scaling), winWCenter + (circleData[0].x * GUI_Scaling), winHCenter - (circleData[0].y * GUI_Scaling), 2, 
        1, 0, 0, 1);


}



int main()
{
    cout << "Hello world!" << endl;

    Punkt A,B,C, circle;
    float radius;

    bool ask = true;
    
    if(ask == true)
    {
        cout << " Podaj wspolrzedne punktu A: \n";
        cout << "   Podaj x: ";
        cin >> A.x;
        cout << "   Podaj y: ";
        cin >> A.y;

        cout << "\n Podaj wspolrzedne punktu B: \n";
        cout << "   Podaj x: ";
        cin >> B.x;
        cout << "   Podaj y: ";
        cin >> B.y;

        cout << "\n Podaj wspolrzedne punktu C: \n";
        cout << "   Podaj x: ";
        cin >> C.x;
        cout << "   Podaj y: ";
        cin >> C.y;

        cout << "\n Podaj wspolrzedne srodka kola: \n";
        cout << "   Podaj x: ";
        cin >> circle.x;
        cout << "   Podaj y: ";
        cin >> circle.y;

        cout << "\n Podaj promien kola: ";
        cin >> radius;
    
    }
    else
    {
        A.x = 0; A.y = 5;
        B.x = 5; B.y = -5;
        C.x = -5; C.y = -5;

        circle.x = 0;
        circle.y = -2;

        radius = 3;

        /*A.x = 0; A.y = 5;
        B.x = 5; B.y = -5;
        C.x = -2; C.y = -5;

        circle.x = -2;
        circle.y = -4;

        radius = 4;*/
    }

    
    Punkt P;

    //FOR 2D DISPLAY FUNCTION
    triangleData[0] = A;
    triangleData[1] = B;
    triangleData[2] = C;

bool nl = false;

    for(int i = 0; i < 360; i++)
    {
        P.x = circle.x + calculatedDiffrence(i, radius, 1);
        P.y = circle.y + calculatedDiffrence(i, radius, 0);

        //FOR 2D DISPLAY FUNCTION
        circleData[i].x = P.x;
        circleData[i].y = P.y;

        if(punktTrojkat(A, B, C, P) == 1)
        {
            fullyInside = false;
            //break;
        }

        cout << "\t" << i << "(" << circleData[i].x << ";" << circleData[i].y << ")";

        switch(nl){
        case 0: nl = 1; break;
        case 1: cout << "\n"; nl = 0; break;
        }
    }

    if(fullyInside == true)
        cout << "\tKolo znajduje sie w pelni w trojkocie." << endl;
    else
        cout << "\tKolo nie znajduje sie w pelni w trojkacie." << endl;


    //ENABLE S2D
    S2D_Window *window = S2D_CreateWindow(
        "TEST", 800, 600, NULL, render, 0);
    
    windowW = window->width;
    windowH = window->height;

    window->background.r = 0.15;
    window->background.g = 0.15;
    window->background.b = 0.15;
    window->background.a = 1;

    S2D_Show(window);

    return 0;
}


float poleTrojkata(Punkt A, Punkt B, Punkt C)
{
    float a = 0.5*fabs((B.x-A.x)*(C.y-A.y) - (B.y-A.y)*(C.x-A.x));
    //cout << "\t" << a << endl;
    return a;
}

bool punktTrojkat(Punkt A, Punkt B, Punkt C,Punkt P)
{
    float ABC = poleTrojkata(A,B,C);
    float ABP = poleTrojkata(A,B,P);
    float APC = poleTrojkata(A,P,C);
    float PBC = poleTrojkata(P,B,C);

    //cout << " Pole ABC = " << ABC << endl;
    //cout << " SUMA ABP + APC + PBC = " << ABP+APC+PBC << endl;
    //cout << "\tDEBUG " << ABC - (ABP+APC+PBC) << endl;
    if(fabs(ABC - (ABP+APC+PBC)) > 0.00001)
        //cout << "\n Punkt P znajduje sie poza trojkatem ABC\n";
        return 1;
    else
        //cout << "\n Punkt P znajduje sie WEWNATRZ trojkata ABC\n";
        return 0;
}

float calculatedDiffrence(int angle, float cLength, bool mode) //mode 0 = calculate triangle height, 1 = calculate triangle width
{
    float result, angle2;
    int sideFromCenter; //0 = LEFT TOP, 1 = RIGHT TOP, 2 = RIGHT DOWN, 3 = LEFT DOWN

    if(angle < 90)
    {
        angle2 = angle;
        sideFromCenter = 0;
    }else if (angle >= 90 && angle < 180)
    {
        angle2 = angle - 90;
        sideFromCenter = 1;
    }else if (angle >= 180 && angle < 270)
    {
        angle2 = angle - 180;
        sideFromCenter = 2;
    }else if (angle >= 270)
    {
        angle2 = angle - 270;
        sideFromCenter = 3;
    }

    if(mode == 0) //calculating height
    {
        result = sin(angle2*PI/180);
        //cout << "[*] DEBUG | angle2 = " << angle2 << "\n[*] DEBUG | H.result = " << result << endl;
        if(sideFromCenter <= 1)
        {
            return result * cLength;
        }
        else
        {
            return (result * cLength) * -1;
        }
    }
    if(mode == 1) // calculating width
    {
        result = cos(angle2*PI/180);
        //cout << "[*] DEBUG | angle2 = " << angle2 << "\n[*] DEBUG | W.result = " << result << endl;
        if(sideFromCenter == 0 || sideFromCenter == 3)
        {
            return (result * cLength) * -1;
        }
        else
        {
            return result * cLength;
        }
        return result * cLength;
    }
    return 0;
}

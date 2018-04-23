#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

void warna(int a, int b, int c){
    glColor3ub(a,b,c);}
void circle(double x, double y, double o){
    double cons=2*3.14/100;
    double pX, pY;
    double posX=x, posY=y;
    int sizee =72/o, i;;
    glBegin(GL_POLYGON);
    for(i=0; i<100; i++){
        pX=sin(i*cons)*sizee+ posX;
        pY=cos(i*cons)*sizee+ posY;
        glVertex2f(pX,pY);
    }
    glEnd();
}
void circle2(double x, double y, double o){
    double cons=2*3.14/100;
    double pX, pY;
    double posX=x, posY=y;
    int sizee =72/o, i;;
    glBegin(GL_LINE_STRIP);
    for(i=0; i<100; i++){
        pX=sin(i*cons)*sizee+ posX;
        pY=cos(i*cons)*sizee+ posY;
        glVertex2f(pX,pY);
    }
    glEnd();
}
void kotak(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
    glBegin(GL_TRIANGLE_FAN);
        glVertex2d(x1,y1);
        glVertex2d(x2,y2);
        glVertex2d(x3,y3);
        glVertex2d(x4,y4);
    glEnd();
}
void segitiga(int x1, int y1, int x2, int y2, int x3, int y3){
    glBegin(GL_TRIANGLES);
        glVertex2d(x1,y1);
        glVertex2d(x2,y2);
        glVertex2d(x3,y3);
    glEnd();
}

int main( void )
{
    GLFWwindow *window;

    // Initialize the library
    if ( !glfwInit( ) )
    {
        return -1;
    }

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow( 800, 800, "My Name", NULL, NULL );

    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    glfwSetKeyCallback(window, key_callback);
    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float) height;
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0, 800, 800, 0, 1.f, -1.f);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        // Render OpenGL here
//background
        glBegin(GL_TRIANGLE_FAN);
            glColor3ub(255,167,124);
            glVertex2d(0,0);
            glVertex2d(800,0);
            glColor3ub(234,210,149);
            glVertex2d(800,800);
            glVertex2d(0,800);
        glEnd();
//awan
        warna(219,114,73);kotak(255,380, 76,580, 723,580, 540,380);
        circle(89,520,1.2);circle(141,456,1.5);circle(200,409,1.5);circle(582,409,1.5);circle(640,456,1.5);circle(680,520,1.2);
        warna(255,167,124);circle(628,552,2.2);
        warna(234,132,87);circle(593,540,2);
        warna(255,180,118);kotak(75,535,75,557,96,557,96,535);circle(85.5,535,7);circle(85.5,557,7);
        kotak(168,535,168,557,189,557,189,535);circle(178.5,535,7);circle(178.5,557,7);
//tanah
        warna(211,132,94);kotak(28,565, 28,597, 771,597, 771,565);
        circle(28,575,7.5);circle(28,587,7.5);circle(28,581,7);
        circle(771,575,7.5);circle(771,587,7.5);circle(771,581,7);
        warna(191,109,76);kotak(124,597,124,625,669,625,669,597);
        kotak(216,625, 216,642, 517,642, 517,625);
        kotak(204,642, 204,670, 581,670, 581,642);
        kotak(628,642, 628,670, 642,670, 642,642);
        circle(628,656,5);circle(642,656,5);
        circle(581,656,5);circle(204,656,5);
        circle(124,611,5);circle(669,611,5);
        warna(170,89,60);kotak(216,625, 216,642, 327,642, 327,625);circle(327,634,8.7);
        warna(244,200,149);circle(517,634,8.7);circle(216,634,8.7);
//rumahtembok
        warna(234,178,140);kotak(217,417, 217,565, 365,565, 365,417);kotak(525,330, 525,379, 545,379, 545,330);
        warna(249,196,160);kotak(365,418, 365,565, 591,565, 591,418);
        segitiga(480,314, 373,426, 585,426);kotak(545,330, 545,379, 561,379, 561, 330);
//bayangantembok
        warna(234,178,140);
        kotak(365,439, 365,456, 392,456, 392,439);circle(392,447,8.7);
        kotak(365,536, 365,553, 414,553, 414,536);circle(414,544,8.7);
        kotak(447,536, 447,553, 471,553, 471,536);circle(447,544,8.7);circle(471,544,8.7);
        kotak(457,445, 457,462, 497,462, 497,445);circle(497,454,8.7);
        kotak(564,515, 564,533, 572,533, 572,515);circle(572,524,8.7);
        kotak(579,460, 579,478, 591,478, 591,460);circle(579,469,8.7);
        kotak(400,378, 400,395, 434,395, 434,378);circle(434,390,15);circle(434,383,15);circle(434,387,15);
        kotak(516,390, 516,407, 567,407, 567,390);circle(516,398,8.7);
        kotak(487,330, 487,347, 508,347, 508,330);circle(487,338,8.7);
        warna(216,161,124);
        kotak(322,536, 322,553, 365,553, 365,536);circle(322,544,8.7);
        kotak(356,439, 356,456, 365,456, 365,439);circle(356,447,8.7);
        kotak(284,536, 284,553, 291,553, 291,536);circle(284,544,8.7);circle(291,544,8.7);
        kotak(260,439, 260,456, 295,456, 295,439);circle(260,447,8.7);circle(295,447,8.7);
        kotak(217,524, 217,541, 245,541, 245,524);circle(245,532,8.7);
//pintu
        warna(142,100,82);
        kotak(510,480, 510,565, 564,565, 564,480);circle(537,480,2.6);
        warna(119,81,66);
        kotak(523,503, 523,555, 551,555, 551,503);kotak(519,507, 519,551, 555,551, 555,507);circle(523,507,15);circle(551,507,15);circle(523,551,15);circle(551,551,15);
        warna(168,217,229);
        kotak(523,480, 523,493, 551,493, 551,480);kotak(519,480, 519,489, 555,489, 555,480);circle(523,489,15);circle(551,489,15);circle(537,480,4);
        warna(142,100,82);kotak(523,493, 523,503, 551,503, 551,493);
//jendela
        warna(142,101,82);
        kotak(408,469, 408,526, 466,526, 466,469);
        kotak(432,478, 432,517, 442,517, 442,478);
        kotak(418,493, 418,502, 456,502, 456,493);
        warna(168,217,229);kotak(418,478, 418,517, 456,517, 456,478);
        warna(119,81,66);
        kotak(432,478, 432,517, 442,517, 442,478);
        kotak(418,493, 418,502, 456,502, 456,493);
        warna(119,81,66);
        kotak(386,469, 386,526, 408,526, 408,469);
        kotak(381,474, 381,521, 408,526, 408,469);circle(386,474,13);circle(386,521,13);
        kotak(466,469, 466,526, 488,526, 488,469);
        kotak(494,474, 466,469, 466,526, 494,521);circle(488,521,13);circle(488,474,13);
        warna(102,67,54);
        kotak(390,481, 390,486, 400,486, 400,481);
        kotak(390,490, 390,495, 400,495, 400,490);
        kotak(390,500, 390,505, 400,505, 400,500);
        kotak(390,510, 390,514, 400,514, 400,510);
        kotak(475,481, 475,486, 485,486, 485,481);
        kotak(475,490, 475,495, 485,495, 485,490);
        kotak(475,500, 475,505, 485,505, 485,500);
        kotak(475,510, 475,514, 485,514, 485,510);
//kanopijendela
        warna(170,73,55);
        kotak(436,445, 446,469, 467,469, 457,445);kotak(463,449, 436,445, 446,469, 471,462);
        circle(467.5,465,15);circle(458,449,15);
        warna(191,94,71);
        kotak(418,445, 408,469, 446,469, 436,445);kotak(411,449, 404,462, 450,462, 443,449);
        circle(407.5,465,15);circle(446.5,465,15);circle(416,449,15);circle(438,449,15);
//garisatas
        warna(102,67,54);kotak(370,407, 370,425, 587,425, 587,407);
//atap
        warna(191,94,71);
        kotak(335,291, 217,426, 274,426, 393,291);kotak(310,302, 209,407, 274,426, 393,291);circle(217,416,6.5);circle(328,310,3.7);
        warna(170,73,55);kotak(393,291, 274,426, 359,426, 480,291);
        kotak(359,412, 372,425, 479,314, 473,294);kotak(487,294, 479,314, 587,425, 599,412);circle(480,303,6);circle(364,416,6.5);circle(593,418,8);
//cerobong
        kotak(525,316, 525,336, 565,336, 565,316);kotak(519,321, 519,331, 570,331, 570,321);circle(525,321,13);circle(525,331,13);
        warna(191,94,71);kotak(547,316, 547,336, 565,336, 565,316);segitiga(570,321, 545,326, 570,331);circle(565,331,13);circle(565,321,13);
//ventilasi
        warna(142,101,82);kotak(457,352, 457,392, 479,392, 479,352);kotak(452,358, 452,386, 479,392, 479,352);circle(457,358,13);circle(457,386,13);
        warna(119,81,66);kotak(479,352, 479,392, 502,392, 502,352);kotak(507,358, 479,352, 479,392, 507,386);circle(502,386,13);circle(502,358,13);
        kotak(460,360, 460,365, 470,365, 470,360);circle(460,362,20);circle(470,362,20);
        kotak(460,369, 460,375, 470,375, 470,369);circle(460,372,20);circle(470,372,20);
        kotak(460,380, 460,385, 470,385, 470,380);circle(460,383,20);circle(470,383,20);
        warna(102,67,54);
        kotak(488,360, 488,365, 498,365, 498,360);circle(488,362,20);circle(498,362,20);
        kotak(488,369, 488,375, 498,374, 498,369);circle(488,372,20);circle(498,372,20);
        kotak(488,380, 488,385, 498,385, 498,380);circle(488,383,20);circle(498,383,20);
//jendelabelakang
        warna(119,81,66);kotak(238,467, 238,524, 279,524, 279,467);kotak(283,470, 238,467, 238,524, 283,520);circle(279,520,20);circle(279,470,20);
        warna(142,101,82);kotak(238,467, 238,524, 253,524, 253,467);kotak(259,472, 259,518, 235,520, 235,470);circle(253,518,13);circle(253,472,13);circle(238,470,20);circle(238,521,20);
        warna(168,217,229);kotak(246,476, 246,514, 271,514, 271,476);kotak(244,478, 244,513, 273,513, 273,478);circle(246,478,26);circle(246,512,26);circle(271,512,26);circle(271,478,26);
        warna(102,67,54);kotak(254,476, 254,514, 263,514, 263,476);kotak(244,490, 244,500, 273,500, 273,490);

        warna(119,81,66);kotak(318,467, 318,524, 344,524, 344,467);kotak(348,470, 318,467, 318,524, 348,520);circle(344,520,20);circle(344,470,20);
        warna(142,101,82);kotak(303,467, 303,524, 318,524, 318,467);kotak(300,472, 300,518, 324,520, 324,470);circle(318,518,13);circle(318,472,13);circle(303,470,20);circle(303,520,20);
        warna(168,217,229);kotak(311,476, 311,514, 336,514, 336,476);kotak(309,478, 309,513, 338,513, 338,478);circle(311,478,26);circle(311,512,26);circle(336,512,26);circle(336,478,26);
        warna(102,67,54);kotak(319,476, 319,514, 328,514, 328,476);kotak(309,490, 309,500, 338,500, 338,490);
 //pohon
        warna(247,147,97);circle(114,385,3);circle(93,416,2.5);circle(135,416,2.5);circle(90,469,2.2);circle(140,469,2.2);
        warna(142,101,82);kotak(106,392, 106,565, 122,565, 122,392);circle(114,394,8.7);
        warna(119,81,66);kotak(90,409, 90,420, 138,420, 138,409);circle(90,414.5,12.5);circle(138,414.5,12.5);
        kotak(80,462, 80,473, 148,473, 148,462);circle(80,467.5,12.5);circle(148,467.5,12.5);
//hiasan
        warna(255,255,255);
        glBegin(GL_LINES);
            glVertex2d(96,220);
            glVertex2d(109,220);
        glEnd();
        glBegin(GL_LINES);
            glVertex2d(117,200);
            glVertex2d(117,213);
        glEnd();
        glBegin(GL_LINES);
            glVertex2d(125,220);
            glVertex2d(137,220);
        glEnd();
        glBegin(GL_LINES);
            glVertex2d(117,227);
            glVertex2d(117,240);
        glEnd();

        glBegin(GL_LINES);
            glVertex2d(566,220);
            glVertex2d(579,220);
        glEnd();
        glBegin(GL_LINES);
            glVertex2d(587,200);
            glVertex2d(587,213);
        glEnd();
        glBegin(GL_LINES);
            glVertex2d(595,220);
            glVertex2d(607,220);
        glEnd();
        glBegin(GL_LINES);
            glVertex2d(587,227);
            glVertex2d(587,240);
        glEnd();
        glLineWidth(3);
        circle2(216,281,8);circle2(687,313,6);
        glBegin(GL_LINES);
            glVertex2d(242,161);
            glVertex2d(263,161);
        glEnd();
        glBegin(GL_LINES);
            glVertex2d(536,161);
            glVertex2d(557,161);
        glEnd();
//P
        int k=100, l=80;
        kotak(389-k,194-l, 389-k,276-l, 431-k,276-l, 431-k,194-l);
        circle(431-k,224-l,2.4);
        warna(255,167,124);circle(431-k,224-l,2.6);
        kotak(391-k,197-l, 391-k,273-l, 429-k,273-l, 429-k,197-l);
        warna(255,255,255);circle(433-k,224-l,15);
        glBegin(GL_LINES);
            glVertex2d(398-k,269-l);
            glVertex2d(423-k,269-l);
            glVertex2d(423-k,269-l);
            glVertex2d(423-k,246-l);
        glEnd();
        glLineWidth(2);
//A
        segitiga(489-k,194-l, 442-k,276-l, 532-k,276-l);
        warna(255,167,124);segitiga(489-k,200-l, 446-k,273-l, 527-k,273-l);
        warna(255,255,255);
        glBegin(GL_LINES);
            glVertex2d(510-k,250-l);
            glVertex2d(520-k,269-l);
            glVertex2d(520-k,269-l);
            glVertex2d(503-k,269-l);
        glEnd();
        circle(488-k,245-l,15);
//M
        kotak(533-k,194-l, 533-k,276-l, 574-k,276-l, 574-k,235-l);
        kotak(617-k,194-l, 617-k,276-l, 574-k,276-l, 574-k,235-l);
        warna(255,167,124);
        kotak(536-k,201-l, 536-k,273-l, 574-k,273-l, 574-k,240-l);
        kotak(614-k,201-l, 614-k,273-l, 574-k,273-l, 574-k,240-l);
        glBegin(GL_LINES);
            glColor3ub(255,255,255);
            glVertex2d(587-k,267-l);
            glVertex2d(607-k,267-l);
            glVertex2d(607-k,267-l);
            glVertex2d(607-k,243-l);
        glEnd();
        // Swap front and back buffers
        glfwSwapBuffers( window );

        // Poll for and process events
        glfwPollEvents( );
    }

    glfwTerminate( );

    return 0;
}


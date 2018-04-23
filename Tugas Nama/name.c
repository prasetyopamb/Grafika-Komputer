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
        warna(37,34,35);
        kotak(0,0,0,800,800,800,800,0);
//i
        warna(204,213,156);
        kotak(182,206, 182,214, 228,214, 228,206);
        kotak(197,214, 197,252, 212,252, 212,214);
        kotak(182,252, 182,259, 227,259, 227,252);

//T
        kotak(231,206, 231,214, 276,214, 276,206);
        kotak(246,214, 246,259, 261,259, 261,214);

//'
        kotak(281,192, 281,207, 296,207, 296,192);
        kotak(288,207, 288,215, 296,215, 296,207);
        kotak(281,215, 281,222, 288,222, 288,215);

//S
        kotak(309,206, 309,214, 339,214, 339,206);
        kotak(331,214, 331,221, 346,221, 346,214);
        kotak(301,214, 301,229, 316,229, 316,214);
        kotak(309,229, 309,237, 346,237, 346,229);
        kotak(339,237, 339,252, 354,252, 354,237);
        kotak(309,252, 309,259, 346,259, 346,252);
        kotak(301,244, 301,252, 316,252, 316,244);
//P
        kotak(389,194, 389,276, 431,276, 431,194);
        circle(431,224,2.4);
        warna(37,34,35);circle(431,224,2.6);
        kotak(391,197, 391,273, 429,273, 429,197);
        warna(204,213,156);circle(433,224,15);
        glBegin(GL_LINES);
            glVertex2d(398,269);
            glVertex2d(423,269);
            glVertex2d(423,269);
            glVertex2d(423,246);
        glEnd();
        glLineWidth(2);
//A
        segitiga(489,194, 442,276, 532,276);
        warna(37,34,35);segitiga(489,200, 446,273, 527,273);
        warna(204,213,156);
        glBegin(GL_LINES);
            glVertex2d(510,250);
            glVertex2d(520,269);
            glVertex2d(520,269);
            glVertex2d(503,269);
        glEnd();
        circle(488,245,15);
//M
        kotak(533,194, 533,276, 574,276, 574,235);
        kotak(617,194, 617,276, 574,276, 574,235);
        warna(37,34,35);
        kotak(536,201, 536,273, 574,273, 574,240);
        kotak(614,201, 614,273, 574,273, 574,240);
        glBegin(GL_LINES);
            glColor3ub(204,213,156);
            glVertex2d(587,267);
            glVertex2d(607,267);
            glVertex2d(607,267);
            glVertex2d(607,243);
        glEnd();
//J
        kotak(196,544, 196,575, 207,575, 207,544);
        kotak(175,575, 175,581, 201,581, 201,575);
        kotak(169,570, 169,575, 180,575, 180,570);
//U
        kotak(214,544, 214,575, 225,575, 225,544);
        kotak(220,575, 220,581, 246,581, 246,575);
        kotak(241,544, 241,575, 252,575, 252,544);
//S
        kotak(277,549, 277,554, 287,554, 287,549);
        kotak(261,544, 261,549, 282,549, 282,544);
        kotak(255,549, 255,560, 266,560, 266,549);
        kotak(261,560, 261,565, 287,565, 287,560);
        kotak(282,565, 282,575, 293,575, 293,565);
        kotak(261,575, 261,581, 287,581, 287,575);
        kotak(255,570, 255,575, 266,575, 266,570);
//T
        kotak(295,544, 295,549, 326,549, 326,544);
        kotak(305,549, 305,581, 316,581, 316,549);
//C
        kotak(380,549, 380,554, 391,554, 391,549);
        kotak(364,544, 364,549, 385,549, 385,544);
        kotak(359,549, 359,554, 370,554, 370,549);
        kotak(354,554, 354,570, 364,570, 364,554);
        kotak(359,570, 359,576, 370,576, 370,570);
        kotak(364,576, 364,581, 385,581, 385,576);
        kotak(380,570, 380,576, 391,576, 391,570);
//A
        kotak(407,544, 407,549, 423,549, 423,544);
        kotak(402,549, 402,554, 412,554, 412,549);
        kotak(396,554, 396,581, 407,581, 407,554);
        kotak(407,565, 407,570, 423,570, 423,565);
        kotak(423,554, 423,581, 434,581, 434,554);
        kotak(418,549, 418,554, 428,554, 428,549);
        warna(37,34,35);kotak(412,549, 412,554, 418,554, 418,549);
        kotak(407,554, 407,565, 423,565, 423,554);
//L
        warna(204,213,156);
        kotak(438,544, 438,581, 449,581, 449,544);
        kotak(449,576, 449,581, 476,581, 476,576);
        kotak(478,544, 478,581, 489,581, 489,544);
        kotak(489,576, 489,581, 515,581, 515,576);
//M
        kotak(543,544, 543,581, 554,581, 554,544);
        kotak(554,549, 554,565, 559,565, 559,549);
        kotak(559,554, 559,570, 565,570, 565,554);
        kotak(565,549, 565,565, 570,565, 570,549);
        kotak(570,544, 570,581, 581,581, 581,544);
//E
        kotak(586,544, 586,581, 597,581, 597,544);
        kotak(586,544, 586,549, 623,549, 623,544);
        kotak(597,560, 597,565, 618,565, 618,560);
        kotak(597,576, 597,581, 623,581, 623,576);
//P
        kotak(243,598, 243,635, 258,635, 258,598);
        kotak(258,598, 258,625, 280,625, 280,598);
        kotak(280,603, 280,619, 285,619, 285,603);
        warna(37,34,35);kotak(258,603, 258,619, 274,619, 274,603);
//A
        warna(204,213,156);
        kotak(302,598, 302,603, 318,603, 318,598);
        kotak(297,603, 297,609, 307,609, 307,603);
        kotak(291,609, 291,635, 302,635, 302,609);
        kotak(302,619, 302,625, 318,625, 318,619);
        kotak(318,609, 318,635, 329,635, 329,609);
        kotak(313,603, 313,609, 323,609, 323,603);
        warna(37,34,35);kotak(307,603, 307,609, 313,609, 313,603);
        kotak(302,609, 302,619, 318,619, 318,609);
//M
        warna(204,213,156);
        kotak(336,598, 336,635, 347,635, 347,598);
        kotak(347,603, 347,619, 352,619, 352,603);
        kotak(352,609, 352,625, 357,625, 357,609);
        kotak(357,603, 357,619, 363,619, 363,603);
        kotak(363,598, 363,635, 373,635, 373,598);
//B
        kotak(381,598, 381,635, 413,635, 413,598);
        kotak(413,603, 413,614, 418,614, 418,603);
        kotak(413,619, 413,630, 418,630, 418,619);
        warna(37,34,35);kotak(392,603, 392,614, 408,614, 408,603);
        kotak(392,619, 392,630, 408,630, 408,619);
//U
        warna(204,213,156);
        kotak(426,598, 426,630, 437,630, 437,598);
        kotak(431,630, 431,635, 458,635, 458,630);
        kotak(453,598, 453,630, 463,630, 463,598);
//D
        kotak(471,598, 471,635, 498,635, 498,598);
        kotak(498,603, 498,630, 503,630, 503,603);
        kotak(503,609, 503,625, 508,625, 508,609);
        warna(37,34,35);kotak(482,603, 482,630, 492,630, 492,603);
        kotak(492,609, 492,625, 498,625, 498,609);
//I
        warna(204,213,156);
        kotak(512,598, 512,603, 544,603, 544,598);
        kotak(523,603, 523,630, 533,630, 533,603);
        kotak(512,630, 512,635, 544,635, 544,630);
//pacman
        warna(242,233,0);circle(187,400,1.6);
        warna(255,255,255);circle(264,400,5);circle(299,400,5);circle(333,400,5);
        glBegin(GL_LINES);
            glVertex2d(188,409);
            glVertex2d(216,422);
        glEnd();
        //circle(184,378,15);circle(193,372,15);
        warna(37,34,35);segitiga(186,400, 240,420, 240,364);

//monster1
        warna(244,145,149);
        kotak(372,392, 372,439, 442,439, 442,392);circle(407,387,2.01);
        warna(37,34,35);segitiga(384,432, 372,439, 395,439);segitiga(407,431, 395,439, 418,439);segitiga(429,432, 418,439, 442,439);
        warna(255,255,255);circle(395,386,9);circle(417,386,9);
        warna(40,71,157);circle(395,388,18.5);circle(417,388,18.5);
//monster2
        warna(134,210,226);
        kotak(476,392, 476,439, 546,439, 546,392);circle(511,387,2.01);
        warna(37,34,35);segitiga(488,432, 476,439, 499,439);segitiga(510,431, 499,439, 520,439);segitiga(533,432, 520,439, 546,439);
        warna(255,255,255);circle(499,386,9);circle(521,386,9);
        warna(40,71,157);circle(497,382,18.5);circle(520,382,18.5);
//monster3
        warna(247,152,29);
        kotak(575,392, 575,439, 645,439, 645,392);circle(610,387,2.01);
        warna(37,34,35);segitiga(587,432, 575,439, 598,439);segitiga(610,431, 598,439, 621,439);segitiga(632,432, 621,439, 645,439);
        warna(255,255,255);circle(598,386,9);circle(620,386,9);
        warna(40,71,157);circle(599,389,18.5);circle(622,389,18.5);



        // Swap front and back buffers
        glfwSwapBuffers( window );

        // Poll for and process events
        glfwPollEvents( );
    }

    glfwTerminate( );

    return 0;
}

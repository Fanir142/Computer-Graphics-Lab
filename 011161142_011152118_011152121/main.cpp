#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include <windows.h>
#include <glut.h>




int drawgrid;
int drawaxes;


struct point
{
	double x,y,z;
};


void drawAxes()
{
	if(drawaxes==1)
	{
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_LINES);{
			glVertex3f( 100,0,0);
			glVertex3f(-100,0,0);

			glVertex3f(0,-100,0);
			glVertex3f(0, 100,0);

			glVertex3f(0,0, 100);
			glVertex3f(0,0,-100);
		}glEnd();
	}
}


void drawGrid()
{
	int i;


    glColor3f(0.6, 0.6, 0.6);	//grey
    glBegin(GL_LINES);{
        for(i=-20;i<=20;i++){

            if(i==0)
                continue;	//SKIP the MAIN axes

            //lines parallel to Y-axis
            glVertex3f(i*5, -90, 0);
            glVertex3f(i*5,  90, 0);

            //lines parallel to X-axis
            glVertex3f(-90, i*5, 0);
            glVertex3f( 90, i*5, 0);
        }
    }glEnd();

}

void point()
{
    glColor3f(0.0f, 0.0f, 1.0f);
    glPointSize(1.5);
    glBegin(GL_POINTS);
    glVertex2f(0.5,0.5);
    glVertex2f(1,1);
    glVertex2f(1.5,1.5);
    glEnd();
}

void pointsMany(int num)
{
    glColor3f(1.0f, 1.0f, 1.0f);
    glPointSize(1.5);
    glBegin(GL_POINTS);
    for(int i = 0;i<num;i++)
    {
        glVertex2f((i*13)%31,(i*31)%39);
    }
    glEnd();
}
void just_line()
{
    glColor3f(0.0f, 0.0f, 1.0f); //BLUE LINE
    glBegin(GL_LINES); // It can be any type Gl_POINT,_LINE

        glVertex2d(-4.0,-2.0);
        glVertex2d(4.0,2.0);

    glEnd();

}
void lines()
{
    glColor3f(0.0f, 1.0f, 0.0f); // GREEN RECTANGLE
    glBegin(GL_LINE_LOOP); // It can be any type Gl_POINT,_LINE

        glVertex2d(20,20);
        glVertex2d(-20,20);
        glVertex2d(-20,-20);
        glVertex2d(20,-20);

    glEnd();
}
void triangle()
{
    glColor3f(1.0f, 0.0f, 0.0f); //RED TRIANGLE
    glBegin(GL_LINE_LOOP); // It can be any type Gl_POINT,_LINE

        glVertex2d(0.0,2.5);
        glVertex2d(-2.5,0.0);
        glVertex2d(2.5,0.0);

    glEnd();

}

void s_triangle()
{
    glBegin(GL_TRIANGLES); // DRAWING 3 SIDED TRIANGLE
        glColor3f(1.0f, 0.0f, 0.0f); glVertex2d(-2.0,-4.0);
        glColor3f(1.0f, 1.0f, 0.0f); glVertex2d(4.0,-2.0);
        glColor3f(1.0f, 0.0f, 1.0f); glVertex2d(-2.0,4.0);
    glEnd();

}

void s_quad()
{
    ////////////////////////C
    glBegin(GL_QUADS); // DRAWING 4 SIDED QUADRILATERAL
        glColor3f(1.0f, 0.0f, 1.0f);
        glVertex2d(-8.0,-6.0);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2d(-6.0,-6.0);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2d(-6.0,6.0);
        glColor3f(0.0f, 1.0f, 1.0f);
        glVertex2d(-8.0,6.0);
    glEnd();

    glBegin(GL_QUADS); // DRAWING 4 SIDED QUADRILATERAL
        glColor3f(1.0f, 0.0f, 1.0f);
        glVertex2d(-8.0,6.0);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2d(-2.0,6.0);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2d(-2.0,8.0);
        glColor3f(0.0f, 1.0f, 1.0f);
        glVertex2d(-8.0,8.0);
    glEnd();


    glBegin(GL_QUADS); // DRAWING 4 SIDED QUADRILATERAL
        glColor3f(1.0f, 0.0f, 1.0f);
        glVertex2d(-8.0,-8.0);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2d(-2.0,-8.0);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2d(-2.0,-6.0);
        glColor3f(0.0f, 1.0f, 1.0f);
        glVertex2d(-8.0,-6.0);
    glEnd();

    ///////////////////////////S
    glBegin(GL_QUADS); // DRAWING 4 SIDED QUADRILATERAL
        glColor3f(1.0f, 0.0f, 1.0f);
        glVertex2d(2.0,6.0);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2d(8.0,6.0);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2d(8.0,8.0);
        glColor3f(0.0f, 1.0f, 1.0f);
        glVertex2d(2.0,8.0);
    glEnd();

    glBegin(GL_QUADS); // DRAWING 4 SIDED QUADRILATERAL
        glColor3f(1.0f, 0.0f, 1.0f);
        glVertex2d(2.0,-8.0);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2d(8.0,-8.0);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2d(8.0,-6.0);
        glColor3f(0.0f, 1.0f, 1.0f);
        glVertex2d(2.0,-6.0);
    glEnd();

     glBegin(GL_QUADS); // DRAWING 4 SIDED QUADRILATERAL
        glColor3f(1.0f, 0.0f, 1.0f);
        glVertex2d(2.0,-1.0);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2d(8.0,-1.0);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2d(8.0,1.0);
        glColor3f(0.0f, 1.0f, 1.0f);
        glVertex2d(2.0,1.0);
    glEnd();

    glBegin(GL_QUADS); // DRAWING 4 SIDED QUADRILATERAL
        glColor3f(1.0f, 0.0f, 1.0f);
        glVertex2d(2.0,1.0);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2d(4.0,1.0);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2d(4.0,6.0);
        glColor3f(0.0f, 1.0f, 1.0f);
        glVertex2d(2.0,6.0);
    glEnd();

    glBegin(GL_QUADS); // DRAWING 4 SIDED QUADRILATERAL
        glColor3f(1.0f, 0.0f, 1.0f);
        glVertex2d(6.0,-6.0);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2d(8.0,-6.0);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2d(8.0,-1.0);
        glColor3f(0.0f, 1.0f, 1.0f);
        glVertex2d(6.0,-1.0);
    glEnd();

    //////////////E
    glBegin(GL_QUADS); // DRAWING 4 SIDED QUADRILATERAL
        glColor3f(1.0f, 0.0f, 1.0f);
        glVertex2d(12.0,6.0);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2d(18.0,6.0);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2d(18.0,8.0);
        glColor3f(0.0f, 1.0f, 1.0f);
        glVertex2d(12.0,8.0);
    glEnd();

    glBegin(GL_QUADS); // DRAWING 4 SIDED QUADRILATERAL
        glColor3f(1.0f, 0.0f, 1.0f);
        glVertex2d(12.0,-8.0);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2d(18.0,-8.0);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2d(18.0,-6.0);
        glColor3f(0.0f, 1.0f, 1.0f);
        glVertex2d(12.0,-6.0);
    glEnd();

    glBegin(GL_QUADS); // DRAWING 4 SIDED QUADRILATERAL
        glColor3f(1.0f, 0.0f, 1.0f);
        glVertex2d(12.0,-1.0);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2d(18.0,-1.0);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2d(18.0,1.0);
        glColor3f(0.0f, 1.0f, 1.0f);
        glVertex2d(12.0,1.0);
    glEnd();

    glBegin(GL_QUADS); // DRAWING 4 SIDED QUADRILATERAL
        glColor3f(1.0f, 0.0f, 1.0f);
        glVertex2d(12.0,-6.0);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2d(14.0,-6.0);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2d(14.0,6.0);
        glColor3f(0.0f, 1.0f, 1.0f);
        glVertex2d(12.0,6.0);
    glEnd();



}

void s_poly()
{
    glBegin(GL_POLYGON); // DRAWING POLYGON
        glColor3f(1.0, 1.0, 0.0); // yellow
        glVertex2f(0.0, 0.0) ;
        glVertex2f(0.0, 3.0) ;
        glVertex2f(4.0, 3.0) ;
        glVertex2f(4.5, 1.5) ;
        glVertex2f(4.0, 0.0);
    glEnd();

}


///start our project here


///draw black down part starts here
void drawBlackBox()
{
    glBegin(GL_QUADS);///nicher black part
    {
        glColor3f(0,0,0);
        glVertex2d(45,6);
        glVertex2d(45,-6);
        glVertex2d(-45,-6);
        glVertex2d(-45,6);

    }glEnd();



}
void drawBlackBoxPos_1()
{
    glPushMatrix();
        glTranslatef(0,-36,0);
        drawBlackBox();
    glPopMatrix();
}
///end black parts here

///start blue down part here
void drawBlueBox()
{
    glBegin(GL_QUADS);///nicher black part
    {
        glColor3f( 0.137255,0.419608,0.556863);
        //glColor3f( 0.137255,0.419608,0.556863);// SteelBlue
        glVertex2d(45,12);
        glVertex2d(45,-12);
        glVertex2d(-45,-12);
        glVertex2d(-45,12);

    }glEnd();

}
void drawBlueBoxPos_1()
{
    glPushMatrix();
        glTranslatef(0,-18,0);
        drawBlueBox();
    glPopMatrix();

}
///end down part here
///starts draw moon here
void drawMoon(float radius_x, float radius_y)
{
	int i = 0;
	float angle = 0.0;
    glColor3f(255,255,255);
	glBegin(GL_POLYGON);
    {
		for(i = 0; i < 100; i++)
		{
			angle = 2 * 3.1416 * i / 100;
			glVertex3f (cos(angle) * radius_x, sin(angle) * radius_y, 0);
		}

    }

	glEnd();

}
void drawMoonPos()
{
    glPushMatrix();
        glTranslatef(31,22,0);
        drawMoon(9,17);
    glPopMatrix();
}

///moon ends here

///starts circle-1
void drawCircle_1(float radius_x, float radius_y)
{
	int i = 0;
	float angle = 0.0;
    glColor3f( 0.137255,0.419608,0.556863);
	glBegin(GL_POLYGON);
    {
		for(i = 0; i < 100; i++)
		{
			angle = 2 * 3.1416 * i / 100;
			glVertex3f (cos(angle) * radius_x, sin(angle) * radius_y, 0);
		}

    }

	glEnd();

}
void drawCirclePos_1()
{
    glPushMatrix();
        glTranslatef(37,-2,0);
        drawCircle_1(7,14);
    glPopMatrix();

}



///end circle-1 here


///starts circle-2
void drawCircle_2(float radius_x, float radius_y)
{
	int i = 0;
	float angle = 0.0;
    glColor3f( 0.137255,0.419608,0.556863);
	glBegin(GL_POLYGON);
    {
		for(i = 0; i < 100; i++)
		{
			angle = 2 * 3.1416 * i / 100;
			glVertex3f (cos(angle) * radius_x, sin(angle) * radius_y, 0);
		}

    }

	glEnd();

}
void drawCirclePos_2()
{
    glPushMatrix();
        glTranslatef(25,-13,0);
        drawCircle_2(7,14);
    glPopMatrix();

}



///end circle 2 here

///starts circle-3
void drawCircle_3(float radius_x, float radius_y)
{
	int i = 0;
	float angle = 0.0;
    glColor3f( 0.137255,0.419608,0.556863);
	glBegin(GL_POLYGON);
    {
		for(i = 0; i < 100; i++)
		{
			angle = 2 * 3.1416 * i / 100;
			glVertex3f (cos(angle) * radius_x, sin(angle) * radius_y, 0);
		}

    }

	glEnd();

}
void drawCirclePos_3()
{
    glPushMatrix();
        glTranslatef(12,-8,0);
        drawCircle_3(7,14);
    glPopMatrix();

}



///end circle 3 here

///starts circle-4
void drawCircle_4(float radius_x, float radius_y)
{
	int i = 0;
	float angle = 0.0;
    glColor3f( 0.137255,0.419608,0.556863);
	glBegin(GL_POLYGON);
    {
		for(i = 0; i < 100; i++)
		{
			angle = 2 * 3.1416 * i / 100;
			glVertex3f (cos(angle) * radius_x, sin(angle) * radius_y, 0);
		}

    }

	glEnd();

}
void drawCirclePos_4()
{
    glPushMatrix();
        glTranslatef(0,-14,0);
        drawCircle_4(7,14);
    glPopMatrix();

}



///end circle 4 here

///starts circle-5
void drawCircle_5(float radius_x, float radius_y)
{
	int i = 0;
	float angle = 0.0;
    glColor3f( 0.137255,0.419608,0.556863);
	glBegin(GL_POLYGON);
    {
		for(i = 0; i < 100; i++)
		{
			angle = 2 * 3.1416 * i / 100;
			glVertex3f (cos(angle) * radius_x, sin(angle) * radius_y, 0);
		}

    }

	glEnd();

}
void drawCirclePos_5()
{
    glPushMatrix();
        glTranslatef(-12,-14,0);
        drawCircle_5(7,14);
    glPopMatrix();

}



///end circle 6 here

void drawCircle_6(float radius_x, float radius_y)
{
	int i = 0;
	float angle = 0.0;
    glColor3f( 0.137255,0.419608,0.556863);
	glBegin(GL_POLYGON);
    {
		for(i = 0; i < 100; i++)
		{
			angle = 2 * 3.1416 * i / 100;
			glVertex3f (cos(angle) * radius_x, sin(angle) * radius_y, 0);
		}

    }

	glEnd();

}
void drawCirclePos_6()
{
    glPushMatrix();
        glTranslatef(-24,-9,0);
        drawCircle_6(8,16);
    glPopMatrix();

}



///end circle 6 here

///end circle 7 here

void drawCircle_7(float radius_x, float radius_y)
{
	int i = 0;
	float angle = 0.0;
    glColor3f( 0.137255,0.419608,0.556863);
	glBegin(GL_POLYGON);
    {
		for(i = 0; i < 100; i++)
		{
			angle = 2 * 3.1416 * i / 100;
			glVertex3f (cos(angle) * radius_x, sin(angle) * radius_y, 0);
		}

    }

	glEnd();

}
void drawCirclePos_7()
{
    glPushMatrix();
        glTranslatef(-37,-5,0);
        drawCircle_7(8,16);
    glPopMatrix();

}



///end circle 7 here


///draw house-1 starts here
void drawHouse_1()
{
    glBegin(GL_QUADS);
    {
        glColor3f(0,0,0);
        glVertex2d(3.5,15);
        glVertex2d(3.5,0);
        glVertex2d(-3.5,0);
        glVertex2d(-3.5,15);

    }glEnd();



}
void drawHousePos_1()
{
    glPushMatrix();
        glTranslatef(-39,-30,0);
        drawHouse_1();
    glPopMatrix();
}
///end house-1 here


///Starts house-2
///draw house-21 starts here
void drawHouse_21()
{
    glBegin(GL_QUADS);
    {
        glColor3f(0,0,0);
        glVertex2d(1,19);
        glVertex2d(1,0);
        glVertex2d(-1,0);
        glVertex2d(-1,19);

    }glEnd();



}
void drawHousePos_21()
{
    glPushMatrix();
        glTranslatef(-29,-30,0);
        drawHouse_21();
    glPopMatrix();
}
///end house-21 here

///starts house-22 here
void drawHouse_22()
{
    glBegin(GL_QUADS);
    {
        glColor3f(0,0,0);
        glVertex2d(2.5,24);
        glVertex2d(2.5,0);
        glVertex2d(-2.5,0);
        glVertex2d(-2.5,24);

    }glEnd();

    glBegin(GL_QUADS);
    {
        glColor3f(0,0,0);
        glVertex2d(0,31);
        glVertex2d(3.5,24);
        glVertex2d(-3.5,24);
        glVertex2d(-3.5,24);

    }glEnd();



}
void drawHousePos_22()
{
    glPushMatrix();
        glTranslatef(-25.5,-30,0);
        drawHouse_22();
    glPopMatrix();
}
///end house-22 here
///end house 2

///starts house-3
void drawHouse_3()
{
    glBegin(GL_QUADS);
    {
        glColor3f(0,0,0);
        glVertex2d(2.5,18);
        glVertex2d(2.5,0);
        glVertex2d(-2.5,0);
        glVertex2d(-2.5,18);

    }glEnd();

}
void drawHousePos_3()
{
    glPushMatrix();
        glTranslatef(-15,-30,0);
        drawHouse_3();
    glPopMatrix();
}
///end house-3 here

///starts house-4
///draw house-41 starts here
void drawHouse_41()
{
    glBegin(GL_QUADS);
    {
        glColor3f(0,0,0);
        glVertex2d(1,13);
        glVertex2d(1,0);
        glVertex2d(-1,0);
        glVertex2d(-1,13);

    }glEnd();



}
void drawHousePos_41()
{
    glPushMatrix();
        glTranslatef(38,-30,0);
        drawHouse_41();
    glPopMatrix();
}
///end house-41 here

///starts house-42
void drawHouse_42()
{
    glBegin(GL_QUADS);
    {
        glColor3f(0,0,0);
        glVertex2d(2.5,8);
        glVertex2d(2.5,0);
        glVertex2d(-2.5,0);
        glVertex2d(-2.5,8);

    }glEnd();

}
void drawHousePos_42()
{
    glPushMatrix();
        glTranslatef(34.5,-30,0);
        drawHouse_42();
    glPopMatrix();
}
///end house-42 here

///end house-4

///starts house-5
///starts house-5 here
void drawHouse_5()
{
    glBegin(GL_QUADS);
    {
        glColor3f(0,0,0);
        glVertex2d(3,13);
        glVertex2d(3,0);
        glVertex2d(-3,0);
        glVertex2d(-3,13);

    }glEnd();

    glBegin(GL_QUADS);
    {
        glColor3f(0,0,0);
        glVertex2d(3,20);
        glVertex2d(3,13);
        glVertex2d(-4,13);
        glVertex2d(-4,13);

    }glEnd();



}
void drawHousePos_5()
{
    glPushMatrix();
        glTranslatef(25,-30,0);
        drawHouse_5();
    glPopMatrix();
}
///end house-5 here

///starts house-6

///draw house-61 starts here
void drawHouse_61()
{
    glBegin(GL_QUADS);
    {
        glColor3f(0,0,0);
        glVertex2d(1,12);
        glVertex2d(1,0);
        glVertex2d(-1,0);
        glVertex2d(-1,12);

    }glEnd();



}
void drawHousePos_61()
{
    glPushMatrix();
        glTranslatef(12,-30,0);
        drawHouse_61();
    glPopMatrix();
}
///end house-61 here

///starts house-62 here
void drawHouse_62()
{
    glBegin(GL_QUADS);
    {
        glColor3f(0,0,0);
        glVertex2d(2.5,24);
        glVertex2d(2.5,0);
        glVertex2d(-2.5,0);
        glVertex2d(-2.5,24);

    }glEnd();

    glBegin(GL_QUADS);
    {
        glColor3f(0,0,0);
        glVertex2d(0,31);
        glVertex2d(3.5,24);
        glVertex2d(-3.5,24);
        glVertex2d(-3.5,24);

    }glEnd();



}
void drawHousePos_62()
{
    glPushMatrix();
        glTranslatef(15,-30,0);
        drawHouse_62();
    glPopMatrix();
}
///end house-62 here


///end house-6


///starts house-7

///draw house-71 starts here
void drawHouse_71()
{
    glBegin(GL_QUADS);
    {
        glColor3f(0,0,0);
        glVertex2d(1,12);
        glVertex2d(1,0);
        glVertex2d(-1,0);
        glVertex2d(-1,12);

    }glEnd();



}
void drawHousePos_71()
{
    glPushMatrix();
        glTranslatef(-6,-30,0);
        drawHouse_71();
    glPopMatrix();
}
///end house-71 here

///starts house-72 here
void drawHouse_72()
{
    glBegin(GL_QUADS);
    {
        glColor3f(0,0,0);
        glVertex2d(5,42);
        glVertex2d(5,0);
        glVertex2d(-5,0);
        glVertex2d(-5,42);

    }glEnd();

    glBegin(GL_QUADS);
    {
        glColor3f(0,0,0);
        glVertex2d(0,53);
        glVertex2d(5,42);
        glVertex2d(-5,42);
        glVertex2d(-5,42);

    }glEnd();



}
void drawHousePos_72()
{
    glPushMatrix();
        glTranslatef(0,-30,0);
        drawHouse_72();
    glPopMatrix();
}
///end house-72 here


///end house-7

///starts stand-1 here
void drawStand_1()
{
    glBegin(GL_QUADS);
    {
        glColor3f(0,0,0);
        glVertex2d(0.3,7);
        glVertex2d(0.3,-5);
        glVertex2d(-0.3,-5);
        glVertex2d(-0.3,7);

    }glEnd();

}
void drawStandPos_1()
{
    glPushMatrix();
        glTranslatef(0,27,0);
        drawStand_1();
    glPopMatrix();
}
///end stand-1 here


///starts stand-2 here
void drawStand_2()
{
    glBegin(GL_QUADS);
    {
        glColor3f(0,0,0);
        glVertex2d(2,0.6);
        glVertex2d(2,-0.6);
        glVertex2d(-2,-0.6);
        glVertex2d(-2,0.6);

    }glEnd();

}
void drawStandPos_2()
{
    glPushMatrix();
        glTranslatef(0,31,0);
        drawStand_2();
    glPopMatrix();
}
///end stand here

///starts box-1 here
void drawBox_1()
{
    glBegin(GL_QUADS);
    {
        glColor3f(1,1,0);
        glVertex2d(1,2);
        glVertex2d(1,-2);
        glVertex2d(-1,-2);
        glVertex2d(-1,2);

    }glEnd();

}
void drawBoxPos_1()
{
    glPushMatrix();
        glTranslatef(-40,-24,0);
        drawBox_1();
    glPopMatrix();
}
///end box-1 here

///starts box-2 here
void drawBox_2()
{
    glBegin(GL_QUADS);
    {
        glColor3f(1,1,0);
        glVertex2d(1,2);
        glVertex2d(1,-2);
        glVertex2d(-1,-2);
        glVertex2d(-1,2);

    }glEnd();

}
void drawBoxPos_2()
{
    glPushMatrix();
        glTranslatef(-40,-19,0);
        drawBox_2();
    glPopMatrix();
}
///end box-2 here


///starts box-3 here
void drawBox_3()
{
    glBegin(GL_QUADS);
    {
        glColor3f(1,1,0);
        glVertex2d(1,2);
        glVertex2d(1,-2);
        glVertex2d(-1,-2);
        glVertex2d(-1,2);

    }glEnd();

}
void drawBoxPos_3()
{
    glPushMatrix();
        glTranslatef(-37.5,-24,0);
        drawBox_3();
    glPopMatrix();
}
///end box-3 here

///starts box-4 here
void drawBox_4()
{
    glBegin(GL_QUADS);
    {
        glColor3f(1,1,0);
        glVertex2d(1,2);
        glVertex2d(1,-2);
        glVertex2d(-1,-2);
        glVertex2d(-1,2);

    }glEnd();

}
void drawBoxPos_4()
{
    glPushMatrix();
        glTranslatef(-37.5,-19,0);
        drawBox_4();
    glPopMatrix();
}
///end box-4 here

///starts box-5 here
void drawBox_5()
{
    glBegin(GL_QUADS);
    {
        glColor3f(1,1,0);
        glVertex2d(0.7,5);
        glVertex2d(0.7,-5);
        glVertex2d(-0.7,-5);
        glVertex2d(-0.7,5);

    }glEnd();

}
void drawBoxPos_5()
{
    glPushMatrix();
        glTranslatef(-26.5,-24.2,0);
        drawBox_5();
    glPopMatrix();
}
///end box-5 here

///starts box-6 here
void drawBox_6()
{
    glBegin(GL_QUADS);
    {
        glColor3f(1,1,0);
        glVertex2d(0.7,5);
        glVertex2d(0.7,-5);
        glVertex2d(-0.7,-5);
        glVertex2d(-0.7,5);

    }glEnd();

}
void drawBoxPos_6()
{
    glPushMatrix();
        glTranslatef(-26.5,-13,0);
        drawBox_6();
    glPopMatrix();
}
///end box-6 here

///starts box-7 here
void drawBox_7()
{
    glBegin(GL_QUADS);
    {
        glColor3f(1,1,0);
        glVertex2d(0.7,5);
        glVertex2d(0.7,-5);
        glVertex2d(-0.7,-5);
        glVertex2d(-0.7,5);

    }glEnd();

}
void drawBoxPos_7()
{
    glPushMatrix();
        glTranslatef(-24.5,-24.2,0);
        drawBox_7();
    glPopMatrix();
}
///end box-7 here

///starts box-8 here
void drawBox_8()
{
    glBegin(GL_QUADS);
    {
        glColor3f(1,1,0);
        glVertex2d(0.7,5);
        glVertex2d(0.7,-5);
        glVertex2d(-0.7,-5);
        glVertex2d(-0.7,5);

    }glEnd();

}
void drawBoxPos_8()
{
    glPushMatrix();
        glTranslatef(-24.5,-13,0);
        drawBox_8();
    glPopMatrix();
}
///end box-8 here

///starts box-9 here
void drawBox_9()
{
    glBegin(GL_QUADS);
    {
        glColor3f(1,1,0);
        glVertex2d(1.5,2.5);
        glVertex2d(1.5,-2.5);
        glVertex2d(-1.5,-2.5);
        glVertex2d(-1.5,2.5);

    }glEnd();

}
void drawBoxPos_9()
{
    glPushMatrix();
        glTranslatef(-15,-24,0);
        drawBox_9();
    glPopMatrix();
}
///end box-9 here

///starts box-10 here
void drawBox_10()
{
    glBegin(GL_QUADS);
    {
        glColor3f(1,1,0);
        glVertex2d(1.5,2.5);
        glVertex2d(1.5,-2.5);
        glVertex2d(-1.5,-2.5);
        glVertex2d(-1.5,2.5);

    }glEnd();

}
void drawBoxPos_10()
{
    glPushMatrix();
        glTranslatef(-15,-17,0);
        drawBox_10();
    glPopMatrix();
}
///end box-10 here

///starts box-11 here
void drawBox_11()
{
    glBegin(GL_QUADS);
    {
        glColor3f(1,1,0);
        glVertex2d(0.7,5);
        glVertex2d(0.7,-5);
        glVertex2d(-0.7,-5);
        glVertex2d(-0.7,5);

    }glEnd();

}
void drawBoxPos_11()
{
    glPushMatrix();
        glTranslatef(14,-24.2,0);
        drawBox_11();
    glPopMatrix();
}
///end box-11 here

///starts box-12 here
void drawBox_12()
{
    glBegin(GL_QUADS);
    {
        glColor3f(1,1,0);
        glVertex2d(0.7,5);
        glVertex2d(0.7,-5);
        glVertex2d(-0.7,-5);
        glVertex2d(-0.7,5);

    }glEnd();

}
void drawBoxPos_12()
{
    glPushMatrix();
        glTranslatef(14,-13,0);
        drawBox_12();
    glPopMatrix();
}
///end box-12 here

///starts box-13 here
void drawBox_13()
{
    glBegin(GL_QUADS);
    {
        glColor3f(1,1,0);
        glVertex2d(0.7,5);
        glVertex2d(0.7,-5);
        glVertex2d(-0.7,-5);
        glVertex2d(-0.7,5);

    }glEnd();

}
void drawBoxPos_13()
{
    glPushMatrix();
        glTranslatef(16,-24.2,0);
        drawBox_13();
    glPopMatrix();
}
///end box-13 here

///starts box-14 here
void drawBox_14()
{
    glBegin(GL_QUADS);
    {
        glColor3f(1,1,0);
        glVertex2d(0.7,5);
        glVertex2d(0.7,-5);
        glVertex2d(-0.7,-5);
        glVertex2d(-0.7,5);

    }glEnd();

}
void drawBoxPos_14()
{
    glPushMatrix();
        glTranslatef(16,-13,0);
        drawBox_14();
    glPopMatrix();
}
///end box-14 here

///starts box-15 here
void drawBox_15()
{
    glBegin(GL_QUADS);
    {
        glColor3f(1,1,0);
        glVertex2d(1,2);
        glVertex2d(1,-2);
        glVertex2d(-1,-2);
        glVertex2d(-1,2);

    }glEnd();

}
void drawBoxPos_15()
{
    glPushMatrix();
        glTranslatef(36.5,-25,0);
        drawBox_15();
    glPopMatrix();
}
///end box-15 here

///starts box-16 here
void drawBox_16()
{
    glBegin(GL_QUADS);
    {
        glColor3f(1,1,0);
        glVertex2d(1,2);
        glVertex2d(1,-2);
        glVertex2d(-1,-2);
        glVertex2d(-1,2);

    }glEnd();

}
void drawBoxPos_16()
{
    glPushMatrix();
        glTranslatef(33.7,-25,0);
        drawBox_16();
    glPopMatrix();
}
///end box-16 here

///starts box-17 here
void drawBox_17()
{
    glBegin(GL_QUADS);
    {
        glColor3f(1,1,0);
        glVertex2d(2.4,0.7);
        glVertex2d(2.4,-0.7);
        glVertex2d(-2.3,-0.7);
        glVertex2d(-2.3,0.7);

    }glEnd();

}
void drawBoxPos_17()
{
    glPushMatrix();
        glTranslatef(35,-28.5,0);
        drawBox_17();
    glPopMatrix();
}
///end box-17 here

///starts box-18 here
void drawBox_18()
{
    glBegin(GL_QUADS);
    {
        glColor3f(1,1,0);
        glVertex2d(2.4,0.7);
        glVertex2d(2.4,-0.7);
        glVertex2d(-2.3,-0.7);
        glVertex2d(-2.3,0.7);

    }glEnd();

}
void drawBoxPos_18()
{
    glPushMatrix();
        glTranslatef(25,-28.5,0);
        drawBox_18();
    glPopMatrix();
}
///end box-18 here

///starts box-19 here
void drawBox_19()
{
    glBegin(GL_QUADS);
    {
        glColor3f(1,1,0);
        glVertex2d(2.4,0.7);
        glVertex2d(2.4,-0.7);
        glVertex2d(-2.3,-0.7);
        glVertex2d(-2.3,0.7);

    }glEnd();

}
void drawBoxPos_19()
{
    glPushMatrix();
        glTranslatef(25,-26.5,0);
        drawBox_19();
    glPopMatrix();
}
///end box-19 here

///starts box-20 here
void drawBox_20()
{
    glBegin(GL_QUADS);
    {
        glColor3f(1,1,0);
        glVertex2d(0.7,1.5);
        glVertex2d(0.7,-1.5);
        glVertex2d(-0.7,-1.5);
        glVertex2d(-0.7,1.5);

    }glEnd();

}
void drawBoxPos_20()
{
    glPushMatrix();
        glTranslatef(23.5,-23.5,0);
        drawBox_20();
    glPopMatrix();
}
///end box-20 here

///starts box-21 here
void drawBox_21()
{
    glBegin(GL_QUADS);
    {
        glColor3f(1,1,0);
        glVertex2d(0.7,1.5);
        glVertex2d(0.7,-1.5);
        glVertex2d(-0.7,-1.5);
        glVertex2d(-0.7,1.5);

    }glEnd();

}
void drawBoxPos_21()
{
    glPushMatrix();
        glTranslatef(25,-23.5,0);
        drawBox_21();
    glPopMatrix();
}
///end box-21 here

///starts box-22 here
void drawBox_22()
{
    glBegin(GL_QUADS);
    {
        glColor3f(1,1,0);
        glVertex2d(0.7,1.5);
        glVertex2d(0.7,-1.5);
        glVertex2d(-0.7,-1.5);
        glVertex2d(-0.7,1.5);

    }glEnd();

}
void drawBoxPos_22()
{
    glPushMatrix();
        glTranslatef(26.5,-23.5,0);
        drawBox_22();
    glPopMatrix();
}
///end box-22 here

///starts box-23 here
void drawBox_23()
{
    glBegin(GL_QUADS);
    {
        glColor3f(1,1,0);
        glVertex2d(0.7,1.5);
        glVertex2d(0.7,-1.5);
        glVertex2d(-0.7,-1.5);
        glVertex2d(-0.7,1.5);

    }glEnd();

}
void drawBoxPos_23()
{
    glPushMatrix();
        glTranslatef(23.5,-19.5,0);
        drawBox_23();
    glPopMatrix();
}
///end box-23 here

///starts box-24 here
void drawBox_24()
{
    glBegin(GL_QUADS);
    {
        glColor3f(1,1,0);
        glVertex2d(0.7,1.5);
        glVertex2d(0.7,-1.5);
        glVertex2d(-0.7,-1.5);
        glVertex2d(-0.7,1.5);

    }glEnd();

}
void drawBoxPos_24()
{
    glPushMatrix();
        glTranslatef(25,-19.5,0);
        drawBox_24();
    glPopMatrix();
}
///end box-24 here

///starts box-25 here
void drawBox_25()
{
    glBegin(GL_QUADS);
    {
        glColor3f(1,1,0);
        glVertex2d(0.7,1.5);
        glVertex2d(0.7,-1.5);
        glVertex2d(-0.7,-1.5);
        glVertex2d(-0.7,1.5);

    }glEnd();

}
void drawBoxPos_25()
{
    glPushMatrix();
        glTranslatef(26.5,-19.5,0);
        drawBox_25();
    glPopMatrix();
}
///end box-25 here

///starts box-26 here
void drawBox_26()
{
    glBegin(GL_QUADS);
    {
        glColor3f(1,1,0);
        glVertex2d(1.5,2.5);
        glVertex2d(1.5,-2.5);
        glVertex2d(-1.5,-2.5);
        glVertex2d(-1.5,2.5);

    }glEnd();

}
void drawBoxPos_26()
{
    glPushMatrix();
        glTranslatef(-2,-27,0);
        drawBox_26();
    glPopMatrix();
}
///end box-26 here

///starts box-27 here
void drawBox_27()
{
    glBegin(GL_QUADS);
    {
        glColor3f(1,1,0);
        glVertex2d(1.5,2.5);
        glVertex2d(1.5,-2.5);
        glVertex2d(-1.5,-2.5);
        glVertex2d(-1.5,2.5);

    }glEnd();

}
void drawBoxPos_27()
{
    glPushMatrix();
        glTranslatef(-2,-21,0);
        drawBox_27();
    glPopMatrix();
}
///end box-27 here

///starts box-28 here
void drawBox_28()
{
    glBegin(GL_QUADS);
    {
        glColor3f(1,1,0);
        glVertex2d(1.5,2.5);
        glVertex2d(1.5,-2.5);
        glVertex2d(-1.5,-2.5);
        glVertex2d(-1.5,2.5);

    }glEnd();

}
void drawBoxPos_28()
{
    glPushMatrix();
        glTranslatef(-2,-15,0);
        drawBox_28();
    glPopMatrix();
}
///end box-28 here

///starts box-29 here
void drawBox_29()
{
    glBegin(GL_QUADS);
    {
        glColor3f(1,1,0);
        glVertex2d(1.5,2.5);
        glVertex2d(1.5,-2.5);
        glVertex2d(-1.5,-2.5);
        glVertex2d(-1.5,2.5);

    }glEnd();

}
void drawBoxPos_29()
{
    glPushMatrix();
        glTranslatef(-2,-9,0);
        drawBox_29();
    glPopMatrix();
}
///end box-29 here

///starts box-30 here
void drawBox_30()
{
    glBegin(GL_QUADS);
    {
        glColor3f(1,1,0);
        glVertex2d(1.5,2.5);
        glVertex2d(1.5,-2.5);
        glVertex2d(-1.5,-2.5);
        glVertex2d(-1.5,2.5);

    }glEnd();

}
void drawBoxPos_30()
{
    glPushMatrix();
        glTranslatef(-2,-3,0);
        drawBox_30();
    glPopMatrix();
}
///end box-30 here


///starts box-31 here
void drawBox_31()
{
    glBegin(GL_QUADS);
    {
        glColor3f(1,1,0);
        glVertex2d(1.5,2.5);
        glVertex2d(1.5,-2.5);
        glVertex2d(-1.5,-2.5);
        glVertex2d(-1.5,2.5);

    }glEnd();

}
void drawBoxPos_31()
{
    glPushMatrix();
        glTranslatef(-2,3,0);
        drawBox_31();
    glPopMatrix();
}
///end box-31 here

///starts box-32 here
void drawBox_32()
{
    glBegin(GL_QUADS);
    {
        glColor3f(1,1,0);
        glVertex2d(1.5,2.5);
        glVertex2d(1.5,-2.5);
        glVertex2d(-1.5,-2.5);
        glVertex2d(-1.5,2.5);

    }glEnd();

}
void drawBoxPos_32()
{
    glPushMatrix();
        glTranslatef(-2,9,0);
        drawBox_32();
    glPopMatrix();
}
///end box-32 here


///////////////
///starts box-33 here
void drawBox_33()
{
    glBegin(GL_QUADS);
    {
        glColor3f(1,1,0);
        glVertex2d(1.5,2.5);
        glVertex2d(1.5,-2.5);
        glVertex2d(-1.5,-2.5);
        glVertex2d(-1.5,2.5);

    }glEnd();

}
void drawBoxPos_33()
{
    glPushMatrix();
        glTranslatef(2,-27,0);
        drawBox_33();
    glPopMatrix();
}
///end box-33 here

///starts box-34 here
void drawBox_34()
{
    glBegin(GL_QUADS);
    {
        glColor3f(1,1,0);
        glVertex2d(1.5,2.5);
        glVertex2d(1.5,-2.5);
        glVertex2d(-1.5,-2.5);
        glVertex2d(-1.5,2.5);

    }glEnd();

}
void drawBoxPos_34()
{
    glPushMatrix();
        glTranslatef(2,-21,0);
        drawBox_34();
    glPopMatrix();
}
///end box-34 here

///starts box-35 here
void drawBox_35()
{
    glBegin(GL_QUADS);
    {
        glColor3f(1,1,0);
        glVertex2d(1.5,2.5);
        glVertex2d(1.5,-2.5);
        glVertex2d(-1.5,-2.5);
        glVertex2d(-1.5,2.5);

    }glEnd();

}
void drawBoxPos_35()
{
    glPushMatrix();
        glTranslatef(2,-15,0);
        drawBox_35();
    glPopMatrix();
}
///end box-35 here

///starts box-36 here
void drawBox_36()
{
    glBegin(GL_QUADS);
    {
        glColor3f(1,1,0);
        glVertex2d(1.5,2.5);
        glVertex2d(1.5,-2.5);
        glVertex2d(-1.5,-2.5);
        glVertex2d(-1.5,2.5);

    }glEnd();

}
void drawBoxPos_36()
{
    glPushMatrix();
        glTranslatef(2,-9,0);
        drawBox_36();
    glPopMatrix();
}
///end box-36 here

///starts box-37 here
void drawBox_37()
{
    glBegin(GL_QUADS);
    {
        glColor3f(1,1,0);
        glVertex2d(1.5,2.5);
        glVertex2d(1.5,-2.5);
        glVertex2d(-1.5,-2.5);
        glVertex2d(-1.5,2.5);

    }glEnd();

}
void drawBoxPos_37()
{
    glPushMatrix();
        glTranslatef(2,-3,0);
        drawBox_37();
    glPopMatrix();
}
///end box-37 here


///starts box-38 here
void drawBox_38()
{
    glBegin(GL_QUADS);
    {
        glColor3f(1,1,0);
        glVertex2d(1.5,2.5);
        glVertex2d(1.5,-2.5);
        glVertex2d(-1.5,-2.5);
        glVertex2d(-1.5,2.5);

    }glEnd();

}
void drawBoxPos_38()
{
    glPushMatrix();
        glTranslatef(2,3,0);
        drawBox_38();
    glPopMatrix();
}
///end box-38 here

///starts box-39 here
void drawBox_39()
{
    glBegin(GL_QUADS);
    {
        glColor3f(1,1,0);
        glVertex2d(1.5,2.5);
        glVertex2d(1.5,-2.5);
        glVertex2d(-1.5,-2.5);
        glVertex2d(-1.5,2.5);

    }glEnd();

}
void drawBoxPos_39()
{
    glPushMatrix();
        glTranslatef(2,9,0);
        drawBox_39();
    glPopMatrix();
}
///end box-39 here

///star starts here
///drawing the stars

void drawStar1(float radius_x, float radius_y)
{
	int i = 0;
	float angle = 0.0;
    glColor3f( 1,1,1);
	glBegin(GL_POLYGON);
    {
		for(i = 0; i <360; i++)
		{
			angle = 2 * 3.1416 * i / 180;
			glVertex3f ((-5)+cos(angle) * radius_x, 18+sin(angle) * radius_y, 0);
		}

    }

	glEnd();

}

void drawStar2(float radius_x, float radius_y)
{
	int i = 0;
	float angle = 0.0;
    glColor3f( 1,1,1);
	glBegin(GL_POLYGON);
    {
		for(i = 0; i <360; i++)
		{
			angle = 2 * 3.1416 * i / 180;
			glVertex3f ((-12)+cos(angle) * radius_x, 21+sin(angle) * radius_y, 0);
		}

    }

	glEnd();

}

void drawStar3(float radius_x, float radius_y)
{
	int i = 0;
	float angle = 0.0;
    glColor3f( 1,1,1);
	glBegin(GL_POLYGON);
    {
		for(i = 0; i <360; i++)
		{
			angle = 2 * 3.1416 * i / 180;
			glVertex3f ((-25)+cos(angle) * radius_x, 11+sin(angle) * radius_y, 0);
		}

    }

	glEnd();

}

void drawStar4(float radius_x, float radius_y)
{
	int i = 0;
	float angle = 0.0;
    glColor3f( 1,1,1);
	glBegin(GL_POLYGON);
    {
		for(i = 0; i <360; i++)
		{
			angle = 2 * 3.1416 * i / 180;
			glVertex3f ((-21)+cos(angle) * radius_x, 27+sin(angle) * radius_y, 0);
		}

    }

	glEnd();

}


void drawStar5(float radius_x, float radius_y)
{
	int i = 0;
	float angle = 0.0;
    glColor3f( 1,1,1);
	glBegin(GL_POLYGON);
    {
		for(i = 0; i <360; i++)
		{
			angle = 2 * 3.1416 * i / 180;
			glVertex3f ((-34)+cos(angle) * radius_x, 33+sin(angle) * radius_y, 0);
		}

    }

	glEnd();

}

void drawStar6(float radius_x, float radius_y)
{
	int i = 0;
	float angle = 0.0;
    glColor3f( 1,1,1);
	glBegin(GL_POLYGON);
    {
		for(i = 0; i <360; i++)
		{
			angle = 2 * 3.1416 * i / 180;
			glVertex3f ((-5)+cos(angle) * radius_x, 38+sin(angle) * radius_y, 0);
		}

    }

	glEnd();

}

void drawStar7(float radius_x, float radius_y)
{
	int i = 0;
	float angle = 0.0;
    glColor3f( 1,1,1);
	glBegin(GL_POLYGON);
    {
		for(i = 0; i <360; i++)
		{
			angle = 2 * 3.1416 * i / 180;
			glVertex3f ((-15)+cos(angle) * radius_x, 40+sin(angle) * radius_y, 0);
		}

    }

	glEnd();

}


void drawStar8(float radius_x, float radius_y)
{
	int i = 0;
	float angle = 0.0;
    glColor3f( 1,1,1);
	glBegin(GL_POLYGON);
    {
		for(i = 0; i <360; i++)
		{
			angle = 2 * 3.1416 * i / 180;
			glVertex3f ((5)+cos(angle) * radius_x, 30+sin(angle) * radius_y, 0);
		}

    }

	glEnd();

}

void drawStar9(float radius_x, float radius_y)
{
	int i = 0;
	float angle = 0.0;
    glColor3f( 1,1,1);
	glBegin(GL_POLYGON);
    {
		for(i = 0; i <360; i++)
		{
			angle = 2 * 3.1416 * i / 180;
			glVertex3f ((15)+cos(angle) * radius_x, 22+sin(angle) * radius_y, 0);
		}

    }

	glEnd();

}

void drawStar10(float radius_x, float radius_y)
{
	int i = 0;
	float angle = 0.0;
    glColor3f( 1,1,1);
	glBegin(GL_POLYGON);
    {
		for(i = 0; i <360; i++)
		{
			angle = 2 * 3.1416 * i / 180;
			glVertex3f ((10)+cos(angle) * radius_x, 17+sin(angle) * radius_y, 0);
		}

    }

	glEnd();

}
void drawStar11(float radius_x, float radius_y)
{
	int i = 0;
	float angle = 0.0;
    glColor3f( 1,1,1);
	glBegin(GL_POLYGON);
    {
		for(i = 0; i <360; i++)
		{
			angle = 2 * 3.1416 * i / 180;
			glVertex3f ((7)+cos(angle) * radius_x, 12+sin(angle) * radius_y, 0);
		}

    }

	glEnd();

}

void drawStar12(float radius_x, float radius_y)
{
	int i = 0;
	float angle = 0.0;
    glColor3f( 1,1,1);
	glBegin(GL_POLYGON);
    {
		for(i = 0; i <360; i++)
		{
			angle = 2 * 3.1416 * i / 180;
			glVertex3f ((23)+cos(angle) * radius_x, 33+sin(angle) * radius_y, 0);
		}

    }

	glEnd();

}

void drawStar13(float radius_x, float radius_y)
{
	int i = 0;
	float angle = 0.0;
    glColor3f( 1,1,1);
	glBegin(GL_POLYGON);
    {
		for(i = 0; i <360; i++)
		{
			angle = 2 * 3.1416 * i / 180;
			glVertex3f ((39)+cos(angle) * radius_x, 36+sin(angle) * radius_y, 0);
		}

    }

	glEnd();

}

void drawStar14(float radius_x, float radius_y)
{
	int i = 0;
	float angle = 0.0;
    glColor3f( 1,1,1);
	glBegin(GL_POLYGON);
    {
		for(i = 0; i <360; i++)
		{
			angle = 2 * 3.1416 * i / 180;
			glVertex3f ((20)+cos(angle) * radius_x, 13+sin(angle) * radius_y, 0);
		}

    }

	glEnd();

}


void drawStar15(float radius_x, float radius_y)
{
	int i = 0;
	float angle = 0.0;
    glColor3f( 1,1,1);
	glBegin(GL_POLYGON);
    {
		for(i = 0; i <360; i++)
		{
			angle = 2 * 3.1416 * i / 180;
			glVertex3f ((-40)+cos(angle) * radius_x, 14+sin(angle) * radius_y, 0);
		}

    }

	glEnd();

}

void drawStar16(float radius_x, float radius_y)
{
	int i = 0;
	float angle = 0.0;
    glColor3f( 1,1,1);
	glBegin(GL_POLYGON);
    {
		for(i = 0; i <360; i++)
		{
			angle = 2 * 3.1416 * i / 180;
			glVertex3f ((-30)+cos(angle) * radius_x, 20+sin(angle) * radius_y, 0);
		}

    }

	glEnd();

}

void pointsMany1(int num)
{
    glColor3f(1.0f, 1.0f, 1.0f);
    glPointSize(1.5);
    glBegin(GL_POINTS);
    for(int i = 1;i<num;i++)
    {
        glVertex2f((i*13)%50,(i*20)%50);
        glVertex2f((i*(-13)%50),(i*20)%50);
    }
    glEnd();
}

void pointsMany2(int num)
{
    glColor3f(1.0f, 1.0f, 1.0f);
    glPointSize(3);
    glBegin(GL_POINTS);
    for(int i = 0;i<num;i++)
    {
        glVertex2f((i*13)%50,(i*31)%50);
        glVertex2f((i*(-14)%50),(i*32)%50);
    }
    glEnd();
}

void pointsMany3(int num)
{
    glColor3f(1.0f, 1.0f, 1.0f);
    glPointSize(2);
    glBegin(GL_POINTS);
    for(int i = 0;i<num;i++)
    {
        glVertex2f((i*13)%50,(i*31)%50);
        glVertex2f((i*(-17)%50),(i*35)%50);
    }
    glEnd();
}

///end our project here


void display(){

	//clear the display
    glClearColor(0.184314 ,0.184314,0.309804,0);//mid night blue
	//glClearColor(0,1,0,0);	//color black
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/********************
	/ set-up camera here
	********************/
	//load the correct matrix -- MODEL-VIEW matrix
	glMatrixMode(GL_MODELVIEW);

	//initialize the matrix
	glLoadIdentity();

	//now give three info
	//1. where is the camera (viewer)?
	//2. where is the camera looking?
	//3. Which direction is the camera's UP direction?

	//gluLookAt(100,100,100,	0,0,0,	0,0,1);
	//gluLookAt(200*cos(cameraAngle), 200*sin(cameraAngle), cameraHeight,		0,0,0,		0,0,1);
	gluLookAt(0,0,50,	0,0,0,	0,1,0);


	//again select MODEL-VIEW
	glMatrixMode(GL_MODELVIEW);


	/****************************
	/ Add your objects from here
	****************************/
	//add objects

	//drawAxes();
	//drawGrid();
	//point();
	//pointsMany(100);
	//lines();
	//s_triangle();
	//s_quad();
	//s_poly();


    ///our project starts here

    ///star starts
    drawStar1(.2,.4);
    drawStar2(.2,.4);
    drawStar3(.2,.4);
    drawStar4(.2,.4);
    drawStar5(.2,.4);
    drawStar6(.2,.4);
    drawStar7(.2,.4);
    drawStar8(.2,.4);
    drawStar9(.2,.4);
    drawStar10(.2,.4);
    drawStar11(.2,.4);
    drawStar12(.2,.4);
    drawStar13(.2,.4);
    drawStar14(.2,.4);
    drawStar15(.2,.4);
    drawStar16(.2,.4);



    ///end star


    drawBoxPos_1();
    drawBoxPos_2();
    drawBoxPos_3();
    drawBoxPos_4();
    drawBoxPos_5();
    drawBoxPos_6();
    drawBoxPos_7();
    drawBoxPos_8();
    drawBoxPos_9();
    drawBoxPos_10();
    drawBoxPos_11();
    drawBoxPos_12();
    drawBoxPos_13();
    drawBoxPos_14();
    drawBoxPos_15();
    drawBoxPos_16();
    drawBoxPos_17();
    drawBoxPos_18();
    drawBoxPos_19();
    drawBoxPos_20();
    drawBoxPos_21();
    drawBoxPos_22();
    drawBoxPos_23();
    drawBoxPos_24();
    drawBoxPos_25();
    drawBoxPos_26();
    drawBoxPos_27();
    drawBoxPos_28();
    drawBoxPos_29();
    drawBoxPos_30();
    drawBoxPos_31();
    drawBoxPos_32();
    drawBoxPos_33();
    drawBoxPos_34();
    drawBoxPos_35();
    drawBoxPos_36();
    drawBoxPos_37();
    drawBoxPos_38();
    drawBoxPos_39();


    drawHousePos_1();
    drawHousePos_21();
    drawHousePos_22();
    drawHousePos_3();
    drawHousePos_41();
    drawHousePos_42();
    drawHousePos_5();
    drawHousePos_61();
    drawHousePos_62();
    drawHousePos_71();
    drawHousePos_72();
    drawStandPos_1();
    drawStandPos_2();


    drawBlackBoxPos_1();
    drawBlueBoxPos_1();
    drawCirclePos_1();
    drawCirclePos_2();
    drawCirclePos_3();
    drawCirclePos_4();
    drawCirclePos_5();
    drawCirclePos_6();
    drawCirclePos_7();


    drawMoonPos();

    pointsMany1(200);
    pointsMany2(150);
    pointsMany3(120);


    ///our project ends here;


	//ADD this line in the end --- if you use double buffer (i.e. GL_DOUBLE)
	/*
	Another decision you need to make when setting up the display mode is whether you want to use single buffering (GLUT_SINGLE)
    or double buffering (GLUT_DOUBLE). Applications that use both front and back color buffers are double-buffered. Smooth animation
    is accomplished by rendering into only the back buffer (which isn't displayed), then causing the front and back buffers to be swapped.
    If you aren't using annimation, stick with single buffering, which is the default.
	*/
	glutSwapBuffers();
}


void animate(){
	//angle+=0.05;
	//codes for any changes in Models, Camera
	glutPostRedisplay();
}

void init(){
	//codes for initialization
	//drawgrid=0;
	drawaxes=1;
	//cameraHeight=150.0;
	//cameraAngle=1.0;

	//clear the screen
	glClearColor(0,0,0,0);

	/************************
	/ set-up projection here
	************************/
	//load the PROJECTION matrix
	glMatrixMode(GL_PROJECTION);

	//initialize the matrix
	glLoadIdentity();

	//give PERSPECTIVE parameters
	gluPerspective(80,	1,	1,	1000.0);
	//field of view in the Y (vertically)
	//aspect ratio that determines the field of view in the X direction (horizontally)
	//near distance
	//far distance
}

int main(int argc, char **argv){
	glutInit(&argc,argv);
	glutInitWindowSize(2000, 690);
	glutInitWindowPosition(0, 0);
	/*
	The next thing we need to do is call the glutInitDisplayMode() procedure to specify the display mode for a window. You must first decide whether you want to use an RGBA (GLUT_RGBA) or color-index (GLUT_INDEX) color model.
	The RGBA mode stores its color buffers as red, green, blue, and alpha color components. The forth color component, alpha, corresponds to the notion of opacity. An alpha value of 1.0 implies complete opacity, and an alpha value of 0.0 complete transparancy.
    Color-index mode, in contrast, stores color buffers in indicies. Your decision on color mode should be based on hardware availability and what you application requires. More colors can usually be simultaneously represented with
    RGBA mode than with color-index mode. And for special effects, such as shading, lighting, and fog, RGBA mode provides more flexibility. In general, use RGBA mode whenever possible. RGBA mode is the default.
	*/
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);	//Depth, Double buffer, RGB color

	glutCreateWindow("My OpenGL Program");

	init();

	glEnable(GL_DEPTH_TEST);	//enable Depth Testing

	glutDisplayFunc(display);	//display callback function
	glutIdleFunc(animate);		//what you want to do in the idle time (when no drawing is occuring)



	glutMainLoop();		//The main loop of OpenGL

	return 0;
}

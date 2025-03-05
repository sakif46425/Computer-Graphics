#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <time.h> // For seeding rand()

float motion = -1500.0f; // Start position of car

void drawCircle(float radius, float xc, float yc, float r, float g, float b)//22-49252-3(1)
 {
    glColor3f(r, g, b); // Set color
    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        glVertex2f(x + xc, y + yc);
    }
    glEnd();
}
bool isNight = false;
bool isSnowing = false; // New variable to track snowfall


// Function to change background color
void setSkyColor() //22-49252-3 (2)
 {
    if (isNight) {
        glClearColor(0.0f, 0.0f, 0.2f, 1.0f); // Dark blue for night
    } else {
        glClearColor(0.5f, 0.8f, 1.0f, 1.0f); // Light blue for day
    }
}
void updateSnow(int value);


void keyboard(unsigned char key, int x, int y) {
    if (key == 'N' || key == 'n') {
        isNight = !isNight; // Toggle night/day
        isSnowing = isNight; // Toggle snow along with night
        if (isSnowing) {
            glutTimerFunc(30, updateSnow, 0); // Start snowfall animation
        }
    } else if (key == 'D' || key == 'd') {
        isNight = !isNight; // Toggle night/day
        isSnowing = isNight; // Toggle snow along with day
    }
    setSkyColor();
    glutPostRedisplay();
}
// Function to draw a single snowflake
/*void drawSnow() {
    if (isSnowing) {
        for (int i = 0; i < MAX_SNOWFLAKES; i++) {
            drawCircle(5, snowX[i], snowY[i], 1.0f, 1.0f, 1.0f);
        }
    }
}*/

const int MAX_SNOWFLAKES = 2000; // Increased number of snowflakes
float snowX[MAX_SNOWFLAKES], snowY[MAX_SNOWFLAKES];

void initializeSnow() {
    srand(time(0)); // Seed the random number generator for variation

    for (int i = 0; i < MAX_SNOWFLAKES; i++) {
        snowX[i] = (rand() % 4000) - 2000; // Spread across the screen width
        snowY[i] = (rand() % 2400) - 1200; // Start from above the top (extended)
    }
}


void drawSnow() {
    if (!isSnowing) return;

    glPointSize(2.0); // Adjust snowflake size
    glBegin(GL_POINTS); // Use points for snowflakes (more efficient)
    for (int i = 0; i < MAX_SNOWFLAKES; i++) {
        glColor3f(1.0f, 1.0f, 1.0f); // White snow
        glVertex2f(snowX[i], snowY[i]);
    }
    glEnd();
}
void updateSnow(int value) {
    if (isSnowing) {
        for (int i = 0; i < MAX_SNOWFLAKES; i++) {
            snowY[i] -= 5; // Adjust speed as needed

            if (snowY[i] < -1200) {
                snowY[i] = (rand() % 2400) + 1200; // Random Y at top (extended)
                snowX[i] = (rand() % 4000) - 2000; // Random X
            }
        }

        glutPostRedisplay();
        glutTimerFunc(30, updateSnow, 0); // Adjust timer for smoother animation
    }
}

void Grass() //22-49252-3 (3)
{
    glBegin(GL_QUADS);
    //glColor3f(0.0f, 0.6f, 0.0f); // Green color for grass
    //glColor3ub(128, 250, 97); // Green color for grass
    if (isNight) {
        glColor3ub(51,102,0.0); // Red sun at night
    } else {
         glColor3ub(128,250,97); // Yellow sun during the day
    }
    glVertex2f(-2000, -200);
    glVertex2f(-2000, -1200);
    glVertex2f(2000, -1200);
    glVertex2f(2000, -200);
    glEnd();
}
void Grass1() //22-49252-3 (4)
{
    glBegin(GL_QUADS);
    //glColor3ub(124, 252, 0); // Green color for grass
    if (isNight) {
        glColor3ub(51,102,0.0); // for night
    } else {
         glColor3ub(124, 252, 0); // Yellow sun during the day
    }
    glVertex2f(-2000,500);
    glVertex2f(-2000, 200);
    glVertex2f(2000, 200);
    glVertex2f(2000,500);
    glEnd();
}

void Mountain() //22-49252-3 (5)
{
    glBegin(GL_POLYGON);
    //glColor3ub(48,149,37);
    if (isNight) {
        glColor3ub(102,80,60); // Red sun at night
    } else {
         glColor3ub(48,149,37); // Yellow sun during the day
    }
    glVertex2f(-1924.938193436626, 400.2029251378721); // A
    glVertex2f(-1813.6618406647808, 519.4275888219919); // B
    glVertex2f(-1765.971975191133, 634.6780970499743); // C
    glVertex2f(-1678.5405551561116, 749.9286052779568); // D
    glVertex2f(-1702.3854878929355,547.2466770149532);//E
    glVertex2f(-1654.6956224192877,503.5309669974426);//U
    glVertex2f(-1829.5584624893302,404.1770805940095);//T
    /*glBegin(GL_POLYGON);
    glColor3f(0.8f, 1.0f, 0.89f);
    glVertex2f(-1678.5405551561116,749.9286052779568);//D
    glVertex2f(-1702.3854878929355,547.2466770149532);//E
    glVertex2f(-1654.6956224192877,503.5309669974426);//U
    glVertex2f(-1571.2383578403992,594.9365424886054);//Z*/
    glBegin(GL_POLYGON);
    //glColor3ub(109,225,96);
    if (isNight) {
         glColor3ub(102,80,60);// Red sun at night
    } else {
         glColor3ub(109,225,96); // Yellow sun during the day
    }
    glVertex2f(-1654.6956224192877,503.5309669974426);//U
    glVertex2f(-1571.2383578403992,594.9365424886054);//Z
    glVertex2f(-1440.0912277878717,718.1353616288582);//F
    glVertex2f(-1352.6598077528504,765.8252271025061);//G
    glVertex2f(-1340.7373413844384,837.360025312978);//H
    glVertex2f (-1177.7969676828077,972.4813108216471);//I
    glVertex2f(-1200,800);//J
    glVertex2f(-1200,600);//K
    glVertex2f(-1102.2880140161985,598.9106979447384);//L
    glVertex2f(-1050.623993086413,431.9961687869707);//M
    glVertex2f(-1229.4609886125932,439.9444796992454);//W
    glVertex2f(-1467.910315980833,523.4017442781292);//V
    glBegin(GL_POLYGON);
    //glColor3ub(109,225,96);
    if (isNight) {
         glColor3ub(102,80,60); // Red sun at night
    } else {
        glColor3ub(109,225,96); // Yellow sun during the day
    }
    glVertex2f (-1177.7969676828077,972.4813108216471);//I
    glVertex2f(-1200,800);//J
    glVertex2f(-1200,600);//K
    glVertex2f(-1102.2880140161985,598.9106979447384);//L
    glVertex2f(-1050.623993086413,431.9961687869707);//M
    glVertex2f(-907.5543966654692,428.0220133308334);//N
    glVertex2f(-816.1488211743106,563.1432988395024);//O
    glVertex2f(-732.6915565954266,666.4713406990729);//S
    glVertex2f(-947.2959512268425,912.8689789795872);//R
    glBegin(GL_POLYGON);
    //glColor3ub(121,240,108);
    if (isNight) {
 glColor3ub(102,80,60); // Red sun at night
    } else {
       glColor3ub(121,240,108); // Yellow sun during the day
    }
    glVertex2f(-907.5543966654692,428.0220133308334);//N
    glVertex2f(-816.1488211743106,563.1432988395024);//O
    glVertex2f(-732.6915565954266,666.4713406990729);//S
    glVertex2f(-669.1050692972293,682.3679625236223);//P
    glVertex2f(-255.7929018589467,408.1512360501467);//Q
    glBegin(GL_POLYGON);
    //glColor3f(137, 239, 126);
    if (isNight) {
         glColor3ub(102,80,60); // Red sun at night
    } else {
       glColor3f(137, 239, 126);  // Yellow sun during the day
    }
    glVertex2f(-1829.5584624893302,404.1770805940095);//T
    glVertex2f(-1654.6956224192877,503.5309669974426);//U
    glVertex2f(-1467.910315980833,523.4017442781292);//V
    glVertex2f(-1229.4609886125932,439.9444796992454);//W
    glVertex2f(-1050.623993086413,431.9961687869707);//M
    glVertex2f(-907.5543966654692,428.0220133308334);//N
    glVertex2f(-740.6398675076945,412.1253915062884);//A1
    glEnd();
}

void Leaf() //22-49252-3 (6)
{
    glBegin(GL_TRIANGLES);
    glColor3f(0.0,0.6,0.2);
    glVertex2f(0,1000);
    glVertex2f(-200,800);
    glVertex2f(200,800);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0,0.8,0.4);
    glVertex2f(-136.4581035254357,800);
    glVertex2f(-279.637834595763,638.6522525061159);
    glVertex2f(272.7697738073261,642.6264079622533);
    glVertex2f(121.7518664741075,800);
    glEnd();

//3rd leaf
    glBegin(GL_QUADS);
    glColor3f(0.0,1.0,0.5);
    glVertex2f(-160.4193413217292,639.5099395080874);//I1
    glVertex2f(-283.4204827352345,492.828326609662);//j1
    glVertex2f(271.7917266007077,496.7800149323378);//L1
    glVertex2f(159.2005228328263,641.8093629912138);//K1
    glEnd();
}
void Tree() //22-49252-3 (7)
{
    glBegin(GL_QUADS);
    glColor3f(0.4,0.2,0.0);
    glVertex2f(-79.2018237138391,494.281840197003);//M1
    glVertex2f(-75.9568457947579,208.3067673770099);//N1
    glVertex2f(79.6028684471956,203.3181250177116);//P1
    glVertex2f(79.5967864186112,495.4120794150257);//O1

    glEnd();
}

void Road()  //22-49252-3 (8)
{
    glBegin(GL_QUADS);
   //glColor3ub(169,169,169);
    if (isNight) {
         glColor3ub(64,64,64); // Red sun at night
    } else {
       glColor3f(169,169,169);  // Yellow sun during the day
    }
    glVertex2f(-2000, 200);
    glVertex2f(-2000, -200);
    glVertex2f(2000, -200);
    glVertex2f(2000, 200);
    glEnd();
}

void Roadmarking() //22-49252-3 (9)
{
    glLineWidth(3.5);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 0.0);
    for (int i = -2000; i <= 2000; i += 400) {
        glVertex2f(i, 0.0);
        glVertex2f(i + 200, 0.0);
    }
    glEnd();
}

void Roadsidemarking() //22-49252-3 (10)
{
    glLineWidth(5.5);
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(-2000, 200);
    glVertex2f(2000, 200);
    glVertex2f(-2000, -200);
    glVertex2f(2000, -200);
    glEnd();
}

void Car()  //22-49252-3 (11)
{
    glPushMatrix();
    glTranslatef(motion, 0, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-2000, 119.44);
    glVertex2f(-1898.91, 120.78);
    glVertex2f(-1799.39, 159.78);
    glVertex2f(-1600.35, 159.78);
    glVertex2f(-1499.48, 120.78);
    glVertex2f(-1299.10, 119.44);
    glVertex2f(-1299.10, 42.78);
    glVertex2f(-1498.14, 38.74);
    glVertex2f(-1541.68, 38.92);
    glVertex2f(-1855.70, 41.43);
    glVertex2f(-2000, 40.09);
    glEnd();

    drawCircle(50, -1855.70, 20, 0, 0, 0);
    drawCircle(30, -1855.70, 20, 1, 1, 1);
    drawCircle(50, -1541.68, 20, 0, 0, 0);
    drawCircle(30, -1541.68, 20, 1, 1, 1);

    glPopMatrix();
}

void update(int value) //22-49252-3 (1)
{
    motion += 10.0f;
    if (motion > 4000.0f) {
        motion = -2000.0f;
    }
    glutPostRedisplay();
    glutTimerFunc(15, update, 0);
}
void Bulding() //22-49252-3 (12)
{
    //Left corner
    glBegin(GL_POLYGON);
    glColor3f(0.57,0.38,0.27);
    glVertex2f(599.9767413592405,640.2046351666261);//E3
    glVertex2f(499.1320865423542,580.5653231781454);//G3
    glVertex2f(539.2530782436961,579.4809720510821);//J3
    glEnd();
    //Chal
    glBegin(GL_POLYGON);
    glColor3f(0.48,0.30,0.20);
    glVertex2f(599.9767413592405,640.2046351666261);//E3
    glVertex2f(680.2187247619242,561.0470028910063);//H3
    glVertex2f(922.0290260970388,561.0470028910063);//I3
    glVertex2f(822.2687224072158,641.2889862936894);//F3
    glEnd();
    //Left side
    glBegin(GL_POLYGON);
    glColor3f(0.49,0.76,0.36);
    glVertex2f(599.9767413592405,640.2046351666261);//E3
    glVertex2f(539.2530782436961,579.4809720510821);//j3
    glVertex2f(539.2530782436961,439.5996766599183);//K3
    glVertex2f(678.0500225077977,420.0813563727792);//L3
    glVertex2f(680.2187247619242,561.0470028910063);//H3
    glEnd();
    //front side
    glBegin(GL_POLYGON);
    glColor3f(0.58,0.60,0.64);
    glVertex2f(680.2187247619242,561.0470028910063);//H3
    glVertex2f(678.0500225077977,420.0813563727792);//L3
    glVertex2f(919.8603238429122,433.0935698975386);//M3
    glVertex2f(922.0290260970388,561.0470028910063);//I3
    glEnd();
    //janala
    glBegin(GL_POLYGON);
    glColor3f(0.77,0.86,0.31);
    glVertex2f(579.330150798918,540.700958527913);//Q3
    glVertex2f(577.848897978669,508.8540228925593);//S3
    glVertex2f(615.620844895019,508.1133964824348);//T3
    glVertex2f(617.8427241253926,537.738452887415);//R3
    glEnd();
    //Door
    glBegin(GL_POLYGON);
    glColor3f(0.19,0.37,0.17);
    glVertex2f(770.4117646110416,499.9665059710653);//U3
    glVertex2f(774.1809481598998,425.2543209818608);//V3
    glVertex2f(810.4550680293986,427.206291557798);//Z3
    glVertex2f(809.6649643476405,500.7071323811898);//W3
    glEnd();
    //left pira
    glBegin(GL_POLYGON);
    glColor3f(0.2,0.0,0.0);
    glVertex2f(539.2530782436961,439.5996766599183);//K3
    glVertex2f(539.2530782436961,420.0813563727792);//N3
    glVertex2f(678.0500225077977,400.5630360856401);//O3
    glVertex2f(678.0500225077977,420.0813563727792);//L3
    glEnd();

    //front pira
    glBegin(GL_POLYGON);
    glColor3f(0.2,0.0,0.0);
    glVertex2f(678.0500225077977,420.0813563727792);//L3
    glVertex2f(678.0500225077977,400.5630360856401);//O3
    glVertex2f(919.8603238429122,411.4065473562729);//P3
    glVertex2f(919.8603238429122,433.0935698975386);//M3
    glEnd();

}
void Wood() //22-49252-3 (13)
{
    glBegin(GL_POLYGON);
    glColor3ub(80,16,18);
    glVertex2f(-1706.7985540149004,-986.4832774047668);//B4
    glVertex2f(-1824.3109746773243,-984.6471458319164);//C4
    glVertex2f(-1839.0000272601274,-1037.8949614445776);//D4
    glVertex2f(-1805.9496589488215,-1081.9621191929866);//E4
    glVertex2f(-1765.5547643461132,-1076.4537244744356);//F4
    glVertex2f(-1732.5043960348064,-1030.550435153176);//G4
    glVertex2f(-1677.420448849295,-1021.3697772889241);//H4
    //glVertex2f;
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(80,16,18);
    glVertex2f(-1677.420448849295,-1021.3697772889241);//H4
    glVertex2f(-1732.5043960348064,-1030.550435153176);//G4
    glVertex2f(-1765.5547643461132,-1076.4537244744356);//F4
    glVertex2f(-1736.1766591805072,-1109.5040927857424);//I4
    glVertex2f(-1673.7481857035943,-1113.1763559314431);//J4
    glVertex2f(-1614.9919753723825,-1063.6008034644829);//K4
    //glVertex2f;
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(80,16,18);
    glVertex2f(-1614.9919753723825,-1063.6008034644829);//K4
    glVertex2f(-1609.4835806538313,-1115.0124875042936);//L4
    glVertex2f(-1572.7609491968237,-1135.2099348056477);//M4
    glVertex2f(-1508.4963441470607,-1127.8654085142462);//N4
    glVertex2f(-1482.7905021271554,-1089.3066454843881);//O4
    glVertex2f(-1493.8072915642576,-1054.4201456002309);//P4
    glVertex2f(-1537.8744493126667,-1032.3865667260263);//Q4
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(80,16,18);
    glVertex2f(-1614.9919753723825,-1063.6008034644829);//K4
    glVertex2f(-1556.2357650411705,-1054.4201456002309);//R4
    glVertex2f(-1493.8072915642576,-1054.4201456002309);//P4
    glVertex2f(-1537.8744493126667,-1032.3865667260263);//Q4
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(80,16,18);
    glVertex2f(-1493.8072915642576,-1054.4201456002309);//P4
    glVertex2f(-1482.7905021271554,-1089.3066454843881);//O4
    glVertex2f(-1413.017502358841,-1113.1763559314431);//S4
    glVertex2f(-1350.5890288819282,-1109.5040927857424);//T4
    glVertex2f(-1323.0470552891727,-1078.2898560472859);//U4
    glVertex2f(-1328.5554500077237,-1041.5672245902783);//V4
    glVertex2f(-1365.2780814647313,-1039.7310930174278);//W4
    glVertex2f(-1405.6729760674395,-1026.878172007475);//Z4
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(80,16,18);
    glVertex2f(-1405.6729760674395,-1026.878172007475);//Z4
    glVertex2f(-1295.505081696417,-1047.0756193088293);//A5
    glVertex2f(-1286.3244238321652,-1081.9621191929866);//B5
    glVertex2f(-1262.4547133851104,-1052.5840140273806);//C5
    glVertex2f(-1264.2908449579606,-993.8278036961683);//D5
    glVertex2f(-1367.1142130375817,-997.500066841869);//E5
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(252,64,71);
    glVertex2f(-1706.7985540149004,-986.4832774047668);//B4
    glVertex2f(-1677.420448849295,-1021.3697772889241);//H4
    glVertex2f(-1614.9919753723825,-1063.6008034644829);//K4
    glVertex2f(-1537.8744493126667,-1030.550435153176);//Q4
    glVertex2f(-1493.8072915642576,-1054.4201456002309);//P4
    glVertex2f(-1405.6729760674395,-1026.878172007475);//Z4
    glVertex2f(-1367.1142130375817,-997.500066841869);//E5
    glVertex2f(-1354.2612920276292,-951.5967775206095);//F5
    glVertex2f(-1359.7696867461802,-898.3489619079485);//G5
    glVertex2f(-1394.6561866303375,-843.265014722437);//H5
    glVertex2f(-1411.1813707859908,-766.1474886627209);//I5
    glVertex2f(-1436.887212805896,-843.265014722437);//J5
    glVertex2f(-1453.4123969615493,-795.525593828327);//K5
    glVertex2f(-1442.395607524447,-740.4416466428155);//L5
    glVertex2f(-1446.0678706701478,-690.8660941758552);//M5
    glVertex2f(-1473.6098442629036,-643.1266732817453);//N5
    glVertex2f(-1477.2821074086044,-696.3744888944063);//O5
    glVertex2f(-1491.9711599914074,-736.7693834971147);//P5
    glVertex2f(-1501.1518178556591,-678.0131731659026);//Q5
    glVertex2f(-1514.004738865612,-633.9460154174933);//R5
    glVertex2f(-1504.82408100136,-578.8620682319819);//S5
    glVertex2f(-1528.693791448415,-510.9252000365177);//T5
    glVertex2f(-1530.5299230212652,-562.3368840763285);//U5
    glVertex2f(-1554.39963346832,-633.9460154174933);//V5
    glVertex2f(-1558.0718966140207,-556.8284893577772);//W5
    glVertex2f(-1596.6306596438787,-624.7653575532414);//Z5
    glVertex2f(-1603.9751859352803,-670.668646874501);//A6
    glVertex2f(-1603.9751859352803,-720.2441993414614);//B6
    glVertex2f(-1622.336501663784,-747.7861729342171);//C6
    glVertex2f(-1631.5171595280358,-707.3912783315086);//D6
    glVertex2f(-1648.0423436836893,-666.9963837288002);//E6
    glVertex2f(-1644.3700805379885,-619.2569628346903);//F6
    glVertex2f(-1668.2397909850433,-687.1938310301545);//G6
    glVertex2f(-1664.5675278393426,-736.7693834971147);//H6
    glVertex2f(-1660.8952646936418,-788.1810675369255);//I6
    glVertex2f(-1675.5843172764448,-834.0843568581851);//J6
    glVertex2f(-1700,-800);//K6
    glVertex2f(-1703.1262908692004,-835.9204884310354);//L6
    glVertex2f(-1719.6514750248539,-872.6431198880431);//M6
    glVertex2f(-1721.4876065977041,-931.3993302192553);//N6
    glEnd();
}
void drawSun() //22-49252-3 (14)
{
    if (isNight) {
        drawCircle(150, 1500, 900, 1.0, 1.0, 1.0); // Red sun at night
    } else {
        drawCircle(150, 1500, 900, 1.0, 1.0, 0.0); // Yellow sun during the day
    }
}
void Laftside()  //22-49252-3 (15)
{
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(129.4325555435912,363.5193328942221);//w6
    glVertex2f(127.277924683114,304.6260893745122);//A7
    glVertex2f(136.6146584118485,303.9078790876864);//B7
    glVertex2f(139.4874995591514,362.8011226073963);//Z6
    glEnd();
}
void Laftside1()  //22-49252-3 (16)
{
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(118.6594012412056,290.2618836379975);//L7
    glVertex2f(118.6594012412053,237.1143224128934);//N7
    glVertex2f(130.8689761172427,237.1143224128934);//M7
    glVertex2f(130.1507658304173,290.2618836379975);//K7
    glEnd();
}
void middleside()  //22-49252-3 (17)
{
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(241.4733602884045,363.5193328942221);//C7
    glVertex2f(241.4733602884045,306.7807202349894);//e7
    glVertex2f(250.0918837303132,306.7807202349894);//F7
    glVertex2f(252.2465145907904,363.5193328942221);//D7
    glEnd();
}

void middleside1()  //22-49252-3 (18)
{
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(240.036939714753,290.9800939248233);//P7
    glVertex2f(241.4733602884045,237.1143224128934);//R7
    glVertex2f(255.1193557380933,236.3961121260677);//Q7
    glVertex2f(255.837566024919,289.5436733511718);//O7
    glEnd();
}
void Rightside() //22-49252-3 (19)
 {
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(351.3595341727406,363.5193328942221);//G7
    glVertex2f(356.3870061805206,306.0625099481636);//J7
    glVertex2f(365.0055296224293,306.0625099481636);//I7
    glVertex2f(363.5691090487779,363.5193328942221);//H7
    glEnd();
}
void Rightside1()  //22-49252-3 (20)
{
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(364.2873193356036,291.698304211649);//T7
    glVertex2f(362.1326884751264,238.5507429865449);//V7
    glVertex2f(375.7786839248152,237.1143224128934);//U7
    glVertex2f(378.6515250721181,291.698304211649);//S7
    glEnd();
}
void Bench() //22-49252-3 (21)
{
    glBegin(GL_QUADS);
    glColor3ub(204,0.0,0.0);
    glVertex2f(114.3501395202513,361.3647020337449);//W7
    glVertex2f(113.6319292334255,346.2822860104046);//A8
    glVertex2f(377.9333147852933,346.2822860104046);//B8
    glVertex2f(377.9333147852933,362.0829123205706);//z7;
    glEnd();
}
void Bench2() //22-49252-3 (22)
{
    glBegin(GL_QUADS);
    glColor3ub(204,0.0,0.0);
    glVertex2f(115.068349807077,339.1001831421472);//C8
    glVertex2f(114.3501395202513,324.7359774056326);//E8
    glVertex2f(377.2151044984676,324.0177671188069);//f8
    glVertex2f(376.4968942116418,340.5366037157987);//D8
    glEnd();
}
void Bench3() //22-49252-3 (23)
{
    glBegin(GL_QUADS);
    glColor3ub(204,0.0,0.0);
    glVertex2f(113.6319292334256,305.3442996613379);//G8
    glVertex2f(100.7041440705625,293.1347247853005);//I8
    glVertex2f(392.2975205218078,295.2893556457777);//j8
    glVertex2f(375.7786839248161,306.0625099481636);//H8
    glEnd();
}






void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    setSkyColor(); // Set the sky color based on day/night



    Grass1();
    Mountain();
    Bulding();
    Leaf();
    Tree();
    Road();
    Roadmarking();
    Roadsidemarking();
    Car();

    Grass();
       Wood();
       drawSun();
       Bench();
       Laftside();
       Laftside1();
       middleside();
       middleside1() ;
       Rightside();
       Rightside1();
       Bench();
        Bench2();
        Bench3();
    if (isSnowing) {
        drawSnow();
    }

     glutSwapBuffers();
};

void init() {
glClearColor(0.6f, 0.85f, 1.0f, 1.0f); // Brighter blue

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-2000, 2000, -1200, 1200);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // Use double buffering
    glutInitWindowSize(1200, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Mountain Scene");

    initializeSnow(); // Initialize snow positions

    //glClearColor(0.6f, 0.85f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-2000, 2000, -1200, 1200);

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(10, update, 0); // Car animation
    glutTimerFunc(30, updateSnow, 0); // Snow animation

    glutMainLoop();
    return 0;
}

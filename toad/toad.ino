#include <TVout.h>
#include <Keypad.h>


const byte ROWS = 4;
const byte COLS = 7;

char hexaKeys[ROWS][COLS] = {
  {'0','1','2','3','4','5','6'},
  {'7','8','9','A','B','C','D'},
  {'E','F','G','H','I','J','K'},
  {'L','M','N','O','P','Q','R'}
};

byte rowPins[ROWS] = {53, 51, 49, 47};
byte colPins[COLS] = {45, 43, 41, 39, 37, 35, 33};
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

//double* x_rot( double x, double y, double z, double a){
//   double* s = (double*) malloc(3 * sizeof(double));
//   s[0] = x;
//   s[1] = y*cos(a)+z*sin(a);
//   s[2] = -y*sin(a)+z*cos(a);
//   return s;
//}

void x_rot( double* p, double a, double* nwpt){
   nwpt[0] = p[0];
   nwpt[1] = p[1]*cos(a) + p[2]*sin(a);
   nwpt[2] = -p[1]*sin(a) + p[2]*cos(a);
}

void y_rot( double* p, double a, double* nwpt ){
   nwpt[0] = p[0]*cos(a)+p[2]*sin(a);
   nwpt[1] = p[1];
   nwpt[2] = -p[0]*sin(a)+p[2]*cos(a);
}
void z_rot( double* p, double a, double* nwpt ){
   nwpt[0] =  p[0]*cos(a)+p[1]*sin(a);
   nwpt[1] = -p[0]*sin(a)+p[1]*cos(a);
   nwpt[2] = p[2];
}

//double* y_rot( double x, double y, double z, double a){
//   double s[] = { x*cos(a)+z*sin(a), y, -x*sin(a)+z*cos(a)};
//  return s;
//}
//
//double* z_rot( double x, double y, double z, double a){
//  double s[] = { x*cos(a)+y*sin(a), -x*sin(a)+y*cos(a), z};
//  return s;
//}


//static double* x_rot( double x, double x,  double a){
//   double s[] = { 
//    p[0],
//    (p[1]*cos(a)) + (p[2]*sin(a)),
//    (-p[1]*sin(a)) + (p[2]*cos(a))
//    };
//   return s;
//}

//double* y_rot( double p[3], double a){
//   double s[] = { 
//    p[0]*cos(a)+p[2]*sin(a),
//    p[1],
//    -p[0]*sin(a)+p[2]*cos(a)
//    };
//  return s;
//}
//
//double* z_rot( double p[3], double a){
//  double s[] = { 
//    p[0]*cos(a)+p[1]*sin(a),
//    -p[0]*sin(a)+p[1]*cos(a),
//    p[2]
//    };
//  return s;
//}


int w = 800;
int h = 60;
TVout TV;

//void set_pixel(int x, int y){
//  TV.set_pixel(x, y + 10 ,0x60 );
//}

void setup() {TV.begin(_NTSC,128,96);
Serial.begin(9600);}


// crt origin is 0, 10
// crt bottom right is is 105, 70
//full range (0,0) -> (104,60)


double vert[229][3] = {
  {0.0071, 0.003, -0.0335},
{-0.0526, 0.0309, -0.0437},
{-0.0109, 0.0312, -0.0297},
{-0.0521, 0.0003, -0.0525},
{-0.1133, -0.0068, 0.0386},
{-0.0626, 0.0438, 0.0413},
{-0.0984, 0.0281, 0.0358},
{-0.0689, 0.0299, 0.076},
{-0.0304, 0.031, 0.0585},
{-0.0178, -0.0037, 0.0705},
{-0.0767, -0.0056, 0.0923},
{-0.018, 0.0401, 0.0364},
{-0.0623, 0.0776, 0.0311},
{-0.0664, 0.0398, 0.0371},
{-0.0746, 0.0769, -0.0091},
{-0.0803, 0.0348, -0.0105},
{-0.0204, 0.0774, 0.0317},
{-0.042, 0.0243, 0.0033},
{-0.002, 0.0337, -0.0102},
{-0.008, 0.0767, -0.0084},
{-0.0409, 0.0321, -0.044},
{-0.0412, 0.0758, -0.0339},
{-0.0648, 0.1406, -0.0061},
{-0.0623, 0.0776, 0.0311},
{-0.0552, 0.1413, 0.0225},
{-0.0204, 0.0774, 0.0317},
{-0.0262, 0.141, 0.0225},
{-0.0407, 0.1569, 0.0014},
{-0.0176, 0.1409, -0.0057},
{-0.0408, 0.1404, -0.0241},
{-0.0412, 0.0758, -0.0339},
{-0.0746, 0.0769, -0.0091},
{-0.008, 0.0767, -0.0084},
{0.0181, -0.0064, 0.0711},
{0.0128, 0.0306, -0.0285},
{-0.0035, 0.001, -0.0337},
{0.0565, 0.0026, -0.0507},
{0.0613, 0.0441, 0.0446},
{0.055, 0.0313, -0.0411},
{0.0297, 0.0287, 0.0601},
{0.0669, 0.0293, 0.0792},
{0.0977, 0.0309, 0.04},
{0.115, -0.0038, 0.0424},
{0.0755, -0.0054, 0.0951},
{0.0039, 0.0336, -0.0087},
{0.0199, 0.0407, 0.0377},
{0.0224, 0.0768, 0.0314},
{0.01, 0.0767, -0.0087},
{0.0681, 0.0415, 0.0375},
{0.0644, 0.077, 0.031},
{0.0438, 0.0245, 0.0049},
{0.0767, 0.0767, -0.0092},
{0.0431, 0.0303, -0.0434},
{0.0432, 0.0764, -0.0341},
{0.0823, 0.0336, -0.0088},
{0.01, 0.0767, -0.0087},
{0.0282, 0.1414, 0.0224},
{0.0197, 0.1409, -0.0058},
{0.0224, 0.0768, 0.0314},
{0.0429, 0.1559, 0.0011},
{0.0572, 0.1417, 0.0224},
{0.0644, 0.077, 0.031},
{0.043, 0.14, -0.0241},
{0.0669, 0.1404, -0.0061},
{0.0432, 0.0764, -0.0341},
{0.0767, 0.0767, -0.0092},
{-0.1107, 0.1711, 0.0372},
{-0.0794, 0.1833, -0.0126},
{-0.1263, 0.1697, -0.0037},
{-0.1151, 0.1553, 0.0193},
{-0.061, 0.1681, 0.0296},
{-0.0869, 0.153, 0.0295},
{-0.1129, 0.154, -0.0138},
{-0.0607, 0.1236, 0.0715},
{-0.1507, 0.119, 0.0409},
{-0.0526, 0.1627, -0.0165},
{-0.0986, 0.1614, -0.0374},
{-0.0657, 0.1512, 0.0032},
{-0.1031, 0.0815, 0.029},
{-0.0785, 0.1062, -0.0398},
{-0.0811, 0.151, -0.0205},
{-0.1407, 0.1066, -0.0282},
{-0.0725, 0.1914, -0.0252},
{-0.102, 0.1644, -0.0001},
{-0.0911, 0.2034, -0.0003},
{-0.074, 0.1929, 0.0264},
{-0.0724, 0.1542, 0.001},
{-0.055, 0.1868, 0.0011},
{-0.0876, 0.158, 0.0183},
{-0.0871, 0.1573, -0.0173},
{-0.074, 0.1929, 0.0264},
{-0.0526, 0.229, 0.0186},
{-0.0626, 0.242, -0.0007},
{-0.0911, 0.2034, -0.0003},
{-0.0428, 0.2388, -0.0},
{-0.0512, 0.2274, -0.0178},
{-0.043, 0.2153, 0.0001},
{-0.0725, 0.1914, -0.0252},
{-0.055, 0.1868, 0.0011},
{0.001, 0.2618, -0.0503},
{-0.0442, 0.2618, -0.0322},
{-0.0454, 0.2527, -0.0797},
{-0.042, 0.3048, -0.0582},
{0.001, 0.307, -0.0571},
{-0.051, 0.2618, -0.0005},
{-0.0782, 0.2946, -0.0005},
{-0.0294, 0.3194, -0.0605},
{0.0463, 0.2527, -0.0797},
{0.0452, 0.2618, -0.0322},
{-0.085, 0.3637, -0.0005},
{0.0429, 0.3048, -0.0582},
{0.0305, 0.3194, -0.0605},
{0.0848, 0.3637, -0.0005},
{0.0792, 0.2946, -0.0005},
{0.0519, 0.2618, -0.0005},
{-0.0895, 0.3184, -0.0107},
{-0.0782, 0.3411, -0.0186},
{-0.0714, 0.2957, 0.0187},
{-0.1065, 0.3501, -0.0164},
{-0.0748, 0.3637, 0.0211},
{-0.0238, 0.2822, 0.1229},
{0.0, 0.307, 0.0221},
{0.0248, 0.2822, 0.1229},
{-0.0363, 0.3172, 0.1229},
{0.0, 0.3093, 0.1353},
{0.0, 0.3387, 0.1229},
{0.0384, 0.3172, 0.1229},
{0.0905, 0.3184, -0.0107},
{0.0792, 0.3411, -0.0186},
{0.1075, 0.3501, -0.0164},
{0.0713, 0.2957, 0.0187},
{0.0758, 0.3637, 0.0211},
{0.0384, 0.3795, -0.0945},
{-0.0294, 0.3194, -0.0605},
{-0.0375, 0.3795, -0.0945},
{-0.085, 0.3637, -0.0005},
{0.0305, 0.3194, -0.0605},
{-0.1121, 0.4247, -0.0005},
{-0.0601, 0.3976, 0.0583},
{0.0848, 0.3637, -0.0005},
{0.0, 0.4904, 0.0324},
{-0.0759, 0.4497, 0.073},
{0.0, 0.4713, 0.1093},
{0.1131, 0.4247, -0.0005},
{0.0769, 0.4497, 0.073},
{0.06, 0.3976, 0.0583},
{0.0, 0.4112, 0.0981},
{0.0554, 0.3953, 0.0958},
{-0.0544, 0.3953, 0.0958},
{0.0, 0.3919, 0.1377},
{0.0, 0.4032, 0.0787},
{-0.0601, 0.3976, 0.0583},
{0.0, 0.4112, 0.0981},
{0.0, 0.4713, 0.1093},
{-0.0759, 0.4497, 0.073},
{0.06, 0.3976, 0.0583},
{0.0769, 0.4497, 0.073},
{0.001, 0.2618, -0.0503},
{0.0452, 0.2618, -0.0322},
{0.001, 0.2425, 0.0561},
{-0.0442, 0.2618, -0.0322},
{-0.051, 0.2618, -0.0005},
{-0.0409, 0.2731, 0.0652},
{0.001, 0.2867, 0.0843},
{0.0418, 0.2731, 0.0652},
{0.0792, 0.2946, -0.0005},
{0.0519, 0.2618, -0.0005},
{0.0, 0.324, 0.089},
{-0.059, 0.3172, 0.0527},
{0.06, 0.3172, 0.0527},
{0.0, 0.4032, 0.0787},
{-0.0601, 0.3976, 0.0583},
{-0.085, 0.3637, -0.0005},
{-0.0782, 0.2946, -0.0005},
{0.0848, 0.3637, -0.0005},
{0.06, 0.3976, 0.0583},
{0.0546, 0.1628, -0.0164},
{0.0677, 0.1512, 0.0032},
{0.0889, 0.1528, 0.0295},
{0.0627, 0.1231, 0.0713},
{0.1128, 0.1708, 0.0372},
{0.0625, 0.1689, 0.0298},
{0.0814, 0.1834, -0.0124},
{0.0803, 0.1064, -0.0401},
{0.1529, 0.1185, 0.0416},
{0.0831, 0.1512, -0.0205},
{0.1171, 0.1551, 0.0192},
{0.105, 0.0813, 0.0295},
{0.1005, 0.1616, -0.0374},
{0.1282, 0.1696, -0.0036},
{0.1149, 0.154, -0.014},
{0.1425, 0.1067, -0.0288},
{0.0743, 0.1542, 0.0011},
{0.0897, 0.1577, 0.0183},
{0.0762, 0.192, 0.0256},
{0.0569, 0.1867, 0.0003},
{0.1039, 0.1643, -0.0001},
{0.0932, 0.2032, -0.0},
{0.0747, 0.1912, -0.025},
{0.089, 0.1574, -0.0173},
{0.0449, 0.2153, 0.0002},
{0.0762, 0.192, 0.0256},
{0.055, 0.2281, 0.0186},
{0.0569, 0.1867, 0.0003},
{0.0932, 0.2032, -0.0},
{0.0647, 0.242, -0.0007},
{0.0448, 0.2388, -0.0001},
{0.0532, 0.2273, -0.0178},
{0.0747, 0.1912, -0.025},
{0.0253, 0.109, -0.0388},
{0.0, 0.0854, 0.0013},
{-0.0244, 0.109, -0.0388},
{-0.0498, 0.109, 0.0013},
{-0.0313, 0.2006, -0.0485},
{-0.0635, 0.2006, 0.0013},
{-0.0244, 0.109, 0.0471},
{0.0253, 0.109, 0.0471},
{0.0498, 0.109, 0.0013},
{-0.0224, 0.2006, 0.0608},
{-0.0469, 0.2425, 0.0013},
{0.0644, 0.2006, 0.0013},
{-0.0234, 0.2425, -0.0418},
{0.0233, 0.2006, 0.0608},
{0.0, 0.2826, -0.0036},
{-0.0234, 0.2425, 0.0442},
{0.0469, 0.2425, 0.0013},
{0.0233, 0.2425, 0.0442},
{0.0321, 0.2006, -0.0485},
{0.0233, 0.2425, -0.0418},
};


int vert_2d[229][2] = {
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},

};

int edge[526][2] = {
  {0, 1},
{1, 2},
{2, 0},
{0, 3},
{3, 1},
{4, 1},
{3, 4},
{5, 2},
{1, 5},
{4, 6},
{6, 1},
{6, 5},
{6, 7},
{7, 5},
{5, 8},
{8, 2},
{7, 8},
{2, 9},
{9, 0},
{10, 8},
{7, 10},
{8, 9},
{4, 10},
{10, 6},
{10, 9},
{9, 3},
{4, 9},
{11, 12},
{12, 13},
{13, 11},
{14, 13},
{12, 14},
{14, 15},
{15, 13},
{11, 16},
{16, 12},
{13, 17},
{17, 11},
{15, 17},
{16, 18},
{18, 19},
{19, 16},
{11, 18},
{17, 18},
{19, 20},
{20, 21},
{21, 19},
{17, 20},
{20, 18},
{14, 20},
{20, 15},
{14, 21},
{22, 23},
{23, 24},
{24, 22},
{25, 24},
{23, 25},
{26, 27},
{27, 24},
{24, 26},
{27, 22},
{28, 27},
{26, 28},
{27, 29},
{29, 22},
{28, 29},
{25, 26},
{28, 30},
{30, 29},
{22, 31},
{31, 23},
{26, 32},
{32, 28},
{32, 30},
{30, 22},
{25, 32},
{30, 31},
{33, 34},
{34, 35},
{35, 33},
{36, 35},
{34, 36},
{34, 37},
{37, 38},
{38, 34},
{38, 36},
{33, 39},
{39, 34},
{39, 37},
{40, 37},
{39, 40},
{37, 41},
{41, 38},
{38, 42},
{42, 36},
{33, 40},
{41, 42},
{40, 41},
{40, 43},
{43, 42},
{42, 40},
{33, 43},
{36, 33},
{33, 42},
{44, 45},
{45, 46},
{46, 44},
{46, 47},
{47, 44},
{48, 49},
{49, 46},
{46, 48},
{45, 48},
{50, 48},
{45, 50},
{44, 50},
{48, 51},
{51, 49},
{47, 52},
{52, 44},
{52, 50},
{47, 53},
{53, 52},
{48, 54},
{54, 51},
{50, 54},
{53, 54},
{54, 52},
{53, 51},
{55, 56},
{56, 57},
{57, 55},
{55, 58},
{58, 56},
{59, 56},
{56, 60},
{60, 59},
{59, 57},
{61, 60},
{56, 61},
{59, 62},
{62, 57},
{59, 63},
{63, 62},
{58, 61},
{57, 64},
{64, 55},
{62, 64},
{62, 65},
{65, 64},
{63, 65},
{60, 63},
{61, 65},
{63, 61},
{66, 67},
{67, 68},
{68, 66},
{68, 69},
{69, 66},
{70, 67},
{66, 70},
{71, 66},
{69, 71},
{68, 72},
{72, 69},
{71, 70},
{73, 69},
{69, 74},
{74, 73},
{73, 71},
{70, 75},
{75, 67},
{67, 76},
{76, 68},
{73, 77},
{77, 71},
{71, 75},
{74, 78},
{78, 73},
{75, 76},
{73, 79},
{79, 77},
{75, 80},
{80, 76},
{77, 75},
{78, 79},
{77, 80},
{79, 80},
{80, 68},
{80, 72},
{79, 72},
{81, 69},
{72, 81},
{78, 81},
{81, 79},
{74, 81},
{82, 83},
{83, 84},
{84, 82},
{83, 85},
{85, 84},
{85, 86},
{86, 87},
{87, 85},
{83, 88},
{88, 85},
{86, 82},
{82, 87},
{88, 86},
{86, 89},
{89, 82},
{89, 83},
{90, 91},
{91, 92},
{92, 90},
{92, 93},
{93, 90},
{92, 94},
{94, 95},
{95, 92},
{91, 94},
{95, 93},
{96, 94},
{91, 96},
{90, 96},
{96, 95},
{96, 97},
{97, 95},
{90, 98},
{98, 96},
{97, 93},
{98, 97},
{99, 100},
{100, 101},
{101, 99},
{102, 101},
{100, 102},
{101, 103},
{103, 99},
{102, 103},
{104, 105},
{105, 102},
{102, 104},
{100, 104},
{102, 106},
{106, 103},
{103, 107},
{107, 99},
{108, 99},
{107, 108},
{109, 102},
{105, 109},
{110, 107},
{103, 110},
{109, 106},
{110, 108},
{106, 111},
{111, 103},
{112, 110},
{110, 111},
{111, 112},
{110, 113},
{113, 108},
{112, 113},
{113, 114},
{114, 108},
{115, 116},
{116, 117},
{117, 115},
{115, 118},
{118, 116},
{118, 119},
{119, 116},
{115, 119},
{117, 119},
{120, 121},
{121, 122},
{122, 120},
{123, 121},
{120, 123},
{124, 123},
{120, 124},
{125, 121},
{123, 125},
{122, 124},
{121, 126},
{126, 122},
{124, 125},
{125, 126},
{124, 126},
{127, 128},
{128, 129},
{129, 127},
{127, 130},
{130, 128},
{127, 131},
{131, 130},
{129, 131},
{128, 131},
{132, 133},
{133, 134},
{134, 132},
{135, 134},
{133, 135},
{132, 136},
{136, 133},
{135, 137},
{137, 134},
{138, 137},
{135, 138},
{132, 139},
{139, 136},
{134, 140},
{140, 132},
{137, 140},
{137, 141},
{141, 140},
{138, 141},
{141, 142},
{142, 140},
{132, 143},
{143, 139},
{143, 144},
{144, 145},
{145, 143},
{145, 139},
{142, 144},
{144, 140},
{143, 140},
{146, 147},
{147, 145},
{145, 146},
{146, 148},
{148, 149},
{149, 146},
{149, 147},
{147, 150},
{150, 145},
{146, 138},
{138, 148},
{150, 149},
{148, 150},
{138, 150},
{151, 152},
{152, 153},
{153, 151},
{153, 154},
{154, 151},
{152, 155},
{155, 156},
{156, 152},
{156, 153},
{157, 158},
{158, 159},
{159, 157},
{160, 157},
{159, 160},
{161, 159},
{159, 162},
{162, 161},
{161, 160},
{163, 159},
{159, 164},
{164, 163},
{163, 162},
{165, 164},
{164, 166},
{166, 165},
{159, 166},
{162, 167},
{167, 168},
{168, 162},
{163, 167},
{165, 169},
{169, 164},
{169, 163},
{168, 170},
{170, 171},
{171, 168},
{167, 170},
{168, 172},
{172, 173},
{173, 168},
{171, 172},
{174, 169},
{165, 174},
{169, 167},
{174, 175},
{175, 169},
{169, 170},
{173, 162},
{175, 170},
{158, 166},
{173, 161},
{176, 177},
{177, 178},
{178, 176},
{177, 179},
{179, 178},
{178, 180},
{180, 181},
{181, 178},
{181, 176},
{182, 181},
{180, 182},
{182, 176},
{177, 183},
{183, 179},
{184, 178},
{179, 184},
{176, 185},
{185, 177},
{178, 186},
{186, 180},
{187, 179},
{183, 187},
{187, 184},
{182, 188},
{188, 176},
{180, 189},
{189, 182},
{188, 185},
{184, 186},
{189, 188},
{185, 183},
{189, 190},
{190, 188},
{190, 185},
{185, 191},
{191, 183},
{190, 191},
{186, 190},
{189, 186},
{191, 187},
{186, 191},
{191, 184},
{192, 193},
{193, 194},
{194, 192},
{194, 195},
{195, 192},
{196, 197},
{197, 194},
{194, 196},
{198, 192},
{195, 198},
{196, 198},
{198, 197},
{193, 196},
{196, 199},
{199, 198},
{199, 192},
{200, 201},
{201, 202},
{202, 200},
{200, 203},
{203, 201},
{201, 204},
{204, 205},
{205, 201},
{205, 202},
{206, 207},
{207, 200},
{200, 206},
{208, 200},
{207, 208},
{208, 203},
{206, 205},
{205, 207},
{204, 207},
{204, 208},
{206, 202},
{209, 210},
{210, 211},
{211, 209},
{210, 212},
{212, 211},
{213, 209},
{211, 213},
{214, 211},
{212, 214},
{214, 213},
{210, 215},
{215, 212},
{210, 216},
{216, 215},
{217, 210},
{209, 217},
{218, 212},
{215, 218},
{217, 216},
{219, 213},
{214, 219},
{218, 214},
{209, 220},
{220, 217},
{221, 213},
{219, 221},
{222, 215},
{216, 222},
{218, 219},
{223, 221},
{219, 223},
{217, 222},
{218, 224},
{224, 219},
{222, 218},
{220, 222},
{224, 223},
{225, 222},
{220, 225},
{218, 226},
{226, 224},
{226, 223},
{227, 225},
{220, 227},
{222, 226},
{226, 225},
{225, 223},
{227, 209},
{213, 227},
{228, 227},
{227, 221},
{221, 228},
{223, 228},
{225, 228},
  
};
double b = 0.0;
double c = 1.0;
double g = 0.0;
double dis = 0.3;
bool spin = true;

void loop() {



char customKey = customKeypad.getKey();

if (spin){
  b += .17;
  c += .1;
  g += .14;
  if (customKey == 'O'){
  spin = false;
}
}
else
{

if (customKey == '1'){
  dis += .05;
}
else if (customKey == '2'){
  dis -= .05;
}
else if (customKey == '5'){
  c += .17;
}
else if (customKey == '6'){
  c -= .17;
}
else if (customKey == 'O'){
  spin = true;
}
}
//b += .057;
//c += .05;

for (int i = 70; i < 229; i++){
  //get vertex
  //double x = vert[i][0];
  //double y = vert[i][1];
  //double z = vert[i][2];
  //double s[] = { vert[i][0], vert[i][1]*cos(b)+vert[i][2]*sin(b), -vert[i][1]*sin(b)+vert[i][2]*cos(b)};
  double* s = (double*) malloc(3 * sizeof(double));

  //z_rot(vert[i], g, s);
  z_rot(vert[i], 3.14159/2, s);
  x_rot(s, b, s);
  
  //z_rot(s, g, s);
  s[2] += 2.;
  s[0]-=0.35;
  s[1]-=0.03;
  //z_rot(s, g, s);
  vert_2d[i][0] = round(       ( (s[1])/(s[2]*1+1) )*1000      )+64;
  vert_2d[i][1] = round(       ( -(s[0])/(s[2]*1+1) )*1000       )+48;
  free(s);
  //Serial.println(x_rot(vert[i],b)[1]);

}

TV.clear_screen();

TV.draw_line( 10, 5, 10, 10, 0x60 );
TV.draw_line( 10, 10, 12, 10, 0x60 );

TV.draw_line( 15, 5, 15, 9, 0x60 );
TV.draw_line( 15, 10, 18, 10, 0x60 );
TV.draw_line( 18, 5, 18, 10, 0x60 );

TV.draw_line( 22, 5, 22, 10, 0x60 );

TV.draw_line( 26, 5, 26, 10, 0x60 );
TV.draw_line( 26, 10, 28, 10, 0x60 );
TV.draw_line( 28, 8, 28, 10, 0x60 );
TV.draw_line( 26, 5, 28, 5, 0x60 );

TV.draw_line( 31, 5, 31, 10, 0x60 );

for (int i = 226; i < 526-136; i++){
  int x1 = vert_2d[ edge[i][0] ][0];
  int y1 = vert_2d[ edge[i][0] ][1];
  int x2 = vert_2d[ edge[i][1] ][0];
  int y2 = vert_2d[ edge[i][1] ][1];
  
  if (x1 == x2){
    TV.draw_line( x1, y1, x2, y2, 0x60 );
  }
  else if (y1 == y2){
    TV.draw_line( x1, y1, x2, y2, 0x60 );
  }
  else {
    TV.draw_line( x1, y1, x2, y2, 0x60 );
  }
  delay(10);
}

delay(1000);
b = fmod(b,999.0);
c = fmod(c,999.0);
g = fmod(g,999.0);

//for (int i = 0; i < 4; i++){
//TV.set_pixel(vert_2d[i][0], vert_2d[i][1], 0x60);
//}

//float x = 0.0;
//TV.draw_line(0,10,105,70,0x60);

//TV.draw_circle(50, 40, 15, 0x60);
//for(float i = 0.0; i <= 2*3.14159; i += .01){
//  set_pixel( round(sin(i)*15)+50, round(cos(i)*15)+30 );
//}


//TV.set_pixel(105,70 ,0x60 );
//TV.set_pixel(0,10 ,0x60 );
//TV.bitmap(10, 10, Pi);

}

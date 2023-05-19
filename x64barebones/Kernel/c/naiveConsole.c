#include <naiveConsole.h>
#include <time.h>
#include <string.h>

extern int getSeconds();
extern int getMinutes();
extern int getHours();
// extern int getDays();
// extern int getMonth();
// extern int getYears();
extern int keyPressed();

static uint32_t uintToBase(uint64_t value, char * buffer, uint32_t base);

static char buffer[64] = { '0' };
static uint8_t * const video = (uint8_t*)0xB8000;
static uint8_t * currentVideo = (uint8_t*)0xB8000;
static const uint32_t width = 80;
static const uint32_t height = 25 ;

static const uint8_t charHexMap[256] = {
          0,    0,  '1',  '2',  '3',  '4',  '5',  '6',   '7',  '8',  '9',   '0',   '-',  '=',  0xF0, '    ',
        'Q',  'W',  'E',  'R',  'T',  'Y',  'U',  'I',   'O',  'P',  '[',   ']',  '\n',    0,   'A',    'S',
        'D',  'F',  'G',  'H',  'J',  'K',  'L',  ';',  '\'',    0,    0,  '\\',   'Z',  'X',   'C',    'V',
        'B',  'N',  'M',  ',',  '.',  '/',    0,  '*',     0,  ' ',    0,     0,     0,    0,     0,      0,
    };

void ncPrint(const char * string)
{
	int i;

	for (i = 0; string[i] != 0; i++)
		ncPrintChar(string[i]);
}

void ncPrintChar(char character)
{
	*currentVideo = character;
	currentVideo += 2;
}

void ncNewline()
{
	do
	{
		ncPrintChar(' ');
	}
	while((uint64_t)(currentVideo - video) % (width * 2) != 0);
}

void ncPrintDec(uint64_t value)
{
	ncPrintBase(value, 10);
}

void ncPrintHex(uint64_t value)
{
	ncPrintBase(value, 16);
}

void ncPrintBin(uint64_t value)
{
	ncPrintBase(value, 2);
}

void ncPrintBase(uint64_t value, uint32_t base)
{
    uintToBase(value, buffer, base);
    ncPrint(buffer);
}

void ncClear()
{
	int i;

	for (i = 0; i < height * width; i++)
		video[i * 2] = ' ';
	currentVideo = video;
}

static uint32_t uintToBase(uint64_t value, char * buffer, uint32_t base)
{
	char *p = buffer;
	char *p1, *p2;
	uint32_t digits = 0;

	//Calculate characters for each digit
	do
	{
		uint32_t remainder = value % base;
		*p++ = (remainder < 10) ? remainder + '0' : remainder + 'A' - 10;
		digits++;
	}
	while (value /= base);

	// Terminate string in buffer.
	*p = 0;

	//Reverse string in buffer.
	p1 = buffer;
	p2 = p - 1;
	while (p1 < p2)
	{
		char tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
		p1++;
		p2--;
	}

	return digits;
}

//Ej1
void printCharColor(uint8_t character, uint8_t attribute){ //aca avanza las 2 dir previamente mencionadas
    *currentVideo++ = character; //1ero carga en la dir de video el caracter y despues avanza 
    *currentVideo++ = attribute ; 
}

void printStringColor(const char * string, uint16_t attribute){
    for(int i=0; string[i]!=0; i++){
        printCharColor(string[i], attribute);
    }
}

//Ej3
void getRTC(){
	ncPrintHex(getHours());
	ncPrint(":");
	ncPrintHex(getMinutes());
	ncPrint(":");
	ncPrintHex(getSeconds());
}

// void convertToGMT3(int * hours, int * days, int * month, int * year){
// 	int daysInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};
//     int monthDays = daysInMonth[(*month - 1) % 12];

//     if (*year % 4 == 0 && (*year % 100 != 0 || *year % 400 == 0)) {
//         daysInMonth[1] = 29;
//     }
//     *hours -= 3;
//     if (*hours < 0) {
//         *hours += 24;
//         *days -= 1;
//         if (*days < 1) {
//             *month -= 1;
//             monthDays = daysInMonth[(*month - 1) % 12];
//             if (*month < 1) {
//                 *month = 12;
//                 *year -= 1;
//             }
//             *days = monthDays;
//         }
//     }
// }

//Ej4
void ncScanf(){
	ncPrint("Seleccione una tecla");
	ncNewline(); 
	int key = keyPressed(); 
	char toPrint = charHexMap[key]; 
	ncPrint("La tecla es: "); 
	ncPrintChar(toPrint); 
}

//Ej5
void timerTickIDT(){
	load_idt();

	uint8_t changeDetected = 0;

	while(1){
		if(!changeDetected && ticks_elapsed() % 6 == 0){
			changeDetected = 1;
			ncPrint("0");
			if(ticks_elapsed() % 18 == 0)
				ncPrint("T");
		}
	}

	if(changeDetected && ticks_elapsed() % 6 != 0)
		changeDetected = 0;
}

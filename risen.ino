#define LENGTH(x) (sizeof(x)/sizeof(*(x)))

#define C4  262
#define CS4 277
#define D4  294
#define DS4 311
#define E4  330
#define F4  349
#define FS4 370
#define G4  392
#define GS4 415
#define A4  440
#define AS4 466
#define B4  494

#define C  523
#define CS 554
#define D  587
#define DS 622
#define E  659
#define F  698
#define FS 740
#define G  784
#define GS 831
#define A  880
#define AS 932
#define B  988

struct Note {
	int pitch;
	int len;
};

struct Note notes[] = {

	// 1
	{D,  3},
	{E,  3},
	{F,  6},
	{F,  6},
	{E,  2},
	{E,  2},
	{F,  2},

	// 2
	{D,  6},
	{C,  3},
	{D,  3},
	{D,  3},
	{E,  3},
	{C,  2},
	{G,  2},
	{F,  2},

	// 3
	{D,  3},
	{E,  3},
	{F,  6},
	{F,  6},
	{E,  2},
	{E,  2},
	{F,  2},

	// 4
	{D,  6},
	{C,  3},
	{D,  3},
	{D,  3},
	{E,  3},
	{C,  2},
	{G,  2},
	{F,  2},


	// 5
	{D,  3},
	{C,  3},
	{D,  6},
	{E,  6},
	{A4, 3},
	{A4, 3},


	// 6
	{E,  2},
	{E,  2},
	{F,  2},
	{E,  2},
	{D,  2},
	{G,  2},
	{G4, 2},
	{D,  2},
	{C,  2},
	{F,  6},

	// 7
	{D,  3},
	{C,  3},
	{D,  6},
	{E,  6},
	{A4, 3},
	{A4, 3},

	// 8
	{E,  2},
	{E,  2},
	{F,  2},
	{E,  2},
	{D,  2},
	{G,  2},
	{B4, 2},
	{D,  2},
	{C,  2},
	{F,  6},
};


int i = 0;
void setup() {
	Serial.begin(9600);
}

void loop() {
	char buf[128];
	struct Note *n = &notes[i%(LENGTH(notes))];

	tone(2, n->pitch, n->len*60);
	sprintf(buf, "playing note(%d) %d for %d\n", i, n->pitch, n->len);
	Serial.print(buf);

	delay(n->len*60);
	i++;
}

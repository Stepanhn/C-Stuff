#include <iostream>
#include <array>
#include <fstream>
#include <Windows.h>

const int WIDTH = 50;
const int HEIGHT = 50;

struct point
{
	char c;
	char p;
};

struct Brush {

	char fill_char;
	char outline_char;
	int fill_color;
	int outline_color;
	void set_outline_character(char ch) { outline_char = ch; }
	void set_fill_character(char ch) { fill_char = ch; }
	void set_outline_color(char c) { outline_color = c; }
	void set_fill_color(char c) { fill_color = c; }
};
struct Canvas {

	std::array<std::array<point, WIDTH>, HEIGHT> arr;

	void clear(const char c = ' ', int color = 2) {
		for (int i = 0; i < HEIGHT; ++i) {
			for (int j = 0; j < WIDTH; ++j) {
				arr[i][j].c = c;
				arr[i][j].p = color;
			}
		}
	}

	void draw_rectangle(const Brush& brush, int upperleft_x, int upperleft_y, int width, int height) {
		for (int i = upperleft_x; i < upperleft_x + height; ++i) {
			for (int j = upperleft_y; j < upperleft_y + width; ++j) {
				//std::cout << i <<" "<< j << std::endl;
				if (i >= HEIGHT || j >= WIDTH || j < 0 || i < 0) {
					continue;
				}
				if (i == upperleft_x || i == upperleft_x + height - 1 || j == upperleft_y || j == upperleft_y + width - 1) {
					arr[i][j].c = brush.outline_char;
					arr[i][j].p = brush.outline_color;
				}
				else {
					arr[i][j].c = brush.fill_char;
					arr[i][j].p = brush.fill_color;
				}
			}

		}

	}

	void draw_triangle(const Brush& brush, int upperleft_x, int upperleft_y, int width, int height, int rotation = 0) {
		if (rotation == 0 || rotation == -360)
		{
			for (int i = upperleft_x; i < upperleft_x + height; ++i) {
				for (int j = upperleft_y; j - upperleft_y <= i - upperleft_x; ++j) {
					if (i >= HEIGHT || j >= WIDTH || j < 0 || i < 0) {
						continue;
					}
					if (i == upperleft_x + height - 1 || j == upperleft_y || i - upperleft_x == j - upperleft_y) {
						arr[i][j].c = brush.outline_char;
						arr[i][j].p = brush.outline_color;
					}
					else {
						arr[i][j].c = brush.fill_char;
						arr[i][j].p = brush.fill_color;
					}

				}
			}
		}
		else if (rotation == 90 || rotation == -270) {
			for (int i = upperleft_x; i < upperleft_x + height; ++i) {
				for (int j = upperleft_y; j < upperleft_y + width - (i - upperleft_x); ++j) {
					if (i >= HEIGHT || j >= WIDTH || j < 0 || i < 0) {
						continue;
					}
					if (j == upperleft_y || i == upperleft_x || j == upperleft_y + width - (i - upperleft_x) - 1) {
						arr[i][j].c = brush.outline_char;
						arr[i][j].p = brush.outline_color;
					}
					else {
						arr[i][j].c = brush.fill_char;
						arr[i][j].p = brush.fill_color;
					}

				}
			}
		}
		else if (rotation == 180 || rotation == -180) {
			for (int i = upperleft_x; i < upperleft_x + height; ++i) {
				for (int j = upperleft_y + (i - upperleft_x); j < upperleft_y + width; ++j) {
					if (i >= HEIGHT || j >= WIDTH || j < 0 || i < 0) {
						continue;
					}
					if (j == upperleft_y + width - 1 || i == upperleft_x || i - upperleft_x == j - upperleft_y) {
						arr[i][j].c = brush.outline_char;
						arr[i][j].p = brush.outline_color;
					}
					else {
						arr[i][j].c = brush.fill_char;
						arr[i][j].p = brush.fill_color;
					}
				}
			}
		}
		else if (rotation == 270 || rotation == -90) {
			for (int i = upperleft_x; i < upperleft_x + height; ++i) {
				for (int j = upperleft_y; j >= upperleft_y - (i - upperleft_x); --j) {
					if (i >= HEIGHT || j >= WIDTH || j < 0 || i < 0) {
						continue;
					}
					if (j == upperleft_y || i == upperleft_x + height - 1 || j == (upperleft_y - (i - upperleft_x))) {
						arr[i][j].c = brush.outline_char;
						arr[i][j].p = brush.outline_color;
					}
					else {
						arr[i][j].c = brush.fill_char;
						arr[i][j].p = brush.fill_color;
					}
				}
			}
		}

	}

	void flush(std::ostream& out = std::cout) {
		HANDLE  hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, arr[0][0].p);

		for (int i = 0; i < HEIGHT; ++i) {
			for (int j = 0; j < WIDTH; ++j) {
				SetConsoleTextAttribute(hConsole, arr[i][j].p - '0');
				out << arr[i][j].c;
			}
			out << std::endl;
		}

	}
};


void test1()

{

	Canvas canvas;  //initially the canvas contains garbage.

	canvas.clear(); //this call clears the canvas, i.e. sets all the characters to whitespace

	canvas.clear('.', '5'); //come to think of it, clearing with dots is better as the coordinates will be more visible

	//Let's draw an outline of a 5x5 square with upper left corner at coordinates (2, 2) with the character x.

	//For that, let's create a brush with outline character x and transparent fill character and pass it to the canvas for painting.

	Brush brush;

	brush.set_outline_character('x');

	brush.set_fill_character('.'); //let's assume the null character means transparent
	brush.set_outline_color(9);

	brush.set_fill_color(4); //let's assume the null character means transparent

	canvas.draw_rectangle(brush, 2, 2, 8, 10);
	//Now, let's draw another rectangle, this time filled with $s
	brush.set_fill_character('%');
	brush.set_outline_character('#');
	brush.set_fill_color('3');
	brush.set_outline_color('4');
	canvas.draw_rectangle(brush, 15, 2, 8, 10);

	//OK, let's see what we've got. Let's flush the canvas into a file:

	std::ofstream file("two_rects.txt");

	canvas.flush(file); //the flush function takes an std::ostream&

	////stream parameter and draws the current canvas to that stream.        default value is std::cout

	file << "\n\n\n\n\n"; //leave some space

	canvas.flush(file); //let's draw the same picture one more time

	canvas.flush(); //and let's draw once to std::cout

}

void test2()
{
	Canvas picture;

	picture.clear('.', '2'); //with spaces
	Brush brush;

	brush.set_outline_character('0'); //no outline


	char fill_char = 'A';
	char k = '1';
	for (int width = 20; width >= 5; width -= 3)

	{

		brush.set_fill_character(fill_char);

		brush.set_outline_character(fill_char);

		brush.set_fill_color(k);

		brush.set_outline_color(k);

		picture.draw_rectangle(brush, 0, 0, width, width);

		++fill_char; //next letter for next (smaller) square
		++k;
	}


	picture.flush();

}

void test3() {
	Canvas canvas;
	canvas.clear('.', '11');
	Brush brush;
	brush.set_fill_character('#');
	brush.set_outline_character('*');
	brush.set_fill_color('1');
	brush.set_outline_color('2');
	canvas.draw_rectangle(brush, 2, 2, 8, 10);


	brush.set_fill_character('%');
	brush.set_outline_character('#');
	brush.set_fill_color('3');
	brush.set_outline_color('4');
	canvas.draw_rectangle(brush, 15, 2, 8, 10);

	brush.set_fill_character('^');
	brush.set_outline_character('%');
	brush.set_fill_color('5');
	brush.set_outline_color('6');
	canvas.draw_rectangle(brush, 2, 15, 8, 10);

	brush.set_fill_character('&');
	brush.set_outline_character('*');
	brush.set_fill_color('7');
	brush.set_outline_color('8');
	canvas.draw_rectangle(brush, 15, 15, 8, 10);

	canvas.flush();

}

void test4() {

	Canvas canvas;
	canvas.clear('.', 6);
	Brush brush;
	brush.set_fill_character('$');
	brush.set_outline_character('0');
	brush.set_fill_color('1');
	brush.set_outline_color('2');

	canvas.draw_rectangle(brush, 2, 2, 21, 21);
	brush.set_fill_character('#');
	brush.set_outline_character('*');
	brush.set_fill_color('3');
	brush.set_outline_color('4');
	canvas.draw_rectangle(brush, 6, 6, 13, 13);

	brush.set_fill_character('&');
	brush.set_outline_character('*');
	brush.set_fill_color('7');
	brush.set_outline_color('8');
	canvas.draw_rectangle(brush, 9, 9, 7, 7);

	canvas.flush();

}

void test5() {
	Canvas canvas;
	canvas.clear('.', '11');

	Brush brush;
	brush.set_fill_character('!');
	brush.set_outline_character('3');
	brush.set_fill_color('1');
	brush.set_outline_color('2');
	canvas.draw_triangle(brush, 2, 2, 10, 10, 0);

	brush.set_fill_character('#');
	brush.set_outline_character('2');
	brush.set_fill_color('3');
	brush.set_outline_color('4');
	canvas.draw_triangle(brush, 15, 3, 10, 10, 90);

	brush.set_fill_character('$');
	brush.set_outline_character('0');
	brush.set_fill_color('5');
	brush.set_outline_color('6');
	canvas.draw_triangle(brush, 2, 6, 10, 10, 180);

	brush.set_fill_character('^');
	brush.set_outline_character('1');
	brush.set_fill_color('7');
	brush.set_outline_color('8');
	canvas.draw_triangle(brush, 15, 1, 10, 10, 270);
	
	brush.set_fill_character('^');
	brush.set_outline_character('1');
	brush.set_fill_color('7');
	brush.set_outline_color('8');
	canvas.draw_triangle(brush, 15, 15, 10, 10, 270);

	canvas.flush();
}

int main() {

	test1();
	test2();
	test3();
	test4();
	test5();

	system("pause");


}
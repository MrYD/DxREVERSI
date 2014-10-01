#ifndef some_identifier
#define some_identifier
class Point
{
public:
	Point();
	Point(int num, int space[8][8],int z);
	Point(int num, int space[8][8]);
	Point(int x, int y,int z);
	~Point();
	int get_num(int space[8][8]);
	void set_z(int space[8][8]);
	void set_z(int z);
	void set_x(int x);
	void set_y(int y);
	int get_z();
	int get_x();
	int get_y();
private:
	int x;
	int y;
	int z;
};
#endif
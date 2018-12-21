#pragma once

#include <vector>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

// Traits
template <typename T>
struct pixel_type
{
	static const int value = -1;
};
template <>
struct pixel_type<uchar>
{
	static const int value = CV_8U;
};
template <>
struct pixel_type<short>
{
	static const int value = CV_16S;
};
template <>
struct pixel_type<Vec3b>
{
	static const int value = CV_8UC3;
};
template <>
struct pixel_type<float>
{
	static const int value = CV_32F;
};

template <typename T> class Image : public Mat {
public:
	// Constructors
	Image() {}
	explicit Image(const Mat& A):Mat(A) {}
	Image(int w,int h):Mat(h,w,pixel_type<T>::value) {}
	Image(int w, int h, T initial):Mat(h,w,pixel_type<T>::value, initial) {}
	// Accessors
	inline T operator()(int x,int y) const { return at<T>(y,x); }
	inline T& operator()(int x,int y) { return at<T>(y,x); }
	inline T operator()(const Point& p) const { return at<T>(p.y,p.x); }
	inline T& operator()(const Point& p) { return at<T>(p.y,p.x); }
	//
	inline int width() const { return cols; }
	inline int height() const { return rows; }
	// To display a floating type image
	Image<uchar> greyImage() const {
		double minVal, maxVal;
		minMaxLoc(*this,&minVal,&maxVal);
		Image<uchar> g;
		convertTo(g, CV_8U, 255.0/(maxVal - minVal), -minVal * 255.0/(maxVal - minVal));
		return g;
	}
};

struct Coord
{
    int x, y;

    Coord() {}
    Coord(int a, int b) { x = a; y = b; }

    Coord operator+ (Coord a) const { return Coord(x + a.x, y + a.y); }
    Coord operator+ (int a)   const { return Coord(x+a,y); }
    Coord operator- (int a)   const { return Coord(x-a,y); }
    bool  operator< (Coord a) const { return (x <  a.x) && (y <  a.y); }
    bool  operator<=(Coord a) const { return (x <= a.x) && (y <= a.y); }
    bool  operator!=(Coord a) const { return (x != a.x) || (y != a.y); }
};


/// Is p inside rectangle r?
inline bool inRect(Coord p, Coord r) {
    return (Coord(0,0)<=p && p<r);
}


/// Rectangle iterator
class RectIterator {
	Coord p; ///< Current point
	int w; ///< Width of rectangle
public:
	RectIterator(Coord rect): p(0,0), w(rect.x) {}
	const Coord& operator*() const { return p; }
	bool operator!=(const RectIterator& it) const { return (p!=it.p); }
	RectIterator& operator++() { if(++p.x==w){p.x=0;++p.y;} return *this; }

	friend RectIterator rectBegin(Coord rect);
	friend RectIterator rectEnd(Coord rect);
};

inline RectIterator rectBegin(Coord rect) { return RectIterator(rect); }
inline RectIterator rectEnd(Coord rect) {
	RectIterator it(rect);
	it.p.y = rect.y;
	return it;
};


// Correlation
double NCC(const Image<float>& I1,Point m1,const Image<float>& I2,Point m2,int n);



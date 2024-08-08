// https://godbolt.org/z/MEe1e4794

#include <iostream>
#include <optional>
#include <algorithm> // for std::min and std::max
using namespace std;

struct Point {
    int x;
    int y;
};

struct Line {
    Point a;
    Point b;
};

// 计算两个点组成的直线的方程系数
void getLineEquation(const Line& line, int& A, int& B, int& C) {
    A = line.b.y - line.a.y;
    B = line.a.x - line.b.x;
    C = A * line.a.x + B * line.a.y;
}

// 计算两个直线的交点
optional<Point> lineIntersection(const Line& line1, const Line& line2) {
    int A1, B1, C1;
    int A2, B2, C2;
    
    getLineEquation(line1, A1, B1, C1);
    getLineEquation(line2, A2, B2, C2);
    
    int det = A1 * B2 - A2 * B1;
    
    if (det == 0) {
        return nullopt; // 直线平行或重合
    }
    
    Point intersection;
    intersection.x = (B2 * C1 - B1 * C2) / det;
    intersection.y = (A1 * C2 - A2 * C1) / det;
    
    // 检查交点是否在两个线段上
    if ((min(line1.a.x, line1.b.x) <= intersection.x && intersection.x <= max(line1.a.x, line1.b.x) &&
         min(line1.a.y, line1.b.y) <= intersection.y && intersection.y <= max(line1.a.y, line1.b.y)) &&
        (min(line2.a.x, line2.b.x) <= intersection.x && intersection.x <= max(line2.a.x, line2.b.x) &&
         min(line2.a.y, line2.b.y) <= intersection.y && intersection.y <= max(line2.a.y, line2.b.y))) {
        return intersection;
    }
    
    return nullopt; // 交点不在两个线段上
}

int main() {
    Line line1 = {{1, 1}, {4, 4}};
    Line line2 = {{1, 4}, {4, 1}};
    
    auto intersection = lineIntersection(line1, line2);
    
    if (intersection) {
        cout << "Intersection at: (" << intersection->x << ", " << intersection->y << ")" << endl;
    } else {
        cout << "No intersection within the line segments." << endl;
    }
    
    return 0;
}

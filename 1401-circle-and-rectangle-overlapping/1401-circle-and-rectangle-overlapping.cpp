class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // Find the closest point inside or on the boundary of the rectangle
        int nearestX = std::max(x1, std::min(xCenter, x2));
        int nearestY = std::max(y1, std::min(yCenter, y2));
        
        // Calculate the squared distance between the circle's center and the nearest point
        int dx = xCenter - nearestX;
        int dy = yCenter - nearestY;
        
        return (dx * dx + dy * dy) <= (radius * radius);
    }
};
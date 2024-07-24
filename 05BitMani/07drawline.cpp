// https://godbolt.org/z/Ec8WzWb3v

#include <iostream>
#include <vector>
#include <cstdint> // Include this header to define uint8_t

// Function to draw a horizontal line on a monochrome screen
void drawLine(std::vector<uint8_t>& screen, int width, int x1, int x2, int y) {
    // Calculate the number of bytes in a row
    int bytesPerRow = width / 8;

    // Calculate the starting and ending byte indices
    int startByte = (y * bytesPerRow) + (x1 / 8);
    int endByte = (y * bytesPerRow) + (x2 / 8);

    // Set the bits in the starting and ending bytes
    int startBit = x1 % 8;
    int endBit = x2 % 8;

    // If x1 and x2 are in the same byte, handle this special case
    if (startByte == endByte) {
        uint8_t mask = (0xFF >> startBit) & (0xFF << (7 - endBit));
        screen[startByte] |= mask;
    } else {
        // Set the bits in the starting byte
        screen[startByte] |= (0xFF >> startBit);

        // Set the bits in the bytes between the starting and ending bytes
        for (int i = startByte + 1; i < endByte; i++) {
            screen[i] = 0xFF;
        }

        // Set the bits in the ending byte
        screen[endByte] |= (0xFF << (7 - endBit));
    }
}

// Helper function to print the screen for debugging
void printScreen(const std::vector<uint8_t>& screen, int width) {
    int height = screen.size() * 8 / width;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int byteIndex = (y * width / 8) + (x / 8);
            int bitIndex = x % 8;
            bool bit = (screen[byteIndex] & (1 << (7 - bitIndex))) != 0;
            std::cout << (bit ? "1" : "0");
        }
        std::cout << std::endl;
    }
}

int main() {
    int width = 16; // Screen width in pixels
    int height = 2; // Screen height in rows
    std::vector<uint8_t> screen((width * height) / 8, 0);

    drawLine(screen, width, 2, 13, 0); // Draw a line from (2, 0) to (13, 0)
    drawLine(screen, width, 5, 9, 1);  // Draw a line from (5, 1) to (9, 1)

    printScreen(screen, width);

    return 0;
}

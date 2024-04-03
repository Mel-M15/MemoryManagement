#include <iostream>  // Include header file for input and output
#include <vector>   // Using vector for holding the page table and allocating frames
#include <cstdlib> // Using rand() function from cstdlib
#include <ctime>  // Needed to access the time
#include <iomanip> // Need to output results in hex
using namespace std;

const int PAGE_SIZE = 1024;  // Page size in bytes
const int FRAME_SIZE = 1024; // Frame size in bytes
const int NUM_PAGES = 16;    // Number of pages in logical memory
const int NUM_FRAMES = 8;    // Number of frames in physical memory

// Function randomly generates a logical address
int randomLogicalAddress() {
    return rand() % (NUM_PAGES * PAGE_SIZE);
}

int main() {
    // Seed the random number generator with the current time
    srand(time(nullptr));

    // Initialize page/frame table
    vector<int> pageFrameTable(NUM_PAGES, -1);

    // Allocate frames in physical memory
    vector<int> physicalMemory(NUM_FRAMES, -1);

    // Filling page/frame table
    for (int i = 0; i < NUM_PAGES; ++i) {
        pageFrameTable[i] = i % NUM_FRAMES;
    }

    // Translating logical addresses into physical addresses, the loop will translate up to 10
    // or less random logical addresses to physical addresses using the page/frame table
    for (int i = 0; i < 10; i++) {
        int logicalAddress = randomLogicalAddress(); // Generates random logical address
        int pageNumber = logicalAddress / PAGE_SIZE; // Calculates the page number
        int offset = logicalAddress % PAGE_SIZE; // Calculates the offset

        // Check if the page number is within the number of pages in logical memory
        if (pageNumber < NUM_PAGES) { 
            // Find the frame number
            int frameNumber = pageFrameTable[pageNumber];

            // Page fault if frame is -1
            if (frameNumber == -1) {
                cout << "Page fault!! " << pageNumber << endl;
                // Loading pages from secondary storage into memory
                frameNumber = pageNumber % NUM_FRAMES;
                pageFrameTable[pageNumber] = frameNumber;
                physicalMemory[frameNumber] = pageNumber;
            }

            // Calculating the physical address
            int physicalAddress = frameNumber * FRAME_SIZE + offset;

            // Print out the logical address, physical address, page number, and offset
            if (logicalAddress != physicalAddress) {
                cout << "Logical Address: 0x" << hex << logicalAddress << " => Physical Address: 0x" << physicalAddress << ", " << "Page Number: 0x" << hex << pageNumber << ", " << "Offset: 0x" << hex << offset << endl;
            }
        }
        else {
            cout << "Invalid Page Number: " << pageNumber << endl;
        }
    }

    return 0;
}
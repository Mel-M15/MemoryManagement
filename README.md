# MemoryManagement README
Please run this MemoryManagement project in C++.

# Overview
This C++ program implements a memory management process that translates logical addresses to physical addresses using a page/frame table. The program also provides the page number and offset for a given logical address.

# Functionality
The memory management algorithm has the following functionality:
1. The page size is 1024 bytes, the frame size is 1024 bytes, the number of pages in logical memory is 16, and the number of frames in physical memory is 8.
2. randomlogicalAddress function - randomly generates a logical address. This logical address will be used later in the program to calculate the physical address, page number, and offset.
3. Up to 10 or less logical addressees will be generated with their respective physical address, page number, and offset.
4. If the page number is greater than the number of pages in logical memory, then this indicates that the page number is invalid, and a message will be displayed to the user. Otherwise, the calculations to find the physical address, page number, and offset will be calculated. 
5. If the frame number is -1, this indicates a page fault, and a message will be displayed to the user.
6. Physical address calculated as: physicalAddress = frameNumber * FRAME_SIZE + offset.
7. Page number calculated as: pageNumber = logicalAddress / PAGE_SIZE.
8. Offset calculated as: offset = logicalAddress % PAGE_SIZE.
9. All logical addresses, physical addresses, page numbers, and offsets will be displayed to the user in hexadecimal format.

# Instructions for Execution
1. Run this program in C++.
2. There is no user input to be entered to run the program.
3. Run the program and verify that up to 10 or less logical addresses will be generated with their respective physical addresses, page numbers, and offsets calculated.
4. Optional: Run the program many more times to verify that logical addresses are randomly generated along with their calculated physical addresses, page numbers, and offsets.

#include <stdbool.h>
#include <stdlib.h>

// Structure to hold an interval
typedef struct {
    int start;
    int end;
} Booking;

typedef struct {
    Booking* bookings;
    int bookings_count;
    int bookings_capacity;
    
    Booking* overlaps;
    int overlaps_count;
    int overlaps_capacity;
} MyCalendarTwo;

// Helper function to check if two intervals overlap
bool isOverlapping(int s1, int e1, int s2, int e2) {
    // Overlap happens if the max of starts is strictly less than the min of ends
    int max_start = s1 > s2 ? s1 : s2;
    int min_end = e1 < e2 ? e1 : e2;
    return max_start < min_end;
}

MyCalendarTwo* myCalendarTwoCreate() {
    MyCalendarTwo* obj = (MyCalendarTwo*)malloc(sizeof(MyCalendarTwo));
    
    obj->bookings_count = 0;
    obj->bookings_capacity = 1000; // Constraint says at most 1000 calls
    obj->bookings = (Booking*)malloc(obj->bookings_capacity * sizeof(Booking));
    
    obj->overlaps_count = 0;
    obj->overlaps_capacity = 1000; 
    obj->overlaps = (Booking*)malloc(obj->overlaps_capacity * sizeof(Booking));
    
    return obj;
}

bool myCalendarTwoBook(MyCalendarTwo* obj, int startTime, int endTime) {
    // 1. Check if the new interval conflicts with any existing double-bookings
    for (int i = 0; i < obj->overlaps_count; i++) {
        if (isOverlapping(startTime, endTime, obj->overlaps[i].start, obj->overlaps[i].end)) {
            return false; // This would cause a triple booking!
        }
    }
    
    // 2. Find new double-bookings created by this event intersecting with regular bookings
    for (int i = 0; i < obj->bookings_count; i++) {
        if (isOverlapping(startTime, endTime, obj->bookings[i].start, obj->bookings[i].end)) {
            // Calculate the overlapping interval segment
            int overlap_start = startTime > obj->bookings[i].start ? startTime : obj->bookings[i].start;
            int overlap_end = endTime < obj->bookings[i].end ? endTime : obj->bookings[i].end;
            
            // Record the overlap
            obj->overlaps[obj->overlaps_count].start = overlap_start;
            obj->overlaps[obj->overlaps_count].end = overlap_end;
            obj->overlaps_count++;
        }
    }
    
    // 3. Record the new event itself into regular bookings
    obj->bookings[obj->bookings_count].start = startTime;
    obj->bookings[obj->bookings_count].end = endTime;
    obj->bookings_count++;
    
    return true;
}

void myCalendarTwoFree(MyCalendarTwo* obj) {
    if (obj) {
        free(obj->bookings);
        free(obj->overlaps);
        free(obj);
    }
}

#include <stdlib.h>

// Structure to hold a time boundary change event
typedef struct {
    int time;
    int delta;
} TimeEvent;

typedef struct {
    TimeEvent* events;
    int count;
    int max_k;
} MyCalendarThree;

MyCalendarThree* myCalendarThreeCreate() {
    MyCalendarThree* obj = (MyCalendarThree*)malloc(sizeof(MyCalendarThree));
    // Each book call adds at most 2 boundary events (start and end)
    // 400 calls * 2 = 800 events maximum capacity needed
    obj->events = (TimeEvent*)malloc(800 * sizeof(TimeEvent));
    obj->count = 0;
    obj->max_k = 0;
    return obj;
}

// Helper to insert an event point while maintaining a sorted order by 'time'
void insertEvent(MyCalendarThree* obj, int time, int delta) {
    int idx = 0;
    // Find the correct position to maintain time-sorted order
    while (idx < obj->count && obj->events[idx].time < time) {
        idx++;
    }
    
    // Shift elements to make room for insertion
    for (int i = obj->count; i > idx; i--) {
        obj->events[i] = obj->events[i - 1];
    }
    
    // Insert new point
    obj->events[idx].time = time;
    obj->events[idx].delta = delta;
    obj->count++;
}

int myCalendarThreeBook(MyCalendarThree* obj, int startTime, int endTime) {
    // 1. Add both intervals boundary points to our timeline
    insertEvent(obj, startTime, 1);
    insertEvent(obj, endTime, -1);
    
    // 2. Perform a sweep-line pass to compute the peak active intervals
    int current_overlap = 0;
    int peak_k = 0;
    
    for (int i = 0; i < obj->count; i++) {
        current_overlap += obj->events[i].delta;
        if (current_overlap > peak_k) {
            peak_k = current_overlap;
        }
    }
    
    // 3. Keep record of our highest k score seen so far
    if (peak_k > obj->max_k) {
        obj->max_k = peak_k;
    }
    
    return obj->max_k;
}

void myCalendarThreeFree(MyCalendarThree* obj) {
    if (obj) {
        free(obj->events);
        free(obj);
    }
}

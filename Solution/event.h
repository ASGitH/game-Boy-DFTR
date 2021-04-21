#ifndef EVENT_H
#define EVENT_H

#include <gb/gb.h>

// Delete below later
#include <rand.h>
// Delete above later

#include <stdio.h>

// What do we need to know about our event?
struct event
{
    // A way to figure out if the event has been played already
    BOOLEAN hasEventBeenPlayed;

    // Name of the event
    char *eventName;

    // How long the event will last?
    UINT16 eventDuration;
};

extern UINT8 currentNumberOfEvents;

// Initializer
// Will load a set amount of events to be played out
BOOLEAN eventInitializer(struct event *);

// void playEvent(struct event *);

// Each event logic here?

// Tumbling Barrels
void tumblingBarrels();

#endif
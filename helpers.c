// Helper functions for music

#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int x = atoi(&fraction[0]);
    int y = atoi(&fraction[2]);
    int note_len = 8*x/y;
    return note_len;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    int semitone=0;
    switch (note[0])
    {
        case ('A'):
        semitone = 0;
        break;
        case ('B'):
        semitone = 2;
        break;
        case ('C'):
        semitone = -9;
        break;
        case ('D'):
        semitone = -7;
        break;
        case('E'):
        semitone =-5;
        break;
        case('F'):
        semitone = -4;
        break;
        case('G'):
        semitone = -2;
        break;
        default:
        printf ("ERROR: No such note exists");
        break;
    }
    if (note[1] == '#')
    {
        semitone++;
    }
    else if (note[1] == 'b')
    {
        semitone--;
    }
    int octave = atoi(&note[strlen(note)-1]) - 4;
    float frequency = 440 * pow(2,((12*octave)+semitone)/12.0);
    frequency = round(frequency);
    return frequency;

}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (s[0] == '\0')
    {
        return true;
    }
    else return false;
}

#!/bin/bash

# take every path in the repo ending in .cpp, .c, or .h, ignoring those under book
astyle --style=attach --indent=spaces=4 --indent-switches \
       --suffix=none --formatted --recursive '*.cpp,*.c,*.h' --exclude='book'

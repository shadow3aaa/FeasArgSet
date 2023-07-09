#!/bin/sh
rm -rf $(dirname "$0")/*.bak
clang-format -i $(pwd)/src/*.cpp
clang-format -i $(pwd)/src/include/*.h
/data/data/com.termux/files/usr/bin/git gc --prune=all

/data/data/com.termux/files/usr/bin/git add .

/data/data/com.termux/files/usr/bin/git commit -m "$1"

/data/data/com.termux/files/usr/bin/git push origin main
#!/bin/bash

# Script to add Edward Tufte's ET Bembo font (ETbb) to Doxygen-generated LaTeX files
# Usage: ./add-etbb-font.sh <latex_directory>

if [ $# -ne 1 ]; then
    echo "Usage: $0 <latex_directory>"
    exit 1
fi

LATEX_DIR="$1"

if [ ! -d "$LATEX_DIR" ]; then
    echo "Error: Directory $LATEX_DIR does not exist"
    exit 1
fi

echo "Adding Edward Tufte's ET Bembo font configuration to LaTeX files..."

# Add ETbb package and set as main font in refman.tex
if [ -f "$LATEX_DIR/refman.tex" ]; then
    # Insert \usepackage{ETbb} after the documentclass line
    sed -i '' '/\\documentclass\[twoside\]{book}/a\
\\usepackage{ETbb} % Use Edward Tufte'"'"'s ET Bembo font (requires texlive)
' "$LATEX_DIR/refman.tex"
    
    # Replace \renewcommand{\familydefault}{\sfdefault} with \renewcommand{\familydefault}{\rmdefault}
    # to use the roman (serif) font family instead of sans-serif
    sed -i '' 's/\\renewcommand{\\familydefault}{\\sfdefault}/\\renewcommand{\\familydefault}{\\rmdefault}/' "$LATEX_DIR/refman.tex"
    
    echo "ETbb font configuration added and set as main font successfully."
else
    echo "Error: refman.tex not found in $LATEX_DIR"
    exit 1
fi

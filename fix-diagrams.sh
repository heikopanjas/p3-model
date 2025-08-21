#!/bin/bash

# Fix white backgrounds in DOT files and regenerate PDFs
DOC_DIR="$1"

echo "Processing DOT files in: $DOC_DIR"

# Fix background colors in DOT files
find "$DOC_DIR" -name "*.dot" -exec sed -i.bak \
    -e 's/bgcolor="transparent"/bgcolor="white"/g' \
    -e 's/fillcolor="grey60"/fillcolor="white"/g' \
    -e 's/color="gray40"/color="black"/g' \
    {} +

echo "Fixed DOT file colors"

# Regenerate PDF files from the fixed DOT files
for dotfile in "$DOC_DIR"/*.dot; do
    if [ -f "$dotfile" ]; then
        pdffile="${dotfile%.dot}.pdf"
        echo "Regenerating: $pdffile"
        dot -Tpdf "$dotfile" -o "$pdffile"
    fi
done

# Remove backup files to keep things clean
find "$DOC_DIR" -name "*.dot.bak" -delete

echo "Done processing DOT files"

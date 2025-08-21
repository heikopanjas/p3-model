#!/bin/bash

# Fix white backgrounds and customize fonts in DOT files and regenerate PDFs
DOC_DIR="$1"

# Font Configuration - Customize these settings as needed:
#
# Popular font options:
# - "Arial" (clean, modern sans-serif)
# - "Helvetica" (classic sans-serif)
# - "Times-Roman" (serif, traditional)
# - "Courier" (monospace, code-like)
# - "Verdana" (web-friendly sans-serif)
# - "DejaVu Sans" (open source alternative)

NODE_FONT="Arial"           # Font for class/struct names
NODE_FONTSIZE="11"          # Size for class/struct names (default: 10)
EDGE_FONT="Arial"           # Font for relationship labels
EDGE_FONTSIZE="9"           # Size for relationship labels (default: 8-9)
GRAPH_FONT="Arial"          # Font for graph title
GRAPH_FONTSIZE="12"         # Size for graph title

echo "Processing DOT files in: $DOC_DIR"
echo "Using fonts: Node=$NODE_FONT($NODE_FONTSIZE), Edge=$EDGE_FONT($EDGE_FONTSIZE)"

# Fix background colors and fonts in DOT files
find "$DOC_DIR" -name "*.dot" -exec sed -i.bak \
    -e 's/bgcolor="transparent"/bgcolor="white"/g' \
    -e 's/fillcolor="grey60"/fillcolor="white"/g' \
    -e 's/color="gray40"/color="black"/g' \
    -e "s/fontname=\"Helvetica\"/fontname=\"$NODE_FONT\"/g" \
    -e "s/fontsize=\"10\"/fontsize=\"$NODE_FONTSIZE\"/g" \
    -e "s/fontname=\"FreeSans\"/fontname=\"$NODE_FONT\"/g" \
    -e "s/fontname=\"Times-Roman\"/fontname=\"$NODE_FONT\"/g" \
    -e "s/fontsize=\"8\"/fontsize=\"$EDGE_FONTSIZE\"/g" \
    -e "s/fontsize=\"9\"/fontsize=\"$EDGE_FONTSIZE\"/g" \
    {} +

echo "Fixed DOT file colors and fonts"

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

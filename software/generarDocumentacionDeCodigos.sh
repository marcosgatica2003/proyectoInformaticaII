#!/bin/bash

mkdir -p ./documentacionCodigos

DOXYFILE_DIR="."
DOCS_DIR="$DOXYFILE_DIR/documentacionCodigos"

mkdir -p "$DOCS_DIR"
cp "$DOXYFILE_DIR/mainReal/mainReal.ino" "$DOXYFILE_DIR"
mv mainReal.ino main.cpp

doxygen "$DOXYFILE_DIR/Doxyfile"

cd "$DOXYFILE_DIR/documentacionCodigos/latex" || exit

make

rm "$DOXYFILE_DIR/main.cpp"
mv refman.pdf S.S.C.F.Software.pdf
mv S.S.C.F.Software.pdf ../
cd - || exit
clear
echo "Documentación de software generada como S.S.C.F.Software.pdf"

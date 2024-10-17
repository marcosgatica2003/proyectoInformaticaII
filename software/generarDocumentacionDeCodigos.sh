#!/bin/bash

mkdir -p ./documentacionCodigos

DOXYFILE_DIR="."
DOCS_DIR="$DOXYFILE_DIR/documentacionCodigos"

mkdir -p "$DOCS_DIR"

doxygen "$DOXYFILE_DIR/Doxyfile"

cd "$DOXYFILE_DIR/documentacionCodigos/latex" || exit

make

mv refman.pdf S.S.C.F.Software.pdf
mv S.S.C.F.Software.pdf ../

cd - || exit

echo "Documentación de software generada como S.S.C.F.Software.pdf"

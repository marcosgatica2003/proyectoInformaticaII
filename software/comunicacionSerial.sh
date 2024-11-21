#/bin/bash
cat /dev/ttyUSB0 | tee >(grep "Temperatura máxima:" >> temperaturaMaxima.txt) >(grep "Ingreso número:" >> ingresos.txt) > /dev/null

cat temperaturaMaxima.txt ingresos.txt >> registroFinal.txt



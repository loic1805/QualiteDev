#!/bin/bash
set -e  # on stoppe le script si une commande echoue

echo "=== Running Bubble Sort Tests ==="

# on compile le programme
make clean && make all

# on execute le programme et redirige la sortie vers un fichier
./bubble_sort > output.txt

# on verifie si la sortie contient le texte attendu
if grep -q "Tri croissant" output.txt; then
  echo "✅ Test réussi"
  exit 0
else
  echo "❌ Test échoué"
  exit 1
fi

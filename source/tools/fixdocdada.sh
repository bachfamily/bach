for f in /Users/danieleghisi/Documents/Max\ 7/Packages/dada/source/mains/*
do
  echo "Processing $f..."
  sh ./fixdocpar_once.sh "$f"
done


for f in /Users/danieleghisi/Documents/Max\ 7/Packages/dada/source/commons/*
do
  echo "Processing $f..."
  sh ./fixdocpar_once.sh "$f"
done

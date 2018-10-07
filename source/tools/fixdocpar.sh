for f in ../mains/aa/*
do
  echo "Processing $f..."
  sh ./fixdocpar_once.sh "$f"
done


for f in ../mains/dg/*
do
  echo "Processing $f..."
  sh ./fixdocpar_once.sh "$f"
done


for f in ../commons/aa/*
do
  echo "Processing $f..."
  sh ./fixdocpar_once.sh "$f"
done


for f in ../commons/dg/*
do
  echo "Processing $f..."
  sh ./fixdocpar_once.sh "$f"
done


for f in ../abstractions/aa/*
do
  echo "Processing $f..."
  sh ./fixdocpar_once.sh "$f"
done


for f in ../abstractions/dg/*
do
  echo "Processing $f..."
  sh ./fixdocpar_once.sh "$f"
done
for f in /Users/danieleghisi/Documents/Max\ 7/Packages/cage/docs/DoctorMax_sources/files/*
do
  echo "Processing $f..."
  sh ./fixdocpar_once.sh "$f"
done

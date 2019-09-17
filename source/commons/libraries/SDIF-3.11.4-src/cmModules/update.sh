#! /bin/sh

echo "$@"

dir="$1";
shift
command="$1"
shift
cd "$dir"
"$command" "$@"  

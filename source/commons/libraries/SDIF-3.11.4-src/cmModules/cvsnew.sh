#! /bin/sh

dir="$1";
shift
command="$1"
shift

cd "$dir"
"$command" status "$@"  2>/dev/null | perl -e '$num=0;while(<STDIN>) {if( m/.*Status:.*/ ) {$num=$num+1;
@stat=m/File:(.*)Status:\s*(.*)/} ; if($stat[1] !~ "Up-to-date" && m/ *Repository/ )
{@file=m/\s*Repository.*:\s*([-+.0-9]+)\s*(.+)/; print (@stat," -> ",$file[1],"\n");};};
print($num, " files checked \n");  '
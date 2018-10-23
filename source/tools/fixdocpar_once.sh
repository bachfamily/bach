> /tmp/fixdocpartmp1.txt
> /tmp/fixdocpartmp2.txt

awk '{
    gsub("</b>","CYI")
    while ( match($0,/<b>[^\n]*\([^\n]*CYI/) ) {
        tgt = substr($0,RSTART,RLENGTH)
        gsub(/\(/,"[",tgt)
        gsub(/\)/,"]",tgt)
        $0 = substr($0,1,RSTART-1) tgt substr($0,RSTART+RLENGTH)
    }
    gsub("CYI","</b>")
    print
}' "$1" > /tmp/fixdocpartmp1.txt

awk '{
    gsub("@caption","CYI")
    while ( match($0,/@example[^\n]*\([^\n]*CYI/) ) {
        tgt = substr($0,RSTART,RLENGTH)
        gsub(/\(/,"[",tgt)
        gsub(/\)/,"]",tgt)
        $0 = substr($0,1,RSTART-1) tgt substr($0,RSTART+RLENGTH)
    }
    gsub("CYI","@caption")
    print
}' /tmp/fixdocpartmp1.txt > /tmp/fixdocpartmp2.txt

mv /tmp/fixdocpartmp2.txt "$1" 
#usage sh removepatreonbutton.sh <helpdirectory>
#beware: will substitute files in-place!

#file name
input=$1
if [[ -d $input ]]; then
    path="$input"/bach.*.maxhelp
elif [[ -f $input ]]; then
    path="$input"
else
    echo "$input is not valid"
    exit 1
fi

for file in $path; do

echo "Processing file $file..."

#retrieve position of the basic tab in help file
basictabidx=$(jq '[ .patcher.boxes[] | .box.varname == "basic_tab" ] | index(true)' "$file" )

jq --arg basictabidx "$basictabidx" 'del(.patcher.boxes[$basictabidx | tonumber].box.patcher.boxes[] | 
				select(.box.varname == "becomeapatronimg" or .box.varname == "becomeapatronlaunch" or .box.varname == "becomeapatronclick")) |
			del(.patcher.boxes[$basictabidx | tonumber].box.patcher.lines[] | 
				select(.patchline.source[0] == "becomeapatronclick"))' "$file" >> /tmp/patronizetmp.txt

mv /tmp/patronizetmp.txt "$file"

done

echo "Done!"
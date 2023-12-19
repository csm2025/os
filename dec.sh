read -p "Enter a decimal" d
bi=""
while [ $d -gt 0 ]; do
	rem=$((d%2))
	bi="$rem$bi"
	d=$((d/2))
done
echo "$bi"

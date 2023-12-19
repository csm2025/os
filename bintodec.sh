read -p "base 5 Number:" n
p=1
for ((i=${#n}-1;i>=0;i--)); do
	d="${n:i:1}"
	dn=$((dn+d*p))
	p=$((p*5))
done
echo "$dn"

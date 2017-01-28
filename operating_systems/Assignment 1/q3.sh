
Hello ( ) 
{
	for TOKEN in "$@"

	do
	len=`expr $TOKEN|wc -m $TOKEN`
	echo $len
	done
	return 10
}

Hello $@

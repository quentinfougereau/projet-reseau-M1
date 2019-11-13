if [ -z "$1" ]
then
 echo "usage : $0 <port>"
 exit 1
fi

echo "Compilation du fichier echoserveur.c"

gcc echoserveur.c -o echoserveur
./echoserveur $1 > log.txt 2>&1 &

iperf3 -s >> log.txt 2>&1 &

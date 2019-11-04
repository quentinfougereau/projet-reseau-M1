ip link set tun0 up
ip a add 172.16.2.3/28 dev tun0
ip route add 172.16.2.144/28 via 172.16.2.3 dev tun0
